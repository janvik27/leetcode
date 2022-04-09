class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        
        // calculating frequency of each element
        for(int i=0;i<nums.size();i++)
        {
            map[nums[i]]++;
        }
        
        priority_queue<pair<int,int>> pq;
        //pushing pair of <frequency,element of nums array> 
        unordered_map<int,int>:: iterator it;
        for(it=map.begin();it!=map.end();it++)
        {
            pq.push(make_pair(it->second,it->first));
        }
        
        vector<int>res;
        while(k--)
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        return res;
    }
};