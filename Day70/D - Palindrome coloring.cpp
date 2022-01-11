/*
Platform :- Codeforces
Contest :- Codeforces Round 764 Div 3
Approach :- Find no of pairs of equal characters we can make , take count of uniqueue or charactre with odd frequency .
            let x = no of pair
            y = no of unique character 
            if we want 'k' palindrome strings then we need to distribute x/k to each of 'k' .
            then there would be some extraa values if (x%k) if (x%k)*2+y>=k then d=1 and max lenth is (x/k)*2+d
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
         int n,k;
         cin>>n>>k;
         
         
         string s;
         cin>>s;
         
         vector<int>z(26);
         for(int i=0;i<n;++i){
             z[s[i]-'a']++;
         }
          
         /*
         So basic approach is to count no of characters with even length 
         d = no of characters with odd lenght
         if(d>k) ans =0
         */
         
         int ans=1;
         int c=0,d=0;
         for(int i=0;i<26;++i){
             c+=z[i]/2;
             z[i]%=2;
             d+=z[i];
         }
         
          
              
             int zz=c%k;
             zz*=2;
             
             c/=k;
             c*=2;
            
            // ;
             //c*=2;
            // cout<<d<<" "<<zz<<" "<<k<<"\n";
             if((d+zz)>=k )d=1;
             else d=0;
             
            // if(zz>=k)d=1;
             
             ans=max(ans,c+d);
             cout<<ans<<"\n";
          
         
    }
}
