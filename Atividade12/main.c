#include <stdio.h>
#include <stdlib.h>

static int retorna_maxAmigos(int *qtdAmigosCaminho, int origem, int nLinhas, int nColunas);
static int max(int a, int b);

int main()
{
    int linha, coluna;
    int n;
    int *qtdAmigosCaminho;
    int qtdCaminhos;
    int maxAmigos;

    scanf("%d %d", &linha, &coluna);
    qtdCaminhos = 2*(linha*coluna - 1);
    qtdAmigosCaminho = (int *)malloc(sizeof(int)*qtdCaminhos);
    if(qtdAmigosCaminho != NULL)
    {
        for(int i = 0; i < qtdCaminhos; i++)
        {
            qtdAmigosCaminho[i] = -1;
        }
    }
    
    n = linha*(coluna - 1) + coluna*(linha - 1);
    for(int i = 0; i < n; i++)
    {
        int origem, destino, nAmigos;
        scanf("%d %d %d", &origem, &destino, &nAmigos);
        if(destino - origem == 1)
        {
            qtdAmigosCaminho[2*origem] = nAmigos;
        }
        else
        {
            qtdAmigosCaminho[2*origem + 1] = nAmigos;
        }
    }
    maxAmigos = retorna_maxAmigos(qtdAmigosCaminho, 0, linha, coluna);
    printf("%d\n", maxAmigos);
    return 0;
}

int max(int a, int b)
{
    return (a > b ? a : b );
}

int _maxAmigos(int *cache, int *qtdAmigosCaminho, int origem, int nLinhas, int nColunas)
{

    if(cache[origem] == -1)
    {
        int res = 0;
        if(origem == nLinhas*nColunas - 1)
        {
            res = 0;
        }
        else if(origem >= (nLinhas - 1)*nColunas)
        {
            if(qtdAmigosCaminho[2*origem] != -1)
            {
                res = qtdAmigosCaminho[2*origem] + _maxAmigos(cache, qtdAmigosCaminho, origem + 1, nLinhas, nColunas);
            }
        }
        else if((origem + 1) % nColunas == 0)
        {
            if(qtdAmigosCaminho[2*origem + 1] != -1)
            {
                res = qtdAmigosCaminho[2*origem + 1] + _maxAmigos(cache, qtdAmigosCaminho, origem + nColunas, nLinhas, nColunas);
            }
        }
        else
        {
            int a = 0;
            int b = 0;
            if(qtdAmigosCaminho[2*origem] != -1)
            {
                a = qtdAmigosCaminho[2*origem] + _maxAmigos(cache, qtdAmigosCaminho, origem + 1, nLinhas, nColunas);
            }
            if(qtdAmigosCaminho[2*origem + 1] != -1)
            {
                b = qtdAmigosCaminho[2*origem + 1] + _maxAmigos(cache, qtdAmigosCaminho, origem + nColunas, nLinhas, nColunas);
            }
            res = max(a,b);
        }
        cache[origem] = res;
    }
    return cache[origem];
}
int retorna_maxAmigos(int *qtdAmigosCaminho, int origem, int nLinhas, int nColunas)
{
    int *cache = (int *)malloc(sizeof(int)*nLinhas*nColunas);
    for(int i = 0; i < nLinhas*nColunas; i++)
    {
        cache[i] = -1;
    }
    int res = _maxAmigos(cache, qtdAmigosCaminho, origem, nLinhas, nColunas);
    free(cache);
    return res;    
}