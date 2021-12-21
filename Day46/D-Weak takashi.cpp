/*
Platfor :- Atcoder
Contest :- Atcoder Beginner Contest 232
Approach :- DP of n*m where dp[i] stores the no of ways to reach there and answer is max value of all . dp[i][j] = max(dp[i-1][j],dp[i][j-1]) + 1 for valid cells 
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
   
   int n,m;
   cin>>n>>m;
   
   vector<vector<int>>grid(n,vector<int>(m));
   char ch[n][m];
   
   for(int i=0;i<n;++i){
       for(int j=0;j<m;++j){
           cin>>ch[i][j];
       }
   }
   
   int ans=1;
   grid[0][0]=1;
   for(int i=0;i<n;++i){
       for(int j=0;j<m;++j){
           if(i==0||j==0){
               if(i==0 && j==0){
                    continue;
               }
               else if(i==0){
                   if(ch[i][j]=='.'){
                       if(grid[i][j-1]){
                           grid[i][j]=1+grid[i][j-1];
                           ans=max(ans,grid[i][j]);
                       }
                       else grid[i][j]=0;
                   }
                   else grid[i][j]=0;
               }
               else{
                   if(ch[i][j]=='.'){
                       if(grid[i-1][j]){
                           grid[i][j]=1+grid[i-1][j];
                           ans = max(ans,grid[i][j]);
                       }
                       else grid[i][j]=0;
                   }
                   else{
                       grid[i][j]=0;
                   }
               }
           }
           else{
               if(ch[i][j]=='.'){
                   if(grid[i-1][j] || grid[i][j-1]){
                       grid[i][j]=max(grid[i-1][j],grid[i][j-1])+1;
                       ans=max(ans,grid[i][j]);
                   }
                   else grid[i][j]=0;
               }
               else grid[i][j]=0;
           }
       }
   }
   
   cout<<ans<<"\n";
}
