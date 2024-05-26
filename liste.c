#include "main.h"

void addAtBeginning(Node **head, Echipa v){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = v;
    newNode->next = *head;
    *head = newNode;
}

void addAtEnd(Node** head, Echipa v){
	Node *aux = *head;
	Node *newNode = (Node*)malloc(sizeof(Node)); 
	newNode->val = v; 
	if (*head == NULL) addAtBeginning(head, v);
	else{ 
		while (aux->next!=NULL) 
			aux = aux->next;
		aux->next = newNode;
		newNode->next = NULL; 
	}
}

void eliberareLista(Node *head){
    Node *temp;
    while (head != NULL) {
        free(head->val.Nume_echipa);

        temp = head;
        head = head->next;
        
        free(temp);
    }
}
