/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> nodes;
        queue<pair<TreeNode*,pair<int,int>>> q;
        
        // initially, push root in the queue with 0 H.D and 0 level
        q.push({root,{0,0}});
        
        while(!q.empty())
        {
            auto p= q.front();
            q.pop();
            
            TreeNode* node = p.first; // node val
            int x = p.second.first;   // horizontal distance
            int y = p.second.second;  // level
            
            nodes[x][y].insert(node->val);
            if(node->left)
                q.push({node->left,{x-1,y+1}});
            if(node->right)
                q.push({node->right,{x+1,y+1}});
        }
        
        vector<vector<int>> ans;
        
        for(auto p :nodes)
        {
            vector<int> levelnodes;
            for(auto q : p.second)
            {
                levelnodes.insert(levelnodes.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(levelnodes);
        }
        return ans;
    }
};