#include <stdio.h>
#include <stdlib.h>
/*Tek yönlü bir bağlı listede kullanıcının girdiği konumdaki(sıradaki)
sayıyı kullanıcıdan alınan sayı ile değiştiriniz.(Örneğin; 4, 7, 2, 5 olan bir listede sıra:2 yeni sayı:1 ise yeni liste:4, 1, 2, 5 olacaktır)*/

struct deneme
{
    int x;
    struct deneme *next;
};

struct deneme *bas = NULL;

void add_to_end(int number)
{
    struct deneme *k = (struct deneme *)malloc(sizeof(struct deneme));
    k->x = number;
    k->next = NULL;

    if (bas == NULL)
    {
        bas = k;
    }
    else
    {
        struct deneme *c = bas;

        while (c->next != NULL)
        {
            c = c->next;
        }
        c->next = k;
    }
}

void process(int locastion, int new_number)
{
    int i = 0;
    struct deneme *c = bas;
    while (c != NULL)
    {
        i++;
        if (i == locastion)
        {
            c->x = new_number;
        }

        c = c->next;
    }
}

void writer()
{
    struct deneme *c = bas;
    if (c == NULL)
    {
        printf("list is empty");
    }
    else
    {
        while (c != NULL)
        {
            printf("%d ", c->x);
            c = c->next;
        }
        printf("\n");
    }
}

int main()
{
    int number;
    for (int i = 0; i < 5; i++)
    {
        printf("enter please a number:");
        scanf("%d", &number);
        add_to_end(number);
    }
    int locasions, new_number;
    printf("enter pleease a locasions:");
    scanf("%d", &locasions);
    printf("enter please new number:");
    scanf("%d", &new_number);
    printf("old list\n");
    writer();
    process(locasions, new_number);
    printf("new number with new list\n");
    writer();
    return 0;
}
