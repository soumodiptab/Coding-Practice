#include<bits/stdc++.h>
using namespace std;
const long long int MOD=1e9+7;
void store(long long int res[26][26],long long int a[26][26])
{
    for(int i=0;i<26;i++)
        for(int j=0;j<26;j++)
            res[i][j]=a[i][j];
}
// MAtrix Multiply [a]=[a]*[b]
void multiply(long long int a[26][26],long long int b[26][26])
{
    long long int mult[26][26];
    for(int i=0;i<26;i++)
    {
        for(int j=0;j<26;j++)
        {
            mult[i][j]=0;
            for(int k=0;k<26;k++)
                mult[i][j]=((mult[i][j]%MOD)+((a[i][k]%MOD)*(b[k][j]%MOD))%MOD)%MOD;
        }
    }
    //store the result of [mult] in [a]
    store(a,mult);//[a]<-[mult]
}
void matrix_expo(long long int a[26][26],int n)
{
    long long int res[26][26];
    for(int i=0;i<26;i++)
            res[i][i]=1;
    while(n>0)
    {
        if(n&1)
            multiply(res,a);
        multiply(a,a);
        n>>=1;
    }
    store(a,res);
}
long long int stringmatrix(long long int arr[26][26],int c,int n)
{
    long long int temp[26][26];
    store(temp,arr);
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    matrix_expo(temp,n-1);
    long long int sum=0;
    for(int i=0;i<26;i++)
        sum=(sum+(arr[i][c]%MOD))%MOD;
    return sum;
}
int main()
{
   int t,n;
   char c;
   long long int arr[26][26];
   for(int i=0;i<26;i++)
        for(int j=0;j<26;j++)
            cin>>arr[i][j];
   cin>>t;
   while(t--)
   {
       cin>>c;
       cin>>n;
       cout<<stringmatrix(arr,c-'a',n)<<endl;
   }
}