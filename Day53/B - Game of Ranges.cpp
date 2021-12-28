/*
Platform :- Codeforces
Contest :- Codeforces Round 763 Div 2
Approach :- We need to find count of ranges of all the values from ( 1 to n ) , and sort them in increasing order and  we choose the value with min count every time and find the 
            appropriate range.
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
         int n;
         cin>>n;
         
         vector<int>z(n+1);
         int x,y;
         //set<pair<int,int>>Q;
         set<pair<int,int>>P;
         priority_queue<pair<int,int>>Q;
         for(int i=0;i<n;++i){
             cin>>x>>y;
             x--;
             y--;
             P.insert({x,y});
             z[x]++;
             z[y+1]--;
         }
         set<int>val;
         int tot=0;
         for(int i=0;i<n;++i){
             tot+=z[i];
             z[i]=tot;
             val.insert(i);
            // cout<<(i+1)<<" "<<z[i]<<endl;
         }
          
         
         vector<vector<int>>ans;
         
         while(!P.empty()){
             pair<int,int>temp;
             int l = INT_MAX,r=INT_MIN;
             int d=INT_MAX;
             
             for(auto &x:val){
                 if(z[x]<d){
                     temp.first=z[x];
                     d=z[x];
                     temp.second=x;
                 }
             }
             
             for(auto &x:P){
                 if(x.first<=temp.second && temp.second<=x.second){
                     if(x.first<l){
                         l=x.first;
                     }
                     if(x.second>r){
                         r=x.second;
                     }
                 }
             }
            
             ans.push_back({l,r,temp.second});
             P.erase({l,r});
              
             val.erase(temp.second);
              
            
         }
         
         
         for(auto &x:ans){
             for(auto &y:x)cout<<(y+1)<<" ";
             cout<<"\n";
         }
         cout<<"\n";
         
        
    }
}
