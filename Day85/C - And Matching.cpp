/*
Platform :- Codeforces
Contest :- Codeforces Round 768 Div 2
Approach :- The maximum value possible for a given 'n' is "sum of even terms till  0+2+4+...n-2",
             for values less than (n-1) we can always make first pair with (n-1,k) and other be greedily such that their sum is 0.
             For values >=(n-1) , we try by making the maximum value possible which is' [ val = min( k-k%n , n-2) ]' then we try val-2 and so on till the value 
             of 'k' is not '0' we have handle the case of '1' carefully.
             After acheiving the sum if we have some values left then we try to map with them the highest values which will result in '0' when we do bitwise and.
            
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        
        int lim = (n/2)-1;
        int val = ((lim-1)*2 + 4)*lim;
        val/=2;
        
        if(val<k)cout<<"-1\n";
        else{
            
            if(k<(n-1)){
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
            continue;
            }
            
            set<int>avail;
            for(int i=0;i<n;++i)avail.insert(i);
           
             
               
            int d = k-(k%2);
            d = min(d,n-2);
            
            while(k){
               avail.erase(d+1);
               avail.erase(d);
               cout<<(d+1)<<" "<<d<<"\n";
               k-=d;
               d-=2;
               if(k==1){
                   auto it = avail.rbegin();
                   cout<<(*it)<<" "<<1<<"\n";
                   avail.erase(*it);
                   avail.erase(1);
                   k=0;
               }
               else{
                   d = min(d,k-(k%2));
               }
               
            }
            
            string ss;
           // for(auto &x:avail)cout<<x<<" ";
          //  cout<<" -- >\n";
            while(avail.size()){
                auto it = avail.rbegin();
                int some = 0;
                string temp = bitset<16>(*it).to_string();
                int f=0;
                ss="";
                for(int i=0;i<16;++i){
                    if(f){
                        if(temp[i]=='0')ss+='1';
                        else ss+='0';
                    }
                    else {
                        if(temp[i]=='1')f=1;
                    }
                }
                
                reverse(ss.begin(),ss.end());
                for(int i=0;i<ss.size();++i){
                    if(ss[i]=='1')some+=(1<<i);
                }
                
                auto it2 = avail.lower_bound(some);
                if((*it2)>some || (*it2)==(*it))it2--;
                cout<<(*it)<<" "<<(*it2)<<"\n";
                avail.erase(*it);
                avail.erase(*it2);
            }
        }
    }
}
