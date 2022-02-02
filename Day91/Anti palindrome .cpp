/*
Platform :- Codechef
Contest :- Codechef Starters 
Approach :- If we have odd length string then we dont' have any solution or if have a character which is more than (n/2) times in our array ,
            else for all case we sort the string and flip the second half of characters.
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
         int n;
         cin>>n;
         
         string s;
         cin>>s;
         
         if(n%2)cout<<"NO\n";
         else{
             vector<int>c(26);
             for(auto &x:s){
                 c[x-'a']++;
             }
             
             int f=0;
             for(int i=0;i<26;++i){
                 if(c[i] >(n/2)){
                     f=1;break;
                 }
             }
             
             if(f)cout<<"NO\n";
             else{
                 vector<pair<int,char>>P;
                 for(int i=0;i<26;++i){
                     if(c[i])P.push_back({c[i],char('a'+i)});
                 }
                 
                 sort(P.begin(),P.end());
                 string ans = "";
                 for(int i=0;i<P.size();++i){
                   for(int j=0;j<P[i].first;++j)ans+=P[i].second;  
                 }
                 
                 string z="";
                 for(int i=n/2;i<n;++i)z+= ans[i];
                 for(int i=(n/2)-1;i>=0;--i)z+= ans[i];
                 cout<<"YES\n";
                 cout<<z<<"\n";
                 
             }
         }
    }
}
