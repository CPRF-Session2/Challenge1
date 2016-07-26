/* Jared Wasserman -- hangman.c */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

int memberq(char guessedLetters[],int size,char character){
	int guessed=0;
	int x;
	for(x=0;x<size;x++){
		if(character==guessedLetters[x]){
			guessed=1;
			break;
		}
	}
	return guessed;
}

int correct(char word[],char guessedLetters[]){
		int k;
		int correct=0;
		for(k=0;k<strlen(word);k++){
			if(word[k]!=' '){
				if(!memberq(guessedLetters,26,word[k])){
					correct++;
				}
			}
		}
		if(correct>0){
			return 1;
		}else{
			return 0;
		}
}

int print(char word[],char guessedLetters[26],int numOfGuess,int incorrectGuesses){
	int i;
	printf("\n");
	for(i=0;i<strlen(word);i++){
		int guessed=0;
		int x;
		for(x=0;x<26;x++){
			if(word[i]==guessedLetters[x]){
				guessed=1;
				break;
			}
		}

		if(guessed){
			printf("%c",word[i]);
		}else if(word[i]==' '){
			printf(" ");
		}else{
			printf("_");
		}
	}
	printf("\n\n");
	printf("Guessed Leters: \n");
	for(i=0;i<numOfGuess;i++){
		printf("%c ",guessedLetters[i]);
	}
	printf("\n\n");
	switch(incorrectGuesses){
		case 0:
			printf("  +===+\n");
			printf("  |   |\n");
			printf("      |\n");
			printf("      |\n");
			printf("      |\n");
			printf("      |\n");
			printf("=======\n");
			break;

		case 1:
			printf("  +===+\n");
			printf("  |   |\n");
			printf("  O   |\n");
			printf("      |\n");
			printf("      |\n");
			printf("      |\n");
			printf("=======\n");
			break;

		case 2:
			printf("  +===+\n");
			printf("  |   |\n");
			printf("  O   |\n");
			printf("  |   |\n");
			printf("      |\n");
			printf("      |\n");
			printf("=======\n");
			break;

		case 3:
			printf("  +===+\n");
			printf("  |   |\n");
			printf("  O   |\n");
			printf(" /|   |\n");
			printf("      |\n");
			printf("      |\n");
			printf("=======\n");
			break;

		case 4:
			printf("  +===+\n");
			printf("  |   |\n");
			printf("  O   |\n");
			printf(" /|\\  |\n");
			printf("      |\n");
			printf("      |\n");
			printf("=======\n");
			break;

		case 5:
			printf("  +===+\n");
			printf("  |   |\n");
			printf("  O   |\n");
			printf(" /|\\  |\n");
			printf(" /    |\n");
			printf("      |\n");
			printf("=======\n");
			break;

		case 6:
			printf("  +===+\n");
			printf("  |   |\n");
			printf("  O   |\n");
			printf(" /|\\  |\n");
			printf(" / \\  |\n");
			printf("      |\n");
			printf("=======\n");
			break;

		case 7:
			printf("  +===+\n");
			printf("  |   |\n");
			printf("  O   |\n");
			printf(" /|\\  |\n");
			printf(" / \\  |\n");
			printf("      |\n");
			printf("=======\n");
			break;

	}
	return 0;
}

char input(char guessedLetters[26]){
	char wordOrLetter;
	while(1){
		printf("Would you like to guess a letter or a word?(l/w): ");
		wordOrLetter = getchar();
		if(isalpha(wordOrLetter)){
			if(wordOrLetter=='w'||wordOrLetter=='W'){
				break;
			}else if(wordOrLetter=='l'||wordOrLetter=='L'){
				break;
			}
		}
		printf("Invalid input. ");
		while(getchar()!='\n');
	}
	wordOrLetter=tolower(wordOrLetter);
	char c;
	if(wordOrLetter=='w'){
		return '#';
	}else{
		while(getchar()!='\n');
		while(1){
			printf("Enter you guess: ");
			c = getchar();
			if(isalpha(c)){
				if(memberq(guessedLetters,26,c)){
					printf("You already guessed that character. ");
					while(getchar()!='\n');
				}else{
					break;
				}
			}else{
				printf("Invalid input. ");
				while(getchar()!='\n');
			}
		}	
	}
	return c;	
}


int main(){

	char words[][20]={"sky","apple","friday","hello","hello world","hangman","bob","word","other","test"};
	int incorrectGuesses=0;
	char guessedLetters[26];
	int numOfGuess=0;
	srand(time(NULL));

	char word[20]="";
	strcat(word,words[(rand()%11)]);
	 
	printf("\nWelcome To Hangman!\n");
	printf("\nYou are trying to guess: \n");
	int i;
	for(i=0;i<strlen(word);i++){
		if(word[i]==' '){
				printf(" ");
			}else{
				printf("_");
		}
	}
	printf("\n\n");

	while(1){
		if(incorrectGuesses!=6&&correct(word,guessedLetters)){
			char userInput = input(guessedLetters);
			char wordGuess[100];

			if(userInput=='#'){
				printf("Please enter your guess for the word: ");
				while(getchar()!='\n');
				fgets(wordGuess,sizeof(wordGuess),stdin);
				wordGuess[strlen(wordGuess)-1]='\0';
				int j;
				for(j=0;j<=strlen(wordGuess);j++){
					wordGuess[j] = tolower(wordGuess[j]); 
				}
				if(strcmp(wordGuess,word)==0){
					printf("\nCongrats! You guessed the word correctly!\n\n");
					break;
				}else{
					printf("\nSorry! You lose. You guessed %s. The word was %s.\n\n",wordGuess,word);
					break;
				}
			}else{
				if(memberq(word,(sizeof(word)/sizeof(word[0])),tolower(userInput))){
				}else{
					incorrectGuesses++;
				}
				guessedLetters[numOfGuess]=tolower(userInput);
				numOfGuess++;
				print(word,guessedLetters,numOfGuess,incorrectGuesses);
			}
			while(getchar()!='\n');
			printf("\n");
		}else if(incorrectGuesses==6){
			printf("Sorry! You lose. You guessed ran out of guesses. The word was %s.\n\n",word);
			break;
		}else{
			printf("Congrats! You guessed the word correctly!\n\n");
			break;
		}
	}

return 0;
}
