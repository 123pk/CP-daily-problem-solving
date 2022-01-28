/*
Platform :- Codeforces
Contest :- Codeforces Round 750 Div 2
Approach :- If length is even then we can always do operation on pair of elements (1,2) (3,4) ,  where A[1] = A[2] & A[2] = -A[1] and so on this will given sum of adjacent pairs 
            for to be '0' ,
            If length is odd then we need to find a trio where sum of any two is assign to any one and sum is non zero and other two will get -ve value of this single element
            and for remaining element we do the same we did with the even no of elements.
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
         long long tot=0;
         int f=0;
         long long z = INT_MIN;
         vector<pair<int,int>>P;
         for(int i=0;i<n;++i){
             cin>>A[i];
             P.push_back({A[i],i});
         }
         
        // sort(A,A+n);
         if(n%2){
             f=1;
         }
         
         if(f){
             sort(P.begin(),P.end());
             vector<long long>Q(n);
             long long val = P[0].first+P[1].first;
             if(val){
                 Q[P[0].second] = P[2].first;
                 Q[P[1].second] = P[2].first;
                 Q[P[2].second] = -val;
                 
             }
             else{
                 val = P[1].first+P[2].first;
                 
                 Q[P[0].second] = val;
                 Q[P[1].second] = -P[0].first;
                 Q[P[2].second] = -P[0].first;
             }
              for(int i=3;i<n;i+=2){
                 Q[P[i].second] = (P[i+1].first);
                 Q[P[i+1].second]=(-P[i].first);
             }
             
             for(int i=0;i<n;++i)cout<<Q[i]<<" ";
             cout<<"\n";
         }
         else{
             for(int i=0;i<n;i+=2){
                 cout<<(A[i+1])<<" "<<(-A[i])<<" ";
             }
             cout<<"\n";
         }
         
    }
}
