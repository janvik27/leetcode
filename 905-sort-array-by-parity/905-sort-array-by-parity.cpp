class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int size = nums.size();
        int left=0;
        int right = size-1;
        vector<int> res(size,0);
        
        for(int i=0;i<size;i++)
        {
            if(nums[i]%2==0)
            {
                res[left] = nums[i];
                left++;
            }
            else
            {
                res[right] = nums[i];
                right--;
            }
        }
        return res;
    }
};