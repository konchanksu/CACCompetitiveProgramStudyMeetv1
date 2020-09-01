#include <iostream>
#define ll long long
#define MOD 1000000007
using namespace std;



int main()
{
    int N;
    cin >> N;
    ll A[N];
    ll S[N + 1];
    ll ans = 0;

    for(int i = 0; i < N; i++) cin >> A[i];

    S[0] = 0;
    for(int i = 0; i < N; i++)
    {
        S[i + 1] = S[i] + A[i];
    }

    for(int i = 0; i < N - 1; i++)
    {
        ans += A[i] * ((S[N] - S[i + 1]) % MOD);
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}
