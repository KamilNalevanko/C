#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "bmp.h"

char* reverse(const char* text){

 if(text==NULL){
  
  return NULL;
 }

char* text2 = (char *) calloc(strlen(text)+1,sizeof(char));

 int a=0;
 int b= strlen(text);
 a=b-1;

 for (int i = 0; i < strlen(text); i++)
 {  
 	text2[i]=toupper(text[a]);
 	a--;
 }
 text2[strlen(text2)]='\0';
 return text2;

}




char* vigenere_encrypt(const char* key, const char* text){
//  bez tohto 10 erorov
if(text == NULL || key == NULL)
{
 return NULL;
}  
char abeceda[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char text3[strlen(text)+1];
char text4[strlen(key)+1];
int g=0;
int m=0;

for (int i = 0; i < strlen(text); ++i)
{
     text3[i]=text[i];
     text3[i]=toupper(text3[i]);
     for (int j = 0; j < strlen(abeceda); ++j)
     {
       if (text3[i]==abeceda[j])
       {
         m++;
       }
     }
}
if(m == 0)
{
 return NULL;
} 

text3[strlen(text)]='\0';

for (int i = 0; i < strlen(key); ++i)
{
     text4[i]=key[i];
      if (text4[i]==' ')
       {
       	  return NULL;
       }

     text4[i]=toupper(text4[i]);
     for (int j = 0; j < strlen(abeceda); ++j)
     {
       if (text4[i]==abeceda[j])
       {
         g++;
       }
     }
}
 
text4[strlen(key)]='\0';


if(g == 0)
{
 return NULL;
} 

 char* encrypted = (char *) calloc(strlen(text)+1,sizeof(char));

 int j=0;
 char text2[strlen(text)+1];
 
 int x=0;
 int y=0;

  for (int i = 0; i < strlen(text); ++i)  //prepisanie si textu do text 2
  {
  	  text2[i]=text[i];
  	  text2[i]=toupper(text2[i]);
      x=text2[i];

     if(x<=90 && x>=65){
         y++;
      }
    }
  text2[strlen(text)]='\0';

//printf("pocet pismen %d\n", y);
//printf("text2 :  %s\n",text2 );

 // mnozenie keyu na dlzku textu ktory ideme sifrovat
 for (int i = 0; i < y; ++i)
 {
 	encrypted[i]=key[j];
 	encrypted[i]=toupper(encrypted[i]);
 	j++;
 	if(j==strlen(key)){
 		j=0;
 	}
 } 
// sifrovanie 

int ulozisko[y];
int a=0;
// zistenie pozicie pismen v abecede v key
  for (int i = 0; i < y; i++)
  {   
  	 for (int j = 0; j < strlen(abeceda); ++j)
  	 {  
  	 	a++;
   	 	if(encrypted[i]==abeceda[j]){       
  	 	ulozisko[i]=a-1;
  	 //	printf("pozicia je %d\n",ulozisko[i]);
  	 	a=0;
  	    }
  	 }
  	 a=0;
  }

 // vypisanie si pola intigerov 

// sifrovanie posun o intiger
char sifra[strlen(text2)];

for (int i = 0; i < strlen(text2); ++i)
{
	sifra[i]=text2[i];
}
 
int k=0;
int p=0;
int d=0;

for (int i = 0; i < strlen(text); ++i)
{   
	for (int j = 0; j < strlen(abeceda); ++j)
	{   
		if(text2[i]==abeceda[j]){
			k=ulozisko[p];
			p++;
            d=j+k;
            if (d>25)
            {
             d=d-26;
            }
			sifra[i]=abeceda[d];
		}
	}
}
// koniec sifrovania 
 sifra[strlen(text)]='\0';
 //printf("Šifra : %s\n", sifra);
 
  for (int i = 0; i < strlen(sifra); ++i)
 {
  encrypted[i]=sifra[i];
 }

 encrypted[strlen(text)]='\0';

return encrypted;

}

// rozkodovanie

char* vigenere_decrypt(const char* key, const char* text){
if(text == NULL || key == NULL)
{
 return NULL;
} 
char abeceda[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char text3[strlen(text)+1];
char text4[strlen(key)+1];
int g=0;
int m=0;

for (int i = 0; i < strlen(text); ++i)
{
     text3[i]=text[i];
     text3[i]=toupper(text3[i]);
     for (int j = 0; j < strlen(abeceda); ++j)
     {
       if (text3[i]==abeceda[j])
       {
         m++;
       }
     }
}


for (int i = 0; i < strlen(key); ++i)
{
     text4[i]=key[i];
       if (text4[i]==' ')
       {
       	  return NULL;
       }
     text4[i]=toupper(text4[i]);
     for (int j = 0; j < strlen(abeceda); ++j)
     {
       if (text4[i]==abeceda[j])
       {
         g++;
       }
     }
}
 

text4[strlen(key)]='\0';
text3[strlen(text)]='\0';


if(g == 0)
{
 return NULL;
} 
if(m == 0)
{
 return NULL;
} 


char* decrypted = (char *) calloc(strlen(text)+1,sizeof(char));

char text2[strlen(text)+1];

int x=0;
int y=0;


 for (int i = 0; i < strlen(text); ++i)  //prepisanie si textu do text 2
  {
      text2[i]=text[i];
      text2[i]=toupper(text2[i]);
      x=text2[i];

     if(x<=90 && x>=65){
         y++;
      }
    }
  text2[strlen(text)]='\0';
 
  //printf("pocet pismen decrypt :%d\n", y);
  //printf("text2  :  %s\n",text2 );

 // mnozenie keyu na dlzku textu ktory ideme sifrovat
int j=0;
 for (int i = 0; i < y; ++i)
 {
  decrypted[i]=key[j];
  decrypted[i]=toupper(decrypted[i]);
  j++;
  if(j==strlen(key)){
    j=0;
  }
 } 
  //printf("decrypted na dlzku slova %s\n",decrypted );

// sifrovanie 

int ulozisko[y];
int a=0;
// zistenie pozicie pismen v abecede v key
  for (int i = 0; i < y; i++)
  {   
     for (int j = 0; j < strlen(abeceda); ++j)
     {  
      a++;
      if(decrypted[i]==abeceda[j]){       
      ulozisko[i]=a-1;
    //  printf("pozicia je %d\n",ulozisko[i]);
      a=0;
        }
     }
     a=0;
  }
  //koniec vypoctu umiestnenia 

  // sifrovanie posun o intiger
char sifra[strlen(text2)];

for (int i = 0; i < strlen(text2); ++i)
{
  sifra[i]=text2[i];
}

   //printf("sirfa : %s\n", sifra);
int k=0;
int p=0;
int d=0;
//tu nastava problem !!!!  potadial to slape
for (int i = 0; i < strlen(text); ++i)
{   
  for (int j = 0; j < strlen(abeceda); ++j)
  {   
    if(text2[i]==abeceda[j]){
      k=ulozisko[p];
 //     printf("K= %d\n",k );
      p++;  
            d=j-k;
   //         printf("d = %d\n",d );
            if (d<0)
            {
             d=d+26;
            }
         //   printf("d = %d\n",d );
      sifra[i]=abeceda[d];
    }
  }
}
 //printf("sifra 2 %s\n", sifra);  
// koniec sifrovania 
 sifra[strlen(text)]='\0';
 // printf("SIFRA : %s\n",sifra );
for (int i = 0; i < strlen(sifra); ++i)
 {
  decrypted[i]=sifra[i];
  decrypted[i]=tolower(decrypted[i]);
 }

 decrypted[strlen(text)]='\0';


 return decrypted;

}

unsigned char* bit_encrypt(const char* text){

if(text==NULL){
  
  return NULL;
 }

unsigned char* byte =calloc(strlen(text)+1,sizeof(char));

int y=0;
for (int i = 0; i < strlen(text); ++i)
{
	byte[i]=text[i];
    y++;
}

int pole[y];

for (int i = 0; i < y; i++)
{
	 pole[i]=byte[i];
	 //printf(" %d ",pole[i]);
}
 printf("\n");

int prehodeniebitov(int cislo, int nPozicia, int mPozicia)
{
    int nHodnota = ( cislo >> nPozicia ) % 2;
    int mHodnota = ( cislo >> mPozicia ) % 2;

    if (nHodnota != mHodnota)
    {
        cislo += (-1)*(2*mHodnota-1)*(1<<mPozicia) + (-1)*(2*nHodnota-1)*(1<<nPozicia);
    }

    return cislo;
}

// SIFROVANIE 

for (int j=0;j < y; ++j)
{  
  /*
	for (int i = 7; 0 <= i; i--)
  {
   printf("%d",(pole[j] >> i) & 0x01);
  }
   printf("\n");
*/
	unsigned char byte2=prehodeniebitov(pole[j],6,7); // PREHODENIE 1 a 2 bitu 
	/*
	for (int y = 7; 0 <= y; y--)
    {
   printf("%d",(byte2 >> y) & 0x01);
    }

    printf("\n");
*/
    unsigned char pravastrana; 
                                // vysledny bin kod prehodene 3 4 a 1 2
    pravastrana=prehodeniebitov(byte2,4,5);

   // printf("PREHODENE BITY:        ");
/*
    for (int a = 7; 0 <= a; a--)
    {
   printf("  %d",(pravastrana >> a) & 0x01);
    }
    printf("\n"); // prehodenie 3 a 4 bitu 
*/
    unsigned char lavastrana;

    lavastrana=pravastrana;

    
    pravastrana=pravastrana<<4;   // posun do lava o 4 ziskanie 0 to co delim
    
/*
    printf("PRAVA STRANA POSUNUTA :");
    for (int b = 7; 0 <= b; b--)
    {
   printf("  %d",(pravastrana >> b) & 0x01);
    }

    printf("\n");
   */

    lavastrana=lavastrana>>4;  // to co budem xorom delit
    lavastrana=lavastrana<<4;   // robenie si nul toto cim delim v xor
     
     /*
    printf("LAVA STRANA POSUNUTA : ");
     for (int b = 7; 0 <= b; b--)
    {
   printf("  %d",(lavastrana >> b) & 0x01);
    }

    printf("\n");
  */

    unsigned char vysledok;
    vysledok = pravastrana ^ lavastrana ; // xor k lomeno l
    /*
    printf("Xor lava lomeno prava :");
    for (int b = 7; 0 <= b; b--)
    {
   printf("  %d",(vysledok >> b) & 0x01);
    }
    printf("\n");
    */
    vysledok= vysledok >> 4;  // posunutie vysledku o 4 do prava aby som mohol spojit 

    byte[j]= vysledok+lavastrana;

    /*
    printf("Vysledok:              ");
    for (int b = 7; 0 <= b; b--)
    {
    printf("  %d",(byte[j] >> b) & 0x01);
    }
    printf("\n");
    */
}
 
 byte[strlen(text)]='\0';
 return byte;

}

char* bit_decrypt(const unsigned char* text){
 
 if(text==NULL){
  
  return NULL;

 }

unsigned char* byte1 =calloc(strlen((char*)text)+1,sizeof(char));
char* byteD =calloc(strlen((char*)text)+1,sizeof(char)); 

int y=0;
for (int i = 0; i < strlen((char*)text) ; ++i)
{
  byte1[i]=text[i];
    y++;
}

int pole[y];

for (int i = 0; i < y; i++)
{
   pole[i]=byte1[i];
  // printf("%d ",pole[i]);
}

 int prehodeniebitov(int cislo, int nPozicia, int mPozicia)
{
    int nHodnota = ( cislo >> nPozicia ) % 2;
    int mHodnota = ( cislo >> mPozicia ) % 2;

    if (nHodnota != mHodnota)
    {
        cislo += (-1)*(2*mHodnota-1)*(1<<mPozicia) + (-1)*(2*nHodnota-1)*(1<<nPozicia);
    }

    return cislo;
}

for (int j=0;j < y; ++j)
{  
  /*  for (int i = 7; 0 <= i; i--)
  {
   printf("%d",(pole[j] >> i) & 0x01);
  }
   printf("\n");
   */
  unsigned char prava;
  unsigned char lava;

   prava=pole[j];
   lava=pole[j];
   
   lava=lava>>4;
   lava=lava<<4;
   prava=prava<<4;
   
 /*
   printf(" lava strana \n");
  for (int b = 7; 0 <= b; b--)
    {
   printf("  %d",(lava >> b) & 0x01);
    }

    printf("\n");
 printf("prava strana\n");
    for (int b = 7; 0 <= b; b--)
    {
   printf("  %d",(prava >> b) & 0x01);
    }

    printf("\n");
  */
   unsigned char vysledok;
   vysledok=lava^prava;
   vysledok=vysledok>>4;
   
/*
   printf("Vysledok\n");
    for (int b = 7; 0 <= b; b--)
    {
   printf("  %d",(vysledok >> b) & 0x01);
    }

     printf("\n");
   */
   unsigned char vysledok2;
   vysledok2=vysledok^lava;

      /* for (int b = 7; 0 <= b; b--)
    {
   printf("  %d",(vysledok2 >> b) & 0x01);
    }
    printf("\n");
    */
    vysledok2=prehodeniebitov(vysledok2,6,7);
    vysledok2=prehodeniebitov(vysledok2,4,5);
     /*
     for (int b = 7; 0 <= b; b--)
    {
   printf("  %d",(vysledok2 >> b) & 0x01);
    }
    printf("\n");
  */
  // printf("%c\n",vysledok2 );
   byteD[j]=vysledok2;
}  
   free(byte1);
   byteD[strlen((char*)text)]='\0';
   return byteD;
}


unsigned char* bmp_encrypt(const char* key, const char* text){
  

     char* text1;
     
     text1=reverse(text);
     
     if (text1 == NULL)
     {  
     	 return NULL;
     }
     
     char* text2;

     text2=vigenere_encrypt(key,text1);

     if (text2 == NULL)
     {   
     	 return NULL;
     }
     free(text1);

  unsigned char* bmp_encrypts;
  
  bmp_encrypts=bit_encrypt(text2);
  if (bmp_encrypts == NULL)
     {  
     	 return NULL;
     }

  
  free(text2);
  return bmp_encrypts;  
}

char* bmp_decrypt(const char* key, const unsigned char* text){
  
    char* text1; 
    
    text1=bit_decrypt(text);
    if (text1 == NULL)
    {
    	return NULL;
    }

    char* text2;

    text2=vigenere_decrypt(key,text1);
    free(text1);
    
    if (text2 == NULL)
    {
    	return NULL;
    }
     char* bmp_decrypts;
     bmp_decrypts=reverse(text2);
     if (bmp_decrypts == NULL)
    {   	
    	return NULL;
    }

     free(text2);
     return bmp_decrypts;
}