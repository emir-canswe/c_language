#include <stdlib.h>
#include <stdio.h>
// Listedeki sayıların toplamını ve ortalamasını bulunuz.

struct deneme
{
    int x;
    struct deneme *nex;
};
struct deneme *head = NULL;

void add_of_end(int number)
{
    struct deneme *k = (struct deneme *)malloc(sizeof(struct deneme));
    k->x = number;
    k->nex = NULL;
    if (head == NULL)
    {
        head = k;
    }
    else
    {
        struct deneme *c = head;
        while (c->nex != NULL)
        {
            c = c->nex;
        }
        c->nex = k;
    }
}

void intections(){
    struct deneme *c=head;
    int i=0;
    int toplam=0;
    while (c!=NULL)
    {
        i++;
        toplam+=c->x;
        c=c->nex;
    }
    int avarege=toplam/i;
    printf("entereden numbers of the avatege:%d\nenterded numbers is sum:%d",avarege,toplam);
    
}

int main()
{
    int number;

    for (int i = 0; i < 5; i++)
    {
        printf("enter please a number:");
        scanf("%d",&number);
        add_of_end(number);
    }
    intections();
    

    return 0;
}
