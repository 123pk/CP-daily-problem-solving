/*
Platform :- Atcoder
Contest :- Atcoder Beginner Contest 230
Approach :- first create a string of repeatative "oxx" of length greater than 10 , now check for given string in this string if present then it is possible else no.
*/
#include<bits/stdc++.h>
using namespace std;


int main(){
    string s;
    cin>>s;
    
    string p,d="oxx";
    p="oxx";
    for(int i=1;i<=9;++i)p+=d;
    
    //now check if that substring is possible or not
    
    int f=0;
    
    for(int i=0;i<=(p.size()-s.size());++i){
        int g=0;
        for(int j=0;j<s.size();++j){
            if(p[i+j]!=s[j]){
                g=1;break;
            }
        }
        if(g==0){
            f=1;break;
        }
    }
    
    if(f)cout<<"Yes\n";
    else cout<<"No\n";
}
