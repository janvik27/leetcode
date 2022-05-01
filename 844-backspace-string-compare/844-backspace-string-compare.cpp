class Solution {
public:
    stack<char>s1;
    stack<char> s2;
    bool backspaceCompare(string s, string t) {
        
        
        for(int i=0;i < s.length();i++)
        {
            if(s[i]=='#')
            {
                if(!s1.empty())
                    s1.pop();
                else
                    continue;
            }
            else
                s1.push(s[i]);
        }
        for(int i=0;i<t.length();i++)
        {
            if(t[i]=='#')
            {
                if(!s2.empty())
                    s2.pop();
                else
                    continue;
            }
            else
                s2.push(t[i]);
        }
        
        int flag=0;
        while(!s1.empty() && !s2.empty() && s1.size()==s2.size())
        {
            if(s1.top() != s2.top())
            {
                flag=1;
                break;
            }
            else
            {
                s1.pop();
                s2.pop();
            }
        }
        if(flag==1 || s1.size()!=s2.size())
            return false;
        else
            return true;
    }
};