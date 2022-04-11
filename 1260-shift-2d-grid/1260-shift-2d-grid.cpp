class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> temp(m,vector<int>(n,0));
        
        for(int r=0;r<m;r++)
        {
            for(int c=0;c<n;c++)
            {
                int newind = ((r*n +c)+k)%(m*n);
                int newr = newind / n;
                int newc = newind % n;
                temp[newr][newc] = grid[r][c];
            }
        }
        return temp;
    }
};