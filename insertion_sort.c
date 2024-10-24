#include "insertion_sort.h"
#include <stdio.h>
#include <stdlib.h>

node* isort(node *list) {
    node* sorted = NULL; //Vi laver en ny liste, som er den sorterede liste, der initialiseres som NULL
    node* current = list; //Her sættes "current" til at pege på det første element i listen

    while (current != NULL)//Her starter løkken, hvor den går gennem hver node i den originale liste
    {
        node* nextNode = current->next; //Vi gemmer den næste node, før pointeren ændres

        if (sorted == NULL || sorted->data >= current->data) //Her tjekkes der om listen er tom eller om den aktuelle node er mindre end det første element
        { 
            current->next = sorted; //Vi sætter den aktuelle node til at pege mod det første element i vores liste
            sorted = current; //Opdaterer vores aktuelle node til det første element i den sorterede liste
        }
        else { //Hvis den aktuelle node ikke er mindre, finder vi den rigtige plads.
            node* temp = sorted; //Starter med at pege på det første element i den sorterede liste
            while (temp->next != NULL && temp->next->data < current->data) // Her finder vi hvor noden passer ind i den sorterede liste
            {
                temp = temp->next; //Kører alle noder igennem i vores sorterede liste
            }
            current->next = temp ->next; // Her sættes "current" next til at være den næste node i den sorterede liste
            temp->next = current; // Opdaterer "temp" next til at pege på current
        }
        //Flytter videre til den næste node i den oprindelige liste
        current = nextNode; //Gemmer den næste node, som den nye aktuelle node.
    }
    return sorted; // Returnerer den sorterede liste
}

