#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void choice1(char man[], int manSize, char blanks[], int answerSize, char answer[]){
	char guess[answerSize];
	printf("\n%s", man);
	printf("\n%s", blanks);
	printf("\nEnter your guess: ");
	scanf("%s", &guess);
	for(int i = 0; i<strlen(guess); i++)
		guess[i]=tolower(guess[i]);
		if(strcmp(guess, answer)==0){
			printf("\nYOU WON!!!!!!!!\n");
		}	
		else{
			printf("\nSORRY YOU LOSE!\n");
			printf("The correct word was %s.\n", answer);
		}
}

int spotOfLetter(char answer[], int answerLength, char guess){
	for(int j=0;j<answerLength; j++)
		if(guess==answer[j])
			return j;
	return -1;
}/*returns spot in answer where letter is or -1 if letter is not in answer*/

int main(){
	char man[100] = {'*', '*', '*', '*', '*', '|', '\n', '|',' ', ' ', ' ', ' ', /*12*/'O', '\n', '|', ' ', ' ', ' ', /*18*/ '\\',/*19*/ '|',/*20*/ '/', '\n', '|', ' ', ' ' ,' ' ,/*26*/ '/', ' ',/*28*/ '\\'};
	/*creates man figure marks spots in array that are part of the man*/
	int locationInMan=0;
	int manCharSpots[] = {12, 18, 19, 20, 26, 28};/*locations of body parts*/
	printf("\n%s\n", man);
	printf("The goal of the game is to try to guess the word chosen\nby the computer.  You may choose to either guess a single letter \nat a time or guess the whole word.  However, BEWARE, if you choose\nto guess the whole word and guess wrong, you automatically lose.\nGOOD LUCK :)\n");
	/*gives directions*/

	char words[][100] = {"benchmark", "blacksmith", "background", "aftershock", "clipboard", "complain", "consumable", "decorate", "smart", "discourage"};
	/*creates array of possible answers*/
	srand(time(NULL));
	int r = rand();
	r = r%10;
	char answer[100];
	strcpy(answer,words[r]);/*puts the answer into 'answer'*/

	printf("\n%s", answer);/*for TESTING*/

	char blanks[100];
	int k; 
	for(k = 0; k<strlen(answer); k++)
		blanks[k]='_';
	blanks[k]='\0';
	/*creates string made of blanks*/
	
	while(1){
		int lOrW=2;
		char guess[100];
		printf("\nIf you would like to guess the whole word,");
		printf(" enter 1.\nIf you would like to only guess a ");
		printf("letter, enter 0.\n");
	
		scanf("%d", &lOrW);/*gets input for letter or word choice*/
		printf("\nchoice = %d", lOrW);
	
		while(lOrW!=0 && lOrW!=1){
			printf("\nInvalid option!\nEnter a valid choice: ");
			while(getchar()!='\n');/*clears input buffer*/
			scanf("%d", &lOrW);
		}
		if(lOrW==1){
			choice1(man, strlen(man), blanks, strlen(blanks), answer);
		/*takes care of whole word choice*/
		break;
		}
		if(lOrW==0){
			printf("\n\nYou chose to enter one letter!");
			printf("\n\n%s\n\n",man);/*prints man*/
			printf("\n\n%s\n\n", blanks);/*prints blanks*/
			while(getchar()!='\n');/*clears input buffer*/
			printf("\nEnter your guess: ");
			char l = getchar();
			int spot = spotOfLetter(answer, strlen(answer), l);
			if(spot<0){
				if(locationInMan>4){
					printf("\n\n%s\n\n", man);
					printf("\nSorry you lose!\n");
					printf("\nThe correct answer was %s\n", answer);
					break;
				}
				printf("\n\nSorry, you guessed wrong!\n");
				man[manCharSpots[locationInMan]]=' ';/*deletes character in man*/
				locationInMan++;
				printf("\n\n%s\n\n", man);
			}
			if(spot>=0){
				printf("\n\nYou guessed right!");
				blanks[spot]=answer[spot];
				printf("\n\n%s\n\n", blanks);
			}
			if(blanks[strlen(blanks)-1]!='_'){
				printf("\nCongratulations, you won!");
				printf("\nThe correct word was %s\n", answer);
				break;
			}
		}
	}
	return 0;
}
