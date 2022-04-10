class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        int x1,x2;
        int ans=0;
        
        for(auto it:ops)
        {
            if(it=="+")
            {
                x1 = st.top();
                st.pop();
                x2 = st.top();
                st.push(x1);
                st.push(x1+x2);
            }
            
            else if(it=="D")
            {
                x1 = st.top();
                st.push(2*x1);
            }
            
            else if(it=="C")
            {
                st.pop();
            }
            else
            {
                st.push(stoi(it));
            }
        }
        
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        
        return ans;
    }
};