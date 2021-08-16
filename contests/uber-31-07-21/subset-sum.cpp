#include <bits/stdc++.h>                                                

#define endl            "\n"
#define FASTIO          ios_base::sync_with_stdio(false);cin.tie(NULL);
#define int             long long


using namespace std;

const int MOD = 1e9 + 7;
const int N   = 1e5;

void preprocess(){
    return;
}

int inline solve(){
    int N, i, K, n, k;
    
    cin >> N >> K;
    
    int A[N];
    
    for(i = 0; i < N; ++i)
        cin >> A[i];
    
    int dp[K+9][N+9][2];
    
    for(i = 0; i <= K; ++i)
        dp[i][0][0] = dp[i][0][1] = 0;
    
    for(i = 1; i <= N; ++i){
        int idx = A[i-1] & 1;
        dp[1][i][idx]      = A[i-1];
        dp[1][i][1 - idx]  = 0;
        dp[1][i][0]       += dp[1][i-1][0];
        dp[1][i][1]       += dp[1][i-1][1];
    }
    
    for(k = 2; k <= K; ++k){
        for(n = 1; n <= N; ++n){
            if(A[n-1] & 1){
                dp[k][n][0] = A[n-1] * dp[k-1][n-1][1] + dp[k][n-1][0];
                dp[k][n][1] = A[n-1] * dp[k-1][n-1][0] + dp[k][n-1][1];
            }else{
                dp[k][n][0] = A[n-1] * dp[k-1][n-1][0] + dp[k][n-1][0];
                dp[k][n][1] = A[n-1] * dp[k-1][n-1][1] + dp[k][n-1][1];
            }
        }
    }
    
    cout << dp[K][N][0] << endl;
    
    return 0;
}

signed main(){
    FASTIO;
    preprocess();
    int t = 1, i;
    cin >> t;
    for(i=1; i<=t; ++i){
//        cout << "Case #" << i << ": ";
//        cout << 
            solve();
//        cout << endl;
    }
    return 0;
}