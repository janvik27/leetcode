class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        
        if(nums.empty())
            return res;
        int n= nums.size();
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int target2= target-nums[i]-nums[j];
                int left= j+1;
                int right= n-1;
                
                while(left<right)
                {
                    if ((nums[left]+nums[right]) < target2)
                        left++;
                    else if ((nums[left]+nums[right]) > target2)
                        right--;
                    else
                    {
                        vector<int> quad(4,0);
                        quad[0]= nums[i];
                        quad[1]= nums[j];
                        quad[2]= nums[left];
                        quad[3]= nums[right];
                        res.push_back(quad);
                        
                        //now,after finding a quad, we have to move the left                                pointer in such a way that it skips the duplicates of                               quad2
                    while(left<right &&  nums[left]==quad[2])
                        left++;
                    
                    //skipping the duplicates of quad3
                    while(left<right && nums[right]==quad[3])
                        right--;
                    }
                }
                // skipping the duplicates of quad[1] 
            while(j+1 <n && nums[j+1]==nums[j])
                j++;
            }
            
            //skipping the duplicates of quad[0]
            while(i+1 <n && nums[i+1]==nums[i])
                i++;
        }
        return res;
    }
};