/*
Platform :- Codeforces
Contest :- Codeforces Round 222 Div 2
Approach :- We will do bfs as we have connected free cells we will look for (s-k) free cells and mark the remaining 'k' cells as we know remaining (s-k) cells are already connected
*/
#include<bits/stdc++.h>
using namespace std;

/*

The basic approach is to do bfs from any empty cell and visit s-k empty cells now we know that 
these are already connected and mark the remaining cells as new walls 
*/
int main(){
    
   int n,m,k;
   cin>>n>>m>>k;
   
   char ch[n][m];
   pair<int,int> start;
   int d=0;
   for(int i=0;i<n;++i){
       for(int j=0;j<m;++j){
           cin>>ch[i][j];
           if(ch[i][j]=='.'){
               d++;
               start={i,j};
           }
       }
   }
   k=d-k;
   d=0;
   //k--;
   
   //now we will do bfs and visit s-k of free cell and after that we start marking
   // the remaining cells
   queue<pair<int,int>>bfs;
   bfs.push(start);
   set<pair<int,int>>used;
   used.insert(start);
   
   while(!bfs.empty()){
       int c = bfs.size();
       for(int i=0;i<c;++i){
           pair<int,int>temp = bfs.front();
           bfs.pop();
           int x = temp.first;
           int y = temp.second;
           d++;
           //check in four directins and if there is any unvisited empty cell 
           //if already visited s-k cell
           //cout<<d<<" "<<k<<" "<<x<<" "<<y<<"\n";
           if(d>k){
               ch[x][y] = 'X';
           }
           
           
           if((x-1)>=0){
               if(ch[x-1][y]=='.'){
                   if(used.find({x-1,y})==used.end()){
                       used.insert({x-1,y});
                       bfs.push({x-1,y});
                   }
               }
           }
           
           if((x+1)<n){
               if(ch[x+1][y]=='.'){
                   if(used.find({x+1,y})==used.end()){
                       used.insert({x+1,y});
                       bfs.push({x+1,y});
                   }
               }
           }
           
           if((y-1)>=0){
               if(ch[x][y-1]=='.'){
                   if(used.find({x,y-1})==used.end()){
                       used.insert({x,y-1});
                       bfs.push({x,y-1});
                   }
               }
           }
           
           if((y+1)<m){
               if(ch[x][y+1]=='.'){
                   if(used.find({x,y+1})==used.end()){
                       used.insert({x,y+1});
                       bfs.push({x,y+1});
                   }
               }
           }
           
       }
   }
 // cout<<d<<" \n";
   for(int i=0;i<n;++i){
       for(int j=0;j<m;++j){
           cout<<ch[i][j];
       }
       cout<<"\n";
   }
}
