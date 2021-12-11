#include <bits/stdc++.h>
using namespace std;
#define LONG long long int
const LONG MOD = 1e9 + 7;
int main()
{
    LONG n;
    cin >> n;
    vector<LONG> dp;
    dp = vector<LONG>(n + 1, 0);
    dp[0] = dp[1] = 1;
    for (LONG i = 2; i <= n; i++)
    {
        for (LONG j = 0; j < i; j++)
        {
            dp[i] = (dp[i] + (dp[j] * dp[i - j - 1]) % MOD) % MOD;
        }
    }
    cout << dp[n];
    return 0;
}