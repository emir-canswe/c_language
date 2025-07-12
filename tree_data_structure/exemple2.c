#include <stdlib.h>
#include <stdio.h>
/*Ağaçtaki sayılardan en büyük ve en küçük sayıları hem özyinelemeli hem de döngüsel olarak bulan fonksiyonları yazınız.*/

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
    return k;//bu siktigim returnlari unutma lav
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

void eb(struct deneme *k)
{

    if (k->right != NULL)
    {

        eb(k->right);
    }
    else
    {
        printf("\nen buyuk deger:%d\n", k->x);
    }
}

void ek(struct deneme *k)
{

    if (k->left != NULL)
    {

        ek(k->left);
    }
    else
    {
        printf("\nen buyuk deger:%d\n", k->x);
    }
}

int main()
{
    struct deneme *k = NULL;

    int number;

    for (int i = 0; i < 5; i++)
    {
        printf("enter please a  number:");
        scanf("%d", &number);
        k = add(k, number);
    }

    ek(k);

    eb(k);

    return 0;
}
