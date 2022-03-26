class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hs;
        for(int num:nums)
            hs.insert(num);
        
        int longestlength=0;
        
        for(int num:nums)
        {
            if(!hs.count(num-1))
            {
                int currnum= num;
                int currlength= 1;
                
                while(hs.count(currnum+1))
                {
                    currnum+=1;
                    currlength+=1;
                }
                
                longestlength = max(longestlength, currlength);
            }
        }
        return longestlength;
    }
};