#include "main.h"

Graph *create(){
    
    Graph *g = (Graph*)malloc(sizeof(Graph));
    if(g == NULL)
        eroare_la_alocare();

    g->V = totalEchipe;

    g->matrice = (int**)malloc(g->V * sizeof(int*));
    for(int i=0; i<g->V; i++){
        g->matrice[i] = (int*)calloc(g->V, sizeof(int));
    if(g->matrice == NULL)
        eroare_la_alocare();
    }

    return g;
}

void introduceInGraf(Graph *g, Node *echipa_castigatoare, Node *echipa_pierzatoare){
    g->matrice[echipa_pierzatoare->val.pozitie][echipa_castigatoare->val.pozitie] = 1;
    g->E++;
}