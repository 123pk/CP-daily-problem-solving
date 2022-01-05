
/*
Platform :- Codechef
Contest :- Codechef starters 21 
Approach :- If sum of x and y is even then we need 0 coin else we need 1 coin.
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,x,y;
        cin>>n>>x>>y;
        
        int ans=(x+y)%2;
        
        cout<<ans<<"\n";
    }
}
