/*
Platform :- Codeforces
Contest :- Codeforces ROund 762 Div 3
Approach :- We need to care of few case and greedily implement , if the digit of 'A' is greater than the digit of 'S' then we have to use two digits of 's' and if we have remaining
            digits in S then we add as it is to our answer.
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
         string a,b;
         cin>>a>>b;
         
         string ans="";
         int f=0;
         
         ///perform the operations 
         reverse(a.begin(),a.end());
         reverse(b.begin(),b.end());
         int j=0;
         for(int i=0;i<a.size();++i){
             if(j==b.size()){
                 f=1;break;
             }
             
             if(a[i]<=b[j]){
                
                  ans+=to_string(b[j]-a[i]);
                  j++;
                
             }
             else{
                 if(j==b.size()-1){
                     f=1;break;
                 }
                 
                 int temp = b[j+1]-'0';
                 if(temp>1){
                     f=1;break;
                 }
                 
                 temp*=10;
                 temp+=(b[j]-'0');
                 
                 if(temp<(a[i]-'0')){
                     f=1;break;
                 }
                 
                 ans+=to_string(temp-(a[i]-'0'));
                 j+=2;
             }
         }
         
         while(j<b.size()){
             ans+=b[j];
             j++;
         }
         reverse(ans.begin(),ans.end());
         
         string temp;
         int g=0;
         for(int i=0;i<ans.size();++i){
             if(g)temp+=ans[i];
             else{
                 if(ans[i]-'0'){
                     g=1;
                     temp+=ans[i];
                 }
             }
         }
         ans=temp;
         
         if(f)cout<<"-1\n";
         else cout<<ans<<"\n";
    }
}
