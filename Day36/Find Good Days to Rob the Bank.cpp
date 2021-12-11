/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 67
Approach :- We will create two array one which store the prefix array of no of continuous days of a non increasing continuous segment for each  index , we will choose those index
            which are having value in prefix and suffix array greater than "time".
*/
class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& A, int time) {
        vector<int>ans;
        int n = A.size();
        vector<int>pref(n),suff(n);
        int c=0,prev = A[0];
        for(int i=0;i<A.size();++i){
            if(A[i]<=prev){
                c++;
            }
            else{
                c=1;
                
            }
            prev=A[i];
            pref[i]=c;
        }
        
        c=0;
        prev=A[n-1];
        //now for suffix do the same
        for(int i=n-1;i>=0;--i){
            if(A[i]<=prev){
                c++;
            }
            else{
                c=1;
                
            }
            prev=A[i];
            suff[i]=c;
        }
        
        for(int i=0;i<n;++i){
            if(min(pref[i],suff[i])>time)ans.push_back(i);
        }
        
        return ans;
    }
};
