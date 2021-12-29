/*
Platform :- Codeforces
Contest :- Good Bye 2021: 2022 is NEAR
Approach :- Take care of cases like "CBBA" , here we will take continue characters that are same.
*/
#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        string s;
        cin>>s;
        
        string ans="";
        int d=n/2;
       
        
        char ch=s[0];
        int f=0;
        for(int i=0;i<n;++i){
            if(i==0){
                ch=s[i];
                ans+=s[i];
            }
            else{
                if(ch>s[i]){
                    ans+=s[i];
                    ch=s[i];
                    f=1;
                }
                else{
                    if(ch==s[i] && f){
                        ch=s[i];
                        ans+=s[i];
                    }
                    else break;
                } 
            }
        }
        cout<<ans;
        for(int i=ans.size()-1;i>=0;--i)cout<<ans[i];
        cout<<"\n";
    }
}
