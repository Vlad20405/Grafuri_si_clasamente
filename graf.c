#include "main.h"

Graph *create(){
    
    Graph *g = (Graph*)malloc(sizeof(Graph));
    if(g == NULL)
        eroare_la_alocare();

    g->V = totalEchipe;
    g->Varf = (Echipa*)malloc(g->V * sizeof(Echipa));
    if(g->Varf == NULL)
        eroare_la_alocare();
    
    g->matrice = (int**)malloc(g->V * sizeof(int*));
    for(int i=0; i<g->V; i++){
        g->matrice[i] = (int*)calloc(g->V, sizeof(int));
    if(g->matrice == NULL)
        eroare_la_alocare();
    }

    return g;
}

void freeGraph(Graph *g){
    for(int i = 0; i<g->V; i++){
        free(g->matrice[i]);
    }
    free(g->matrice);
    free(g->Varf);
    free(g);
}