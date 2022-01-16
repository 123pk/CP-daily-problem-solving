/*
Platform :- Codeforces
Contest :- Codeforces Educational contest 121
Approach :- sort the string and all the characters appearing twice will come together hence distance between all of them would be same
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        string s;
        cin>>s;
        sort(s.begin(),s.end());
        cout<<s<<"\n";
    }
}
