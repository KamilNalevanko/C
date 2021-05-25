#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"playfair.h"

char* playfair_encrypt(const char* key, const char* text){	 
	// zaciatok upravy keyu

if(key == NULL)
{
return NULL;
}

char* encrypted = (char *) calloc(strlen(text)+1,sizeof(char));

	int z=0;
	char abeceda[strlen(ALPHA)+1];
	char upravenyKluc[strlen(key)+1];
	char novyKluc[20];

	for(int i=0;i<strlen(ALPHA);i++){
		abeceda[i]=ALPHA[i];
	}

	abeceda[strlen(ALPHA)] = '\0';
//	printf("Abeceda je : %s \n",abeceda);

	for(int i=0;i<strlen(key);i++){         //prepisanie key
		upravenyKluc[i]=key[i];
	}
        
	int tmp=0;

	for(int i=0;i<strlen(key);i++){      // pretypovanie na velke pismena
	        if(key[i]!=' '){
		upravenyKluc[tmp]=toupper(upravenyKluc[i]);
		tmp++;
		} 	
	}
         
	upravenyKluc[strlen(upravenyKluc)] = '\0';
	printf("VELKE PISMENA : %s \n",upravenyKluc);

	int pismeno=0;

	for(int i=0;i<strlen(upravenyKluc);i++){
		if(upravenyKluc[i]=='W'){
		   upravenyKluc[i]='V';                  //prepisanie W na V
		}
		for(int y=0;y<strlen(abeceda);y++){
			if(upravenyKluc[i]==abeceda[y]){	
				novyKluc[z]=abeceda[y];
				z++;
				pismeno++;
				abeceda[y]=' ';    
			}	
		}
	}
	// vypisovanie abecedy bez medzier
    char abeceda2[25-pismeno];
	int poradie=0;
;
	  for(int i=0;i<25;i++){
                   while(abeceda[poradie]==' '){
		      poradie++;
		   }	
	           abeceda2[i]=abeceda[poradie];
		   poradie++;
         	  
 	}
//konec vypisovania abecedy bez medzer
//pridanie slova k abecede aby sa vsetko mohlo vypisat do matice

	char abeceda3[25];
	int c=0;

        for(int i=0;i<25;i++){
           if(i<pismeno){
           abeceda3[i]=novyKluc[i];
	   }
	   else{
	    abeceda3[i]=abeceda2[c];
	    c++;	    
	   }
	}	

	// koniec toho toto ide do matice 
	abeceda3[strlen(abeceda3)]='\0';	
	abeceda2[strlen(abeceda2)]='\0';
	novyKluc[strlen(novyKluc)]='\0';
//	printf("pocet pismen : %d \n", pismeno);
//	printf("Novy kluc : %s \n", novyKluc);
	
//	printf("Abeceda je : %s \n \n",abeceda); // abeceda s medzerami
//	printf("Abeceda bez mezer: %s \n",abeceda2);//abeceda bez medzier	
//	printf("To co ide do matice: %s \n \n" , abeceda3);//to co ide do matice
	// koniec upravy keyu

	// MATICA
	char matica[5][5];
	int i=0;
	for(int x=0;x<5;x++){

		for(int y=0;y<5;y++){

			matica[x][y]=abeceda3[i];
			i++;      
			printf("%c",matica[x][y]); 

		}
		printf("\n");
	}
  
////////////////////////////////////////////////
  
        
  char upravenyText[strlen(text)+1];
 
for(int i=0;i<strlen(text);i++){         //prepisanie key
		upravenyText[i]=text[i];
	}


  int m=0; //medzera

  for (int i = 0; i < strlen(text); ++i)
  {

  	for (int j = 0; j < strlen(abeceda); ++j)
  	{   
        
  		if (text[i]==abeceda[j])
  		{   
  			upravenyText[i]=abeceda[j];
  		}
  		if (text[i]!=abeceda[j])
  		{
  			if (text[i]==' ')
  			{
  				upravenyText[i]=' ';
  				m++;
  			}
  			if (text[i]=='W')
  			{
  				upravenyText[i]='V';
  			}
  		}
  	}
  }
   

   int m2=0;

   upravenyText[strlen(text)]='\0';
   printf("%s\n",upravenyText );

   for (int i = 0; i < strlen(text); ++i)
   {  
   	  if (upravenyText[i]==' ')
   	  {
   	  	m2++;
   	  }
   	  upravenyText[i]=toupper(upravenyText[i]);
   }

  printf("%d\n",m2 );

  printf("%s\n",upravenyText );


   int d=0;

   char upravenyText2[strlen(text-m)];

  for (int i = 0; i < strlen(text); ++i)
  {  

  	 while(upravenyText[i]==' '){
         i++;
  	 }

     	 upravenyText2[d]=upravenyText[i];
         d++;
  }


   upravenyText2[d]='\0';
   printf("%s\n",upravenyText2 );
// text spojeny kontrola ci nesu 2 rovnake pismena
  //int dvojice=0;

  char text_upraveny[strlen(text)*2];
  



  for (int i = 0; i < strlen(upravenyText2); ++i)
  {
  	 text_upraveny[i]=upravenyText2[i];

  	 printf("%c",text_upraveny[i] );
  }
 
  char pismenko;
  int a=0;
  int g=0;

  for (int i = 0; i < strlen(upravenyText2); ++i)
  {     
        
        text_upraveny[a]=upravenyText2[i];
        pismenko=upravenyText2[i];
      if(pismenko==upravenyText2[i+1] && g%2==0 && upravenyText2[i+1]!='X'){
         
         text_upraveny[a+1]='X';     
         a++;
      }
        a++;
        g++;
  }

  int u=0;
  printf("a = %d\n",a );
  if (a%2!=0)
  {
   text_upraveny[a]='X'; 
   u=a+1;

  }
    
 

  text_upraveny[u]='\0';
  printf(" \n%s\n",text_upraveny );
  abeceda[strlen(ALPHA)] = '\0';
  
  char pole[2];
  int posun=0;
  
 for (int i = 0; i < u ; ++i)
 {    
  	  pole[posun]=text_upraveny[i];
  	  printf("1-%c", pole[i]);
  	  pole[posun+1]=text_upraveny[i+1];
      printf(" 2-%c", pole[i+1]);
   for (int i = 0; i < 5; ++i)
  {
  	 for (int j = 0; j < 5; ++j)
  	 {
  	 	if (pole[posun]==matica[i][j])
  	 	    printf(" Prve :%c\n",matica[i][j] );
  	 	  
  	 	if (pole[posun+1]==matica[i][j])
  	 	    printf(" Druhe :%c\n",matica[i][j] );
  	 	   
  	 	}
  	 }

 	if (posun==2)
 	{
 		posun=0;
 	}
  	 posun++;
  
  
         i++;
   } 



 
  return encrypted;

}
