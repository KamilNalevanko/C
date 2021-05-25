#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include<math.h>
#define M_PI 3.14159265358979323846
int main()
{
	int diera=0;
	int platky=0;

 scanf("%d %d",&diera,&platky);	

 
 int dlzka=diera*4;
 long double Rpolomer[diera];
 long double polohaGule[diera];
 long double vsetkyhodnoty[dlzka];
 int a=0;
 int b=3;
for (int i = 0; i < dlzka; ++i)
{   

	scanf("%Lf",&vsetkyhodnoty[i]);
   
}

 for (int i = 0; i < diera; ++i) 
 {
 	Rpolomer[i]=vsetkyhodnoty[a]/1000;
    a=a+4;
  }
  a=0;

   for (int i = 0; i < diera; ++i)
 {
 	polohaGule[i]=vsetkyhodnoty[b]/1000;
    b=b+4;
  }
  b=0;


double p=3;
double l=4;
long double objemsyra=1000000; //cm 3
long double objemG[diera];
long double sucet=0;

for (int i = 0; i < diera; ++i)
{
	objemG[i]= ((l/p)*M_PI)*powl(Rpolomer[i],3);
    sucet=sucet+objemG[i];
}

objemsyra=objemsyra-sucet;
long double jedenplatok=0;
int c = platky;
long double rezy[c];
long double strana=0;
long double dolnyrez=0;
int v=0;
 //printf("jeden slice :  %Lf \n",jedenplatok);
 
for (int i = 0; i < platky; ++i)
{
  
 v++;

 //double long kuzelnyplatok=0;
 jedenplatok=objemsyra/platky;
 jedenplatok=jedenplatok*v;


 
 long double lavyokraj=0;
 long double pravyokraj=100;
 long double o=1;
 long double sum=0;

//int n=0;
while(o>0 && o>0.000001){

sum=0;
strana=(lavyokraj+pravyokraj)/2;


long double h=0;
long double u=0;
long double objemstrany=0;
objemstrany=strana*100*100;
sum=objemstrany;
//printf("Objem strany %Lf\n", objemstrany);
//printf("dolnyrez : %Lf \n",dolnyrez );
//printf("strana %Lf\n", strana);
for (int j = 0; j < diera; ++j)
{  
	
   if (strana > polohaGule[j]+Rpolomer[j] && dolnyrez < polohaGule[j]-Rpolomer[j])
   {
   	 sum=sum-objemG[j];  //gula je v platičku
   	
   }
   if (strana > polohaGule[j]+Rpolomer[j] && dolnyrez > polohaGule[j]-Rpolomer[j] && dolnyrez < polohaGule[j]+Rpolomer[j] )
   {
   	   h=(polohaGule[j]+Rpolomer[j])-dolnyrez;   //horny vrchlik
   	   h=((M_PI*powl(h,2))/3)*((3*Rpolomer[j])-h);
   	   sum=sum-h;
	//    printf("Horny vrchlik %Lf \n",h);
   	    h=0;
   } 
   if (strana < polohaGule[j]+Rpolomer[j] && dolnyrez < polohaGule[j]-Rpolomer[j] && strana > polohaGule[j]-Rpolomer[j])  
   {    
   	   h=(Rpolomer[j]+polohaGule[j])-strana;
   	   h=(2*Rpolomer[j])-h;   //dolny vrchlik
   	   h=((M_PI*powl(h,2))/3)*((3*Rpolomer[j])-h);
   	   sum=sum-h;
   	//   printf("Dolny Vrchlik %Lf \n",h);
   	    h=0;
   }
   
if (strana < polohaGule[j]+Rpolomer[j] && strana > polohaGule[j]-Rpolomer[j] && dolnyrez > polohaGule[j]-Rpolomer[j] && dolnyrez < polohaGule[j]+Rpolomer[j] && strana > dolnyrez)  // ZLEE
{
	  h=(Rpolomer[j]+polohaGule[j])-strana;  
    h=((M_PI*powl(h,2))/3)*((3*Rpolomer[j])-h);
    u=(polohaGule[j]+Rpolomer[j]-dolnyrez);
    u=((M_PI*powl(u,2))/3)*((3*Rpolomer[j])-u);
    h=u-h;
    sum=sum-h;
    h=0;
    u=0;
  
} // ukoncenie foru
}
//printf("sum = %Lf\n",sum );
    if (sum>0)
    { 
          if (sum<jedenplatok)
           {
              lavyokraj=strana;
           }
               if (sum>jedenplatok)
               {
                   pravyokraj=strana;
                }
   }
     if (sucet<0)
 {
            if (sum<jedenplatok)
         {
               lavyokraj=strana;
         }
 }


//printf("lavyokraj :  %Lf pravyokraj :  %Lf \n",lavyokraj, pravyokraj );
  
//printf("objem po odratani %Lf\n",sum );
 o=sum-(jedenplatok);
 if (o<0)
 {
 	o=o*(-1);
 }// ukoncenie while
}
rezy[i]=strana;

} 



for (int i = 0; i < platky; ++i)
{  

  long double premenna=0;
  long double vypocit=0;
   if (i==0)
    {
      premenna=0;
   } else{premenna=rezy[i-1];}
   //printf(" %Lf",premenna );
   vypocit=rezy[i]-premenna;
   printf("%Lf\n",vypocit);
}

	return 0;
}

