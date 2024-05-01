//Final Group Project 1102 Team 3 May 2024
//Erinstagram by Summer Avissanyx and Tirth Patel

#include <stdio.h>
#define ROWS 500
#define COLS 500

int editmenu(int rows, int cols, int theimagearray[][COLS]);
int crop(int rows, int cols, int newTrow, int newBrow, int newLcol, int newRcols, int theimagearray[][COLS]);

int main () {
    int theimagearray[ROWS][COLS], mainchoice;
    
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
    int editchoice, cropLcol, cropRcol, cropTrow, cropBrow;
    printf ("**EDITING**\n1: Crop image\n2: Dim image\n3: Brighten image\n0: Return to main menu\nChoose from one of the options above: ");
    scanf ("%d", &editchoice);
    if (editchoice == 1) {
       printf ("\nImage height: \nImage width: \nThe row and columns start at 1 in the upper lefthand corner.\nWhich column do you want to be the new left side? ");
       scanf ("%d", &cropLcol);
       printf ("Which column do you want to be the new right side? ");
       scanf ("%d", &cropRcol);
       if (cropRcol <= cropLcol) {
           printf ("Invalid column value. Choose a value between %d and %d: ", cropLcol, *colsize);
           scanf ("%d", &cropRcol);
       }
       printf ("Which row do you want to be the new top? ");
       scanf ("%d", &cropTrow);
       printf ("Which row do you want to be the new bottom? ");
       scanf ("%d", &cropBrow);
       if (cropBrow <= cropTrow) {
           printf ("Invalid row value. Choose a value between %d and %d: ", cropTrow, *rowsize);
           scanf ("%d", &cropBrow);
       }
       crop(rows, cols, cropTrow, cropBrow, cropLcol, cropRcol, theimagearray);
       
       return 0;
    }
}
int crop(int rows, int cols, int newTrow, int newBrow, int newLcol, int newRcol, int theimagearray[][COLS]) {
    
}
