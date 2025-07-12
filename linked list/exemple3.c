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


void found(){
    int total=0;
    float avarege=0;
    float a=0;

    struct deneme *c=bas;
    if (c==NULL)
    {
        printf("struct id empyt");
    }
    else
    {
        while (c!=NULL)
        {
            a++;
            total+=c->x;
            c=c->sonraki;
        }
        
    }
    avarege=total/a;
    printf("total:%d\navarege=%d",total,avarege);
    

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
    printf("\n");
    found();

    return 0;
}
