#include <stdio.h>
#include <stdlib.h>

/*Kullanıcının girdiği sırada(konumda) bulunan sayıyı ekrana yazdırınız.(Örneğin; 4, 7, 2, 5 olan bir listede sıra:2 girilmişse sayı:7 olur)
 */

struct deneme
{
    int x;
    struct deneme *next;
};

struct deneme *bas = NULL;

void add_to_end(int number)
{
    struct deneme *k = (struct deneme *)malloc(sizeof(struct deneme));
    k->x = number;
    k->next = NULL;
    if (bas == NULL)
    {
        bas = k;
    }
    else
    {
        struct deneme *c = bas;
        while (c->next != NULL)
        {
            c = c->next;
        }
        c->next = k;
    }
}

int found(int lacasion)
{
    int i = 0;
    struct deneme *c = bas;
    if (c == NULL)
    {
        printf("struct is empty");
    }
    else
    {
        while (c != NULL)
        {
            i++;
            if (i == lacasion)
            {
                return c->x;
            }
            c = c->next;
        }
    }
}

int main()
{

    int number, locasion;
    for (int i = 0; i < 10; i++)
    {
        printf("enter please a number:");
        scanf("%d", &number);
        add_to_end(number);
    }
    printf("enter pleasse locasion:");
    scanf("%d", &locasion);

    int result = found(locasion);

    printf("wanted mnumer of the locasions:%d", result);

    return 0;
}
