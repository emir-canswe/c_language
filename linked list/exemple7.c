#include <stdio.h>
#include <stdlib.h>
/*Bağlı listeyi ikinci bir bağlı liste kullanarak tersten yazdırınız.(İlk listedeki her eleman ikinci listenin sürekli başına eklenmelidir)*/
struct deneme
{
    int x;
    struct deneme *sonraki;
};

struct
try
{
    int y;
    struct try *next;
};

struct deneme *bas = NULL;
struct try *head = NULL;

int ekleme(int sayi)
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

void basa_ekle(int sayi)
{
    struct try *k = (struct try *)malloc(sizeof(struct try));
    k->y = sayi;
    k->next = head;
    head = k;
}

void bastan_sil()
{

    struct deneme *c = bas;
    struct deneme *k;
    if (c == NULL)
    {
        printf("listen bosalmistir");
    }
    else
    {
        k = c->sonraki;
        basa_ekle(c->x);
        free(c);
        bas = k;
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

void write()
{
    struct try *c = head;
    while (c != NULL)
    {
        printf("%d ", c->y);
        c = c->next;
    }
}
int main()
{

    int sayi;

    for (int i = 0; i < 5; i++)
    {
        printf("sayi gir lutfen:");
        scanf("%d", &sayi);
        ekleme(sayi);
    }
    printf("bastan cikralimamis hali\n");
    yazma();
    printf("\n");
    bastan_sil();
    bastan_sil();
    bastan_sil();
    bastan_sil();
    bastan_sil();
    bastan_sil();
    printf("\nbastan cikralidiktan sonra listenin son hali\n");
    printf("\n");
    yazma();
    printf("\nyeni listeye eklenmeis sayi\n");
    write();

    return 0;
}
