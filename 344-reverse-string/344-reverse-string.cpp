class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<int>st;
        int l = s.size();
        for(int i=0;i<l;i++)
        {
            st.push(s[i]);
        }
        for(int i=0;i<l;i++)
        {
            s[i]= st.top();
            st.pop();
        }
        
    }
};