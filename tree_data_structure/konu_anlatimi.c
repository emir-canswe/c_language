#include <stdio.h>
#include <stdlib.h>

// Düğüm yapısı: her düğüm bir sayı (x) tutar ve sol-sağ çocuklarını gösteren pointer'lar içerir
struct deneme
{
    int x;                // düğümdeki veri (sayı)
    struct deneme *left;  // sol çocuk
    struct deneme *right; // sağ çocuk
};

// Yeni bir kök düğüm oluşturur, sadece ilk kez çağırıldığında çalışır
struct deneme *kok_dugum(int number)//
{
    struct deneme *k = (struct deneme *)malloc(sizeof(struct deneme)); // hafızadan yer ayır
    k->x = number;                                                     // düğüme sayıyı ata
    k->left = NULL;                                                    // sol çocuğu boş
    k->right = NULL;                                                   // sağ çocuğu boş
    return k;                                                          // oluşturulan düğümü geri döndür
}

// Ağaca yeni eleman ekleme işlemi (ikili arama ağacı mantığıyla)
// Eğer sayı kökten küçükse sola, büyükse sağa eklenir
struct deneme *eleman_ekle(struct deneme *k, int number)
{
    if (k == NULL)
    {
        // Eğer ağaçta o konum boşsa, yeni düğüm oluştur
        return kok_dugum(number);//bu dugumu gord
    }
    else
    {
        if (number < k->x)
        {
            // Sayı küçükse sol alt ağaca ekle
            k->left = eleman_ekle(k->left, number);
        }
        else
        {
            // Sayı büyükse sağ alt ağaca ekle
            k->right = eleman_ekle(k->right, number);
        }
    }
    return k; // Güncellenmiş kökü geri döndür maine bu sayede daha iyi bir 
}

// PREORDER GEZİNTİ: önce kök, sonra sol, sonra sağ (KÖK - SOL - SAĞ)
void preorder(struct deneme *k)
{
    if (k != NULL)
    {
        printf("%d ", k->x); // önce kökü yazdır
        preorder(k->left);   // sonra sol alt ağacı gez
        preorder(k->right);  // sonra sağ alt ağacı gez
    }
}

// INORDER GEZİNTİ: önce sol, sonra kök, sonra sağ (SOL - KÖK - SAĞ)
// Bu sırayla yazarsan sayılar küçükten büyüğe sıralı çıkar
void inorder(struct deneme *k)
{
    if (k != NULL)
    {
        inorder(k->left);    // önce sol alt ağacı gez null olana kadar devam eder
        printf("%d ", k->x); // sonra kökü yazdır
        inorder(k->right);   // sonra sağ alt ağacı gez
    }
}

// POSTORDER GEZİNTİ: önce sol, sonra sağ, sonra kök (SOL - SAĞ - KÖK)
void postorder(struct deneme *k)
{
    if (k != NULL)
    {
        postorder(k->left);  // önce sol alt ağacı gez
        postorder(k->right); // sonra sağ alt ağacı gez
        printf("%d ", k->x); // en son kökü yazdır
    }
}

int main()
{
    struct deneme *k = NULL; // ağaç başlangıçta boş
    int number;

    // Kullanıcıdan 7 sayı alarak ağaca ekleme
    for (int i = 0; i < 7; i++)
    {
        printf("Enter a number: "); // kullanıcıdan sayı al
        scanf("%d", &number);
        k = eleman_ekle(k, number); // sayıyı ağaca ekle
    }

    // Ağacı farklı sıralamalarla yazdır
    printf("\nInorder (kucukten buyuge sirayla):\n");
    inorder(k);

    printf("\nPreorder (kok basta):\n");
    preorder(k);

    printf("\nPostorder (kok sonda):\n");
    postorder(k);

    return 0; // program başarıyla bitti
}
