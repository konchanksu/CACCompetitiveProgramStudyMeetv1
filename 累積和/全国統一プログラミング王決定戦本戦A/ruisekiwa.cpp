#include <iostream>
#include <vector>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;

int main()
{
    int n;
    long int ans = 0;
    cin >> n;
    vector<long int> a(n);
    vector<long int> s(n + 1, 0);
    rep(i, n) cin >> a[i];
    rep(i, n) s[i + 1] += s[i] + a[i];

    for(int i = 1; i <= n; i++)
    {
        ans = 0;
        for(int j = 0; j + i <= n; j++)
        {
            ans = max(ans, s[j + i] - s[j]);
        }
        cout << ans << endl;
    }
 
    return 0;
}
