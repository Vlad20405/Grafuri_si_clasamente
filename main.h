#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

struct Echipa{
    char* Nume_echipa; 
    float punctaj;
    int nr_victorii;
};
typedef struct Echipa Echipa;

struct Q_Elem{
	Echipa *echipa_1, *echipa_2;
	struct Q_Elem* next;
};
typedef struct Q_Elem Meciuri;

struct Queue{
    Meciuri *front, *rear;
};
typedef struct Queue Queue;

void eroare_la_deschidere();
void eroare_la_alocare();
