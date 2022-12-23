//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        /*
        3 DATA STRUCTURES :
        (1) KEY VECTOR
        (2) MST VECTOR
        (3) PARENT VECTOR
        */
        
        vector<int> key(V);
        vector<bool> MST(V);
        vector<int> parent(V);
        for(int i=0;i<V;i++)
        {
            key[i]=INT_MAX;
            MST[i]=false;
            parent[i]=-1;
        }
 
        
        // initially, for source node, key[src]=0 and parent[src]=-1;
        key[0]=0;
        parent[0]=-1;
        
        // start the algo
        
        for(int i=0;i<V;i++)
        {
            // STEP 1 : FIND THE MINI NODE
            int mini = INT_MAX;
            int u;
            
            // mini node = u
            for(int j=0;j<V;j++)
            {
                // consider a node only when the below condition meets
                if(MST[j]== false && key[j]<mini)
                {
                    u=j;
                    mini = key[j];
                }
            }
            
            // STEP 2 : MARK MST[MINI]=TRUE
            MST[u] = true;
            
            // STEP 3 : PROCESS THE ADJACENTS
            for(auto it:adj[u])
            {
                // it[0] will be the neighbour
                // it[1] will be the weight between the node and neighbour
                int neighbour = it[0];
                int weight = it[1];
                
                if(weight < key[neighbour] && MST[neighbour]==false)
                {
                    key[neighbour]=weight;
                    parent[neighbour] = u;
                }
            }
        }
        // ans will be the sum of values of key array
        int ans=0;
        for(int i=0;i<V;i++)
        {
            ans+= key[i];
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends