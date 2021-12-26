/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 273
Approach :- Do Bruteforce and for each value find the max no of operations that can be performed
*/
class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& x, string s) {
       int m = s.length();
        vector<int>ans(m);
        set<pair<int,int>>vis;
        int d=0;
        for(int i=0;i<m;++i){
            //start from start pos
            int start=x[0],end=x[1];
            vis.clear();
            vis.insert({x[0],x[1]});
            int j=i;
            d=0;
         //   cout<<(i+1)<<"\n";
            while(j<m){
                if(s[j]=='L'){
                    if((end-1)<0)break;
                    d++;
                    end--;
                }
                else if(s[j]=='R'){
                    if((end+1)>=n)break;
                    end++;
                    d++;
                }
                else if(s[j]=='D'){
                    if((start+1)>=n)break;
                    d++;
                    start++;
                }
                else{
                    if((start-1)<0)break;
                    d++;
                    start--;
                }
                j++;
               // cout<<start<<" "<<end<<"\n";
            }
            ans[i]=d;
        }
        
        return ans;
    }
};
