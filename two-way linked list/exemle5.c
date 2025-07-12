#include <stdlib.h>
#include <stdio.h>
/*Bir sınıftaki N öğrenci için kullanıcıdan alınan öğrenci no,vize ve final notlarını tek yönlü bir bağlı listeye ekleyiniz.
 Her öğrencinin numarasını ve not ortalamasını, ayrıca sınıfın genel not ortalamasını yazdırınız.
 Daha sonra kullanıcının girdiği bir öğrenci numarasını listede arayıp eğer varsa öğrencinin vize,final notlarını yazdırınız.*/

struct deneme
{
    int vize;
    int final;
    int no;
    struct deneme *next;
};

struct deneme *head = NULL;

void ekleme(int vize, int final, int no)
{
    struct deneme *k = (struct deneme *)malloc(sizeof(struct deneme));
    k->final = final;
    k->no = no;
    k->vize = vize;
    k->next = NULL;

    if (head == NULL)
    {
        head = k;
    }
    else
    {
        struct deneme *c = head;

        while (c->next != NULL)
        {
            c = c->next;
        }
        c->next = k;
    }
}

void intections(int wanten_no)
{
    struct deneme *c = head;
    int ortalama = 0;
    int toplam = 0;
    int i;
    while (c != NULL)
    {
        ortalama=c->vize*0.4+c->final*0.6;
        i++;
        printf("\n%d nolu ogrencinin ortalamasi:%d\n",c->no,ortalama);
        toplam+=ortalama;
        ortalama=0;
        c = c->next;
    }
    printf("\navarage of the class:%d\n",toplam/i);

    c=head;
    while (c!=NULL)
    {
        if (c->no==wanten_no)
        {
            printf("\nwanted studentin of the final:%d\nwanted student of the vize:%d\n",c->final,c->vize);
        }
        
        c=c->next;
    }
    
}

int main()
{   
    int n;

    printf("enter please n:");
    scanf("%d",&n);
    int vize,final,no;

    for (int i = 0; i < n; i++)
    {
        printf("enter please no:");
        scanf("%d",&no);
        printf("enter please vize:");
        scanf("%d",&vize);
        printf("enter please final:");
        scanf("%d",&final);
        ekleme(vize,final,no);
    }
    int wanted;
    printf("enter please wanted number:");
    scanf("%d",&wanted);
    intections(wanted);
    

    return 0;
}
