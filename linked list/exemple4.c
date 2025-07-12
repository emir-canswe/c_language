#include <stdio.h>
#include <stdlib.h>

/*Kullanıcıdan alınan bir sayının listede kaçıncı sırada olduğunu bulunuz.(Örneğin; 4, 7, 2, 5 olan bir listede sayı:2 girilmişse sıra:3 olur)*/

struct deneme
{
    int x;
    struct deneme *sonraki;
};

struct deneme *bas = NULL;

void add_to_end(int number)
{
    struct deneme *k = (struct deneme *)malloc(sizeof(struct deneme)); // sayi eklemek için gerekli parametre
    k->x = number;                                                     // gelen ilk  sayilari surekli x sruguna atmani saglar
    k->sonraki = NULL;                                                 // sona eklediginde her son degerini surekli sona esitlemen lazim
    if (bas == NULL)
    {
        bas = k;
    }
    else
    {
        struct deneme *c;
        c = bas;
        while (c->sonraki != NULL)
        {
            c = c->sonraki;
        }
        c->sonraki = k;
    }
}

int wanted(int want_number)
{

    int a = 0;
    struct deneme *c = bas;
    if (c == NULL)
    {
        printf("the struct is empty");
    }
    else
    {
        while (c != NULL)
        {
            a++;
            if (c->x == want_number)
            {
                return a;
            }
            c=c->sonraki;
        }

        return -1;
    }
}

int main()
{

    int number;

    for (int i = 0; i < 5; i++)
    {
        printf("enter a numnber:");
        scanf("%d", &number);
        add_to_head(number);
    }
    int want_number;
    printf("enter please wanted numebr:");
    scanf("%d", &want_number);

    int result = wanted(want_number);

    if (result == -1)
    {
        printf("wanted number is not found");
    }
    else
    {
        printf("wanted number is to %d locasion", result);
    }

    return 0;
}
