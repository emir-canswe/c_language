#include <stdlib.h>
#include <stdio.h>

struct deneme
{
    int x;
    struct deneme *sonraki;
    struct deneme *onceki;
};

struct deneme *bas = NULL;
/*
void basa_ekle(int sayi){
    struct deneme *k=(struct deneme*)malloc(sizeof(struct deneme));
    k->x=sayi;
    k->onceki=NULL;

    if (bas==NULL)
    {
        bas=k;
        k->sonraki=NULL;
    }
    else
    {
        k->sonraki=bas;
        bas=k;
    }

}*/

void sona_ekle(int sayi)
{
    struct deneme *k = (struct deneme *)malloc(sizeof(struct deneme));
    k->x = sayi;
    k->sonraki = NULL;

    if (bas == NULL)
    {
        bas = k;
        bas->onceki = NULL;
        bas->sonraki = NULL;
    }
    else
    {
        if (bas->sonraki == NULL)
        {
            bas->sonraki = k;
            k->onceki = bas;
        }
        else
        {
            struct deneme *c = bas;
            while (c->sonraki != NULL)
            {
                c = c->sonraki;
            }
            c->sonraki = k; // amk  ne sacma sey sonraki degerini k yaasagida ise k nin onceki degeini c ye esitliyoruz
            k->onceki = c;
        }
    }
}

void yazma()
{

    struct deneme *c = bas;

    while (c != NULL)
    {
        printf("%d ", c->x);
        c = c->sonraki;
    }
}

int main()
{

    int sayi;

    for (int i = 0; i < 5; i++)
    {
        printf("sayi gir lutfen:");
        scanf("%d", &sayi);
        sona_ekle(sayi);
    }

    yazma();
    return 0;
}
