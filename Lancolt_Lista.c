#include <stdio.h>

typedef struct lista
{
    int ertek;
    struct lista *kov;
} Lista;

Lista* ujelem(int adat)
{
    Lista *uj =(Lista*) malloc(sizeof(Lista));
    uj->ertek = adat;
    uj->kov = NULL;
    return uj;
}
Lista* vegerehozzaad(Lista *fej, int ertek)
{
    Lista *tmp;
    Lista *uj = ujelem(ertek);
    if(fej == NULL){
        return uj;
    }
    for(tmp = fej; tmp->kov; tmp = tmp->kov);
    tmp->kov = uj;
    return fej;
}
Lista* elejehezAd(Lista *fej, int ertek)
{
    Lista *uj =ujelem(ertek);
    uj->kov = fej;
    fej = uj;
}
void kiiratas(Lista *fej)
{
    Lista *tmp;
    for(tmp=fej; tmp->kov; tmp=tmp->kov)
        printf("%d ", tmp->ertek);
}
int main()
{
    Lista *fej=NULL;
    int i;
    for(i=1; i<=11; i++){
        fej=vegerehozzaad(fej, i);
    }
    kiiratas(fej);
}
