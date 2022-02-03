/*
Platform :- Codechef
Contest :- Codechef Starters 3 feb
Approach :- there are two cases if we have only one bit set then we have two case :-
            1. When set bit is only 1 and values is '1' here we chhose 4,3,and 1 
            2. if the set bit is only 1 and 'n' is not '1' here we choose 'n' ,0 and bit next to set bit in third one
            we use greedy approach for seet bit count of 2 or more
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int x;
        cin>>x;
        
        int val1 = x;
        string s = bitset<32>(x).to_string();
        reverse(s.begin(),s.end());
        
        //So for set bit we want atleast two of three values to have that bit set in them
        // for all other non set bits we want something to be stopped
        int val2 = 1;
        
        if(x==1){
            cout<<1<<" "<<4<<" "<<3<<"\n";
            continue;
        }
        
        string p = s,q;
        int c = 0;
        for(int i=0;i<32;++i){
            if(s[i]=='1')c++;
        }
        
        if(c==1){
            val2 = 0;
            int f=0;
            //choose one 0
            //choose one set and next one
            for(int i=0;i<32;++i){
                if(f){
                    if(s[i]=='1')val2+=(1<<i);
                }
                else{
                    if(s[i]=='0'){
                        val2+=(1<<i);
                        f=1;
                    }
                }
            }
            
            cout<<val1<<" "<<val2<<" "<<0<<"\n";
            
        }
        else{
            //set first bit in this and second bit in that 
            q = s;
            c= 0 ;
            for(int i=0;i<32;++i){
                if(p[i]=='1'){
                    p[i]='0';
                    break;
                }
            }
            
            for(int i=0;i<32;++i){
                if(p[i]=='1'){
                    q[i] = '0';
                    break;
                }
            }
            
            val2 = 0;
            int val3 = 0;
            for(int i=0;i<32;++i){
                if(p[i]=='1')val2+=(1<<i);
            }
            
            for(int i=0;i<32;++i){
                if(q[i]=='1')val3+=(1<<i);
            }
            
            cout<<val1<<" "<<val2<<" "<<val3<<"\n";
        }
        
        
    }
}
