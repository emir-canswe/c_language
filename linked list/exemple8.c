#include <stdio.h>
#include <stdlib.h>
/*Bağlı listedeki sayıların ortalamasından küçük olanları listeden siliniz.*/

struct deneme
{
    int x;
    struct deneme *sonraki;
};

struct deneme *bas = NULL;

void ekleme(int sayi)
{
    struct deneme *k = (struct deneme *)malloc(sizeof(struct deneme));
    k->x = sayi;
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

void inceleme()
{
    float ortalama = 0;
    struct deneme *c = bas;
    int toplam = 0, sayac = 0;

    while (c != NULL)
    {
        toplam += c->x;
        sayac++;
        c = c->sonraki;
    }

    if (sayac == 0)
        return;

    ortalama = (float)toplam / sayac;

    struct deneme *onceki = NULL;
    c = bas;

    while (c != NULL)
    {
        if (c->x < ortalama)
        {
            if (onceki == NULL)
            { // İlk eleman silinecek
                bas = c->sonraki;
                free(c);
                c = bas;
            }
            else
            {
                onceki->sonraki = c->sonraki;
                free(c);
                c = onceki->sonraki;
            }
        }
        else
        {
            onceki = c;
            c = c->sonraki;
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
    printf("\n");
}
int main()
{

    int sayi;

    for (int i = 0; i < 5; i++)
    {
        printf("sayi gir lan:");
        scanf("%d", &sayi);
        ekleme(sayi);
    }
    printf("eleman silinmeden once\n");
    yazma();
    printf("eleman silindikten sonra\n");
    inceleme();
    yazma();

    return 0;
}
