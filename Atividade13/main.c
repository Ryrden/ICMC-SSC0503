#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct _ponto
{
    float x;
    float y;
} PONTO;

//Ordena o vetor de pontos pelo eixo x
static void quickSort(PONTO *vetor, int n);

//Utilizado para ordenar o subvetor de pontos pelo eixo y
static void quickSortY(PONTO *pontos, int n);

// Retorna o menor valor entre a,b
static float min(float a, float b);

// Calcula a distância entre dois pontos
static float calculaDistanciaPontos(PONTO *a, PONTO *b);

// Inicia o algoritmo que calcula a menor distância entre dois pontos de um conjunto de pontos
static float menorDistancia(PONTO *pontos, int n);

// Encontra a menor distância entre dois pontos de um conjunto de pontos de forma quadrática
// Utilizado apenas em pequenos conjuntos de pontos
static float menorDistanciaBruto(PONTO *pontos, int n);

// Faz quase a mesma coisa que a função anterior, mas recebe um limitante (min) que ignora pontos que
// possuem delta y maior que minimo.
static float menorDistanciaBrutoSubvetor(PONTO *pontos, int n, float delta);

// Utilizado para criar uma cópia da faixa de pontos que atende o critério (delta x < d)
static PONTO *cria_subvetor(PONTO *pontos, int tamanho);

// Outras funções auxiliares

// auxiliar da função quickSort
static void _sort(PONTO *vetor, int inicio, int fim);

// auxiliar da função quickSortY
static void _sortY(PONTO *vetor, int inicio, int fim);

// função auxiliar que encontra a faixa de pontos em torno do ponto do meio que tenha distância
// no máximo (delta)
static void _encontraFaixa(PONTO *pontos, int n, float delta, PONTO referencia, int *inicio, int *fim);

// auxiliar da função menorDistancia para ser utilizado na recursão
static float _menorDistancia(PONTO *pontos, int n);

int main()
{
    PONTO *pontos;
    int n;
    float distancia;
    //Leitura dos pontos
    scanf("%d", &n);
    pontos = (PONTO *)malloc(sizeof(PONTO)*n);
    if(pontos != NULL)
    {
        for(int i = 0; i < n; i++)
        {
            scanf("%f %f", &pontos[i].x, &pontos[i].y);
        }
    }

    distancia = menorDistancia(pontos, n);
    free(pontos);
    printf("%f\n", distancia);
    return 0;
}

void _sort(PONTO *vetor, int inicio, int fim)
{
        if(inicio >= fim)
    {
        return;
    }

    int pivot = (inicio + fim)/2;
    float x = vetor[pivot].x;
    int i = inicio;
    int j = fim;
    
    while(1)
    {
        while(vetor[i].x < x)
        {
            i++;
        }
    
        while(vetor[j].x > x)
        {
            j--;
        }
        if(j <= i)
        {
            break;
        }

        PONTO tmp = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = tmp;
        i++;
        j--;
    }
    _sort(vetor, inicio, j);
    _sort(vetor, j + 1, fim);
}

void quickSort(PONTO *vetor, int n)
{
    _sort(vetor, 0, n-1);
}

void _sortY(PONTO *vetor, int inicio, int fim)
{
        if(inicio >= fim)
    {
        return;
    }

    int pivot = (inicio + fim)/2;
    float y = vetor[pivot].y;
    int i = inicio;
    int j = fim;
    
    while(1)
    {
        while(vetor[i].y < y)
        {
            i++;
        }
    
        while(vetor[j].y > y)
        {
            j--;
        }
        if(j <= i)
        {
            break;
        }

        PONTO tmp = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = tmp;
        i++;
        j--;
    }
    _sortY(vetor, inicio, j);
    _sortY(vetor, j + 1, fim);
}

void quickSortY(PONTO *vetor, int n)
{
    _sortY(vetor, 0, n-1);
}

float min(float a, float b)
{
    return (a < b ? a : b);
}

float calculaDistanciaPontos(PONTO *a, PONTO *b)
{
    float dx = a->x - b->x;
    float dy = a->y - b->y;
    return sqrt(pow(dx,2) + pow(dy,2));
}
void _encontraFaixa(PONTO *pontos, int n, float delta, PONTO referencia, int *inicio, int *fim)
{
    int i = 0;
    while(abs(referencia.x - pontos[i].x) < delta)
    {
        i++;
    }
    *inicio = i;
    i = n - 1;
    while(abs(referencia.x - pontos[i].x) > delta)
    {
        i--;
    }
    *fim = i;
}
float _menorDistancia(PONTO *pontos, int n)
{
    float minimo = INFINITY;
    if(n <= 1500)
    {
        return menorDistanciaBruto(pontos, n); 
    }
    else
    {
        int meio = n/2;
        float dE = _menorDistancia(pontos, meio);
        float dD = _menorDistancia(&pontos[meio], meio);
        float d = min(dE, dD);
        if(d < minimo)
        {
            minimo = d;
        }
        int inicio, fim;
        _encontraFaixa(pontos,n, minimo, pontos[meio], &inicio, &fim);
        if(inicio < meio && fim > meio)
        {
            PONTO *subvetor = cria_subvetor(pontos, fim - meio + 1);
            minimo = min(minimo, menorDistanciaBrutoSubvetor(subvetor, fim - meio + 1, minimo));
            free(subvetor);
        }
    }    
    return minimo;
}
float menorDistancia(PONTO *pontos, int n)
{
    if(n > 1500)
    {
        quickSort(pontos, n);
    }    
    return _menorDistancia(pontos, n);   
}

float menorDistanciaBruto(PONTO *pontos, int n)
{
    float delta = INFINITY;
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            float d = calculaDistanciaPontos(&pontos[i], &pontos[j]);
            if(d < delta)
            {
                delta = d;
            }
        }
    }

    return delta;
}



PONTO *cria_subvetor(PONTO *pontos, int tamanho)
{
    PONTO *subvetor = (PONTO *)malloc(sizeof(PONTO)*tamanho);
    if(subvetor != NULL)
    {
        for(int i = 0; i < tamanho; i++)
        {
            subvetor[i].x = pontos[i].x;
            subvetor[i].y = pontos[i].y;
        }
    }
    quickSortY(subvetor, tamanho);
    return subvetor;
}

float menorDistanciaBrutoSubvetor(PONTO *pontos, int n, float delta)
{
    float minimo = delta;
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(abs(pontos[j].y - pontos[i].y) > delta)
            {
                break;
            }
            float d = calculaDistanciaPontos(&pontos[i], &pontos[j]);
            if(d < minimo)
            {
                minimo = d;
            }
        }
    }
    return minimo;
}