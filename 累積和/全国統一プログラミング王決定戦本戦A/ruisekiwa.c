#include <stdio.h>
#define max(a, b) (((a) > (b)) ? a : b)

int main(void)
{
    int N;
    scanf("%d", &N);

    long A[N], S[N + 1];
    long maxNum;
    for(int i = 0; i < N; i++) { scanf("%ld", &A[i]); }

    S[0] = 0;
    for(int i = 0; i < N; i++) {S[i + 1] = A[i] + S[i]; }

    for(int k = 1; k < N + 1; k++)
    {
        maxNum = 0;
        for(int i = 0; i < N + 1 - k; i++)
        {
            maxNum = max(maxNum, S[i + k] - S[i]);
        }
        printf("%ld\n", maxNum);
    }

    return 0;
}
