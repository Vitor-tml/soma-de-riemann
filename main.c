#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
/***
 *     Autor: Vitor Silva                                                                    
 *     _____                        _        _____ _                       
 *    |   __|___ _____ ___ ___    _| |___   | __  |_|___ _____ ___ ___ ___ 
 *    |__   | . |     | .'|_ -|  | . | -_|  |    -| | -_|     | .'|   |   |
 *    |_____|___|_|_|_|__,|___|  |___|___|  |__|__|_|___|_|_|_|__,|_|_|_|_|
 *                                                                         
 */
float randfloat(float limLow, float limHigh);
float f(float x, int a, int b, int c);

int main()
{
    srand(time(NULL));
    int i;
    int fa, fb, fc; // constantes da função quadrática
    float a, b;
    int n;
    float *xi, dx, soma = 0;
    // Entrada da função quadrática:
    printf("Entre com a, b e c(ax^x + bx + x):\n");
    scanf("%d %d %d", &fa, &fb, &fc);

    // Entrrada dos parâmetros:
    printf("Entre com N: ");
    scanf("%d", &n);
    printf("Entre com a e b: ");
    scanf("%f %f", &a, &b);

    // Inicialização da diferencial e dos indices
    dx = (b - a)/n;
    xi = (float *) malloc((n + 1) * sizeof(float)); // Cria vetor com n + 1 espacos (de x0 até xN)
    for(i = 0; i <= n; i++)
        xi[i] = a + i*dx;

    // Soma de Riemann
    for(i = 1; i <= n; i++)
        soma += f(randfloat(xi[i-1], xi[i]), fa, fb, fc) * dx;  // soma = soma + f(xi*)dx

    // Saída do programa
    printf("A soma e': %f", soma);
    return 0;
}
// f(x) = y
float f(float x, int a, int b, int c)
{   
    float y = a*x*x + b*x + c;
    return y;
}
// Gera um numero aleatório entre [limLow, limHigh]
float randfloat(float limLow, float limHigh)
{
    float n = sin(rand()*rand());   // Gera um númedro de -1 a 1
    n = limLow + (limHigh - limLow) * fabs(n); // Muda o range para de limLow até limHigh
    return n;
}
