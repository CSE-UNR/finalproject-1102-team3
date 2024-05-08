//Final Group Project 1102 Team 3 May 2024
//Erinstagram by Summer Avissanyx and Tirth Patel

#include <stdio.h>
#define ROWS 500
#define COLS 500
#define FILE_NAME_CAP 25

int loadImage(int* rowPtr, int* colPtr, int rows, int cols, char theimagearray[][COLS]);
void displayImage(int rows, int cols, char theimagearray[][COLS], int* rowPtr, int* colPtr);
int editmenu(int rows, int cols, char theimagearray[][COLS], int* rowPtr, int* colPtr);
int crop(int rows, int cols, int newTrow, int newBrow, int newLcol, int newRcols, char theimagearray[][COLS], int* rowPtr, int* colPtr);
void brightenImage(int rows, int cols, char theimagearray[][COLS], int* rowPtr, int* colPtr);
void dimImage(int rows, int cols, char theimagearray[][COLS], int* rowPtr, int* colPtr);

int main () {
    char theimagearray[ROWS][COLS];
    int mainchoice, rowsize=0, colsize=0;
    
    do {
        printf ("\n**ERINSTAGRAM**\n1: Load image\n2: Display image\n3: Edit image\n0: Exit\nChoose from one of the options above: ");
        scanf ("%d", &mainchoice);  
        printf ("\n"); 
        if (mainchoice == 1) {
            loadImage(&rowsize, &colsize, ROWS, COLS, theimagearray);
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

//Check loadImageTest.c for code
int loadImage(int* rowPtr, int* colPtr, int rows, int cols, char theimagearray[][COLS]) {
	int numElements = 0, rowtally=1, coltally=1;
	char fileName[FILE_NAME_CAP], ch, loadArray[ROWS][COLS];
	FILE* fp;
	
	printf("What is the name of the image file? ");
	scanf("%s", fileName);
	fp = fopen(fileName, "r");
	if(fp == NULL){
		printf("Could not find an image with that filename.\n");
		return 0;
	}
    while(fscanf(fp, "%c", &ch) == 1) {	
		numElements++;
		if(ch == '\n'){
			rowtally++;
			numElements = numElements - 1;
		}
	}
	numElements++;
	coltally = (numElements / rowtally)-1;
	*rowPtr = rowtally;
	*colPtr = coltally;
	fclose(fp);
	
	fp = fopen(fileName, "r");
	if(fp == NULL){
		printf("Could not find an image with that filename.\n");
		return 0;
	} 
	for(int i = 0; i <= *rowPtr; i++){
		for(int j = 0; j <= *colPtr; j++){
			fscanf(fp, "%c", &loadArray[i][j]);
		} 
	}
	
	for(int r = 0; r <= *rowPtr; r++){
		for(int c = 0; c <= *colPtr; c++) {
		    switch (loadArray[r][c]) {
		        case '\n': 
		            theimagearray[r][c] = '\n';
		        break;
		        case '0':
		            theimagearray[r][c] = ' ';
		        break;
		        case '1': 
		            theimagearray[r][c] = '.';
		        break;
		        case '2':
		            theimagearray[r][c] = 'o';
		        break;
		        case '3':
		            theimagearray[r][c] = 'O';
		        break;
		        case '4':
		            theimagearray[r][c] = '0';
		        break;
		    }
	    }
    }
	fclose (fp);	
    printf ("\nImage successfully loaded!\n");
    return 0;
}

void displayImage(int rows, int cols, char theimagearray[][COLS], int* rowPtr, int* colPtr) {
    for (int i=0; i <= *rowPtr; i++) {
        for (int j=0; j <= *colPtr; j++) {
            printf ("%c", theimagearray[i][j]);
        }
    }
}

int editmenu (int rows, int cols, char theimagearray[][COLS], int* rowPtr, int* colPtr) {
    int editchoice, savechoice, cropLcol, cropRcol, cropTrow, cropBrow;
    char newfilename[25];
    printf ("**EDITING**\n1: Crop image\n2: Dim image\n3: Brighten image\n0: Return to main menu\nChoose from one of the options above: ");
    scanf ("%d", &editchoice);
    if (editchoice == 1) {
       printf ("\nImage height: %d\nImage width: %d\nThe row and columns start at 1 in the upper lefthand corner.\nWhich column do you want to be the new left side?", *rowPtr, *colPtr);
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
    printf ("\nWould you like to save your new image to a file(1 for yes, 2 for no)? ");
    scanf ("%d", &savechoice);
    if (savechoice == 0) {
        return 0;
    }
    else if (savechoice ==1) {
        printf ("What would you like the name of the new file to be? ");
        scanf ("%s", &newfilename);
        FILE* savePtr; 
        savePtr = fopen (newfilename, "w");
        if (savePtr == NULL) { 
            printf ("Error saving file\n");
        }
//need to fix printing the 2d array to a file            
//            fprintf (savePtr, theimagearray);
            fclose (savePtr);
    }
    else{
        return 0;
    }
    return 0;
}
//Using a pointer to point to the starting memory address of the cropped size(upper left corner) of the array, maybe need to use pointer arithmetic? Then print the array until the ending size (bottom right corner).
int crop(int rows, int cols, int newTrow, int newBrow, int newLcol, int newRcol, char theimagearray[][COLS], int* rowPtr, int* colPtr) {
    char *croppedPtr = &theimagearray[newTrow][newLcol];
    for (int i=0; i < newBrow; i++) {
        for (int j=0; j < newRcol; j++) {
            theimagearray[i][j];
            printf ("%d", *croppedPtr);
        }
    }
    printf("\n");
}

void brightenImage(int rows, int cols, char theimagearray[][COLS], int* rowPtr, int* colPtr){
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			switch (theimagearray[i][j]) {    
			    case '\n': 
		            theimagearray[i][j] = '\n';
		        break;
		        case ' ':
		            theimagearray[i][j] = '.';
		        break;
		        case '.': 
		            theimagearray[i][j] = 'o';
		        break;
		        case 'o':
		            theimagearray[i][j] = 'O';
		        break;
		        case 'O':
		            theimagearray[i][j] = '0';
		        break;
		        case '0':
		            theimagearray[i][j] = '0';
		        break;
		    }
		}
	}
	displayImage(ROWS, COLS, theimagearray, rowPtr, colPtr);
}

void dimImage(int rows, int cols, char theimagearray[][COLS], int* rowPtr, int* colPtr){
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			switch (theimagearray[i][j]) {    
			    case '\n': 
		            theimagearray[i][j] = '\n';
		        break;
		        case ' ':
		            theimagearray[i][j] = ' ';
		        break;
		        case '.': 
		            theimagearray[i][j] = ' ';
		        break;
		        case 'o':
		            theimagearray[i][j] = '.';
		        break;
		        case 'O':
		            theimagearray[i][j] = 'o';
		        break;
		        case '0':
		            theimagearray[i][j] = 'O';
		        break;
		    }
		}
	}
    displayImage(ROWS, COLS, theimagearray, rowPtr, colPtr);
}



