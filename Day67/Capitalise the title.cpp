/*
Platform :- Leetcode
Contest :- Leetcode BiWeekly contest 69
Approach :- First find all the stirg perform the operation and return the answer after cummulating both of them.
*/
class Solution {
public:
    string capitalizeTitle(string title) {
        title+=' ';
        vector<string>temp;
        string s="";
        for(int i=0;i<title.size();++i){
            if(title[i]==' '){
                temp.push_back(s);
                s="";
            }
            else{
                s+=title[i];
            }
        }
        
        for(int i=0;i<temp.size();++i){
            if(temp[i].size()<=2){
                for(int j=0;j<temp[i].size();++j){
                    if(temp[i][j]<='Z' && 'A'<=temp[i][j])temp[i][j]+=32;
                }
            }
            else{
                if(temp[i][0]<='z' && 'a'<=temp[i][0])temp[i][0]-=32;
                for(int j=1;j<temp[i].size();++j){
                    if('A'<=temp[i][j] && temp[i][j]<='Z')temp[i][j]+=32;
                }
            }
        }
        
        string ans="";
        
        for(int i=0;i<temp.size();++i){
            ans+=temp[i];
            if(i==temp.size()-1)continue;
            ans+=' ';
        }
        return ans;
    }
};
