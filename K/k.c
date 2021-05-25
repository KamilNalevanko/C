#include <stdlib.h>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include "k.h"

void add_random_tile(struct game *game){
    int row, col;
    // find random, but empty tile
    do{
        row = rand() % SIZE;
        col = rand() % SIZE;
    }while(game->board[row][col] != ' ');

    // place to the random position 'A' or 'B' tile
    if(rand() % 2 == 0){
        game->board[row][col] = 'A';
    }else{
        game->board[row][col] = 'B';
    }
}

bool is_game_won(const struct game game){
 
 bool status=false;

  for (int i = 0; i < SIZE; ++i)
  {

    for (int j = 0; j < SIZE; ++j)
    {
      if (game.board[i][j]=='K')
      {
          status=true;
      }
    }
  }
return status;
}

bool is_move_possible(const struct game game){

bool move=false;

  for (int i = 0; i < SIZE; ++i)
  {

    for (int j = 0; j < SIZE; ++j)
    {
      if (game.board[i][j]==' ')
      {
          move=true;
      }
      if (j+1<SIZE)
      {
      	  if (game.board[i][j]==game.board[i][j+1] && j+1 < SIZE)
      {
        move=true;
      }
      }

    if (i+1<SIZE)
    {
    	if (game.board[i][j]==game.board[i+1][j] && i+1 < SIZE)
      {
        move=true;
      }
    	
    }
    	}

       }
return move;
}

bool update(struct game *game, int dy, int dx){

bool update=false;
int a=1;
int b=0;
int n=0;
char abeceda[]="ABCDEFGHIJK";

// POHYB HORE
 if (dy!=0 && dx==0)
 {
    if (dy==-1 && dx==0)
    {  
        a=1;
        b=0;
        int points=0;
        int save=0;
        for (int x = 0; x < SIZE; ++x)
        {
          for (int y = 0; y < SIZE; ++y)
          {
            if (game->board[x][y]!=' ')
            { 
                 if ((x-1)>=0)
                 {
                   
              if (game->board[x][y]==game->board[x-1][y])
              {   n=0;
                
                 for (int i = 0; n != 1; ++i)
                 {
                   if (game->board[x][y]==abeceda[i])
                   {
                     game->board[x-1][y]=abeceda[i+1];
                     save=(i+1)+1;
                     save=(int)pow(2,save);
                     points=points+save;
                     game->board[x][y]=' ';
                     n=n+1; 
                   }
                 }
              }}

            
             if ((x-a)>=0)
                 {
              
              while(game->board[x-a][y]==' ')
              { 
                if ((x-a)>=0)
                {
                
                game->board[x-a][y]=game->board[x-b][y];
                game->board[x-b][y]=' ';
                 }
           if (game->board[x-a][y]==game->board[x-(a+1)][y])
              {    

                  int n=0;
                 for (int i = 0; n != 1; ++i)
                 {

                   if (game->board[x-a][y]==abeceda[i])
                   {
                      game->board[x-(a+1)][y]=abeceda[i+1];
                      save=(i+1)+1;
                      save=(int)pow(2,save);
                      points=points+save;
                      game->board[x-a][y]=' '; 
                      n=n+1;
                   }
                 }
              }
                update=true;
                a++;
                b++;

              }  }
              a=1;
              b=0;
            }
          }

        }
        game->score=game->score+points;
    }
    n=0;
// POHYB DO DOLE

 if (dy==1 && dx==0)
    {    int points=0;
         int save=0;
        for (int x = 0; x < SIZE; ++x)
        {
          for (int y = 0; y < SIZE; ++y)
          {
            if (game->board[x][y]!=' ')
            { 
              update=true;
            if (game->board[x][y]==game->board[x+1][y])
              {  
                 for (int i = 0; n != 1; ++i)
                 {
                   if (game->board[x][y]==abeceda[i])
                   {
                     
                     game->board[x+1][y]=abeceda[i+1];
                     save=(i+1)+1;
                     save=(int)pow(2,save);
                     points=points+save;
                     game->board[x][y]=' ';
                     n=n+1; 
                   }
                 }
                 n=0;
              }
             
             
            while(game->board[x+a][y]==' ')
              { if ((x+a)<=SIZE)
              {
                game->board[x+a][y]=game->board[x+b][y];
                game->board[x+b][y]=' ';

                update=true;
                a++;
                b++;
              }
            }
              a=1;
              b=0;
            }
          }
        }
         for (int x = 0; x < SIZE; ++x)
        {
          for (int y = 0; y < SIZE; ++y)
          {
            if (game->board[x][y]!=' ')
            {       
            while(game->board[x+a][y]==' ')
              { 
                game->board[x+a][y]=game->board[x+b][y];
                game->board[x+b][y]=' ';

                update=true;
                a++;
                b++;
              }
              a=1;
              b=0;
            }
          }
        }
        for (int x = 0; x < SIZE; ++x)
        {
          for (int y = 0; y < SIZE; ++y)
          {
            if (game->board[x][y]!=' ')
            {       
            while(game->board[x+a][y]==' ')
              { 
                game->board[x+a][y]=game->board[x+b][y];
                game->board[x+b][y]=' ';

                update=true;
                a++;
                b++;
              }
              a=1;
              b=0;
            }
          }
        }
         game->score=game->score+points;
    }

  }
 

abeceda[strlen(abeceda)] = '\0';
a=1;
b=0;
 
 // POHYB DO prava

 if (dx==1 && dy==0)
 {
    int save=0;
    int points=0;

  for (int x = 0; x < SIZE; ++x)
  {
    for (int y=SIZE ; y>=0 ; --y)
    {
      if (game->board[x][y]!=' ')
      { 
        if ((y+1)<SIZE)
        {
        if (game->board[x][y+1]==' ' )
        {
        game->board[x][y+1]=game->board[x][y];
        game->board[x][y]=' ';
        update=true;
      }
    }
if ((y+2)<SIZE)
{
  if (game->board[x][y+2]==' ' )
        {
        game->board[x][y+2]=game->board[x][y+1];
        game->board[x][y+1]=' ';
        update=true;
      }
    }
      if ((y+3)<SIZE)
      {
      if (game->board[x][y+3]==' ' )
        {
        game->board[x][y+3]=game->board[x][y+2];
        game->board[x][y+2]=' ';
        update=true;
      }
    }
      }
    }

  } 
for (int x = 0; x < SIZE; ++x)
{
  for (int y=SIZE ; y>=0 ; --y)
  { 
   if (game->board[x][y]!=' ')
    { 
      if ((y-1)>=0)
      {
    if (game->board[x][y]==game->board[x][y-1])
    { 
      if ((y-1)>=0 && y!=4)
      {
        for (int i = 0; n != 1; ++i)
                 {
                   if (game->board[x][y]==abeceda[i])
                   {
                     
                     game->board[x][y]=abeceda[i+1];
                     save=(i+1)+1;
                     save=(int)pow(2,save);
                    if (save>0 && save<2049)
                     {
                        points=points+save;
                     }
		 
		     update=true;
   
                     game->board[x][y-1]=' ';
                     n=n+1; 
                   }
                 }
                 n=0;
      }
      
    }
  }
    }  // TU
    
  }
} 

 for (int x = 0; x < SIZE; ++x)
  {
    for (int y=SIZE ; y>=0 ; --y)
    {
      if (game->board[x][y]!=' ')
      {
        if ((y+1)<SIZE && game->board[x][y+1]==' ' )
        {
        game->board[x][y+1]=game->board[x][y];
        game->board[x][y]=' ';
      }
      if ((y+2)<SIZE && game->board[x][y+2]==' ' )
        {
        game->board[x][y+2]=game->board[x][y+1];
        game->board[x][y+1]=' ';
      }
      if ((y+3)<SIZE && game->board[x][y+3]==' ' )
        {
        game->board[x][y+3]=game->board[x][y+2];
        game->board[x][y+2]=' ';
      }
      }
    }

  } 
  game->score=game->score+points;
}
 
// POHYB DO lava


    if (dx==-1 && dy==0)
    { 

       int save=0;
       int points=0;

        for (int x = 0; x < SIZE; ++x)
        {
          for (int y = 0; y < SIZE; ++y)
          {
    if (game->board[x][y]!=' ')
      {
        if ((y-1)>=0 && game->board[x][y-1]==' ' )
        {
        game->board[x][y-1]=game->board[x][y];
        game->board[x][y]=' ';
        update=true;
      }
      if ((y-2)>=0 && game->board[x][y-2]==' ' )
        {
        game->board[x][y-2]=game->board[x][y-1];
        game->board[x][y-1]=' ';
        update=true;
      }
      if ((y-3)>=0 && game->board[x][y-3]==' ' )
        {
        game->board[x][y-3]=game->board[x][y-2];
        game->board[x][y-2]=' ';
        update=true;
      }
      }
          }
        }
for (int x = 0; x < SIZE; ++x)
 {
  for (int y = 0 ; y < SIZE ; ++y)
  { 
   if (game->board[x][y]!=' ')
    {
    if (game->board[x][y]==game->board[x][y+1])
    { 
      if ((y+1)<SIZE)
      {
        for (int i = 0; n != 1; ++i)
                 {
                   if (game->board[x][y]==abeceda[i])
                   {
                     
                     game->board[x][y+1]=abeceda[i+1];
                     save=(i+1)+1;
                     save=(int)pow(2,save);
                    if (save>0 && save<2049)
                     {
                        points=points+save;
                     }
                     update=true;
                     game->board[x][y]=' ';
                     n=n+1; 
                   }
                 }
                 n=0;
      }
      
    }
    }  // TU
    
  }
}
  for (int x = 0; x < SIZE; ++x)
        {
          for (int y = 0; y < SIZE; ++y)
          {
    if (game->board[x][y]!=' ')
      {
        if ((y-1)>=0 && game->board[x][y-1]==' ' )
        {
        game->board[x][y-1]=game->board[x][y];
        game->board[x][y]=' ';
        update=true;
      }
      if ((y-2)>=0 && game->board[x][y-2]==' ' )
        {
        game->board[x][y-2]=game->board[x][y-1];
        game->board[x][y-1]=' ';
        update=true;
      }
      if ((y-3)>=0 && game->board[x][y-3]==' ' )
        {
        game->board[x][y-3]=game->board[x][y-2];
        game->board[x][y-2]=' ';
        update=true;
      }
      }
          }
        }
     game->score=game->score+points;
    }


return update;
}
