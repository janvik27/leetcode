class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> mark(n,0);    
        for(int i=0;i<n;i++)                 // traverse each component
        {
            if(mark[i]) continue;          // if already marked then continue
            queue<int> q;
            q.push(i);
            mark[i]=1;
            while(!q.empty())
            {
                int parent=q.front();
                q.pop();
                for(int child:graph[parent])
                {
                    if(mark[child]==0)
                    {
                        mark[child]=-mark[parent];
                        q.push(child);
                    }
                    else
                    {
                        // if parent and child have same mark then return false;
                        if(mark[parent]==mark[child]) 
                            return false;    
                        
                    }
                }
            }

        }
        return true;
    }
};