#include<stdio.h>

struct ember {

char vnev[20];
char knev[20];
char email[20];
long long tel[6];

};

struct ember beker(){
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

for(i=1; i<=egy.tel[0];i++)
{   printf("Telefonszam?\n");

scanf("%d",&egy.tel[i]);
}


return egy;
};

void kiirato(struct ember egy){
printf("\nvezeteknev: ");
printf(egy.vnev,"\n");
printf("\nkeresztnev: ");
printf(egy.knev,"\n");
printf("\nemail: ");
printf(egy.email,"\n");
int i;

for(i=1; i<=egy.tel[0];i++)
{   printf("\n%d.telefonszam:",i);
printf("%d\n",egy.tel[i]);
}

}

void kiiratas(int n){
    int i;
for(i=0; i<n; i++){
        printf("%d.ember\n",i);
    kiirato(telefonkonyv[i]);
    printf("----------------------------------------------------\n");

}

}

int main(){

struct ember telefonkonyv[100];

printf("Hany ember legyen?");
int n,i;
scanf("%d",&n);

for(i=0; i<n; i++)
    telefonkonyv[i]=beker();



}
