#include <stdio.h>
#include <stdlib.h>

/*Girilen bir kelimenin her harfini çift yönlü bağlı listenin bir düğümüne ekleyiniz. Daha sonra bu kelimenin palindrom olup olmadığını bulunuz.*/

struct deneme
{
    char harf;
    struct deneme *next;
    struct deneme *prev;
};

struct deneme *head = NULL;

void add_to_end(char string)
{

    struct deneme *k = (struct deneme *)malloc(sizeof(struct deneme));
    k->harf = string;
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
        c->next = k;
        k->prev = c;
    }
}

int examation()
{
    struct deneme *c = head;
    struct deneme *a = head;

    while (c->next != NULL)
    {
        c = c->next;
    }

    while (c != NULL && a != NULL)
    {
        if (c->harf != a->harf)
        {
            return -1;
        }
        c = c->prev;
        a = a->next;
    }

    return 1;
}
int main()
{
    char string[10];

    printf("enter please a string:");
    scanf("%s",string);

    for (int i = 0; string[i]!='\0'; i++)
    {
        add_to_end(string[i]);
    }
    int result=examation();

    if (result==-1)
    {
        printf("the words is not polidrom");
    }
    else if(result==1)
    {
        printf("the word is polidrom");
    }
    
    

    return 0;
}
