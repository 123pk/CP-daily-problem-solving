/*
Platform :- Leetcode
Approach :- do bfs and mark left node as 1 and right as 0 , if you reach the leaf then add the values of nodes marked to 1 or so called left leave nodes to your total
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
     
    int sumOfLeftLeaves(TreeNode* root) {
        int tot=0;
        if(!root)return tot;
        
        queue<pair<TreeNode*,int>>bfs;
        bfs.push({root,0});
        
        while(!bfs.empty()){
            int c = bfs.size();
            for(int i=0;i<c;++i){
                pair<TreeNode*,int> temp = bfs.front();
                bfs.pop();
                int f=0;
                if(temp.first->left){
                    //tot+=temp->left->val;
                    f=1;
                    bfs.push({temp.first->left,1});
                }
                if(temp.first->right){
                    f=1;
                    bfs.push({temp.first->right,0});
                }
                if(f==0 && temp.second==1){
                    tot+=temp.first->val;
                }
            }
        }
        
        return tot;
    }
};
