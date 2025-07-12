#include <stdio.h>
#include <stdlib.h>

struct deneme
{
    int x;
    struct deneme *sonraki;
};

struct deneme *bas = NULL;

void add_to_head(int number)
{

    struct deneme *k = (struct deneme *)malloc(sizeof(struct deneme));
    k->x = number;
    k->sonraki = NULL;

    if (bas == NULL)
    {
        bas = k;
    }
    else
    {
        struct deneme *c = bas;
        while (c->sonraki != NULL)
        {
            c = c->sonraki;
        }
        c->sonraki = k;
    }
}

void wrater()
{

    struct deneme *c = bas;
    if (c == NULL)
    {
        printf("list in empty");
    }
    else
    {
        while (c != NULL)
        {
            printf("%d ", c->x);
            c = c->sonraki;
        }
        printf("\n");
    }
}

int main()
{
    int number;
    while (1)
    {
        printf("enter please a number:");
        scanf("%d", &number);
        if (number == -1)
        {
            printf("ap is finnish\n");
            break;
        }
        else
        {
            add_to_head(number);
        }
    }

    wrater();

    return 0;
}
