#include<stdio.h>
#include<stdlib.h>

struct deneme
{
    int x;//bu gelen sayiyi eklemek için kullanilir
    struct deneme *sonraki//bu ise senin diger sayiyi eklemen için bir kopru vazifesi gorur
};

struct deneme *bas=NULL;//gelen her bir sayi buna atanacak yani bizim ana dizimiz bu olacak

void sayiYazdir(int sayi){

    struct deneme* index = bas;
    int sayac = 0;
    while(index!=NULL){
        sayac ++;
        if(index->x == sayi){
            
            printf("%d konumda %d sayi bulundu",sayac,sayi);
        }
        index = index->sonraki;
    }


}

//  0 1 2 3 4-  5 - 6 7 8 9 10
/*
    sol = 0
    sag = 9
    orta = 4

    sol = 5 
    sag = 9
    sol = 7

    sol = 5
    sag = 8

    orta = 6

*/ 


void add_head(int number){
    struct deneme *k=(struct deneme*)malloc(sizeof(struct deneme));
    k->x=number;//her gelen sayiyi gecici olsuturdugun sayiyia ata
    k->sonraki=bas;//geciciden sonraki her bir dege bas olsun bu sayede gelen her bir sayi basa eklenebilsin
    bas=k;//yeni bas degeri artik k strukuna esit olacak
}


void write(){
    struct deneme *c;//yazmak için yine gecici bir struct olustur
    c=bas;
    if (c==NULL)
    {
        printf("liste bos");
        return ;
    }

    while (c!=NULL)
    {
        printf("%d ",c->x);
        c=c->sonraki;
    }
    printf("\n");
    
    

}


int main(){

    int sayi;

    for (int i = 0; i < 5; i++)
    {
        printf("sayi gir:");
        scanf("%d",&sayi);
        add_head(sayi);
    }

    write();
    

    return 0;
}
