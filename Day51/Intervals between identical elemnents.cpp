/*
Platform :- Leetcode
Contest :- Leetcode weekly contest 273
Approach :- I messed up in this problem ,my fomuale is bit messy.
            First I found diff array for each value , where dif[i] contains difference in index between two consecutive similar values,
            then I found prefix sum array of it and the suffix sum of this prefix sum array
            similary I found suffix sum array of it and the prefix sum of this suffix sum array
            then for firt element the ans[i]  = first element of suffix_prefix[ arr[i] ][0]
            and for last element the ans[i] = last element of prefix_suffix[ arr[i] ][ size-1 ]
            then for all other values ans[i]  =  ( suf_pref[arr[i]][j]-(pref[arr[i]][j-1]*sz) )  + (pre_suf[arr[i]][j-1]-(suff[arr[i]][j]*j));
*/
class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        int n=arr.size();
        
        vector<long long>ans(n);
        //I need 5 map 
        // one to store the pref sum
        // one to store the suff sum of diff
        //one to store suff of pref sum
        // one to store pref of suf sum
        // one to store the diff array
        
        map<int,vector<int>>P;
        for(int i=0;i<arr.size();++i){
            P[arr[i]].push_back(i);
        }
        
        //now we will create the diff array
        for(auto &x:P){
            int last=0,temp=0;
            last=x.second[0];
            for(int i=0;i<x.second.size();++i){
                temp=x.second[i];
                x.second[i]=x.second[i]-last;
                last=temp;
            }
        }
        
        
        //Now I will create one pref array and one suff array for these values
        unordered_map<int,vector<long long>>pref,suff;
        unordered_map<int,vector<long long>>suf_pref ,pre_suf;
        
        long long tot=0;
        for(auto &x:P){
            tot=0;
            for(int i=1;i<x.second.size();++i){
                tot+=x.second[i];
                pref[x.first].push_back(tot);
            }
            
            //now for suff
            tot=0;
            for(int i=x.second.size()-1;i>0;--i){
                tot+=x.second[i];
                suff[x.first].push_back(tot);
            }
            reverse(suff[x.first].begin(),suff[x.first].end());
            
        }
        
        
        //now we create suf_pref  and pre_suf
        //firs suf_pref
        for(auto &x:pref){
            tot=0;
            for(int i=x.second.size()-1;i>=0;--i){
                tot+=x.second[i];
                suf_pref[x.first].push_back(tot);
            }
            
        }
        
        //now we find pre_suf
        for(auto &x:suff){
            
            tot=0;
            for(int i=0;i<x.second.size();++i){
                tot+=x.second[i];
                pre_suf[x.first].push_back(tot);
            }
        }
        for(auto &x:suf_pref){
            reverse(x.second.begin(),x.second.end());
            
        }
    /*    //let us check suf_pref
        
        
        for(auto &x:pre_suf){
           // reverse(x.second.begin(),x.second.end());
            cout<<x.first<<" --> ";
            for(auto&y:x.second)cout<<y<<" ";
            cout<<"\n";
        }*/
        map<int,int>count;
        
         for(int i=0;i<n;++i){
          if(count[arr[i]]==0){
              if(suf_pref[arr[i]].size()==0)ans[i]=0;
              else ans[i]=suf_pref[arr[i]][0];
          }  
          else if(count[arr[i]]==pre_suf[arr[i]].size()){
              ans[i]=pre_suf[arr[i]][pre_suf[arr[i]].size()-1];
          }
            else{
                int j=count[arr[i]];
                int sz = suf_pref[arr[i]].size();
                sz-=j;
             //   cout<<arr[i]<<" "<<j<<" "<<sz<<endl;
                long long val = suf_pref[arr[i]][j]-(pref[arr[i]][j-1]*sz);
                val+=pre_suf[arr[i]][j-1]-(suff[arr[i]][j]*j);
                    ans[i]=val;
            }
            count[arr[i]]++;
        } 
        
        return ans;
    }
};
