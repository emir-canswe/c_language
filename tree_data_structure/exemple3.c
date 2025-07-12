#include <stdlib.h>
#include <stdio.h>
/*Ağaçtaki sayıları büyükten küçüğe sıralı olarak yazdırınız.*/

struct deneme
{
    int x;
    struct deneme *left;
    struct deneme *right;
};

struct deneme *add_to_rood(int number)
{
    struct deneme *k = (struct deneme *)malloc(sizeof(struct deneme));
    k->right = NULL;
    k->left = NULL;
    k->x = number;

    return k;
}

struct deneme *add(struct deneme *k,int number){

    if (k==NULL)
    {
        return add_to_rood(number);
    }
    else
    {
        if (number>k->x)
        {
            k->right=add(k->right,number);
        }
        else
        {
            k->left=add(k->left,number);
        }
        
    }


    return k;
    
}


void inorder(struct deneme *k){
    if (k!=NULL)
    {
        inorder(k->left);
        printf("%d ",k->x);
        inorder(k->right);
    }
    
}

int main()
{
    struct deneme *k=NULL;

    int nnumber;

    for (int i = 0; i < 5; i++)
    {
        printf("enter please a number:");
        scanf("%d",&nnumber);
        k=add(k,nnumber);
    }

    inorder(k);
    

    return 0;
}
