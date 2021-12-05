/*
Platform :- Leetcode
Contest :- Leetcode Contest 270
Approach :- First find path from "startNode" to "root" and "destNode" to "root" now find the LCA ( lowest common ancestor ) , we can reach from "startnode" to LCA using "U" command
            and we will now back track from dest node to LCA adding "L" and "R" commands.
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
    
    void dfs(TreeNode*node,vector<TreeNode*>&path,int& f,int target){
        if(!node)return;
        
        
        
        if(node->val==target){
            f=1;
            path.push_back(node);
            return;
        }
        
        if(f){
            path.push_back(node);
            return ;
        }
        else{
        dfs(node->left,path,f,target);
        dfs(node->right,path,f,target);
        }
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string ans;
        
        // I am planning to find paath from root to startValue and root to destValue
        // I will store the pointer and from startvalue to LCA we will just do U , and from LCA to dest value
        // we will use the L and R
        
        vector<TreeNode*>path1,path2;
        int f=0;
        //dfs(root,path1,f,startValue);
       // f=0;
       // dfs(root,path2,f,destValue);
        
        //we need bfs to find thepaths
        queue<TreeNode*>bfs,bfs2;
        bfs.push(root);
        
        map<TreeNode*,TreeNode*>parent;
        map<TreeNode*,int>count;
        parent[root]=root;
        TreeNode*start = root;
        
        while(!bfs.empty()){
            int c = bfs.size();
            for(int i=0;i<c;++i){
                TreeNode*temp=bfs.front();
                bfs.pop();
                
                if(temp->left){
                    parent[temp->left]=temp;
                    if(temp->left->val==startValue){
                        start=temp->left;
                        f=1;break;
                    }
                    bfs.push(temp->left);
                }
                
                if(temp->right){
                    parent[temp->right]=temp;
                    if(temp->right->val==startValue){
                        start=temp->right;
                        f=1;
                        break;
                    }
                    bfs.push(temp->right);
                }
            }
            if(f)break;
        }
        
        path1.push_back(start);
        count[start]++;
       // cout<<(start->val)<<" "<<parent[start]->val<<" check \n";
        while(parent[start]!=start){
            count[parent[start]]++;
            path1.push_back(parent[start]);
            start=parent[start];
        }
        
        //now find the LCA
      /*  for(auto &x:path1){
            cout<<(x->val)<<" ";
        }
        cout<<"\n";*/
        
        
        //now for path 2
        bfs=bfs2;
      // bfs.clear();
        f=0;
        bfs.push(root);
        
        //map<TreeNode*,TreeNode*>parent;
        parent[root]=root;
        start = root;
        
        while(!bfs.empty()){
            int c = bfs.size();
            for(int i=0;i<c;++i){
                TreeNode*temp=bfs.front();
                bfs.pop();
                
                if(temp->left){
                    parent[temp->left]=temp;
                    if(temp->left->val==destValue){
                        start=temp->left;
                        f=1;break;
                    }
                    bfs.push(temp->left);
                }
                
                if(temp->right){
                    parent[temp->right]=temp;
                    if(temp->right->val==destValue){
                        start=temp->right;
                        f=1;
                        break;
                    }
                    bfs.push(temp->right);
                }
            }
            if(f)break;
        }
         path2.push_back(start);
        while(parent[start]!=start){
            path2.push_back(parent[start]);
            start=parent[start];
        }
        
         TreeNode* lca=NULL;
        
         for(auto &x:path2){
             if(count[x]){
                 lca=x;
               //  cout<<x->val<<" check \n";
                 break;
             }
              
         }
         
        
        
        //now we will mveo to the LCA from start value with U
        // find LCA
        
        
        // now from dest to LCA
         start=path2[0];
        if(start!=lca){
        for(int i=1;i<path2.size();++i){
            
            if(path2[i]->left){
                if(path2[i]->left==start){
                    ans+='L';
                }
               else if(path2[i]->right){
                   if(path2[i]->right==start){
                       ans+='R';
                   }
               } 
            }
            else{
               if(path2[i]->right){
                   if(path2[i]->right==start){
                       ans+='R';
                   }
               }   
            }
            if(path2[i]==lca)break;
            start=path2[i];
            
        }
        }
        
        
        for(auto &x:path1){
            if(lca!=x){
                ans+='U';
            }
            else break;
        }
         
        reverse(ans.begin(),ans.end()); 
        return ans;
    }
};
