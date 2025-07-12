#include <stdlib.h>
#include <stdio.h>

/*Çift yönlü bağlı liste elemanlarını tersten yazdırınız.*/

struct deneme
{
    int x;
    struct deneme *sonraki;
    struct deneme *onceki;
};

struct deneme *bas = NULL;
void basa_ekle(int sayi)
{
    struct deneme *k = (struct deneme *)malloc(sizeof(struct deneme));
    k->x = sayi;
    k->sonraki = bas;
    bas = k;
}
void sona_ekle(int sayi)
{
    struct deneme *k = (struct deneme *)malloc(sizeof(struct deneme));
    k->x = sayi;
    k->sonraki = NULL;

    if (bas == NULL)
    {
        k->onceki = NULL;
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
        k->onceki = c;
    }
}


void testen_yazma()
{
    if (bas == NULL)
    {
        printf("Liste boş law\n");
        return;
    }

    struct deneme *c = bas;

    while (c->sonraki != NULL)
    {
        c = c->sonraki;
    }

    while (c != NULL)
    {
        printf("%d ", c->x);
        c = c->onceki;
    }
    printf("\n");
}

void yazma()
{

    struct deneme *c = bas;
    while (c != NULL)
    {
        printf("%d ", c->x);
        c = c->sonraki;
    }
    printf("\n");
}

int main()
{
    int sayi;

    for (int i = 0; i < 5; i++)
    {
        printf("sayi gir luttfen:");
        scanf("%d", &sayi);
        sona_ekle(sayi);
    }

    testen_yazma();

    return 0;
}
