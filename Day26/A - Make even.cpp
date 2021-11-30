/*
Platform :- Codeforces
Contest :- If there is no even elemnt in our number then we cannot change it into even
           else we have three cases 
           Case 1 :- Already even  --> we didnot need to perform any operation 
           Case 2 :- First character or digit of number if even then we just need one operation and last digit is swapped with first digit and we get even number
           Case 3 :- We need 2 operations , in operation one we make first element even then it becomes case 2.
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        string s;
        cin>>s;
        
        int f=0;
        for(auto &x:s){
            if((x-'0')%2==0){
                f=1;break;
            }
        }
        
        if(f==0)cout<<"-1\n";
        else {
            if((s[s.size()-1]-'0')%2==0)cout<<0<<"\n";
            else{
                if((s[0]-'0')%2==0)cout<<1<<"\n";
                else cout<<2<<"\n";
            }
        }
    }
}
