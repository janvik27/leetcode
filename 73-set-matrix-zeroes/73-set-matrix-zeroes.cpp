class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows= matrix.size();
        int cols = matrix[0].size();
        int col0 = true;
        
        int i,j;
        for(i=0;i<rows;i++)
        {
            if(matrix[i][0]==0)
                col0 = false;
            for(j=1;j<cols;j++)
            {
                if(matrix[i][j]==0)
                    matrix[i][0] = matrix[0][j]=0;
            }
        }
        
        //traversing from the back
        for(i=rows-1;i>=0;i--)
        {
            for(j=cols-1;j>=1;j--)
            {
                if(matrix[i][0]==0 || matrix[0][j]==0)
                    matrix[i][j]=0;
            }
            if(col0 ==false)
                matrix[i][0] = 0;
        }
        
    }
};