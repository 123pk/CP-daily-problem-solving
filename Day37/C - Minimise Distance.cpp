/*
Platform :- Codeforces
Contest :- Codeforces Round 759 
Approach :- Approach create two different arrays to deal with positive and -ve numbers , now sort the values and choose group of 'k' , one with max value is visited last and other
            are visited in any order.
*/
#include<bits/stdc++.h>
using namespace std;

bool comp(pair<long long,long long>&P,pair<long long,long long>&Q){
    if(P.second==Q.second)return P.first<Q.first;
    return P.second<Q.second;
}

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        
        long long mx=0;
        long long A[n];
        vector<long long>B,C;
       // vector<pair<long long,long long>>P;
        for(int i=0;i<n;++i){
            cin>>A[i];
            if(A[i]<0)B.push_back(abs(A[i]));
            else C.push_back(A[i]);
        }
        long long ans=0;
        /*sort(P.begin(),P.end(),comp);
        int d=1;
        
        sort(A,A+n);
        for(int i=0;i<n;++i){
             
            if(d==1){
                ans+=abs(P[i].first);
            }
            
            if(d==k && i<n-1){
                ans+=abs(P[i].first);
                d=0;
            }
            
            if(d>1){
                ans+=abs(P[i].first-P[i-1].first);
            }
            d++;
        }
        
        d=1;
        long long tot=0;
        reverse(P.begin(),P.end());
        
        for(int i=0;i<n;++i){
             
            if(d==1){
                tot+=abs(P[i].first);
            }
            
            if(d==k){
                if(i>=k)tot+=abs(P[i].first);
                d=0;
            }
            else if(i==n-1)tot+=abs(P[i].first);
            
            if(d>1){
                tot+=abs(P[i].first-P[i-1].first);
            }
            d++;
            cout<<tot<<" "<<(i+1)<<"\n";
        }
         
        ans=min(ans,tot);
        */
        
        
        sort(B.begin(),B.end(),greater<long long>());
        sort(C.begin(),C.end(),greater<long long>());
        
        long long tot=0;
        vector<long long>z;
        int m = B.size();
        for(int i=0;i<B.size();i+=k){
            z.push_back(B[i]);
        }
        
        for(int i=0;i<C.size();i+=k){
            z.push_back(C[i]);
        }
        
        sort(z.begin(),z.end());
        for(int i=0;i<z.size();++i){
            if(i==z.size()-1)ans+=z[i];
            else ans+=(z[i]*2ll);
        }
        
        cout<<ans<<"\n";
        
    }
}
