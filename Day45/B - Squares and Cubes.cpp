/*
Platform :- Codeforces
Contest :- Codeforces Round 762 Div 3
Approach :- We calculate the cubes and square root until they are less than n and insert in set and set size is our answer.
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        long long n;
        cin>>n;
        
        //check the squres
        set<long long>value;
        for(long long i=1;i*i<=n;++i){
            value.insert(i*i);
        }
        
        long long z=2,d=0;
        while(1){
            d = (z*z*z);
            if(d<=n){
                value.insert(d);
            }
            else break;
            z++;
        }
        
        cout<<value.size()<<"\n";
    }
}
