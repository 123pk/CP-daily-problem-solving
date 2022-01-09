/*
Platform :- Leetcode
Approach:- Find all the values in row and store in set if set size != n return false do this for all rows then for all colummns
*/
class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        set<int>temp;
      //  cout<<n<<"\n";
        for(int i=0;i<n;++i){
            temp.clear();
            for(int j=0;j<n;++j){
             ///   cout<<matrix[i][j]<<" ";
                temp.insert(matrix[i][j]);
            }
           // cout<<"\n";
            if(temp.size()<n)return false;
        }
        
        for(int j=0;j<n;++j){
            temp.clear();
            for(int i=0;i<n;++i){
                temp.insert(matrix[i][j]);
            }
            if(temp.size()<n)return false;
        }
        
        
        return true;
    }
};
