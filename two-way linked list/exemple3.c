#include<stdlib.h>
#include<stdint.h>
#include<stdio.h>

/*Çift yönlü bağlı listede girilen sayının sondan kaçıncı sırada olduğunu bulunuz. (Örnek: 1, 4, 20, 50, 80 ise; 50 sayısı sondan 2. Sıradadır.) */

struct deneme
{
    int x;
    struct deneme *sonraki;
    struct deneme *onceki;
};

struct deneme *bas=NULL;

void sona_ekle(int sayi){
    struct deneme *k=(struct deneme*)malloc(sizeof(struct deneme));
    k->x=sayi;
    k->sonraki=NULL;

    if (bas==NULL)
    {
        bas=k;
        bas->onceki=NULL;
        bas->sonraki=NULL;
    }
    else
    {
        struct deneme *c=bas;

        while (c->sonraki!=NULL)
        {
            c=c->sonraki;
        }
        c->sonraki=k;
        k->onceki=c;
        
    }
    
}

int incele(int wanted){
    struct deneme *c=bas;
    while (c->sonraki!=NULL)
    {
        c=c->sonraki;
    }
    int i=0;
    while (c!=NULL)
    {
        i++;
        if (wanted==c->x)
        {
            return i;
        }
        c=c->onceki;
        
    }


    return -1;
    
    
}


int main(){

    int number,wanted;

    for (int i = 0; i < 6; i++)
    {
        printf("enter please a number:");
        scanf("%d",&number);
        sona_ekle(number);
    }
    printf("enter please wanted number:");
    scanf("%d",&wanted);
    int result=incele(wanted);

    if (result==-1)
    {
        printf("wanted number is not found");
    }
    else
    {
        printf("wanted number is %d finis locasion",result);
    }
    
    

    return 0;
}
