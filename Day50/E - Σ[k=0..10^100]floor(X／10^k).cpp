/*
Platform :- Atcoder 
Contest :- Atcoder Beginner Contest 233
Approach :- If you will carefully analyse the problem you will find that 
            let a example  ( 1239) 
            1 2 3 9
              1 2 3
                1 2
           +      1
           --------
            1 3 7 5
            You can observe that last digit of our value is sum of all the (digits % 10), 
            then second last digit is ( sum of first n-1 digits + carry ) %10..and so on
*/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin>>s;
    
    long long tot=0;
    for(auto &x:s){
        tot+=(x-'0');
    }
    int j=s.size()-1;
    string ans="";
    long long val=0;
    long long carry=0;
    for(int i=0;i<s.size();++i){
        val=tot+carry;
        ans+=to_string(val%10);
        carry=val/10;
        tot-=(s[j]-'0');
        j--;
    }
    if(carry){
        ans+=to_string(carry);
    }
    
    reverse(ans.begin(),ans.end());
    
    cout<<ans<<"\n";
}
