#include <stdio.h>

#define LIN 4
#define COL 5
#define NITMAX 11

int main(void)
{
    /* Declaracao de variaveis decisorias*/
    float matriz[LIN][COL] =
    {
        {1.234, 5.331, 1.231, -2.174, 6.456},
        {1.333, 2.346, -4.234, 3.147, 2.502},
        {2.204, -2.021, 6.001, -1.125, -1.101},
        {0.211, 7.126, -0.234, 5.003, -2.115},
    };
    /*indices*/
    int i,j,k,w,x,y,z;
    float soma=0.0;

    /*matrizes*/
    float mult[LIN];
    float matriz00[LIN][COL];
    float s[NITMAX+1][LIN];


    //Solucoes
    s[0][0] = 0.02;
    s[0][1] = 0.25;
    s[0][2] = 0.75;
    s[0][3] = 0.12;

    printf("===Matriz dada===\n\n");
    for(i=0;i<LIN;i++)
    {
        for(j=0;j<COL; j++)
            printf("%0.4f\t", matriz[i][j]);
        printf("\n");
    }

    printf("\n\n\n");

    for(i=0;i<LIN; i++)
    {
        for(j=0;j<COL;j++)
        {
            matriz00[i][j] = matriz[i][j];
        }
    }
    for(i=0;i<LIN-1; i++)
    {
        printf("=== Elementos da etapa (e=%d) ===\n\n",i+1);
        printf("Calculo para multiplicadores\n");
        for(k=i+1;k<LIN; k++)
        {
            /*encontrar multiplicadores*/
            mult[k] = matriz00[k][i]/matriz[i][i];
            printf("m%d, %d - %f\n",k,i,mult[k]);
        }
        printf("\n\n");

        for(x=i; x<LIN-1; x++)
        {
            printf("Linha L%d(%d)\n", x+1,i+1);
            for(y=0; y<COL; y++)
            {
                matriz00[x+1][y] = matriz[x+1][y]-(mult[x+1]*matriz[i][y]);
                printf("a%d,%d(k=%d)(%f) = a%d,%d(k=%d)(%f)-m%d,%d(%f)*a%d,%d(k=%d)(%f)\n",x+1,y,i+1,matriz00[x+1][y],x+1,y,i,matriz[x+1][y],x+1,i,mult[x+1],x,y,i,matriz[x][y]);
            }
            printf("\n");
        }
        /*igualar a matriz00 a original*/
        for(x=0;x<LIN; x++)
        {
            for(y=0;y<COL;y++)
            {
                matriz[x][y]= matriz00[x][y];
            }
        }


        printf("\n===MATRIZ EXPANDIDA===\n");
        for(w=0;w<LIN;w++)
        {
            printf("\n");
            for(z=0;z<COL;z++)
            {
                if(w<=i+1)
                    printf("%0.4f(%d)\t", matriz[w][z], w);
                else
                    printf("%0.4f(%d)\t", matriz[w][z], i+1);
            }
            printf("\n");

        }

        printf("\n\n\n\n");

    }

    //Calculdo xi^[k], onde i = 1,2,3,4

    for(k=0; k < NITMAX; k++)
    {
        s[k+1][LIN-1] = s[k][LIN-1] + (matriz[LIN-1][LIN] / matriz[LIN-1][LIN-1]);
        for(i=LIN-2; i > -1; i--)
        {
            soma=0.0;
            for(j=i+1; j < LIN; j++)
                soma = soma + matriz[i][j]*s[k][j];
            s[k+1][i] = s[k][i] + (matriz[i][LIN] - soma)/matriz[i][i] ;
        }

    }

    for(k=0; k < NITMAX; k++)
    {
        printf("\nSolucao %d:",k);
        printf("\n");
        for(i=0; i < LIN; i++)
            printf("%0.4f\t", s[k][i]);
        printf("\n");
    }

    return 0;
}

