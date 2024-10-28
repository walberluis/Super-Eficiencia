//https://www.thehuxley.com/problem/1120

#include <stdio.h>
#include <math.h>

unsigned long long calcularFatorial(int numero) 
{
    if (numero == 0 || numero == 1) 
    {
        return 1;
    } 
    
    else 
    {
        return numero * calcularFatorial(numero - 1);
    }
}

void serieComPrints(int rodada, int valor, int armazenador)
{
    unsigned long long fatorial = calcularFatorial(rodada);
    double DoisNMaisUm = (2*rodada) + 1;
    double raizQuadrada = sqrt(DoisNMaisUm);
    
    double divisaoFinal = (double)fatorial/raizQuadrada;
    
    if(valor == 0)
    {
        return;
    }
    
    else
    {
        printf("%.12lf\n", divisaoFinal);
    }
    
    serieComPrints(rodada - 1, valor - 1, armazenador);
    
    
}

void serie(int rodada, int valor, double armazenador)
{
    
    unsigned long long fatorial = calcularFatorial(rodada);
    double DoisNMaisUm = (2*rodada) + 1;
    double raizQuadrada = sqrt(DoisNMaisUm);

    double divisaoFinal = (double)fatorial/raizQuadrada;
    
    if(rodada == valor + 1)
    {
        printf("S: %.12lf\n", armazenador);
        serieComPrints(valor - 1, valor - 1, armazenador);
        return;
    }
    
    else if(rodada == 0)
    {
        armazenador += 0;
    }
    
    else
    {
        armazenador += divisaoFinal;
    }
    
    serie(rodada + 1, valor, armazenador);
}


int main() 
{
    int valor;
    scanf("%d", &valor);
    
    serie(1, valor, 0);
    
    return 0;
}