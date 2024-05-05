#include <stdio.h>
#define ROWS 500
#define COLS 500
#define FILE_NAME_CAP 20
#define FILENAME "test_image.txt"


int main(){
	int numRows = 0, numCols = 0, imageArray[ROWS][COLS];
	char fileName[FILE_NAME_CAP];
	FILE* fp;
	
	//temperarily used file name instead of asking for filename first and using that.
	fp = fopen(FILENAME, "r");
	if(fp == NULL){
		printf("Could not find an image with that filename.\n");
		return 0;
	}
	
	//Goes through each value in file and puts it into 2d array. Since the numbers in file are not seperated by spaces, it is probably putting them all into one column.
	while(fscanf(fp, "%d", &imageArray[numRows][numCols])){
		numCols++;
		if(numCols >= COLS){
			numCols = 0;
			numRows++;
		}
	}
	
	fclose(fp);
	
	//Doesnt print anything. Maybe because there is only one column and there are two many integers?
	for(int i = 0; i < numRows; i++){
		for(int j = 0; j < numCols; j++){
			printf("%d", imageArray[i][j]);
		} 
	}
	
	printf("\n");
	
	

	return 0;
}
