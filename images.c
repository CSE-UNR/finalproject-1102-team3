//Final Group Project 1102 Team 3 May 2024
//Erinstagram by Summer Avissanyx and Tirth Patel

#include <stdio.h>
#define ROWS 500
#define COLS 500

void loadImage(int* rowPtr, int* colPtr, int rows, int cols, int theimagearray[][COLS]);
void displayImage(int rows, int cols, int theimagearray[][COLS], int* rowPtr, int* colPtr);
int editmenu(int rows, int cols, int theimagearray[][COLS], int* rowPtr, int* colPtr);
int crop(int rows, int cols, int newTrow, int newBrow, int newLcol, int newRcols, int theimagearray[][COLS], int* rowPtr, int* colPtr);
void brightenImage(int rows, int cols, int theimagearray[][COLS], int* rowPtr, int* colPtr);
void dimImage(int rows, int cols, int theimagearray[][COLS], int* rowPtr, int* colPtr);

int main () {
    int theimagearray[ROWS][COLS], mainchoice, rowsize, colsize;
    
    do {
        printf ("**ERINSTAGRAM**\n1: Load image\n2: Display image\n3: Edit image\n0: Exit\nChoose from one of the options above: ");
        scanf ("%d", &mainchoice);   
        if (mainchoice == 1) {
            
        }
        else if (mainchoice == 2) {
            displayImage(ROWS, COLS, theimagearray, &rowsize, &colsize);
        }
        else if (mainchoice == 3) {
           editmenu(ROWS, COLS, theimagearray, &rowsize, &colsize);
        }
        
    } while (mainchoice != 0);
    
    printf ("Goodbye!\n");
return 0;
}
void loadImage(int* rowPtr, int* colPtr, int rows, int cols, int theimagearray[][COLS]) {

}
void displayImage(int rows, int cols, int theimagearray[][COLS], int* rowPtr, int* colPtr) {
    for (int i=0; i < *rowPtr; i++) {
        for (int j=0; j < *colPtr; j++) {
            printf ("%d", theimagearray[i][j]);
        }
    }
}
//Won't compile because the pointers for the actual image row size and column size (called rowsize and colsize) haven't been declared or assigned values yet. Need to use these pointers in the load function with fscanf for the sizes
int editmenu (int rows, int cols, int theimagearray[][COLS], int* rowPtr, int* colPtr) {
    int editchoice, cropLcol, cropRcol, cropTrow, cropBrow;
    printf ("**EDITING**\n1: Crop image\n2: Dim image\n3: Brighten image\n0: Return to main menu\nChoose from one of the options above: ");
    scanf ("%d", &editchoice);
    if (editchoice == 1) {
       printf ("\nImage height: \nImage width: \nThe row and columns start at 1 in the upper lefthand corner.\nWhich column do you want to be the new left side? ");
       scanf ("%d", &cropLcol);
       printf ("Which column do you want to be the new right side? ");
       scanf ("%d", &cropRcol);
       if (cropRcol <= cropLcol) {
           printf ("Invalid column value. Choose a value between %d and %d: ", cropLcol, *colPtr);
           scanf ("%d", &cropRcol);
       }
       printf ("Which row do you want to be the new top? ");
       scanf ("%d", &cropTrow);
       printf ("Which row do you want to be the new bottom? ");
       scanf ("%d", &cropBrow);
       if (cropBrow <= cropTrow) {
           printf ("Invalid row value. Choose a value between %d and %d: ", cropTrow, *rowPtr);
           scanf ("%d", &cropBrow);
       }
       crop(rows, cols, cropTrow, cropBrow, cropLcol, cropRcol, theimagearray, rowPtr, colPtr);
       
    }
    else if (editchoice == 2) {
        dimImage(rows, cols, theimagearray, rowPtr, colPtr);
    }
    else if (editchoice == 3) {
        brightenImage(rows, cols, theimagearray, rowPtr, colPtr);
    }
    else if (editchoice == 0) {
        return 0;
    }
}
int crop(int rows, int cols, int newTrow, int newBrow, int newLcol, int newRcol, int theimagearray[][COLS], int* rowPtr, int* colPtr) {
    
}

//Have to add the display image function when it is created
void brightenImage(int rows, int cols, int theimagearray[][COLS], int* rowPtr, int* colPtr){
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			if(theimagearray[i][j] <= 5){
				theimagearray[i][j] = theimagearray[i][j] + 1;
			}
		}
	}
	displayImage(ROWS, COLS, theimagearray, rowPtr, colPtr);
}

//Have to add the display image function when it is created
void dimImage(int rows, int cols, int theimagearray[][COLS], int* rowPtr, int* colPtr){
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			if(theimagearray[i][j] <= 5){
				theimagearray[i][j] = theimagearray[i][j] - 1;
			}
		}
	}
    displayImage(ROWS, COLS, theimagearray, rowPtr, colPtr);
}



