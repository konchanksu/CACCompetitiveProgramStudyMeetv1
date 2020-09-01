#include <stdio.h>
#define MOD 1000000007

int main(void)
{
    int N;
    scanf("%d", &N);

    long A[N];
    long long S[N + 1];
    long long ans = 0;
    for(int i = 0; i < N; i++) { scanf("%ld", &A[i]); }

    S[0] = 0;
    for(int i = 0; i < N; i++) { S[i + 1] = S[i] + A[i]; }

    for(int i = 0; i < N - 1; i++) {
        ans += (A[i] * ((S[N] - S[i + 1]) % MOD));
        ans %= MOD;
    }

    printf("%lld\n", ans);

    return 0;
}
