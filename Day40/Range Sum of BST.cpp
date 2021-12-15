/*
Platform :- Leetcode
Approach :- we do dfs on tree and check if node value is in range of low and high the add to sum.
*/
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
    
    void find(TreeNode*node, int low,int high,int &tot){
        if(!node)return;
        
        if(low<=node->val && node->val<=high)tot+=node->val;
        
        find(node->left,low,high,tot);
        find(node->right,low,high,tot);
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans = 0;
        find(root,low,high,ans);
        
        return ans;
    }
};
