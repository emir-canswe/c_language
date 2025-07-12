#include <stdlib.h>
#include <stdio.h>
/*Ağaçta kaç tane çift sayı olduğunu bulunuz.*/

struct deneme
{
    int x;
    struct deneme *left;
    struct deneme *right;
};

struct deneme *add_to_rood(int number)
{
    struct deneme *k = (struct deneme *)malloc(sizeof(struct deneme));
    k->left = NULL;
    k->right = NULL;
    k->x = number;

    return k;
}

struct deneme *add(struct deneme *k, int number)
{

    if (k == NULL)
    {
        return add_to_rood(number);
    }
    else
    {
        if (k->x > number)
        {
            k->left = add(k->left, number);
        }
        else
        {
            k->right = add(k->right, number);
        }
    }
    return k;
}

int incelme(struct deneme *k)
{
    
    int say=0;
    if (k==NULL)
        return 0;
    

    if (k->x%2==0)
        say=1;
   

    return incelme(k->left)+incelme(k->right)+say;
    

}

int main()
{
    struct deneme *k=NULL;

    int number;

    for (int i = 0; i < 5; i++)
    {
        printf("enter please a number:");
        scanf("%d",&number);
        k=add(k,number);
    }

    int result=incelme(k);
    
    printf("agactaki cift sayialrin toplami:%d",result);

    return 0;
}
