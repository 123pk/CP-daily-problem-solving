/*
Platform :- Codeforces
Contest :- 
Approach :- If the array is already good then we don't need to remove any element else the max no of elmenets we need to remove is 1, and that is the index of element with 
           smallest LSB .
           We use 0-1 Knapsack to find that the array is already divisble in to two subsequence of same sum or not if the sum is not odd initially.
*/
#include<bits/stdc++.h>
using namespace std;
int dp[101][200002];
int main(){
    int n;
    cin>>n;
    
    int A[n];
    int c=0;
    int tot=0;
    for(int i=0;i<n;++i){
        cin>>A[i];
        tot+=A[i];
        if(A[i]%2){
            c=i+1;
        }
    }
    
    
    if(tot%2)cout<<"0\n";
    else{
     //   int dp[n+1][tot+1];
    dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		dp[i][0] = 1;
		for (int j = 1; j <= tot; j++) {
			dp[i][j] = dp[i][j] || dp[i - 1][j];
			if (A[i - 1] <= j) {
				dp[i][j] = dp[i][j] || dp[i - 1][j - A[i - 1]];
			}
			// cout << dp[i][j] << " ";
		}
		// cout << nline;
	}
	//cout<<dp[n][2]<<"\n";
        if(dp[n][tot/2]==0)cout<<"0\n";
        else if(c)cout<<1<<"\n"<<c<<"\n";
        else{
            int d=0,mx;
            c=0;
            cout<<1<<"\n";
            for(int i=0;i<n;++i){
                d=0;
                string temp = bitset<32>(A[i]).to_string();
                reverse(temp.begin(),temp.end());
                for(int j=0;j<32;++j){
                    if(temp[j]=='1'){
                        d=j;
                        break;
                    }
                }
                
                if(i==0){
                    mx=d;
                    c=i+1;
                }
                else{
                    if(mx>d){
                        mx=d;
                        c=i+1;
                    }
                }
            }
            cout<<c<<"\n";
        }
    }
}
