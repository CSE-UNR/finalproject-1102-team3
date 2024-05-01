//Final Group Project 1102 Team 3 May 2024
//Erinstagram by Summer Avissanyx and Tirth Patel

#include <stdio.h>
#define ROWS 500
#define COLS 500

int editmenu(int rows, int cols, int theimagearray[][COLS]);

int main () {
    int theimagearray[ROWS][COLS], mainchoice, rows=ROWS, cols=COLS;
    
    do {
        printf ("**ERINSTAGRAM**\n1: Load image\n2: Display image\n3: Edit image\n0: Exit\nChoose from one of the options above: ");
        scanf ("%d", &mainchoice);   
        if (mainchoice == 1) {
        }
        else if (mainchoice == 2) {
        }
        else if (mainchoice == 3) {
           editmenu(ROWS, COLS, theimagearray);
        }
        
    } while (mainchoice != 0);
    
    printf ("Goodbye!\n");
return 0;
}

int editmenu (int rows, int cols, int theimagearray[][COLS]) {
    int editchoice;
    printf ("**EDITING**\n1: Crop image\n2: Dim image\n3: Brighten image\n0: Return to main menu\nChoose from one of the options above: ");
    scanf ("%d", &editchoice);
    if (editchoice == 1) {
        
    }
    else if (editchoice == 2) {
        
    }
    else if (editchoice == 3) {
        
    }
    else if (editchoice == 0) {
        return 0;
    }
}
