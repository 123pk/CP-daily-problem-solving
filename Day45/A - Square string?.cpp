/*
Platform :- Codeforces
Contest :- Codeforces Round 762 Div3
Approach :- if the length is odd then the string is not square else we compare the two halfs of string .
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
        if(n%2)cout<<"NO\n";
        else{
            int z = (n/2);
            int f=0;
            
            for(int i=0;i<(n/2);++i){
                if(s[i]!=s[z+i]){
                    f=1;break;
                }
            }
            
            if(f)cout<<"NO\n";
            else cout<<"YES\n";
        }
    }
}
