#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
int ks_dp_bup(int wt[], int val[], int index, int cap)
{
    for (int i = 1; i <= index; i++)
    {
        for (int j = 1; j <= cap; j++)
        {

            if (wt[i - 1] <= j)
            {
                dp[i][j] = max(dp[i - 1][j], val[i - 1] + dp[i - 1][j - wt[i - 1]]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[index][cap];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, weight;
    cin >> n >> weight;
    dp = vector<vector<int>>(n + 2, vector<int>(weight + 2, 0));
    int prices[n], pieces[n];
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> pieces[i];
    }
    cout << ks_dp_bup(prices, pieces, n, weight);
    return 0;
}