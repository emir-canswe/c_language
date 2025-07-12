#include <stdlib.h>
#include <stdio.h>
/*Tek yönlü bir bağlı listeyi yığıt şeklinde kullanıp elemanları ekledikten sonra tersten(sondan başa)
yazdırınız.(Listedeki tüm düğümler sırayla yığıta eklenip sonrasında tekrar çekilip yazıldığında tersten yazdırılmış olur)*/

struct deneme
{
    int x;
    struct deneme *next;
    struct deneme *prev;
};

struct deneme *head = NULL;
void add_the_list(int number)
{
    struct deneme *k = (struct deneme *)malloc(sizeof(struct deneme));
    k->x = number;
    k->next = NULL;
    if (head == NULL)
    {
        head = k;
        head->next = NULL;
        head->prev = NULL;
    }
    else
    {
        struct deneme *c = head;
        while (c->next != NULL)
        {
            c = c->next;
        }
        c->next=k;
        k->prev=c;
    }
}

void yazma(){

    struct deneme *c=head;
    while (c->next!=NULL)
    {
        c=c->next;
    }
    
    while (c!=NULL)
    {
        printf("%d ",c->x);
        c=c->prev;
    }
    printf("\n");

}

int main()
{
    int number;
    
    for (int i = 0; i < 5; i++)
    {
        printf("enter please a  number:");
        scanf("%d",&number);
        add_the_list(number);
    }

    yazma();
    
    return 0;
}
