class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> codes ={
            ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."
        };
        
        unordered_set<string> u;
        for(auto word:words)
        {
            string temp;
            for(auto ch:word)
            {
                temp+= codes[ch-'a'];
            }
            u.insert(temp);
        }
        
        return u.size();
    }
};