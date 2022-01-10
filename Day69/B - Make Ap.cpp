/*
Platform :- Codeforces
Contest :- Codeforces Round 764
Approach :- Try to change each of three and check if any state is AP after changing or not .
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        long long a,b,c;
        cin>>a>>b>>c;
        
        //what if it is a
        long long dif=c-b;
        long long z=b-dif;
         
        if((b-z)==(c-b)  && (z%a==0 && z>0)){
            cout<<"YES\n";
            continue;
        }
        
        dif=b-a;
        z=b+dif;
        if((z-b)==(b-a)  && (z%c==0 && z>0)){
            cout<<"YES\n";
            continue;
        }
        
        dif=c-a;
        dif/=2;
        z=a+dif;
        if((z-a)==(c-z) && (z%b==0 && z>0)){
            cout<<"YES\n";
            continue;
        }
        
        cout<<"NO\n";
                 
    }
}
