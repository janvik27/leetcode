//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    // ------------- solution using BFS - KAHN'S ALGORITHM
  
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        
        // create indegree vector
        vector<int> indegree(V,0);
        for(int i=0;i<V;i++)
        {
            for(auto j:adj[i])
            {
                indegree[j]++;
            }
        }
        
        // push nodes with indegree=0 in queue
        queue<int> q;
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        
        // do BFS
        int count=0;
        while(!q.empty())
        {
            int front= q.front();
            q.pop();
            
            // inc count
            count++;
            
            // check its neighbours and update their indegrees
            for(auto neighbour : adj[front])
            {
                indegree[neighbour]--;
                if(indegree[neighbour]==0)
                    q.push(neighbour);
            }
        }
        
        if(count==V)
        {
            // means topological sort is valid and no cycle present (acyclic graph)
            return false;
        }
        else
            return true;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends