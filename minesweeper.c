/* Jared Wasserman -- minesweeper.c */
/*This program takes the dimensions of a grid from the user and a probalility for a mine to be in any given square. Then in returns the board for the end of the game.*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
	srand(time(NULL));	
	int m;
	int n;
	float p;
	
	/*Getting And Checking Input*/
	int returnValue;
	do{
		printf("Enter m dimension: ");
		returnValue = scanf("%d",&m);
		if(returnValue==0){
			printf("Invalid Input. ");
			while(getchar()!='\n');
		}
	}while(returnValue==0);
	while(getchar()!='\n');
	do{
		printf("Enter n dimension: ");
		returnValue = scanf("%d",&n);
		if(returnValue==0){
			printf("Invalid Input. ");
			while(getchar()!='\n');
		}
	}while(returnValue==0);
	while(getchar()!='\n');
	do{
		printf("Enter probalility (between 0 & 1): ");
		returnValue = scanf("%f",&p);
		if(returnValue==0||p<=0||p>=1){
			printf("Invalid Input. ");
			while(getchar()!='\n');
		}
	}while(returnValue==0||p<=0||p>=1);
	
	int p2=(100*p);
	int arr[m][n];
	int x;
	int y;
	
	/*Placing The Mines*/
	for(x=0;x<m;x++){
		for(y=0;y<n;y++){
			if((rand()%101)<=p2){
				arr[x][y]=-1;
			}else{
				arr[x][y]=0;
			}
		}
	}
	
	/*Counting The Number Of Mines*/
	for(x=0;x<m;x++){
		for(y=0;y<n;y++){
			if(arr[x][y]!=-1){
				int count=0;
				int sur[8][2]={{x,y-1},{x,y+1},{x+1,y-1},{x+1,y},{x+1,y+1},{x-1,y-1},{x-1,y},{x-1,y+1}};
				int a;
				for(a=0;a<8;a++){
					if(sur[a][0]<0||sur[a][0]>(m-1)||sur[a][1]<0||sur[a][1]>(n-1)){
						/*Out of bounds*/
					}else{
						if(arr[sur[a][0]][sur[a][1]]==-1){
							count++;
						}
					}
				}
				arr[x][y]=count;
			}
		}
	}
	
	/*Printing The Board*/
	for(x=0;x<m;x++){
		for(y=0;y<n;y++){
			if(arr[x][y]==-1){
				printf(" *");
			}else{
				printf(" %d",arr[x][y]);
			}
		}
		printf("\n");
	}

return 0;
}
