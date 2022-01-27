#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        
        int lim = (n/2)-1;
        int val = ((lim-1)*2 + 4)/2;
        val*=lim;
        if(k>val)cout<<"-1\n";
        else{
            int z = n/2;
            vector<pair<int,int>>temp;
            temp.push_back({0,n-1});
            int val = n-2;
            int d=1;
            for(int i=1;i<z;++i){
                temp.push_back({val,d});
                val--;
                d++;
            }
            
            for(int i=0;i<temp.size();++i){
                if(temp[i].first==k){
                    swap(temp[i].first,temp[0].first);
                }
                else{
                    if(temp[i].second==k){
                        swap(temp[i].second,temp[0].first);
                        break;
                    }
                }
            }
            for(auto &x:temp)cout<<x.first<<" "<<x.second<<"\n";
        }
    }
     
}
