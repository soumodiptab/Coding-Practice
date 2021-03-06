/**
 * @file sieve.cpp
 * @author Soumodipta Bose (sbose2019@gmail.com)
 * @brief 
 * @version 1.0
 * @date 2021-11-30
 * 
 * @copyright Copyright (c) 2021
 *  The idea is to create a boolean array of size n+1
 */
#include <bits/stdc++.h>
#define MAX 1e9 + 7
#define long long long int
using namespace std;

vector<bool> is_prime;
vector<long> prime;
void sieve_init(long n)
{
    is_prime = vector<bool>(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    //for every number less than square root of n
    for (int i = 2; i * i <= n; i++)
    {
        // if number if a prime
        if (is_prime[i])
        {
            prime.push_back(i);
            //mark each of its multiple as false {optimization -> start from i*i instead of 2*i}
            for (int j = 2 * i; j <= n; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
}
int main()
{
    int val = MAX;
    cout << val;
    return 0;
}