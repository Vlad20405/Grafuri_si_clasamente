#include "main.h"

void Cerinta_1(FILE* fisier_out_graf, Graph *g){

    for(int i = 0; i<g->V; i++){
        for(int j=0; j<g->V; j++){
            fprintf(fisier_out_graf, "%d ", g->matrice[i][j]);
        }
        fprintf(fisier_out_graf, "\n");
    }
}

void Cerinta_2(FILE* fisier_out_scor, Node *castigatori, Node *pierzatori){

    Node *pierzatori_c = pierzatori;

    castigatori->val.prestigiu = calculPrestigiu(castigatori);

    while(pierzatori_c != NULL){
        pierzatori_c->val.prestigiu = calculPrestigiu(pierzatori_c);
        pierzatori_c = pierzatori_c->next;
    }

    afisarePrestigiuEchipe(fisier_out_scor, castigatori, pierzatori);
}