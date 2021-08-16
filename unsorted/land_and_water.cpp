#include<bits/stdc++.h>
using namespace std;
int m,n;
int min_val(vector<vector<int>>arr,int i,int j)
{
    if(arr[i][j]==0)
        return 0;
    int top,bottom,right,left;
    top=(i==0)?INT_MAX:arr[i-1][j];
    left=(j==0)?INT_MAX:arr[i][j-1];
    right=(j==n-1)?INT_MAX:arr[i][j+1];
    bottom=(i==m-1)?INT_MAX:arr[i+1][j];
    return 1+min(min(top,left),min(right,bottom));
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    cin>>m>>n;
    vector<vector<int>>arr;
    int temp;
    for(int i=0;i<m;i++){
        vector<int>row;
        for(int j=0;j<n;j++)
        {
            cin>>temp;
            row.push_back(temp);
        }
        arr.push_back(row);
    }
    for(int k=1;k<=m*n;k++)
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                arr[i][j]=min_val(arr,i,j);
    return 0;
}
