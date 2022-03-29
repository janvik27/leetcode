// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    
    
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int>s;
        
        //step 1: push all the elements in stack
        for(int i=0;i<n;i++)
        {
            s.push(i);
        }
        
        // step 2: take 2 elements from stack and stop when there is only one element left
        while(s.size() > 1)
        {
            int a= s.top();
            s.pop();
            int b= s.top();
            s.pop();
            
            if(M[a][b]==1)
            {
                s.push(b);
            }
            else //in this case, b knows a
            {
                s.push(a);
            }
        }
        
        //step 3: now the single element left in stack is the potential celebrity 
        // so check its row and column to confirm whether its the celebrity
        int candidate= s.top();
        
        //row checking : check whether all are zeroes
        bool rowCheck = false;
        int zeroCount=0;
        for(int i=0;i<n;i++)
        {
            if(M[candidate][i]==0)
            {
                zeroCount++;
            }
        }
        
        if(zeroCount==n)
            rowCheck= true;
            
        //column checking : check whether all are one's
        bool colCheck =false;
        int oneCount=0;
        for(int i=0;i<n;i++)
        {
            if(M[i][candidate]==1)
                oneCount++;
        }
        if(oneCount==n-1)
            colCheck = true;
        
        if(rowCheck==true && colCheck==true)
            return candidate;
        else
            return -1;
        
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
  // } Driver Code Ends