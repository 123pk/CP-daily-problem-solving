/*
Platform :- Codechef
Contest :- Codechef starters 17
Approach :- IF both points are same then 0 , else if the sum%2 of both points are same then we can move in 2 operations else we need 1 operations.
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int x,y,a,b;
        cin>>a>>b>>x>>y;
        
        int z=a+b;
        int zz=x+y;
        
        if(a==x && b==y)cout<<"0\n";
        else if(z%2 != zz%2)cout<<1<<"\n";
        else cout<<2<<"\n";
    }
}
