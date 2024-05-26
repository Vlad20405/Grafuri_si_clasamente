#include "main.h"

void Cerinta_1(FILE* fisier_out_graf, Graph *g){

    for(int i = 0; i<g->V; i++){
        for(int j=0; j<g->V; j++){
            fprintf(fisier_out_graf, "%d ", g->matrice[i][j]);
        }
        fprintf(fisier_out_graf, "\n");
    }
}