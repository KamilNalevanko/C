#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hangman.h"
int main(){

	  char slovo[30];
	  srand(time(NULL));
        
	  get_word(slovo);
           hangman(slovo);  


    return 0;
 }
