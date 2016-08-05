/* Write a program minesweeper.c that takes in dimensions m and n from the user and a probability p, then generates a Minesweeper board of size m x n where each cell has a probability of p to be a mine (probability is a number between 0 and 1). Each cell that is not a mine contains a number representing how many mines (above, below, left, right, and diagonal) neighbor that "safe" cell. Print the board, representing each mine as an asterisk (*).
   Your program should check for valid input.
   Some tips: * You may want to store your board as an integer array, with some constant value for the mines (e.g. 99), then convert the integer representation to a * for printing*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){

	int m;
	int n;
	printf("enter m(rows)\n");
	scanf("%d", &m);
	printf("enter n(colums)\n");
	scanf("%d", &n);
	char board[m] [n];
	int row=0;
	int col=0;	
	srand(time(NULL));
	int x;
	float p;
	printf("Enter a probablity\n");
	scanf("%f", &p);
	for (row=0;row<m;row++)
	{	
		for (col=0; col<n; col++)
		{
			board[row] [col]='x';
		}
	}
	for (x=0;x<p*m*n; x++)
	{
		row=rand()%10+1;
		col=rand()%10+1;
		board [row] [col]='*';
	}
	for (row=0;row<m;row++)
	{
		for (col=0;col<n;col++)
		{
			printf("%c\t", board[row] [col]);
			if(col==n-1)	
				printf("\n");
		}
	}
	printf("test");
	return 0;
}
