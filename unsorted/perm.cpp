#include<bits/stdc++.h>
using namespace std;
void permute(string a, int l, int r)  
{  
    // Base case  
    if (l == r)  
        cout<<a<<endl;  
    else
    {  
        // Permutations made  
        for (int i = l; i <= r; i++)  
        {  
  
            // Swapping done  
            swap(a[l], a[i]);  
  
            // Recursion called  
            permute(a, l+1, r);  
  
            //backtrack  
            swap(a[l], a[i]);  
        }  
    }  
} 
void differentFlagPermutations(int X,vector<string> arr)
{
    vector<string> ml;
    ml = arr;   
    for(int i = 0; i < ml.size(); i++)
        cout << ml[i] << " ";
    int count = ml.size();
    for(int z = 0; z < X - 1; z++)
    {
        // Stores all combinations
        // of length z
        vector<string> tmp;  
        // Traverse the array
        for(int i = 0; i < arr.size(); i++)
        {
            for(int k = 0; k < ml.size(); k++)
            {
                if (arr[i] != ml[k])
                {
                     
                    // Generate all
                    // combinations of length z
                    tmp.push_back(ml[k] + arr[i]);
                    count += 1;
                }
            }
        }    
        // Print all combinations of length z
        for(int i = 0; i < tmp.size(); i++)
        {
            cout << tmp[i] << "\n";
        }  
        // Replace all combinations of length z - 1
        // with all combinations of length z
        ml = tmp;
    }
}

int main(){
    string x="hello";
    vector<string> arr={"r","i","d","i"};
    differentFlagPermutations(4,arr);
    //permute(x,0,x.size()-1);
    return 0;
}