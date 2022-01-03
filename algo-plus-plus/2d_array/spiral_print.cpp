#include<bits/stdc++.h>
using namespace std;
/**
 * @brief Spiral Print of a matrix
 * 
 * @return int 
 */
void spiral_print(vector<vector<int>>array)
{
    int rows=array.size(),col=array[0].size();
    int sr=0,sc=0,er=rows-1,ec=col-1;
    while(sr <= er && sc <= ec)
    {
        // L-> R
        for(int i=sc;i<=ec;i++)
            cout<<array[sr][i]<<" ";
        sr++;
        // U-> D
        for(int i=sr;i<=er;i++)
             cout<<array[i][ec]<<" ";
        ec--;
        // R-> L
        for(int i=ec;i>=sc;i--)
             cout<<array[er][i]<<" ";
        er--;
        // D-> U
        for(int i=er;i>=sr;i--)
             cout<<array[i][sc]<<" ";
        sc++;
    }

}
int main()
{
    vector<vector<int>>array={
        {1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15},
        {16,17,18,19,20},
    };
    spiral_print(array);
    return 0;
}