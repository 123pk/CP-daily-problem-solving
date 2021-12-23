/*
Platform :- Codeforces
Contest :- Codeforces Round 762 Div 3
Approach :- For each value from 0 to n , cost of getting mex equal to 'i' is ( cost[i-1] + count [ i ] ) , where cost[i-1] is the cost required till i-1 for mex
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long


int32_t main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        int A[n],f=0;
        set<int>P;
        vector<int>count(n+1);
        vector<int>used(n+1);
        for(int i=0;i<n;++i){
            cin>>A[i];
            if(count[A[i]]){
                P.insert(A[i]);
                used[A[i]]++;
            }
            
            count[A[i]]++;
            
        }  
        sort(A,A+n);
        vector<int>ans(n+1);
       
        int cost=0;
         for(int i=0;i<n;++i){
            if(f)ans[i]=-1;
            else{
                if(i==0){
                  if(A[i]!=0){
                      ans[i]=0;
                      f=1;
                  }    
                  else{
                      ans[i]=count[i];
                       
                      
                  }
                  continue;
                }
                
                ans[i]=cost+count[i];
                
        
                
                if(count[i]==0){
                    
                    
                    if(P.size()==0){
                        f=1;
                        continue;
                    }
                    
                    auto it  = P.lower_bound(i);
                    
                    if(it==P.begin()){
                        int val = *it;
                        if(val>i)f=1;
                        else{
                            used[val]--;
                            if(used[val]==0){
                                P.erase(val);
                            }
                            cost+=(i-val);
                        }
                    }
                    else{
                         it--;
                        int val = *it;
                            used[val]--;
                            if(used[val]==0){
                                P.erase(val);
                            }
                            cost+=(i-val);
                        
                         
                    }
                }
       
            }
         }
      
        if(f)ans[n]=-1;
        else ans[n]=cost+count[n];
        
        for(auto &x:ans)cout<<x<<" ";
        cout<<"\n";
    }
}
