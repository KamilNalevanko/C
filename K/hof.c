#include <stdlib.h>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include "hof.h"
#include <stdbool.h>

int load(struct player list[]){
int number=-1;
char name[30];
int  score=0;

FILE *input = fopen(HOF_FILE, "r");

if (input==NULL)
{   
	return number;
} 

int a=0;

while(fscanf(input, "%s %d", name,&score) != EOF){
if (a<10)
{
strcpy(list[a].name,name);
list[a].score=score;
number++;
}
a++;
}


int score2;
int swap=0;
while(swap!=1){
int swap1=0;
for (int i = 0; i < number; ++i)
{
	if (list[i].score<list[i+1].score)
	{
		score2=list[i].score;
		list[i].score=list[i+1].score;
		list[i+1].score=score2;
        strcpy(name,list[i].name);
		strcpy(list[i].name,list[i+1].name);
		strcpy(list[i+1].name,name);
		swap1=1;
	}
}
if (swap1==0)
{
 swap=1;
}
}
number=number+1;

fclose(input);
if (score==0)
{   
	return 0;
} 
return number;
}


bool save(const struct player list[], const int size){

bool index=false;

FILE *input = fopen(HOF_FILE,"w");
if (input==NULL)
{   
	return index;
} 
for (int i = 0; i < size; ++i)
{

fprintf(input, "%s %d \n",list[i].name ,list[i].score);
index=true;

}
if (size==0)
{
	index=true;
}

fclose(input);

 return index;

}

bool add_player(struct player list[], int* size, const struct player player){

bool succesfull=false;
int size2=*size;
int position=0;

struct player list1[11];
for (int i = 0; i < size2; ++i)
{   	if (player.score<list[i].score)
	{
		position=i+1;
	}
	if (player.score==list[i].score)
	{
		position=i;
	}
}

list1[position].score=player.score;
strcpy(list1[position].name,player.name);

int a=0;

if (player.score!=0 && size2!=10)
{
	*size=*size+1;
	size2=size2+1;
}

for (int i = 0; i < size2; ++i)
{
	if (i!=position)
	{
		list1[i].score=list[a].score;
		strcpy(list1[i].name,list[a].name);
		a++;
	}
}

for (int i = 0; i < size2; ++i)
{
  list[i].score=list1[i].score;
  strcpy(list[i].name,list1[i].name);
}
for (int i = 0; i < size2; ++i)
{
 if (player.score==list[i].score && strcmp(player.name,list[i].name)==0)
 {
 	 succesfull=true;
 }
} 
return succesfull;
} 
