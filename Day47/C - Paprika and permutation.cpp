/*
Platform :- Codeforces
Contest :- Codeforces Round 761 Div 2
Approach :- we run a loop from 1 to n and mark all those which are present in array and we now try to change the remaining values after sorting in increasing order to
            ith with the mod operation , we can do so if the 
            z = (value+1)/2 , if (z-1) is < i then we cannot covert it to that index .else we increment our count. 
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        long long A[n];
        set<long long>unq;
        map<long long,int>P;
        for(int i=0;i<n;++i){
            cin>>A[i];
            P[A[i]]++;
            unq.insert(A[i]);
        }
        
        
        vector<int>used(n+1);
        
        for(int i=1;i<=n;++i){
            if(P[i]){
                used[i]++;
                P[i]--;
                if(P[i]==0)unq.erase(i);
                continue;
            }
        }
        int ans = 0,f = 0;
        long long val = 0;
        for(int i=1;i<=n;++i){
            
            if(used[i])continue;
            auto it = unq.begin();
             val =((*it)+1)/2;
             
                 val--;
                 if(val<(i)){
                     f=1;break;
                 }
                 else {
                     P[*it]--;
                     if(P[*it]==0)unq.erase(unq.begin());
                     ans++;
                 }
        }
        
        if(f)cout<<"-1\n";
        else cout<<ans<<"\n";
        
    }
}
