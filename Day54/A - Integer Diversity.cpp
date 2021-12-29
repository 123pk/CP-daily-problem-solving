/*
Platform :- Codeforces
Contest :- Good Bye 2021: 2022 is NEAR
Approach :- Find the frequency of each element if some element is repeating then we change to negate of it if the negate is note present and at the end the number of
            of unique values is our answer.
*/
#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        int A[n];
        map<int,int>P,Q;
        for(int i=0;i<n;++i){
            cin>>A[i];
            P[A[i]]++;
            Q[A[i]]++;
        }
        int ans=0;
        
        for(auto &x:P){
            ans++;
            if(x.first){
                
                x.second--;
                int val = -x.first;
                if(x.second==0)continue;
                
                if(Q[val]){
                   
                }
                else{
                    Q[val]++;
                     ans++;
                }
            }
            
        }
        
        cout<<ans<<"\n";
    }
}
