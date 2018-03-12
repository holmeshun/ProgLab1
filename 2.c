#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


struct ember
{

    char vnev[20];
    char knev[20];
    char email[20];
    long long tel[6];

};

struct ember beker(int *n)
{
    struct ember egy;

    printf("Vezeteknev?\n");
    scanf("%s",egy.vnev);

    printf("Keresztnev?\n");
    scanf("%s",egy.knev);

    printf("email?\n");
    scanf("%s",egy.email);


    printf("Hany telefonszama van?\n");
    scanf("%lld",&egy.tel[0]);

    int i;

    for(i=1; i<=egy.tel[0]; i++)
    {
        printf("Telefonszam?\n");

        scanf("%d",&egy.tel[i]);
    }

    (*n)++;
    return egy;
};

void kiiratas(int n, struct ember telefonkonyv[])
{
    int i;
    system("cls");
    printf("     %-20s%-20s%-20s%-10s\n","vezeteknev","keresztnev","email","telefonszam");
    for(i=0; i<n; i++)
    {
        printf("%2d.%-20s%-20s%-20s%-10I64d\n",i+1,telefonkonyv[i].vnev,telefonkonyv[i].knev,telefonkonyv[i].email,telefonkonyv[i].tel[1]);
    }
}

void mittesz()
{

    printf("1 - uj ember\n");
    printf("2 - ember torlese\n");
    printf("3 - emberek kiirasa\n");
    printf("4 - rendezes\n");
    printf("5 - file-ba mentes\n");
    printf("6 - file-bol olvas\n");
    printf("7 - file-ba iras_fscanf\n");
    printf("8 - file-bol olvasas_fscanf\n");
    printf("0 - kilepes\n");



}

void torles(int *n, struct ember telefonkonyv[])
{
    int x;
    printf("Hanyadik elemet torlod?\n");
    scanf("%d",&x);
    telefonkonyv[x]=telefonkonyv[*n];
    (*n)--;

}

void clrscr()
{
    system("@cls||clear");
}

void rendezes(struct ember *telefonykonyv, int n)
{

    int i;
    int j;



    struct ember tmp;
    for(i=0; i<n; i++)
        for(j=i+1; j<n; j++)
        {
            if(strcmp(telefonykonyv[i].vnev,telefonykonyv[j].vnev)>0)
            {
                tmp=telefonykonyv[i];
                telefonykonyv[i]=telefonykonyv[j];
                telefonykonyv[j]=tmp;
            }

            if(strcmp(telefonykonyv[i].vnev,telefonykonyv[j].vnev)==0)
                if(strcmp(telefonykonyv[i].knev,telefonykonyv[j].knev)>0)
                {
                    tmp=telefonykonyv[i];
                    telefonykonyv[i]=telefonykonyv[j];
                    telefonykonyv[j]=tmp;
                }

        }



}
void filebairas(struct ember telefonkonyv[], int n)
{
    int i;
    FILE *f = fopen("file_fprintf.txt", "w");
    FILE *f1 = fopen("file_fprintf_konnyebben_olvashato.txt", "w");
    fprintf(f,"      %-20s%-20s%-20s%-10s\n","vezeteknev","keresztnev","email","telefonszam");
    for(i=0; i<n; i++)
    {
        fprintf(f,"%2d.   %-20s%-20s%-20s%-10I64d\n",i+1,telefonkonyv[i].vnev,telefonkonyv[i].knev,telefonkonyv[i].email,telefonkonyv[i].tel[1]);
    }
    for(i=0; i<n; i++)
    {
        fprintf(f1,"%s %s %s %d\n",telefonkonyv[i].vnev,telefonkonyv[i].knev,telefonkonyv[i].email,telefonkonyv[i].tel[1]);
    }
    fclose(f);
    fclose(f1);

}
/*struct ember beolvasasFscanf(struct ember *telefonkonyv,int *n)
{
    FILE *f1 = fopen("file_fprintf_konnyebben_olvashato.txt", "r");
    int i;
        fscanf(f1,"%s %s %s %d", telefonkonyv[i].vnev, telefonkonyv[i].knev,telefonkonyv[i].email,telefonkonyv[i].tel[1]);
    }
    fclose(f1);
};*/
void mentes(struct ember telefonkonyv[], int n)
{
    int i;
    FILE *f = fopen("file.dat", "wb");
    fwrite(&n, sizeof (int), 1, f);
    fwrite(telefonkonyv, sizeof (struct ember), n, f);
    fclose(f);
}
void beolvasas(struct ember *telefonkonyv,int *n)
{
    FILE *f =fopen("file.dat","rb");
    fread(n,sizeof (int) , 1, f);
    fread(telefonkonyv, sizeof (struct ember) , *n, f);
    fclose(f);
}


int main()
{

    struct ember telefonkonyv[100];
    int x=10;
    int n=0;
    while(x!=0)
    {
        clrscr();
        mittesz();
        scanf("%d",&x);
        if(x==1)
        {
            telefonkonyv[n]=beker(&n);

        }
        if(x==2 && n>0)
        {
            torles(&n, telefonkonyv);


        }

        if(x==3)
            kiiratas(n, telefonkonyv);
        if(x==4)
            rendezes(&telefonkonyv,n);
        if(x==5)
            mentes(telefonkonyv,n);
        if(x==6)
            beolvasas(&telefonkonyv,&n);
        if(x==7)
            filebairas(telefonkonyv, n);
        //if(x==8)
            //beolvasasFscanf(&telefonkonyv,&n);
            if(x==0)
                exit(0);
        printf("Nyomj meg barmit a folytatashoz\n");
        getch();
    }




}
