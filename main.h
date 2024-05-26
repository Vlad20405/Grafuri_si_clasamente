#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define totalEchipe 32

struct Echipa{
    char* Nume_echipa; 
    float punctaj;
    float prestigiu;
    int pozitie;
    int nr_victorii;
};
typedef struct Echipa Echipa;

struct Elem{
	Echipa val;
	struct Elem* next;
};
typedef struct Elem Node;

struct Graph
{
    Echipa *Varf; 
    int V; //nr varfuri
    int E; //nr muchii
    int **matrice;
};
typedef struct Graph Graph;

void eroare_la_deschidere();
void eroare_la_alocare();

Node *citireDateEchipe(FILE *fisier_in);
void addAtBeginning(Node **head, Echipa v);
void addAtEnd(Node** head, Echipa v);
void eliberareLista(Node *head);

int isEmptyStack(Node *top);
void push(Node **top, Echipa echipa);
Echipa pop(Node **top);
void deleteStack(Node **top);

Graph *create();
void freeGraph(Graph *g);

void etapaInitiala(Node *head, Node **castigatori, Node **pierzatori, Graph *g);
void etapaFinala(Node **castigatori, Node **pierzatori, Graph *g);
void introduceInGraf(Graph *g, Node *echipa_castigatoare, Node *echipa_pierzatoare);

void Cerinta_1(FILE* fisier_out_graf, Graph *g);