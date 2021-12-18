/*
Platform :- Codeforces
Contest :- Codeforces Educational Round 119
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        string s;
        cin>>s;
        
        int n = s.size();
        
        // if there is just 1 N then it is impossible else we always have one array which satisfy the condition
        int c=0;
        for(int i=0;i<(n);++i){
            if(s[i]=='N')c++;
        }
        
        if(c==1)cout<<"NO\n";
        else cout<<"YES\n";
    }
}
