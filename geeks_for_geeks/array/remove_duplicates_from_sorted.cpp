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
    void removeDuplicates(int &sizeOfArray, int arr[]){
        //ascending
        //scan the  array
        int j=0;
        for(int i=0;i<sizeOfArray;i++)
        {
            if(arr[j]!=arr[i])
                arr[++j]=arr[i];
        }
        sizeOfArray=j+1;
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
	    obj.removeDuplicates(sizeOfArray, arr);
	    for(int i=0;i<sizeOfArray;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl<<sizeOfArray<<endl;
	}
	
	return 0;
}  // } Driver Code Ends