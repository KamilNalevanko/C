#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include<math.h>
#include<time.h>
#include <stdbool.h>

struct node 
{ 
    int data; 
    struct node* left; 
    struct node* right; 
}; 
  


struct node* newNode(int data) 
{ 
    struct node* node = (struct node*) 
                             malloc(sizeof(struct node)); 
    node->data  = data; 
    node->left  = NULL; 
    node->right = NULL; 
  
    return(node); 
    
}

int sameTrees(struct node* a, struct node* b) 
{ 

    if (a==NULL && b==NULL) 
        return 1; 
 
    if (a!=NULL && b!=NULL) 
    { 
        return
        ( 
            sameTrees(a->left, b->left) && 
            sameTrees(a->right, b->right) 
        ); 
    } 

    return 0; 
}  


struct node* insert(struct node* tree, int data) 
{ 
   
    if (tree == NULL) return newNode(data); 
    if (data < tree->data) 
        tree->left  = insert(tree->left, data); 
    else if (data > tree->data) 
        tree->right = insert(tree->right, data);    

    return tree; 
}

int main() 
{ 
    int number=0;
    int lenght=0;
    scanf("%d %d",&number,&lenght);
  
    struct node* polestromov[number];
    struct node* polestromov2[number];
    
    
    for (int i = 0; i < number; ++i)
    {    
        polestromov[i]=NULL;
        for(int j=0;j<lenght;++j)
    	{
            int a=0;
            scanf("%d",&a);
    	    polestromov[i] = insert(polestromov[i],a);
        }
    }
   
    int pole[number]; 
    
int b=0;

for (int j = 0; j < number; ++j)
{
    
  for (int i = 0; i <number; ++i)
  {
  	if(sameTrees(polestromov[j], polestromov[i])){
  	    pole[i]=j;
       }
  }
 }
 

 
 int l=0;
 int k=0;
 
  for(int i=0; i<number; i++)
    {
        for(l=i+1; l<number; l++)
        {
            if(pole[i] == pole[l])
            {
                for(k=l; k<number; k++)
                {
                    pole[k] = pole[k + 1];
                }
                number--;
                l--;
            }
        }
    }


    printf("%d",number);
	return 0;
}
