class Solution {
public:
    bool optimised(string s,string t)
    {
        int l1 = s.length();
        int l2 = t.length();
        
        int count1=0,count2=0;
        string res1="",res2="";
        
        for(int i=l1-1;i>=0;i--)
        {
            if(s[i]=='#')
                count1++;
            else
            {
                if(count1>0)
                    count1--;
                else
                    res1+=s[i];
            }
        }
        for(int i=l2-1;i>=0;i--)
        {
            if(t[i]=='#')
                count2++;
            else
            {
                if(count2>0)
                    count2--;
                else
                    res2+=t[i];
            }
        }
        if(res1 == res2)
            return true;
        else
            return false;
    }
    
    bool backspaceCompare(string s, string t) {
        //BRUTE FORCE
        /*
        stack<char>s1;
        stack<char> s2;
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
        */
        
        // OPTIMISED : WITHOUT STACK
        bool ans = optimised(s,t);
        return ans;
    }
};