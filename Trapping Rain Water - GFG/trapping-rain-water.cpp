// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        /* BRUTE FORCE
        long long totalwater=0;
        for(int i=0;i<n;i++)
        {
            int j=i;
            int leftmax=0, rightmax=0;
            while(j>=0)
            {
                leftmax = max(leftmax,arr[j]);
                j--;
            }
            j=i;
            while(j<n)
            {
                rightmax= max(rightmax,arr[j]);
                j++;
            }
            totalwater += min(leftmax,rightmax) - arr[i];
        }
        return totalwater;
        */
        
        // 2ND APPROACH : PREFIX AND SUFFIX
        long long totalwater=0;
        int prefix[n], suffix[n];
        
        prefix[0]= arr[0];
        suffix[n-1]= arr[n-1];
        
        for(int i=1;i<n;i++)
        {
            prefix[i]= max(prefix[i-1], arr[i]);
        }
        
        for(int i=n-2;i>=0;i--)
        {
            suffix[i]= max(suffix[i+1],arr[i]);
        }
        
        for(int i=0;i<n;i++)
        {
            totalwater += min(prefix[i],suffix[i]) -arr[i];
        }
        
        return totalwater;
        

    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends