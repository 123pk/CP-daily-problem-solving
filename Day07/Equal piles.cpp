/*
Platform :- Topcoder
Contest :- SRM 818
Approach :- sort the array and now itterate through all the unique values from biggest to smallest (descending)order and for current value ,let x = number of value is greater than this 
            and 'k' be the times we have then we can convert min(x,k) values to current value , let 'z' be the total for current value (z = count_of_curr + mix(x,k) ) then ans is max of (ans,z)
*/
#include<bits/stdc++.h>
using namespace std;
 

class  EqualPiles{
    public:
     int equalize(int N, int M, int T){
         vector<long long>A(N);
         map<long long,int>P;
         vector<long long>unq;
         long long val=0;
         for(long long i=0;i<N;++i){
             val = 1;
             val+=(i*i)%M;
             A[i]=val;
             P[A[i]]++;
             if(P[A[i]]==1)unq.push_back(A[i]);
         }
         
         sort(unq.begin(),unq.end());
         int ans=0;
         int big=0;
         for(int i=unq.size()-1;i>=0;--i){
             if(ans==0){
                 ans=P[unq[i]];
             }
             else{
                 ans=max(ans,P[unq[i]]+min(T,big));
             }
             big+=P[unq[i]];
         }
         
         return ans;
        
     }
     
};
/*
int main() {
    int t;
    cin>>t;
    
    while(t--){
     int n,m,y;
     cin>>n>>m>>y;
     
     EqualPiles obj;
     int ans =  obj.equalize(n,m,y);
     cout<<ans<<"\n";
     
    }
}*/
