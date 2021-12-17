/*
Platform :- Codeforces
Contest :- Codeforces Round 761 Div 2
Approach :- We switch between characters while assigning pritority .
*/
#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int,int>&P,pair<int,int>&Q){
    if(P.second==Q.second)return P.first<Q.first;
    return P.second<Q.second;
}

int main(){
    int t;
    cin>>t;
    
    while(t--){
         string s;
        string p;
        cin>>s>>p;
        
        vector<int>z(26);
        vector<pair<int,int>>temp;
        for(auto &x:s){
            z[x-'a']++;
        }
        
        if(z[0]==0||z[1]==0||z[2]==0){
            sort(s.begin(),s.end());
            cout<<s<<"\n";
            continue;
        }
        
        
        for(int i=0;i<26;++i){
            if(i<=2)temp.push_back({i,1});
            else temp.push_back({i,3});
        }
        
       if(p[0]!='a') temp[0].second=0;
       else{
           temp[p[1]-'a'].second=2;
       }
        
        
        sort(temp.begin(),temp.end(),comp);
        string ans;
        
        for(auto&x :temp){
            for(int i=0;i<z[x.first];++i){
                ans+=char('a'+x.first);
            }
        }
        cout<<ans<<"\n";
        
    }
}
