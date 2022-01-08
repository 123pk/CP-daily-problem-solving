/*
Platform :- Leetcode
Contest :- leetcode Bi weekly contest 69
Approach :- There can be two type of string 
          1. both characters are equal , here we use even pairs and add to the string and at the end if we have multiple string with at least one occurence we use any one of them
          2. characters are not equal here we use even pairs only .
*/
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        /*
        approach is to add the equal words first then add the one with reverse approach
        only one of that can be added
        */
        
        map<string,int>P;
        for(int i=0;i<words.size();++i){
            P[words[i]]++;
        }
        
        int ans=0,f=0;
        
        for(auto&x:P){
            if(x.first[0]==x.first[1] && x.second>1){ 
             int val=x.second;
                val-=(x.second%2);
             ans+=(val)*2;
             x.second-=val;
            }
        }
        //cout<<ans<<"\n";
        int g=0;
        //now add the reverse ones
        for(auto &x:P){
            if(x.second==0)continue;
            string z;
            z+=x.first[1];
            z+=x.first[0];
            if(x.first!=z){
                if(P[z]){
                    int val=min(P[z],x.second);
                    x.second-=val;
                    P[z]-=val;
                    ans+=(val*4);
                }
            }
            else{
                if(g)continue;
                g=1;
                ans+=2;
            }
        }
        
        
        return ans;
    }
};
