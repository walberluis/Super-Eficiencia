// https://www.thehuxley.com/problem/3735

#include <stdio.h>

void pontuacaoDeAs(char nome[], int tamDaPalavra, int estouNessaLetra, int armazenador, int walber[])
{
    
    if(estouNessaLetra >= tamDaPalavra) //10 e tamanho ? 9: para o codigo
    {
        printf("%d", armazenador);
        return;
    }
    
    else if(nome[estouNessaLetra] == 'a')
    {
        
        if(nome[estouNessaLetra - 1] == 'i')
        {
            if(walber[estouNessaLetra - 1] == 2) //visitei, logo ignora
            {
                armazenador += 1;
                walber[estouNessaLetra] = 1;
                return pontuacaoDeAs(nome, tamDaPalavra, estouNessaLetra + 1, armazenador, walber);
            }
            
            else if(walber[estouNessaLetra - 1] == 1) //n?o visitei
            {
                armazenador += 2;
                walber[estouNessaLetra] = 1;
                return pontuacaoDeAs(nome, tamDaPalavra, estouNessaLetra + 1, armazenador, walber);
            }
        }
        
        else if(nome[estouNessaLetra + 1] == 'i')
        {
            armazenador += 2;
            walber[estouNessaLetra] = 1; // visitei
            walber[estouNessaLetra + 1] = 2; // visitei o proximo i
            return pontuacaoDeAs(nome, tamDaPalavra, estouNessaLetra + 2, armazenador, walber);
        }
        
        else
        {
            walber[estouNessaLetra] = 1;
            armazenador += 1;
            return pontuacaoDeAs(nome, tamDaPalavra, estouNessaLetra + 1, armazenador, walber);
        }
    }
    
    else if(nome[estouNessaLetra] != 'a')
    {
        walber[estouNessaLetra] = 1;
        armazenador += 0; //s? para lembrar
        return pontuacaoDeAs(nome, tamDaPalavra, estouNessaLetra + 1, armazenador, walber);
    }
    
}

int main() 
{
    char nome[20];
    fgets(nome, sizeof(nome), stdin);
    int tamDaPalavra;
    int tamanho = 0;
    
    for(int i = 0; i< 20; i++)
    {
        if(nome[i] == '\0')
        {
            break;
        }
        
        else
        {
            tamanho += 1;
        }
    }
    
    //printf("Tamanho da palavra = %d\n", tamanho);
    
    
    int walber[20] = {0};


    pontuacaoDeAs(nome, tamanho, 0, 0, walber);

    return 0;
}
