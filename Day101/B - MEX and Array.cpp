/*
Platform :- Codeforces
Contest :- Codeforces Global round 19
Approach :- It is optimal to make set of all values of array size 1 in partition , that will give us (no_of_elements_in_segment + (is_zero_present_in_it) ) 
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
        for(int i=0;i<n;++i)cin>>A[i];
        
        long long ans = 0;
        vector<int>count(n);
        for(int i=1;i<=n;++i){
            for(int j=0;j<n;++j){
                
                if((j+i)>n)break;
                
                for(int k=0;k<i;++k){
                    count[j+k]++;
                }
            }
        }
        
        for(int i=0;i<n;++i){
           // cout<<i<<" "<<count[i]<<"\n";
            ans+=count[i];
            if(A[i]==0)ans+=count[i];
        }
        
        cout<<ans<<"\n";
    }
}
