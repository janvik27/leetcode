class Solution {
public:
    bool isValid(string s) {
        int l= s.length();
        stack<char> st;
        bool ans=true;
        
        for(int i=0;i<l;i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
                st.push(s[i]);
            else if(s[i]==')')
            {
                if(!st.empty() && st.top() =='(')
                {
                    st.pop();
                }
                else
                {
                    ans=false;
                    break;
                }
            }
            else if(s[i]=='}')
            {
                if(!st.empty() && st.top() =='{')
                {
                    st.pop();
                }
                else
                {
                    ans=false;
                    break;
                }
            }
            else if(s[i]==']')
            {
                if(!st.empty() && st.top() =='[')
                {
                    st.pop();
                }
                else
                {
                    ans=false;
                    break;
                }
            }
        }
        if(!st.empty())
        {
            return false;
        }
        else
            return ans;
    }
};