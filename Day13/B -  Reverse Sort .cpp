/*
Platform :- Codeforces
Contest :- Codeforces Round 754
Approach :- If you will analyse the problem you will find that the value if the sorted string is not equal to given string then we can make them equal in just one move . So we will
            add all the index where the s[i] is not equal to sorted string value.
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
        
        int j=0;
        vector<int>one;
        for(int i=0;i<n;++i){
            if(s[i]=='1')one.push_back(i+1);
        }
        string z=s;
        
        sort(z.begin(),z.end());
        
        vector<int>used(n);
        vector<vector<int>>ans;
        vector<int>temp;
        for(int i=n-1;i>=0;--i){
            if(s[i]!=z[i] && used[i]==0){
                temp.push_back(i+1);
            }
            
        }
        if(temp.size()){
            sort(temp.begin(),temp.end());
            ans.push_back(temp);
        }
        
        cout<<ans.size()<<"\n";
        for(int i=0;i<ans.size();++i){
            cout<<ans[i].size()<<" ";
            for(auto &x:ans[i])cout<<x<<" ";
            cout<<"\n";
        }
        
    }
}
