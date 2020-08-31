#include <stdio.h>

int main(void)
{
    int N, Q;

    scanf("%d %d", &N, &Q);
    int A[N + 1];
    int tmpl, tmpr;
    int ans = 0;

    for(int i = 0; i < N; i++)
    {
        A[i] = 0;
    }

    for(int i = 0; i < Q; i++)
    {
        scanf("%d %d", &tmpl, &tmpr);
        A[tmpl - 1] += 1;
        A[tmpr] -= 1;
    }

    for(int i = 0; i < N; i++)
    {
        ans += A[i];
        printf("%d", ans % 2);
    }
    printf("\n");

    return 0;
}
