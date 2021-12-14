/*
Platform :- Codeforces
Contet :- Codeforces Round 760 Div 3
Approach :- the last character of previous string should be same else there is missing string or one which is removed , we always add the first string to our answer , if we found any
            index where the condition is not satisfied then we add whole string else the last element to our answer.
            Now if the size of string is less than 'n' then we will add the first element remainig number of times in start of string.
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string ans,last;
        for(int i=0;i<n-2;++i){
            string temp;
            cin>>temp;
            
            if(i==0){
                ans+=temp;
            }
            else{
               if(last[1]!=temp[0]){
                   ans+=temp;
               }
               else{
                   ans+=temp[1];
               }
               
            }
            last=temp;
            
        }
        if(ans.size()<n){
            char ch=ans[0];
            int m=ans.size();
            reverse(ans.begin(),ans.end());
            
            for(int i=0;i<(n-m);++i){
               ans+=ch;    
            }
            reverse(ans.begin(),ans.end());
        }
        
        cout<<ans<<"\n";
    }
}
