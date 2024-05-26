#include "main.h"

#define maxCaractere 50

void eroare_la_deschidere(){
    puts("Fisierul nu poate fi deschis!\n");
    exit(1);
}

void eroare_la_alocare(){
    puts("Nu s-a putut aloca memorie!\n");
    exit(1);
}

Node *citireDateEchipe(FILE *fisier_in){
    Node *head = NULL;
    char line[maxCaractere], *q;
    
    for (int i = 0; i < totalEchipe; i++){
        Echipa e;
        float punctaj = 0;

        fscanf(fisier_in, "%f", &punctaj);
        fgetc(fisier_in);
        fgets(line, sizeof(line), fisier_in);

        e.Nume_echipa = (char*)malloc((strlen(line)+1) * sizeof(char));
        if(e.Nume_echipa == NULL)
            eroare_la_alocare();

        strcpy(e.Nume_echipa, line);
        e.Nume_echipa[strlen(e.Nume_echipa)-1]='\0';

    	if(e.Nume_echipa[strlen(e.Nume_echipa)-1] == ' ')
            e.Nume_echipa[strlen(e.Nume_echipa)-1] = '\0';
        
        e.pozitie = i;
        e.nr_victorii = 0;
        e.punctaj = punctaj;
        addAtEnd(&head, e);
    }
    return head;
}

void etapaInitiala(Node *head, Node **castigatori, Node **pierzatori, Graph *g){

    while(head != NULL && head->next != NULL){
        Node *echipa_1 = (Node*)malloc(sizeof(Node));
        if (echipa_1 == NULL)
            eroare_la_alocare();

        *echipa_1 = *head;
        head = head->next;

        Node *echipa_2 = (Node*)malloc(sizeof(Node));
        if (echipa_2 == NULL)
            eroare_la_alocare();

        *echipa_2 = *head;
        head = head->next;
        
        if(echipa_1->val.punctaj > echipa_2->val.punctaj){
            echipa_1->val.nr_victorii++;
            push(castigatori, echipa_1->val);
            push(pierzatori, echipa_2->val);
            introduceInGraf(g, echipa_1, echipa_2);
        }
        else if(echipa_1->val.punctaj < echipa_2->val.punctaj){
                echipa_2->val.nr_victorii++;
                push(castigatori, echipa_2->val);
                push(pierzatori, echipa_1->val);
                introduceInGraf(g, echipa_2, echipa_1);
        }
        else{
            if(strcmp(echipa_1->val.Nume_echipa, echipa_2->val.Nume_echipa) > 0){
                echipa_1->val.nr_victorii++;
                push(castigatori, echipa_1->val);
                push(pierzatori, echipa_2->val);
                introduceInGraf(g, echipa_1, echipa_2);
            }
            else{
                echipa_2->val.nr_victorii++;
                push(castigatori, echipa_2->val);
                push(pierzatori, echipa_1->val);
                introduceInGraf(g, echipa_2, echipa_1);
            }
        }
    }
}

void etapaFinala(Node **castigatori, Node **pierzatori, Graph *g){
    Node *head = NULL;
    Node *head_c = NULL;
    Node *current = *castigatori;
    while(current != NULL){
        addAtEnd(&head, current->val);
        current = current->next;
    }
    deleteStack(castigatori);

    head_c = head;
    while(head_c != NULL && head_c->next != NULL){
        Node *echipa_1 = (Node*)malloc(sizeof(Node));
        if (echipa_1 == NULL)
            eroare_la_alocare();

        *echipa_1 = *head_c;
        head_c = head_c->next;

        Node *echipa_2 = (Node*)malloc(sizeof(Node));
        if (echipa_2 == NULL)
            eroare_la_alocare();

        *echipa_2 = *head_c;
        head_c = head_c->next;
        
        if(echipa_1->val.punctaj > echipa_2->val.punctaj){
            echipa_1->val.nr_victorii++;
            push(castigatori, echipa_1->val);
            push(pierzatori, echipa_2->val);
            introduceInGraf(g, echipa_1, echipa_2);
        }
        else if(echipa_1->val.punctaj < echipa_2->val.punctaj){
                echipa_2->val.nr_victorii++;
                push(castigatori, echipa_2->val);
                push(pierzatori, echipa_1->val);
                introduceInGraf(g, echipa_2, echipa_1);
        }
        else{
            if(strcmp(echipa_1->val.Nume_echipa, echipa_2->val.Nume_echipa) > 0){
                echipa_1->val.nr_victorii++;
                push(castigatori, echipa_1->val);
                push(pierzatori, echipa_2->val);
                introduceInGraf(g, echipa_1, echipa_2);
            }
            else{
                echipa_2->val.nr_victorii++;
                push(castigatori, echipa_2->val);
                push(pierzatori, echipa_1->val);
                introduceInGraf(g, echipa_2, echipa_1);
            }
        }
    }
    //eliberareLista(head);
}

void introduceInGraf(Graph *g, Node *echipa_castigatoare, Node *echipa_pierzatoare){
    g->matrice[echipa_pierzatoare->val.pozitie][echipa_castigatoare->val.pozitie] = 1;
    g->E++;
}