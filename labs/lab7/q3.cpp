#include <bits/stdc++.h>
using namespace std;
int sum;
vector<int> get_digits(int number)
{
    vector<int> num;
    sum = 0;
    while (number > 0)
    {
        int digit = number % 10;
        sum += digit;
        num.push_back(digit);
        number /= 10;
    }
    return num;
}
bool find_powerful_recur(vector<int> &digits, int s, int index)
{
    if (s == 0)
        return true;
    if (index == 0 && s != 0)
        return false;
    if (digits[index - 1] <= s)
    {
        return find_powerful_recur(digits, s, index - 1) || find_powerful_recur(digits, s - digits[index - 1], index - 1);
    }
    else
        return find_powerful_recur(digits, s, index - 1);
}
bool find_powerful(vector<int> &digits)
{
    sum = sum / 2;
    vector<vector<bool>> dp(digits.size() + 1, vector<bool>(sum + 1, false));
    for (int i = 0; i <= digits.size(); i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (i == 0)
                dp[i][j] = false;
            else if (j == 0)
                dp[i][j] = true;
            else if (digits[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - digits[i - 1]] || dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[digits.size()][sum];
}
int main()
{
    int a, b;
    cin >> a >> b;
    int counter = 0;
    for (int i = a; i <= b; i++)
    {
        vector<int> digits = get_digits(i);
        if (sum % 2)
            continue;
        if (find_powerful(digits))
        {
            counter++;
        }
    }
    cout << counter;
    return 0;
}