class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string ans="";
        int i;
        string str="";
        for(i=0;i<s.length();i++)
        {
            if(s[i]==' ')
            {
                if(str!="")
                {
                st.push(str);
                str="";
                }
            }
            else
            {
                str+= s[i];
            }
        }
        if(str!="")
        {
        st.push(str);
        }
        
        while(st.size()!=1)
        {
            string st2= st.top();
            st.pop();
            ans+=st2;
            ans+= " ";
        }
        ans += st.top();
        return ans;
    }
};