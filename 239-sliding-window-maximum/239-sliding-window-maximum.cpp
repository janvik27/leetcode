class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> ans;
        
        for(int i=0;i<n;i++)
        {
            // remove the out of bound elements, pops dq from front
            if(!dq.empty() && dq.front()== i-k)
                dq.pop_front();
            
            // removes the elements smaller than nums[i] from dq, pops from back
            while(!dq.empty() && nums[dq.back()]<= nums[i])
                dq.pop_back();
            
            dq.push_back(i);
            
            if(i>=k-1)
                ans.push_back(nums[dq.front()]);
            //we are pushing back only when i crosses k-1 bcs, before that, window of size 3 is                 not formed so you cant find the max element. 
            // max element for the first window is found only when i becomes greater than or                    equal to 2
        }
        return ans;
    }
};