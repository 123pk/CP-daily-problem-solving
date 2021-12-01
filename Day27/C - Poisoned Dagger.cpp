/*
Platform :- Codeforces
Contest:- Codeforces Educational Round 118
Approach ;- Binary search on values starting from 'h' , and every time you calclate the cummulative poised value you can have for each value and change accordingly
*/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
     int t;
     cin>>t;
     
     while(t--){
         int n;
         long long h;
         cin>>n>>h;
         
         long long A[n];
         for(int i=0;i<n;++i)cin>>A[i];
         
         //full utilised values
         long long tot=0;
         map<long long,int>P;
         set<long long>z;
         for(int i=1;i<n;++i){
             tot+=(A[i]-A[i-1]);
             P[(A[i]-A[i-1])]=tot;
             z.insert((A[i]-A[i-1]));
         }
         
         //why not use binary search
         long long end = h,ans=h;
         long long s=1,e=h;
         long long mid=(s+e)/2;
         while(s<=e){
             //check for current value of end
             long long sum=end;
             int f=0;
             for(int i=1;i<n;++i){
                 if(sum>=h){
                    f=1;break;
                 }
                 sum+=min(end,A[i]-A[i-1]);
                 if(sum>=h){
                    f=1;break;
                 }
             }
           //  cout<<s<<" "<<e<<" "<<end<<" "<<sum<<" "<<mid<<"\n";
             if(f==0){
                 s=end+1;
                 mid=(s+e)/2;
                 end=mid;
                 continue;
             }
             
             ans=min(ans,end);
             e=end-1;
             mid=(s+e)/2;
             end=mid;
             
         }
         
         cout<<ans<<"\n";
     }
}
