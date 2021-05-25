#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "hangman.h"
#include <string.h>
#include<ctype.h>
int overenie(const char secret[],char pismeno );
void hangman(const char secret[]);
void get_guessed_word(const char secret[], const char letters_guessed[], char guessed_word[]);
int is_word_guessed(const char secret[], const char letters_guessed[]);
int get_word(char secret[]){
	// check if file exists first and is readable
	FILE *fp = fopen(WORDLIST_FILENAME, "rb");
	if( fp == NULL ){
		fprintf(stderr, "No such file or directory: %s\n", WORDLIST_FILENAME);
		return 1;
	}

	// get the filesize first
	struct stat st;
	stat(WORDLIST_FILENAME, &st);
	long int size = st.st_size;

	do{
		// generate random number between 0 and filesize
		long int random = (rand() % size) + 1;
		// seek to the random position of file
		fseek(fp, random, SEEK_SET);
		// get next word in row ;)
		int result = fscanf(fp, "%*s %20s", secret);
		if( result != EOF )
			break;
	}while(1);

	fclose(fp);


	return 0;
}

int is_word_guessed(const char secret[], const char letters_guessed[]){

	int velkost=strlen(secret);
	int velkost2=strlen(letters_guessed);
	int zhoda=0;

	for(int i=0;i<velkost2;i++){

		for(int a=0;a<velkost;a++){
			if(letters_guessed[i]==secret[a]){
				zhoda=zhoda+1;  
			}     
		}
	}
	if(zhoda>=velkost){ 
		return 1;
	}

	return 0;
} 

void get_guessed_word(const char secret[], const char letters_guessed[], char guessed_word[]){

	int velkost=strlen(secret);
	int velkost2=strlen(letters_guessed);

	for(int i=0;i<velkost;i++){

		guessed_word[i]='0';
	}

	for(int i=0;i<velkost;i++){

		for(int a=0;a<velkost2;a++){
			if(letters_guessed[a]==secret[i]){
				guessed_word[i] = secret[i];

			} 
			else if( guessed_word[i]=='0'){

				guessed_word[i] =  '_';

			}
		}
	}
	if(velkost2==0){
	for(int i=0;i<velkost;i++){

		guessed_word[i]='_';
	}


	}

	guessed_word[velkost]='\0'; 
}


void get_available_letters(const char letters_guessed[], char available_letters[]){
	char abeceda[]="abcdefghijklmnopqrstuvwxyz";
	int velkost2=strlen(letters_guessed);
	int velkost=strlen(abeceda);

	for(int i=0;i<velkost2;i++){

		for(int a=0;a<velkost;a++){   
			if(letters_guessed[i]==abeceda[a]){
				abeceda[a]='0';
			}  

		}

	}
	int poradie=0;

	for(int i=0;i<velkost;i++){
		if(abeceda[i]!='0'){
			available_letters[poradie]=abeceda[i];
			poradie++;
		}


	}

	available_letters[poradie]='\0';
}

void hangman(const char secret[]){
	int velkost=strlen(secret);
	int pokusy=8;
	char letters_guessed[50];
	char available_letters[50];
	char pokus[50];
	char vysledok[50];

	printf("Welcome to the game, Hangman!\n");
	printf("I am thinking of a word that is %d letters long.\n",velkost);

	while(pokusy!=0){
		printf("-------------\n");
		printf("You have %d guesses left.\n",pokusy);
		get_available_letters(letters_guessed,available_letters);
		printf("Available letters: %s\n",available_letters); 
		printf("Please guess a letter: ");
		scanf("%s",pokus);

                 for(int i=0;i<strlen(pokus);i++){
		    pokus[i]=tolower(pokus[i]);
		 }

		if(strlen(pokus)>1){
		    
		      if(strcmp(pokus,secret)==0){
				  printf("Congratulations, you won!\n");
			  break;
		      }
		      else if(strcmp(pokus,secret)!=0){
		         printf("Sorry, bad guess. The word was %s.\n",secret);
			 break;
		     
		      }
		
		}   

		if(overenie("abcdefghijklmnopqrstuvwxyz",pokus[0])==0){
			
			printf("Oops! '%c' is not a valid letter:",pokus[0]);
		        for(int i=0;i<strlen(vysledok);i++){

				printf(" %c",vysledok[i]);

			}
			printf("\n");
		        continue;

		}

			if(overenie(letters_guessed,pokus[0])==1){
                       printf("Oops! You've already guessed that letter:");
         

		       get_guessed_word(secret,letters_guessed,vysledok);
    
		       for(int i=0;i<strlen(vysledok);i++){

				printf(" %c",vysledok[i]);

			}
			printf("\n");
		
		}else{

              	letters_guessed[strlen(letters_guessed)]=pokus[0];

		get_guessed_word(secret,letters_guessed,vysledok);

		if(overenie(secret,pokus[0])==1){
			printf("Good guess:");

			for(int i=0;i<strlen(vysledok);i++){

				printf(" %c",vysledok[i]);

			}
			printf("\n");

		}

		else{
			printf("Oops! That letter is not in my word:");

			for(int i=0;i<strlen(vysledok);i++){

				printf(" %c",vysledok[i]);

			}
			printf("\n");
			pokusy=pokusy-1;
		}


            }
          if(is_word_guessed(secret,letters_guessed)==1){
	    printf("-------------\n");

	   printf("Congratulations, you won!\n");
	    break;
	  }
	  
          
	}
	if(pokusy==0){
	printf("-------------\n");

	printf("Sorry, you ran out of guesses. The word was %s.\n",secret);
		
      }
}


int overenie(const char secret[],char pismeno ){

	for(int i=0;i<strlen(secret);i++){
		if(secret[i]==pismeno){
			return 1;
		}
	}
	return 0;	
}
