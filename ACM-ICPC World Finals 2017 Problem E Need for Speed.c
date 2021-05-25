#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include<math.h>
#include <stdbool.h>

int main()
{	

 int number=0;
 int time=0;
 long double leftside=-1000;
 long double rightside=2000;
 long double k=0.000000;
 long double deviation=0.000000;
 long double sum=0;
 long double de=2;

 scanf("%d %d", &number , &time );
  
  int array1[number];
  int array2[number];
  
  for (int i = 0; i < number; ++i)
  {

  	scanf("%d %d", &array1[i] , &array2[i] );
    
}
 int min=array2[0];
 for(int i = 0; i< number;++i){
 	if(array2[i]<min){
 		min=array2[i];
	 }
 	
 }
 
if(min<0){
	leftside=-1*min;
}

if(min>0){
	rightside=min;
}
 


 
while(de>0.000001){
sum=0;

k=(leftside+rightside)/2;

for (int i = 0; i < number; ++i)
  {
    deviation=array1[i]/(array2[i]+k); //odchylka/mid
    sum=deviation+sum;
  }
	 
if(sum>0) {
	if(sum < time){
	rightside=k;
}
if (sum > time)
{
	leftside=k;
}
	
}

if(sum<0){

	leftside=k;
}
de=sum-(time);
if(de<0)
{
	de=de*(-1);
}

}

printf("%Lf\n", k);	
	return 0;
}