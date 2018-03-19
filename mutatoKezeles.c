#include <stdio.h>

int main()
{
    int variableX;
    int *pointerY;
    int *pointerZ;
    int **pointerW;

    scanf("%d", &variableX);

    int *lefoglalt = (int *) malloc(sizeof (int));
    lefoglalt = &variableX;
    printf("%d %x\n", *lefoglalt, lefoglalt);

    pointerY = &variableX;
    pointerZ = &pointerY;
    pointerW = &pointerY;

    printf("X: %d %x PointerY: %d %x PointerZ: %x %x PointerW: %x %x\n",variableX,&variableX,*pointerY,pointerY,*pointerZ, pointerZ, **pointerW,pointerW);
    *pointerY = 23;
    printf("X: %d %x PointerY: %d %x PointerZ: %x %x PointerW: %x %x\n",variableX,&variableX,*pointerY,pointerY,*pointerZ, pointerZ, **pointerW,pointerW);

    free(pointerW); //Javában van Garbage_Collector

    //Mutatók értelme: cím szerinti paraméterátadás
    //dinamikus tömbök
    //láncolt lista
}
