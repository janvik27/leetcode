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
    void reverse_iot(TreeNode* root,int &sum)
    {
        if(root==NULL)
            return ;
        
        reverse_iot(root->right,sum);
        sum+= root->val;
        root->val =sum;
        reverse_iot(root->left,sum);
    }
    
    
    TreeNode* convertBST(TreeNode* root) {
        int sum=0;
        reverse_iot(root,sum);
        return root;
    }
};