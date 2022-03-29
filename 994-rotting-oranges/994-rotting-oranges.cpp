class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty())
            return 0;
        int m= grid.size(), n= grid[0].size(), mins=0, total=0, count=0;
        queue<pair<int,int>> rotten;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]!=0)
                    total++;   //counting the total no of oranges in grid
                if(grid[i][j]==2)
                    rotten.push({i,j});  
                // initially, pushing all the rotten oranges into the grid
            }
        }
        
        int dx[4]= {0,0,1,-1};
        int dy[4]= {1,-1,0,0};
        
        while(!rotten.empty())
        {
            int k= rotten.size();
            count+=k;
            
            while(k--)
            {
                int x= rotten.front().first;
                int y= rotten.front().second;
                rotten.pop();
                
                for(int i=0;i<4;i++)
                {
                    int nx= x+dx[i];
                    int ny= y+dy[i];
                    
                    if(nx<0 || ny<0 || nx>=m || ny>=n || grid[nx][ny]!=1)
                        continue;
                    grid[nx][ny]=2;
                    rotten.push({nx,ny});
                }
            }
            if(!rotten.empty())
                mins++;
        }
        return total==count ? mins : -1;
    }
};