// { Driver Code Starts
//Initial Template for C++

// CPP code to find largest and 
// second largest element in the array

#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
     

class Solution{
  public:
    /* Function to find largest and second largest element
    *sizeOfArray : number of elements in the array
    * arr = input array
    */
    bool isSorted(int sizeOfArray, int arr[]){
        //ascending
        bool flag=true;
        //scan the  array
        for(int i=0;i<sizeOfArray-1;i++)
        {
            if(arr[i]>=arr[i+1])
            {
                flag=false;
                break;
            }
        }
        long long x=1LL;
        return flag;
    }
};

// { Driver Code Starts.

// Driver Code
int main() {
	
	// Testcase input
	int testcases;
	cin >> testcases;
    
    // Looping through all testcases
	while(testcases--){
	    int sizeOfArray;
	    cin >> sizeOfArray;
	    
	    int arr[sizeOfArray];
	    
	    // Array input
	    for(int index = 0; index < sizeOfArray; index++){
	        cin >> arr[index];
	    }
	    Solution obj;
	    bool ans = obj.isSorted(sizeOfArray, arr);
	    cout<<ans<<endl;
	}
	
	return 0;
}  // } Driver Code Ends