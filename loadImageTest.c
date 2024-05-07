#include <stdio.h>
#define ROWS 500
#define COLS 500
#define FILE_NAME_CAP 20
#define FILENAME "test_image.txt"


int main(){
	int numRows = 1, numCols, numElements = 0;
	char fileName[FILE_NAME_CAP], ch, imageArray[ROWS][COLS];
	FILE* fp;
	
	//temperarily used file name instead of asking for filename first and using that.
	fp = fopen(FILENAME, "r");
	if(fp == NULL){
		printf("Could not find an image with that filename.\n");
		return 0;
	}
	
	//Goes through each value in file and puts it into 2d array. Since the numbers in file are not seperated by spaces, it is probably putting them all into one column.//increment number of elements instead of cols. use %c and ch on loop. divide elements by rows to get cols.
	while(fscanf(fp, "%c", &ch) == 1){
		
		numElements++;
		if(ch == '\n'){
			numRows++;
			numElements = numElements - 1;
		}
	}
	numElements = numElements + 1;
	printf("Number of elements: %d\n", numElements);
	printf("Number of rows: %d\n", numRows);
	
	numCols = numElements / numRows;
	printf("Number of Columns: %d\n", numCols);
	
	fclose(fp);
	
	fp = fopen(FILENAME, "r");
	if(fp == NULL){
		printf("Could not find an image with that filename.\n");
		return 0;
	}
	
	for(int i = 0; i < numRows; i++){
		for(int j = 0; j < numCols; j++){
			fscanf(fp, "%c", &imageArray[i][j]);
			printf("%c", imageArray[i][j]);
		} 
	}
	
	//Doesnt print anything. Maybe because there is only one column and there are two many integers?
	
	
	printf("\n");
	
	

	return 0;
}
