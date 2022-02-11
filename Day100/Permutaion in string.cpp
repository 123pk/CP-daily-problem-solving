/*
Platform :- Leetcode
Approach :- For each index find the frequency for each character ( 'a' to 'z' ) , Now check in substring of  ( size_of_string1 ) from index [ 0 to n-size_of_string1 ] 
*/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        //sort(s1.begin(),s1.end());
        //sort(s2.begin(),s2.end());
        
        
        vector<int>req(26) , avail(26);
        
        for(int i=0;i<s1.size();++i){
            req[s1[i]-'a']++;
        }
        
        
        vector<vector<int>>temp;
        for(int i=0;i<s2.size();++i){
            avail[s2[i]-'a']++;
            temp.push_back(avail);
        }
        
        int sz = s1.size();
        int f = 0;
        vector<int>at,to;
        for(int i = sz-1;i<s2.size();++i){
            if(i==sz-1){
                at = temp[i];
                f = 0;
                for(int j = 0; j<26 ; ++j){
                    if((at[j])<req[j]){
                        f=1;break;
                    }
                }
                if(f==0)return true;
            }
            else{
                to = temp[i];
                at = temp[i-sz];
                f = 0;
                for(int j = 0; j<26 ; ++j){
                    if((to[j]-at[j])<req[j]){
                        f=1;break;
                    }
                }
                if(f==0)return true;
            }
        }
        
        return false;
    }
};
