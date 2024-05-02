//Have to add the display image function when it is created
void brightenImage(int rows, int cols, int theimagearray[][COLS]){
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			if(theimagearray[i][j] <= 5){
				theimagearray[i][j] = theimagearray[i][j] + 1;
			}
		}
	}
}

//Have to add the display image function when it is created
void dimImage(int rows, int cols, int theimagearray[][COLS]){
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			if(theimagearray[i][j] <= 5){
				theimagearray[i][j] = theimagearray[i][j] - 1;
			}
		}
	}
}
