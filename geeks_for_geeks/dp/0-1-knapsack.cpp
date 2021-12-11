#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<vector<int>> dp;
    int ks_recur(int wt[], int val[], int n, int index, int cap)
    {
        if (index == -1 || cap == 0)
            return 0;
        if (wt[index] <= cap) //current weight is within capacity
        {
            //we can take or leave current item - so choose profit among the rest
            return max(
                (val[index] + ks_recur(wt, val, n, index - 1, cap - wt[index])),
                ks_recur(wt, val, n, index - 1, cap));
        }
        else
        {
            return ks_recur(wt, val, n, index - 1, cap);
        }
    }
    int ks_recur_dp(int wt[], int val[], int n, int index, int cap)
    {
        if (dp[index][cap] != -1)
        {
            return dp[index][cap];
        }
        if (wt[index] <= cap) //current weight is within capacity
        {
            //we can take or leave current item - so choose profit among the rest
            dp[index][cap] = max(
                (val[index] + ks_recur(wt, val, n, index - 1, cap - wt[index])),
                ks_recur(wt, val, n, index - 1, cap));
            return dp[index][cap];
        }
        else
        {
            dp[index][cap] = ks_recur(wt, val, n, index - 1, cap);
            return dp[index][cap];
        }
    }
    int ks_dp_bup(int wt[], int val[], int n, int index, int cap)
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

public:
    /**
     * @brief driver to the different approaches
     * 
     * @param W Weight
     * @param wt - contains the weight of all items 
     * @param val - contains the value of all items
     * @param n -total no
     * @return int 
     */
    int
    knapSack(int W, int wt[], int val[], int n)
    {
        dp = vector<vector<int>>(n + 2, vector<int>(W + 2, -1));
        for (int i = 0; i < W; i++)
        {
            dp[0][i] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = 0;
        }
        return ks_recur_dp(wt, val, n, n, W);
    }
};
int main()
{
    int wt[] = {};
    int val[] = {};
    Solution s;
    return 0;
}