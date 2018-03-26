#include <stdio.h>
#include <stdlib.h>
typedef struct ovisok
{
    char vnev[25];
    char knev[25];
    int kor;
    int azonosito;
    struct ovisok *next;
} Ovisok;
Ovisok* hozzaad(struct ovisok *fej)
{
    Ovisok *tmp,*uj = (Ovisok *) malloc(sizeof(Ovisok));
    scanf("%s",uj->vnev);
    scanf("%s",uj->knev);
    scanf("%d",&uj->kor);
    scanf("%d",&uj->azonosito);
    uj->next= NULL;
    if(fej==NULL)
    {
        return uj;
    }
    for(tmp = fej; tmp->next; tmp = tmp->next);
    tmp->next = uj;
    return fej;
}
void kiiratas(Ovisok *fej)
{
    for(; fej; fej=fej->next)
    {
        printf("%s %s %d %d\n",fej->vnev,fej->knev,fej->kor,fej->azonosito);
        //system("pause");
    }
}
void lista(Ovisok *fej)
{
    int i=1;
    for(; fej; fej=fej->next)
    {
        printf("Sorszam: %d\nVezeteknev: %s Keresztnev: %s Kor: %d Azonosito: %d\n", i,fej->vnev,fej->knev,fej->kor,fej->azonosito);
        i++;
    }
}
void torol(Ovisok *fej, int n)
{
    int i=1;
    Ovisok *fejes = (Ovisok *)malloc(sizeof(Ovisok));

        for(; fej; fej=fej->next)
        {
            i++;
            if(i == n)
            {
                fej->next = (fej->next)->next;
            }
        }
}
Ovisok* elsoElemTorlese(Ovisok *fej)
{
        fej = fej->next;
        return fej;
}
int main()
{
    Ovisok *fej = NULL;
    int i,n,k;
    while(1)
    {
        printf("1 ---- Hozzaad\n");
        printf("2 ---- Kiirat\n");
        printf("3 ---- Torol\n");
        printf("4 ---- Kilep\n");
        scanf("%d",&k);
        if(k==1)
        {
            fej=hozzaad(fej);
        }
        else if(k==2)
        {
            lista(fej);
        }
        else if(k==3)
        {
            printf("Melyiket akarjuk torolni?\n");
            scanf("%d",&n);
            if(n>1)
                torol(fej,n);
            else
                fej=elsoElemTorlese(fej);
        }
        else
            exit(0);
        /*switch(k)
        {
        case 1:
            fej=hozzaad(fej);
            break;
        case 2:
            kiiratas(fej);
            break;
        case 3:
            ;
            break;
        }
        }*/
    }
}
