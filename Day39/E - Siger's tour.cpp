/*
Platform:- Codeforces
Contest :- Codeforces Round 760 Div 3
Approach :- You need to simplify and you will find that for given 'n' , the sum need to be multiple of (n*(n+1))/2 . 
           * Then we will get the sum of all value of original array from there which is (tot_sum / z) , z = (n*(n+1))/2
           * We just need two equations to get any value ,if we want A[0] we need to simplify (A[0] , A[n-1])
           * then for all other values we simplify (A[i] and A[i-1] )
           
           if there are 3 value . 
           A[0] = x0 + 3*x1 + 2*x2 
           A[1] = 2*x0 + x1 + 3*x2 
           A[2] = 3*x0 + 2*x1 + x2 ,
           we know (x0 + x1 + x2  = tot_sum / z)
           and simplify using these two equations .
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
         
        
        long long A[n];
        long long tot=0;
        long long mn=(n*(n+1))/2;
        long long z=n;
        z*=mn;
        for(int i=0;i<n;++i){
            cin>>A[i];
            tot+=A[i];
        }
        
        if(tot%mn)cout<<"NO\n";
        else{
            
            int f=0;
            vector<long long>ans;
            //we start simpifying
            long long sum = tot/mn;
            
            for(int i=0;i<n;++i){
                if(i==0){
                     
                    long long val = (A[i]-sum);
                   
                    val = (A[n-1]-val);
                    
                    if(val%n || val<=0){
                      
                        f=1;break;
                    }
                    val/=n;
                    ans.push_back(val);
                }
                else{
                    long long val = (A[i]-sum);
                    val = (A[i-1]-val);
                    if(val%n || val<=0){
                       
                        f=1;break;
                    }
                    val/=n;
                    ans.push_back(val);
                }
            }
            
            
            if(f)cout<<"NO\n";
            else{
                cout<<"YES\n";
                for(auto &x:ans)cout<<x<<" ";
                cout<<"\n";
            }
            
        }
        
    }
}
