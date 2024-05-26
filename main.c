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
    
    
    fclose(fisier_in);
    fclose(fisier_out_graf);
    fclose(fisier_out_scor);

    return 0;
}
