#include <stdio.h>
#include <stdlib.h>

struct deneme
{
    int x;//sayi ataman için yapilan kod
    struct deneme *sonraki;//diger sayilari ulasman için yapilmis bir kopru gib dusun
};//

struct deneme *bas = NULL;//bu ise sayilari ekleyecegin struct

void arayaekle(int sayi, int n)
{
    struct deneme *k = (struct deneme *)malloc(sizeof(struct deneme));
    k->x = sayi;

    struct deneme *c = bas;

    // Eğer liste boşsa veya ilk düğüme eklenmesi gerekiyorsa
    if (bas == NULL || bas->x == n)
    {
        k->sonraki = bas;
        bas = k;
        return;
    }

    // Elemanı ekleyeceğimiz değeri bulana kadar ilerle
    while (c->sonraki != NULL && c->sonraki->x != n)
    {
        c = c->sonraki;
    }

    if (c->sonraki == NULL)
    {
        printf("Hata: %d değeri listede bulunamadı!\n", n);
        free(k);
        return;
    }

    k->sonraki = c->sonraki;
    c->sonraki = k;
}

void sonaekle(int sayi)
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

void basaekle(int sayi)//
{
    struct deneme *p = (struct deneme *)malloc(sizeof(struct deneme));//gelen her bir sayiy eklemek için yazilan bir arac daha cok  arac gib dusun
    p->x = sayi;//ilk degeri gelen sayiya esitle
    p->sonraki = bas;//sonraki deger bas parametresi olsun
    bas = p;//yeni bas degeri artik p degeri olacak
}

void bastansil()
{
    if (bas == NULL)
    {
        printf("Liste zaten boş!\n");
        return;
    }

    struct deneme *temp = bas;
    bas = bas->sonraki;
    free(temp);
}

void sondansil()
{
    if (bas == NULL)
    {
        printf("Liste zaten boş!\n");
        return;
    }

    struct deneme *c = bas;
    if (c->sonraki == NULL)
    { // Tek eleman varsa
        free(bas);
        bas = NULL;
        return;
    }

    while (c->sonraki->sonraki != NULL)
    {
        c = c->sonraki;
    }

    free(c->sonraki);
    c->sonraki = NULL;
}

void aradansil(int n)
{
    if (bas == NULL)
    {
        printf("Liste zaten boş!\n");
        return;
    }

    struct deneme *c = bas;

    // Eğer ilk düğüm silinecekse
    if (bas->x == n)
    {
        bastansil();
        return;
    }

    while (c->sonraki != NULL && c->sonraki->x != n)
    {
        c = c->sonraki;
    }

    if (c->sonraki == NULL)
    {
        printf("Hata: %d değeri listede bulunamadı!\n", n);
        return;
    }

    struct deneme *temp = c->sonraki;
    c->sonraki = c->sonraki->sonraki;
    free(temp);
}

void yazdirma()
{
    struct deneme *c = bas;
    if (c == NULL)
    {
        printf("Liste boş!\n");
        return;
    }

    while (c != NULL)
    {
        printf("%d ", c->x);
        c = c->sonraki;
    }
    printf("\n");
}

int main()
{
    sonaekle(1);
    sonaekle(2);
    sonaekle(4);
    yazdirma(); // 1 2 4

    basaekle(54);
    basaekle(4);
    yazdirma(); // 4 54 1 2 4

    int s1, s2;
    printf("Araya eklenecek sayıyı gir: ");
    scanf("%d", &s1);
    printf("Hangi sayıdan önce girilsin: ");
    scanf("%d", &s2);

    arayaekle(s1, s2);
    yazdirma();

    printf("\nBaştaki değerin silinmiş hali\n");
    bastansil();
    yazdirma();

    printf("\nSondan bir eleman silinmiş hali\n");
    sondansil();
    yazdirma();

    int n;
    printf("\nHangi sayı silinsin: ");
    scanf("%d", &n);
    aradansil(n);
    yazdirma();

    return 0;
}
