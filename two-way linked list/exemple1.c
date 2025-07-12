#include <stdlib.h>
#include <stdio.h>
/*

cift yonlu bagli listede sona eklemenin genel mantigi tek yonle ayni ama onceki degeri de digeri ile onceki belirtilen sonraki parametreye atama işlemi yapacaksin 

*/
struct deneme
{
    int x;
    struct deneme *sonraki;
    struct deneme *onceki;
};

struct deneme *bas = NULL;

void sona_ekle(int sayi)
{
    struct deneme *k = (struct deneme *)malloc(sizeof(struct deneme));
    k->x = sayi;
    k->sonraki = NULL;
    if (bas == NULL)
    {
        bas = k;
        k->onceki = NULL;
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
            c->sonraki = k;
            k->onceki = c;
        }
    }
}


void yazma(){

    struct deneme *c=bas;

    while (c!=NULL)
    {
        printf("%d ",c->x);
        c=c->sonraki;
    }
    printf("\n");
    
}

int main()
{
    int sayi;

    for (int i = 0; i < 5; i++)
    {
        printf("sayi gir lutfen:");
        scanf("%d",&sayi);
        sona_ekle(sayi);
    }
    yazma();
    

    return 0;
}
