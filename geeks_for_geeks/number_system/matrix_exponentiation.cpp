#include<bits/stdc++.h>
using namespace std;
// Iterative version of fast exponentiation to compute power in O(log n)

void store(int res[2][2],int a[2][2])
{
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            res[i][j]=a[i][j];
}
// MAtrix Multiply [a]=[a]*[b]
void multiply(int a[2][2],int b[2][2])
{
    int mult[2][2];
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            mult[i][j]=0;
            for(int k=0;k<2;k++)
                mult[i][j]+=a[i][k]*b[k][j];
        }
    }
    //store the result of [mult] in [a]
    store(a,mult);//[a]<-[mult]
}
//[A]^n and stores it [A]
//Iterative version of binary exponentiation
void matrix_expo(int a[2][2],int n)
{
    //identity matrix
    int res[2][2]={{1,0},{0,1}};
    // Traverse all the bits of the number
    while(n>0)
    {
        if(n&1)//if bit is set
            multiply(res,a);
        multiply(a,a);
        n>>=1;
    }
    store(a,res);
}
int nthFibonacci(int n)
{
    int arr[2][2]={{1,1},{1,0}};
    if(n==0)
        return 0;
    if(n==1)
        return 1;
        matrix_expo(arr,n-1);
    return arr[0][0];
}
int main()
{
    // Objective : Find nth term of Fibonacci in O(log n) time.
    // f(n)=f(n-1)+f(n-2) so 2x2 matrix multiply
   int t,n;
   cin>>t;
   while(t--)
   {
       cin>>n;
       cout<<nthFibonacci(n)<<endl;
   }
}