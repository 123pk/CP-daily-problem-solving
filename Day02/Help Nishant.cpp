/*
Platform :- Codechef
Contest :- Codechef Snackdown Round 1B
Approach :- If you will carefully analyse you will find that for a given n we need the nearest (x*(x+1))/2 value and answer is 2*x , pre calulate all those values for first 10^5
             values and binary search on them , you can use lower_bound on set that will work as binary search part for you.
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    set<long long>option;
    long long z=1;
    long long val=0;
    map<long long,long long>P;
    for(int i=1;i<=int(1e5);++i){
        val=(z*(z+1))/2;
        option.insert(val);
        P[val]=z;
        z++;
    }
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        
        auto it = option.lower_bound(n);
        //cout<<(*it)<<" check ";
         
        int ans=P[(*it)];
        ans*=2;
        cout<<ans<<"\n";
        
    }
}
