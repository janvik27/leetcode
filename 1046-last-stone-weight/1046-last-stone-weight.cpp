class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n= stones.size();
        priority_queue<int> heap;
        
        for(int i=0;i<n;i++)
        {
            heap.push(stones[i]);
        }
        
        int s1,s2;
        while(n>1)
        {
            s1 = heap.top();
            heap.pop();
            s2 = heap.top();
            heap.pop();
            n-=2;
            
            // if (s1!=s2)
            if(s1 -s2 >0)
            {
                heap.push(s1-s2);
                n+=1;
            }
        }
        if(!heap.empty())
            return heap.top();
        return 0;
    }
};