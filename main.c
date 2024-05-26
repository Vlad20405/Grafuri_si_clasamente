#include "main.h"

int main(int arcg, char *argv[])
{   
    FILE *fisier_in, *fisier_out_graf, *fisier_out_scor;
    if((fisier_in = fopen(argv[1], "rt")) == NULL)
        eroare_la_deschidere();

    if((fisier_out_graf = fopen(argv[2], "wt")) == NULL)
        eroare_la_deschidere();

    if((fisier_out_scor = fopen(argv[3], "wt")) == NULL)
        eroare_la_deschidere();
    
    Node *head = NULL;
    head = citireDateEchipe(fisier_in);

    Node *castigatori = NULL;
    Node *pierzatori = NULL;
    Graph *graf = create();
    etapaInitiala(head, &castigatori, &pierzatori, graf);

    int nrEchipe = totalEchipe/2;
    while(nrEchipe > 1){
        etapaFinala(&castigatori, &pierzatori, graf);
    nrEchipe = nrEchipe/2;
    }

    Cerinta_1(fisier_out_graf, graf);

    fclose(fisier_in);
    fclose(fisier_out_graf);
    fclose(fisier_out_scor);

    eliberareLista(head);
    deleteStack(&castigatori);
    deleteStack(&pierzatori);
    return 0;
}
