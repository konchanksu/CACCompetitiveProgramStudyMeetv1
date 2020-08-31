#include <iostream>
#define rep(i, n) for(int(i) = 0; (i) < int(n); (i)++)
using namespace std;

int main()
{
    int N, Q, i;
    cin >> N >> Q;

    int l, r;
    int A[N + 1], ans = 0;
    rep(i, N + 1) { A[i] = 0; }

    rep(i, Q)
    {
        cin >> l >> r;
        A[l - 1] += 1;
        A[r] -= 1;
    }

    rep(i, N)
    {
        ans += A[i];
        cout << ans % 2;
    }
    cout << endl;

    return 0;
}
