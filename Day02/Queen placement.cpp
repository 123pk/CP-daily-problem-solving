/*
Platform :- Codechef
Contest :- Codechef Snackdown Round 1B
Approach :- Basic approach is to put N-2 queen on mail diagonal , first queen on top left(1,1) and then from (3,3) to (n,n) put the remaining ones
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
         int n;
         cin>>n;
         
         vector<vector<char>>A(n,vector<char>(n,'.'));
         A[1][1]='Q';
         for(int i=3;i<n;i++){
             A[i][i]='Q';
         }
         for(auto &x:A){
             for(auto &y:x)cout<<y<<"";
             cout<<"\n";
         }
    }
}
