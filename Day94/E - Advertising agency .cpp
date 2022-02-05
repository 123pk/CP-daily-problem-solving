/*
Platform :- Codeforces
Contest :- Codeforces Round 697 Div 3
Approach :- Since we need to select 'k' elements it is always optimal to choose the biggest 'k' elements asthey will give us the largest values,
            so we will sort the value and store the frequency of each element in hashmap , now for each of the 'k' values if there is repeating term
            we will have to choose ( nCr%mod ) where 'n' is total frequency of ith largest value in choosen 'k' values and 'r' is the required 
*/
#include<bits/stdc++.h>
using namespace std;

unsigned long long power(unsigned long long x,
                                  int y, int p)
{
    unsigned long long res = 1; // Initialize result
 
    x = x % p; // Update x if it is more than or
    // equal to p
 
    while (y > 0)
    {
     
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;
 
        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}
 
// Returns n^(-1) mod p
unsigned long long modInverse(unsigned long long n, 
                                            int p)
{
    return power(n, p - 2, p);
}
 
// Returns nCr % p using Fermat's little
// theorem.
unsigned long long nCrModPFermat(unsigned long long n,
                                 int r, int p)
{
    // If n<r, then nCr should return 0
    if (n < r)
        return 0;
    // Base case
    if (r == 0)
        return 1;
 
    // Fill factorial array so that we
    // can find all factorial of r, n
    // and n-r
    unsigned long long fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;
 
    return (fac[n] * modInverse(fac[r], p) % p
            * modInverse(fac[n - r], p) % p)
           % p;
}

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        
        //We need to calculate nCr
        vector<int>A(n);
        map<int,int>P;
        for(int i=0;i<n;++i){
            cin>>A[i];
            P[A[i]]++;
        }
        sort(A.begin(),A.end(),greater<int>());
        map<int,int>Q;
        set<int>item;
        for(int i=0;i<k;++i){
            Q[A[i]]++;
            item.insert(A[i]);
        }
        int ans = 1;
        int mod = 1e9+7;
        for(auto &x:item){
            ans*=(nCrModPFermat(P[x], Q[x], mod));
            ans%=mod;
        }
        cout<<ans<<"\n";
    }
}
