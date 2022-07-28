class Solution {
    
    private:
    void recursion(int index, vector<int> &nums, vector<vector<int>> &ans)
    {
        // base case
        if(index == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        
        for(int i=index;i<nums.size();i++)
        {
            swap(nums[index],nums[i]);
            recursion(index+1,nums,ans);
            swap(nums[index],nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        recursion(0,nums,ans);
        return ans;
    }
};