#include <stdio.h>
typedef struct ugyfelek
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
    int hanyNap;
    UGYFEL ugyfel;
} AUTO;

void menu()
{
    printf("1. ---- Uj auto bevezetese, rendezes napidij szerint.\n");
    printf("2. ---- Auto kolcsonzese (kilistazzuk majd valasztunk).\n");
    printf("3. ---- Auto visszavetele kolcsonzesbol (kilistazzuk, valasztunk sorszam alapjan,kiirjuk az osszeget, majd visszavesszuk).\n");
    printf("4. ---- Auto torlese az adatbazisbol,rendezes napidij szerint.\n");
    printf("5. ---- Lista kiirasa kepernyore (tartalmazza osszes gepkocsi adatat.\n");
    printf("6. ---- Lista kiirasa txt-be\n");
    printf("7. ---- Mentes binaris fajlba\n");
    printf("8. ---- Beolvasas binaris fajlbol\n");
    printf("9. ---- Kilepes\n");
}

AUTO autoUjAuto(int* n)
{
    AUTO kocsi;
    printf("Tipus: ");
    scanf("%s",kocsi.tipus);
    printf("Rendszam: ");
    scanf("%s",kocsi.rendszam);
    printf("Napidij: ");
    scanf("%d",&kocsi.napidij);
    kocsi.hanyNap=0;
    strcpy(kocsi.ugyfel.keresztnev,"");
    strcpy(kocsi.ugyfel.vezeteknev,"");
    strcpy(kocsi.ugyfel.utlevelszam,"");
    (*n)++;
    return kocsi;
}
void autoNapiDijRendezes(AUTO kocsi[], int n)
{
    int i,j;
    AUTO temp;
    for(i=0; i<n; i++)
    {
        for(j=0; j<i; j++)
        {
            if(kocsi[i].napidij<kocsi[j].napidij)
            {
                temp = kocsi[i];
                kocsi[i] = kocsi[j];
                kocsi[j] = temp;
            }
        }
    }
}
void autoKolcsonzes(AUTO kocsi[], int n)
{
    AUTO kocsi1;
    int i, number;
    for(i=0; i<n; i++)
    {
        if(kocsi[i].hanyNap==0){
            printf("Sorszam: %d\n", i+1);
            printf("%s\n",kocsi[i].tipus);
            printf("%s\n",kocsi[i].rendszam);
            printf("%d\n",kocsi[i].napidij);
            printf("%d\n",kocsi[i].hanyNap);
        }

    }
    printf("Valasszon kocsit: ");
    scanf("%d",&number);

    //kocsi1 = kocsi[number-1];
    printf("Ugyfel_keresztneve: ");
    scanf("%s",kocsi[number-1].ugyfel.keresztnev);
    printf("Ugyfel_vezetekneve: ");
    scanf("%s",kocsi[number-1].ugyfel.vezeteknev);
    printf("Ugyfel_utlevelszama: ");
    scanf("%d",&kocsi[number-1].ugyfel.utlevelszam);
    printf("Hany napra?");
    scanf("%d",&kocsi[number-1].hanyNap);
}
void autoVisszaVetel(AUTO kocsi[], int n)
{
    //AUTO kocsi1;
    int i, number;
    for(i=0; i<n; i++)
    {
        if(kocsi[i].hanyNap!=0)
        {
            printf("Sorszam: %d\n", i+1);
            printf("%s\n",kocsi[i].tipus);
            printf("%s\n",kocsi[i].rendszam);
            printf("%d\n",kocsi[i].napidij);
            printf("%d\n",kocsi[i].hanyNap);
        }

    }
    printf("Valasszon kocsit: ");
    scanf("%d",&number);
    printf("Fizetendo osszeg: %d", kocsi[number-1].napidij*kocsi[number-1].hanyNap);
    strcpy(kocsi[number-1].ugyfel.keresztnev,"");
    strcpy(kocsi[number-1].ugyfel.vezeteknev,"");
    strcpy(kocsi[number-1].ugyfel.utlevelszam,"");
    kocsi[number-1].hanyNap=0;

}
void autoTorlese(AUTO kocsi[],int *n, int melyiket)  //int *n csak akkor ha n et valtoztatni akarjuk
{
    AUTO kocsi1;
    strcpy(kocsi[melyiket-1].tipus,"");
    strcpy(kocsi[melyiket-1].rendszam,"");
    kocsi[melyiket-1].napidij=99999999;
    kocsi[melyiket-1].hanyNap=0;
    strcpy(kocsi[melyiket-1].ugyfel.keresztnev,"");
    strcpy(kocsi[melyiket-1].ugyfel.keresztnev,"");
    strcpy(kocsi[melyiket-1].ugyfel.vezeteknev,"");
    strcpy(kocsi[melyiket-1].ugyfel.utlevelszam,"");

    autoNapiDijRendezes(kocsi,&n);
    (*n)--;
    //return kocsi1;
}
void autoKiiratas(AUTO kocsi[],int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("Sorszam: %d\n", i+1);
        printf("Tipus: %s\n",kocsi[i].tipus);
        printf("Rendszam: %s\n",kocsi[i].rendszam);
        printf("Napidij: %d\n",kocsi[i].napidij);
        printf("Kolcsonzesi ido: %d\n",kocsi[i].hanyNap);
        printf("Ugyfel keresztneve: %s\n",kocsi[i].ugyfel.keresztnev);
        printf("Ugyfel vezetekneve: %s\n",kocsi[i].ugyfel.vezeteknev);
        printf("Ugyfel utlevelszama: %s\n",kocsi[i].ugyfel.utlevelszam);
    }
}
void autoKiiratasTxtFajlba(AUTO kocsi[], int n)
{
    FILE *f = fopen("autokFprintf.txt","w");
    int i;
    for(i=0; i<n; i++)
    {
        printf("Sorszam: %d\n", i+1);
        fprintf(f,"Tipus: %s\n",kocsi[i].tipus);
        fprintf(f,"Rendszam: %s\n",kocsi[i].rendszam);
        fprintf(f,"Napidij: %d\n",kocsi[i].napidij);
        fprintf(f,"Kolcsonzesi ido: %d\n",kocsi[i].hanyNap);
        fprintf(f,"Ugyfel keresztneve: %s\n",kocsi[i].ugyfel.keresztnev);
        fprintf(f,"Ugyfel vezetekneve: %s\n",kocsi[i].ugyfel.vezeteknev);
        fprintf(f,"Ugyfel utlevelszama: %s\n",kocsi[i].ugyfel.utlevelszam);
    }
    fclose(f);
}
void autoKiiratasBinarisFajlba(AUTO kocsi[], int n)
{
    FILE *f = fopen("autokFwrite.bin","wb");
    int i;
    fwrite(&n, sizeof(int), 1,f);
    fwrite(kocsi, sizeof (AUTO), n, f);
    fclose(f);
}
void autoBeolvasasBinFajlbol(AUTO kocsi[], int* n){
    FILE *f = fopen("autokFwrite.bin","rb");
    fread(n,sizeof (int) ,1, f);
    fread(kocsi,sizeof (AUTO) ,*n, f);
}
int main()
{
    int n=0,x,melyik;
    AUTO tomb[100];
    while(1)
    {
        menu();
        //system("@cls||clear");
        scanf("%d",&x);
        if(x==1){
            tomb[n]=autoUjAuto(&n);
            autoNapiDijRendezes(tomb,n);
            printf("       %d         ",n);
            }
        if(x==2)
            autoKolcsonzes(tomb,n); //itt jarok, ugyfel.vezeteknev kapjon erteket
        if(x==3)
            autoVisszaVetel(tomb,n);
        if(x==4  && n>0){
            printf("Melyiket? ");
            scanf("%d",&melyik);
            autoTorlese(tomb,&n,melyik);}
        if(x==5)
            autoKiiratas(tomb,n);
        if(x==6)
            autoKiiratasTxtFajlba(tomb,n);
        if(x==7)
            autoKiiratasBinarisFajlba(tomb,n);
        if(x==8){}
            if(x==9)
                exit(0);
        printf("Nyomj meg barmit a folytatashoz\n");
        getch();
    }
}
