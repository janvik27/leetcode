class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int,int> ump;
        
        for(int i=0;i<nums.size();i++)
        {
            // if the pair not found in ump, then simply push the index of                  that element in ump
            if (ump.find(target-nums[i]) == ump.end())
            {
                ump[nums[i]]=i;
            }
            
            //if the corresponding value found in ump, then push the                    indexes in result vector
            else
            {
                res.push_back(i);
                res.push_back(ump[target-nums[i]]);
                return res;
            }
        }
        return res;
    }
};