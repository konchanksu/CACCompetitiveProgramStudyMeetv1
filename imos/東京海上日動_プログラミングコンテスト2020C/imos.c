#include <stdio.h>

#define max(a, b) ((int)(a) > (int)(b) ? (a) : (b))
#define min(a, b) ((int)(a) > (int)(b) ? (b) : (a))

int main(void)
{
    int N, K;
    scanf("%d %d", &N, &K);

    int A[N + 1], lamp[N + 1];
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }

    for(int i = 0; i < min(K, 50); i++)
    {
        for(int j = 0; j < N + 1; j++) { lamp[j] = 0; }
        for(int j = 0; j < N; j++)
        {
            lamp[max(0, j - A[j])] += 1;
            lamp[min(N, j + A[j] + 1)] -= 1;
        }

        for(int j = 1; j < N + 1; j++) { lamp[j] += lamp[j - 1]; }
        for(int j = 0; j < N + 1; j++) { A[j] = lamp[j]; }
    }

    for(int i = 0; i < N; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
