#include <stdio.h>

#define LIN 4
#define COL 5

void printmat(float matriz[][COL]);

int main(void)
{
    /* Declaracao de variaveis decisorias*/
    float matriz [LIN][COL] =
    {
        {1.234, 5.331, 1.231, -2.174, 6.456},
        {1.333, 2.346, -4.234, 3.147, 2.502},
        {2.204, -2.021, 6.001, -1.125, -1.101},
        {0.211, 7.126, -0.234, 5.003, -2.115},
    };
    /*indices*/
    int i,j,k,w,x,y,z;

    /*matrizes*/
    float mult[LIN];
    float matriz00[LIN][COL];
    float f[LIN];
    float s[LIN] = {0.02, 0.25, 0.75, 0.12};

    float soma = 0;
    //float pivo;
    float ind;
    // float sum=0;
    float divisor;
    printf("===Matriz dada=== \n");
    printmat(matriz);
    printf("\n\n\n");

    for(i=0;i<LIN; i++)
    {
        for(j=0;j<COL;j++)
        {
            matriz00[i][j] = matriz[i][j];
            for(i=0;i<LIN; i++)
            {
                for(j=0;j<COL;j++)
                {
                    matriz00[i][j] = matriz[i][j];

                }
            }
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
        for(w=0;w<LIN;w++)
        {
            for(z=0;z<COL;z++)
            {
                if(w<=i+1)
                    printf("\t%0.4f(%d)\t", matriz[w][z], w);
                else
                    printf("\t%0.4f(%d)\t", matriz[w][z], i+1);
            }
            printf("\n");
        }

        printf("\n\n\n\n");

    }

    /*Encontrar os valores pra f*/
    printf("===Calculos para F===\n");
    for(i=0;i<LIN; i++)
    {
        f[i]=0;
    }
    //pivo
    /*for(i=0;i<LIN; i++)
      {
    //soma=0;
    for(j=0;j<COL;j++)
    {
    if(i==j)
    pivo=matriz[i][j];
    if(j==5)
    {
    ind=matriz[i][j];
    continue;
    }
    soma+= matriz[i][j];
    sum=soma;
    }
    sum= sum-matriz[i][i];

    f[i]=((ind-sum)/pivo);
    }*/
    /*
       for(i=3; i>-1; i--)
       {
       soma=0;
       pivo=matriz[i][COL]; 
       for(j=4; j>-1; j--)
       {

       if(j==i)
       {
       divisor=matriz[i][j];
       soma+=0;
       }
       else
       soma+=matriz[i][j];
       }
       f[i]=(pivo-soma)/divisor;
       }*/
    for(i=0; i<LIN; i++)
    {
        ind=matriz[i][COL];
        for(j=0; j<COL-1; j++)
        {
            if(i==j)
            {
                divisor=matriz[i][j];
            }
            else
                soma+=matriz[i][j];
        }
        f[i]=(ind-soma)/divisor;
    }
    for(i=0;i<COL-1;i++)
    {
        printf("f%d = %f\n",i,f[i]);
    }

    printf("\n\n");

    printf("Solucao = ( f1;\tf2;\tf3;\tf4 )\n");

    for(j=0;j<10;j++)
    {
        printf("Sf(k = %d) = (",j);
        for(k=0;k<LIN;k++)
        {
            printf("%0.4f",s[k]);
            if(i!=LIN-1)
                printf(";");
            s[k]+=f[k]; 

        }
        printf(")\n\n");

    }
    return 0;

}
void printmat(float matriz[][COL])
{
    int i, j;
    for(i=0;i<LIN;i++)
    {
        for(j=0;j<COL; j++)
        {
            printf("\t%0.4f\t", matriz[i][j]);
        }
        printf("\n");
    }

}

