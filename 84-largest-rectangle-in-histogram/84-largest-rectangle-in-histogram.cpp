class Solution {
public:
    vector<int> prevsmallerelement(vector<int>arr, int n)
    {
        stack<int> st;
        vector<int> ans(n,-1);
        
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
        
            if(!st.empty())
                ans[i]=st.top();
        
            st.push(i);
        }
        return ans;
    }
    
    vector<int> nextsmallerelement(vector<int>arr,int n)
    {
        stack<int>st;
        vector<int> ans(n,-1);
        
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && arr[st.top()]>= arr[i])
                st.pop();
            
            if(!st.empty())
                ans[i]= st.top();
            st.push(i);
        }
        return ans;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        int n= heights.size();
        
        vector<int> prev(n);
        prev= prevsmallerelement(heights,n);
        
        vector<int> next(n);
        next= nextsmallerelement(heights,n);
        
        int max_area= INT_MIN;
        for(int i=0;i<n;i++)
        {
            //if there is no next smaller element, in that case the next[i] will be boundary
            if(next[i]==-1)
            {
                next[i]=n;
            }
            
            int width= next[i]-prev[i]-1;
            int height= heights[i];
            
            
            int area= width*height;
            
            max_area= max(max_area,area);
        }
        return max_area;
    }
};