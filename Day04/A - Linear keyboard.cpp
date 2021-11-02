/*
Platform :- Codeforces
Contest :- Codeforces Round 753 Div 3
Approach :- Store the value of each charter in a vector and now for given string find the adjacent different between values and add to our answer
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        string s,p;
        cin>>s>>p;
        
        vector<int>z(26);
        for(int i=0;i<26;++i){
            z[s[i]-'a']=i+1;
        }
        
        int last=z[p[0]-'a'];
        int ans=0;
        for(int i=1;i<p.size();++i){
            ans+=abs(last-z[p[i]-'a']);
            last=z[p[i]-'a'];
        }
        cout<<ans<<"\n";
    }
}
