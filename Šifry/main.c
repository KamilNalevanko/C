#include <stdio.h>
#include<stdlib.h>
#include "bmp.h"
#include "playfair.h"

int main(){

	char *encrypted; //, *decrypted;

    // even length of string
    encrypted = playfair_encrypt("SeCReT", "Hello World");
    printf("%s", encrypted);
    // "Hello world" --> "HELXLOVORLDX"
    // IS JZ JQ XN TK JC
    free(encrypted);
   /*
    char* reversed = reverse("HEllo World!");
    printf("%s\n", reversed);
    free(reversed);
    
    // basic test with long text
    encrypted = vigenere_encrypt("computer","Hello world!");
    printf(" %s \n", encrypted);
    // "JSXAI PSINR!"
    decrypted = vigenere_decrypt("computer",encrypted);
    printf(" %s \n", decrypted);
    // HELXLOVORLDX
    free(encrypted);
    free(decrypted);

 unsigned char* byte;
    
    // basic test with long text
    byte = bit_encrypt("Hello world!");
    printf("\n");
    for(int i=0; i < 12;i++) {
        printf("%x ", byte[i]);
        //80 9c 95 95 96 11 bc 96 b9 95 9d 10
    }
   
    char* byteD;
    printf("\n");
    byteD = bit_decrypt(byte);
    for (int i = 0; i < 12; ++i)
    {
        printf("%c",byteD[i]);  
    }
     printf("\n");
   
    free(byte);
    free(byteD);
    
    printf("\n");

       unsigned char* bmp_encrypts;
       bmp_encrypts=bmp_encrypt("computer","Hello World!");
      
          for(int i=0; i < 12;i++) {
          printf("%x ",  bmp_encrypts[i]);
        
       }
      printf("\n");


       char* bmp_decrypts;
       bmp_decrypts=bmp_decrypt("computer",bmp_encrypts);
     
       for(int i=0; i < 12;i++) {
        printf("%c",  bmp_decrypts[i]);
        
      }
      printf("\n");

    free(bmp_encrypts);
    free(bmp_decrypts);
   */
        return 0;
}

