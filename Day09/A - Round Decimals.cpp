/*
Platform :- Atcoder
Contest :- Atcoder Beginner Contest 226
Approach:- check the first charcter after '.' and if it is >=5 then increment value before '.' by 1 else print it as it is.
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    double a;
    cin>>a;
    
    string s = to_string(a);
    int f=0,g=0;
    int ans=0;
    for(int i=0;i<s.size();++i){
        if(f){
            if(s[i]>='5'){
                g=1;
            }break;
        }
        else if(s[i]=='.')f=1;
        else{
            ans*=10;
            ans+=(s[i]-'0');
        }
    }
    
    if(g)ans++;
    cout<<ans<<"\n";
}
