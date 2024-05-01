//Final Group Project 1102 Team 3 May 2024
//Erinstagram by Summer Avissanyx and Tirth Patel

#include <stdio.h>

int main () {
    int mainchoice;
    
    do {
        printf ("**ERINSTAGRAM**\n1: Load image\n2: Display image\n3: Edit image\n0: Exit\nChoose from one of the options above: ");
        scanf ("%d", &mainchoice);   
    
    } while (mainchoice != 0);
    
    printf ("Goodbye!\n");
return 0;
}

