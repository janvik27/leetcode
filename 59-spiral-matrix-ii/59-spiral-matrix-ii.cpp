class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int rs=0, re=n-1,cs=0,ce=n-1;
        vector<vector<int>> ans(n,vector<int>(n,0));
        int num=1;
        while(rs<=re && cs<=ce)
        {
            // for row start
            for(int col=cs;col<=ce;col++)
            {
                ans[rs][col] = num;
                num++;
            }
            rs++;
            
            // for col end
            for(int row=rs;row<=re;row++)
            {
                ans[row][ce]=num;
                num++;
            }
            ce--;
            
            //for row end
            for(int col=ce;col>=cs;col--)
            {
                ans[re][col]=num;
                num++;
            }
            re--;

            //for column start
            for(int row=re;row>=rs;row--)
            {
                ans[row][cs]=num;
                num++;
            }
            cs++;
        }
        return ans;
    }
};