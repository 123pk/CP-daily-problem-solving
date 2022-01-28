/*
Platform :- Leetcode
Approach :- Do dfs on binary and store in array for both roots then sort the array and return it.
*/
class Solution {
public:
    
    void dfs(TreeNode* node,vector<int>&ans){
        if(!node)return;
        ans.push_back(node->val);
        dfs(node->left,ans);
        dfs(node->right,ans);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>ans;
        
        dfs(root1,ans);
        dfs(root2,ans);
        
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};
