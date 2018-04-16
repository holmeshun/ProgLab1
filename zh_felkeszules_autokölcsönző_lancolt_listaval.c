#include <stdio.h>

typedef struct ugyfel
{
    char vezeteknev[20];
    char keresztnev[20];
    char utlevelszam[20];
} UGYFEL;
typedef struct autok
{
    char tipus[20];
    char rendszam[6];
    int napidij;
    int hanynap;
    UGYFEL ugyfel;

    struct autok *next;

} AUTO;

AUTO* autoHozzaad(AUTO *fej)
{
    AUTO *tmp,*uj = (AUTO *) malloc(sizeof(AUTO));

    scanf("%s",uj->tipus);
    scanf("%s",uj->rendszam);
    scanf("%d",&uj->napidij);
    uj->hanynap=0;
    strcpy(uj->ugyfel.vezeteknev,"");
    strcpy(uj->ugyfel.keresztnev,"");
    strcpy(uj->ugyfel.utlevelszam,"");
    uj->next = NULL;
    if(fej == NULL)
    {
        return uj;
    }

    for(tmp=fej; tmp->next; tmp=tmp->next);
    tmp->next=uj;
    return fej;
}
void autoKiiratas(AUTO *fej){
    int i=0;
    for(; fej; fej=fej->next)
    {
       printf("Sorszam: %d\n", i+1);
        printf("Tipus: %s\n",fej->tipus);
        printf("Rendszam: %s\n",fej->rendszam);
        printf("Napidij: %d\n",fej->napidij);
        printf("Kolcsonzesi ido: %d\n",fej->hanynap);
        printf("Ugyfel keresztneve: %s\n",fej->ugyfel.keresztnev);
        printf("Ugyfel vezetekneve: %s\n",fej->ugyfel.vezeteknev);
        printf("Ugyfel utlevelszama: %s\n",fej->ugyfel.utlevelszam);
        i++;
    }
}

int main()
{
    AUTO *fej=NULL;
    fej=autoHozzaad(fej);
    autoKiiratas(fej);
}
