#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TAM_VET 10
#define TAM_MAT 10

float epsilon = 0.000000001;
float A[TAM_MAT][TAM_MAT];
float b[TAM_VET];
float x[TAM_VET];
float xn[TAM_VET];

int iter = 0, variaveis = 0, linha, coluna;

int main(){

    float tolerancia = epsilon*2;
    float normaResiduo = epsilon*2;

    printf("\nEscreva a quantidade de variaveis da equacao: ");
    scanf("%d", &variaveis);

    printf("\nEscreva os numeros de cada linha: ");
    for (linha = 0; linha < variaveis; linha++){
        for (coluna = 0; coluna< variaveis; coluna++){
            scanf("%f", &A[linha][coluna]);
        }
    }
    
    printf("\nEscreva o vetor b: ");
    for(linha = 0; linha< variaveis; linha++){
        scanf("%f",&b[linha]);
    }

    for (int i = 0; i < variaveis; i++){
        x[i] = 0;
        xn[i] = 0;
    }
    

    return 0;
}