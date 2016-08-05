#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
	int dim1, dim2;
	float prob;
	
	char line[100];
	while(1){
		printf("Enter first dimension: ");
		fgets(line, sizeof(line), stdin);
		if(sscanf(line, "%d", &dim1))
			break;
		printf("\nYou did not enter a valid dimension.\n");
	}/*checks for invalid input*/
	while(1){
		printf("Enter second dimension: ");
		fgets(line, sizeof(line), stdin);
		if(sscanf(line, "%d", &dim2))
			break;
		printf("\nYou did not enter a valid dimension.\n");
	}/*checks for invalid input*/

	while(1){
		printf("Enter probability of mines: ");
		fgets(line, sizeof(line), stdin);
		if(sscanf(line, "%f", &prob)&&prob>0 && prob<1)
			break;
		printf("\nYou did not enter a valid probability.\n");
	}/*checks for invalid input*/
	prob*=10;/*makes prob a value between 1 and 9*/

	srand(time(NULL)); /*initializes generator*/

	int board[dim1][dim2];

	for(int r=0; r<dim1; r++){
		for(int c=0; c<dim2; c++){
			int r = rand();
			r%=10;
		}
	}/*puts values between 0-9 in board*/
	
	char printBoard[dim1+2][dim2+2];/*creates printable board*/

	for(int r=1; r<dim1+1; r++){
		for(int c=1; c<dim2+1; c++){
			if(prob>board[r][c]){
				printBoard[r][c] = ' ';
			}
			else printBoard[r][c] = '*';
		}
	}/*fills in printableBoard*/

	int count = 0;
	for(int r=0; r<dim1+2; r++){
		for(int c=0; c<dim2+2; c++){
			if(printBoard[r][c]!='*'){
				if(printBoard[r+1][c]=='*')
					count++;
				if(printBoard[r-1][c]=='*')
					count++;
				if(printBoard[r+1][c+1]=='*')
					count++;
				if(printBoard[r+1][c-1]=='*')
					count++;
				if(printBoard[r][c+1]=='*')
					count++;
				if(printBoard[r][c-1]=='*')
					count++;
				if(printBoard[r-1][c-1]=='*')
					count++;
				if(printBoard[r-1][c+1]=='*')
					count++;
			
			board[r][c]=count;
			printBoard[r][c]=count + '0';
			count=0;
			}
		}
	}/*puts numbers into non-mine spaces*/

	char userBoard[dim1][dim2];
	for(int r =0; r<dim1; r++){
		for(int c = 0; c<dim2; c++){
			userBoard[r][c]= printBoard[r+1][c+1];
		}
	}/*sets board dimensions back to regular*/

	for(int r = 0; r<dim1; r++){
		for(int c = 0; c<dim2; c++){
			if(userBoard[r][c]!='*'){
				char temp[100] = "_";
				strcat(temp, userBoard[r][c]);
				printf("\n\n%c", userBoard[r][c]);
			}
		}
	}

	printf("\n");

	for(int r=0; r<dim1; r++){
		for(int c=0; c<dim2; c++)
			printf("%c", userBoard[r][c]);
		printf("\n");
	}
	return 0;
}
