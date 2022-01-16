/*
Platform :- Codeforces
Contest :- Codeforces Educational Round 121
Approach :- If there is a pair of adjacent digits whose sum is >=10 then we will change them , starting from end we do this with the first pair we find 
            else there is no such pair then it is optimal to choose the first two digits and replace with sum as this will give the maximum value than can
            be achieved
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        string s;
        cin>>s;
        
        int f=0;
        string ans=s;
        string temp;
        for(int i=s.size()-1;i>0;--i){
            int val=(s[i]-'0')+(s[i-1]-'0');
            if(val>=10){
                temp=to_string(val);
                ans[i]=temp[1];
                ans[i-1]=temp[0];
                f=1;
                break;
            }
        }
        
        if(f==0){
            //reverse(ans.begin(),ans.end());
            ans.erase(ans.begin());
           // reverse(ans.begin(),ans.end());
            int n=s.size();
            int val=(s[0]-'0')+(s[1]-'0');
            temp=to_string(val);
            ans[0]=temp[0];
        }
        cout<<ans<<"\n";
    }
}
