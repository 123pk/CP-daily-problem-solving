/*
Platform :- Topcoder
Contest :- SRM 818
Approach :- First create the array now using sliding window find all the valid subarray of size k and store in vector of pair with values and starting index now find the smallest value
            with smallest index and largest value with largest index and return ans with those indexes.
*/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

bool check(pair<long double,int>&P,pair<long double,int>&Q){
    if(P.first==Q.first)return P.second<Q.second;
    return P.first<Q.first;
}

class  GlobalWarmingCheck{
    public:
     vector <int> solve(int n, int M, int Y){
         vector<long long>A(n);
         long long z;
         for(long long i=0;i<n;++i){
             z = (i*i);
             z+=(4*i);
             z+=7;
             z%=M;
             A[i]=z;
         }
         double zz=Y;
         vector<pair<long double,int>>values;
         long long tot=0;
         for(int i=0;i<Y;++i){
             tot+=A[i];
         }
         
         values.push_back({tot/zz,0});
         for(int i=Y;i<n;++i){
             tot+=A[i];
             tot-=A[i-Y];
             values.push_back({tot/zz,(i-Y)+1});
         }
         
         sort(values.begin(),values.end());
         vector<int>ans;
         int start = values[0].second;
         
         int last = values[values.size()-1].second;
        // long double mx=values[values.size()-1].first;
         for(int i=0;i<values.size();++i){
             if(values[i].first==values[0].first){
                 if(start>values[i].second){
                     start=values[i].second;
                 }
             }
             else{
                 if(values[i].first==values[values.size()-1].first){
                     if(last<values[i].second){
                         last=values[i].second;
                     }
                 }
             }
         }
         ans = {start,last};
         //ans.push_back(last);
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
     
     GlobalWarmingCheck obj;
     vector<int>ans=obj.solve(n,m,y);
     cout<<ans[0]<<" "<<ans[1]<<"\n";
     
    }
}*/
