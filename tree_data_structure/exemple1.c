#include<stdlib.h>
#include<stdio.h>

/*Kullanıcıdan alınan sayıları ikili arama ağacına ekleyen kodu hem 
özyinelemeli hem de döngüsel olarak ayrı ayrı yazınız.*/

struct deneme
{
    int x;
    struct deneme *left;
    struct deneme *right;
};

struct deneme *add_to_root (int number){

    struct deneme *k=(struct deneme *)malloc(sizeof(struct deneme));
    k->x=number;
    k->left=NULL;
    k->right=NULL;

    return k;

}

struct deneme *add(struct deneme *k,int number){
    if (k==NULL)
    {
        return add_to_root(number);//eger dugum bossa gerekli girdileri saglar
    }
    else
    {
        if (k->x>number)
        {
            k->left=add(k->left,number);
        }
        else
        {
            k->right=add(k->right,number);
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


int main(){

    int number;
    struct deneme *k=NULL;

    for (int i = 0; i < 5; i++)
    {
        printf("enter please a number:");
        scanf("%d",&number);
        k=add(k,number);
    }

    inorder(k);
    


    return 0;
}
