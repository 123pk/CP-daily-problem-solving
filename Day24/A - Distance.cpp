/*
Platform :- Codeforces
Contest :- Codeforces Educational Round 117 Rated for Div 2
Approach :- There are just three cases , if sum of (x,y) is odd then we don't have any solution , else if x==y then we can either put to {x,0} or {0,x} , else
            if(x>y) then we have ((x+y)/2,0) else (0,(x+y)/2)
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int x,y;
        cin>>x>>y;
        
        int d = (x+y);
        if(d%2)cout<<"-1 -1\n";
        else{
            if(x==y){
                cout<<x<<" "<<0<<"\n";
                }else if(x>y){
                    cout<<(d/2)<<" "<<0<<"\n";
                }
                else{
                    cout<<0<<" "<<(d/2)<<"\n";
                }
            
        }
    }
}
