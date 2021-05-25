#include <Arduino.h>
#include "lcd_wrapper.h"
#include "mastermind.h"
#include <stdlib.h>
#include <string.h>
#include <LiquidCrystal.h>
#define oneskorenie 50


char* generate_code(bool repeat, int length){
    if (length<1 || length>10)
    {
        return NULL;
    }

    char* code=(char*)calloc(length,sizeof(char));
    
    if (repeat == true)
    {   char number='0';
        char randomnumber;
        for (int i = 0; i < length; ++i)
        {
            
            randomnumber = number + random(10);
            code[i]=randomnumber;
        }
        code[length]='\0';
    }
    else{
        
        char number='0';
        char randomnumber;
        int news=0;
        int old=0;
        int same=0;
        for (int i = 0; i < length; ++i)
        {

            randomnumber = number + random(10); 
            if (i<1)
            {
            	code[i]=randomnumber;
            }
            if (i>0)
            {  
            	news=randomnumber-48;
            	
               for (int y = 0; y < i; ++y)
               {  
               	   old=code[y]-48;
               	   if (old==news)
            	{
            	
            		same++;
            	}
               }

               if (same!=0)
               {  
               	  i--;
               }
               else
               {
               	 code[i]=randomnumber;
               }
               same=0;
            }
        }
        code[length]='\0';
    }
 return code;

}


void get_score(const char* secret, const char* guess, int* peg_a, int* peg_b){

  int b=0;
  int a=0;


  for (int i = 0; i < strlen(secret) ; ++i)
  {
    printf("%d\n",secret[i]-48);

      for (int y = 0; y < strlen(guess); ++y)
      {
        
         if (secret[i]==guess[y])
         {
          if(y!=i){
              b++;
          } 
         }
        

      
         if (secret[i]==guess[y])
         { 
          if(i==y){
              a++; 
          }
         }
      }
  }
*peg_a=a;
*peg_b=b;

}


void turn_off_leds(){

digitalWrite(6,LOW);
digitalWrite(7,LOW);
digitalWrite(8,LOW);
digitalWrite(9,LOW);
digitalWrite(10,LOW);
digitalWrite(11,LOW);
digitalWrite(12,LOW);
digitalWrite(13,LOW);
}


void render_leds(const int peg_a, const int peg_b){
int a=7;
int b=6;

if (peg_a!=0)
{
  for (int i = 0; i < peg_a; ++i)
  {
      digitalWrite(a,HIGH);
      a=a+2;
  }
 }

if (peg_b!=0)
{
  for (int i = 0; i < peg_b; ++i)
  {
      digitalWrite(b,HIGH);
      b=b+2;
  }
}
 
}


void play_game(char* secret){

int length=0;
int i=-1;
int y=-1;
int z=-1;
int u=-1;
int pokusy=0;

bool ENTER=0;
bool MinulyStav1=1;
bool MinulyStav2=1;
bool MinulyStav3=1;
bool MinulyStav4=1;
bool MinulyStav5=1;
unsigned long CasZmeny1;
unsigned long CasZmeny2;
unsigned long CasZmeny3;
unsigned long CasZmeny4;
unsigned long CasZmeny5;
turn_off_leds();

length=strlen(secret);

  lcd_print_at(0, 0,"Mastermind!");
  delay(3000);
  lcd_print_at(0, 0, "Guess password");
  delay(2000);
  Serial.println(secret);

while(pokusy<9){
  
  
ENTER=0;
while(ENTER==0){
 //tlacitko 1
  if(digitalRead(BTN_1_PIN)==0){

    if(MinulyStav1==1 && millis() - CasZmeny1 > oneskorenie){
        i++;
       if(i>9){
          i=0;
        }
       char ii[2];
  ii[0]= '0' + i;
  ii[1]='\0';
  lcd_print_at(1, 0, ii);
  
       Serial.println(i);
       MinulyStav1=0;
  }
  }
  else
  {
    CasZmeny1 = millis();
    MinulyStav1=1;
    }
    
// Tlacitko 2
 if(digitalRead(BTN_2_PIN)==0){

    if(MinulyStav3==1 && millis() - CasZmeny3 > oneskorenie){
        y++;
       if(y>9){
          y=0;
        }
         char yy[2];
  yy[0]= '0' + y;
  yy[1]='\0';
  lcd_print_at(1, 0, yy);
       Serial.println(y);
       MinulyStav3=0;
  }
  }
  else
  {
    CasZmeny3 = millis();
    MinulyStav3=1;
    }

    // tlacitko 3
    if(digitalRead(BTN_3_PIN)==0){

    if(MinulyStav4==1 && millis() - CasZmeny4 > oneskorenie){
        z++;
       if(z>9){
          z=0;
        }
         char zz[2];
  zz[0]= '0' + z;
  zz[1]='\0';
  lcd_print_at(1, 0, zz);
       Serial.println(z);
       MinulyStav4=0;
  }
  }
  else
  {
    CasZmeny4 = millis();
    MinulyStav4=1;
    }

    // tlacitko 4
    if(digitalRead(BTN_4_PIN)==0){

    if(MinulyStav5==1 && millis() - CasZmeny5 > oneskorenie){
        u++;
       if(u>9){
          u=0;
        }
        
    char uu[2];
  uu[0]= '0' + u;
  uu[1]='\0';
  lcd_print_at(1, 0, uu);
       Serial.println(u);
       MinulyStav5=0;
  }
  }
  else
  {
    CasZmeny5 = millis();
    MinulyStav5=1;
    }
 // Tlacitko na vypinanie
   if(digitalRead(BTN_ENTER_PIN)==0){

    if(MinulyStav2==1 && millis() - CasZmeny2 > oneskorenie){
       
       MinulyStav2=0;
   
   } 
  }
  else
  {
    CasZmeny2 = millis();
    MinulyStav2=1;
    turn_off_leds();
    ENTER=1;
    } 
} 

//TU SOM POTVRDIL KOD CO HADAM
char* guess = (char*)calloc(strlen(secret),sizeof(char));
char number='0';
char randomnumber;
       
            
            randomnumber = number + i;
            guess[0]=randomnumber;

             randomnumber = number + y;
            guess[1]=randomnumber;

             randomnumber = number + z;
            guess[2]=randomnumber;

             randomnumber = number + u;
            guess[3]=randomnumber;
guess[strlen(secret)]='\0';    

   int peg_a;
   int peg_b;
    

get_score(secret,guess, &peg_a, &peg_b);

render_leds(peg_a,peg_b);
delay(1000);

//turn_off_leds();
 
 
if (peg_a==4)
{ 
  
  lcd_clear();
  lcd_print_at(0, 0,"VYHRAL SI !              ");
  digitalWrite(6,HIGH);
digitalWrite(7,HIGH);
digitalWrite(8,HIGH);
digitalWrite(9,HIGH);
digitalWrite(10,HIGH);
digitalWrite(11,HIGH);
digitalWrite(12,HIGH);
digitalWrite(13,HIGH);
  delay(5000);
  pokusy=+10;
  turn_off_leds();
  peg_a=0;
  peg_b=0;
} else{
  
 
  delay(2000);
  Serial.println(i);
  pokusy++;
  char peg_aa[3];
  peg_aa[0]= '0' + peg_a;
  peg_aa[1]='\0';
  char cisielko[3];
  cisielko[0]= '0' + pokusy;
  cisielko[1]='\0';
    char peg_bb[3];
  peg_bb[0]= '0' + peg_b;
  peg_bb[1]='\0';
  lcd_clear();
  lcd_print_at(0, 0, "Cislo dobre");
  lcd_print_at(1, 0, peg_bb);
  delay(2000);
  lcd_clear();
  lcd_print_at(0, 0, "Pozicie dobre");
   lcd_print_at(1, 0, peg_aa);
  delay(2000);
  lcd_clear();
  lcd_print_at(0, 0," Neuhadol             ");
  delay(2000);
   lcd_clear();
   turn_off_leds();
  lcd_print_at(0, 0,"pokus cislo :              ");
  lcd_print_at(1,0,cisielko);
  delay(2000);
  lcd_print_at(0, 0,"Guess password             ");
   i=0; 
   y=0;
   z=0;
   u=0;
} 
}
lcd_clear();
lcd_print_at(0, 0, "KONIEC !!             ");
turn_off_leds();
delay(5000);


}
