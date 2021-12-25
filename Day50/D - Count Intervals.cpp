/*
Platform :- Atcoder
Contest :- Atcoder Beginner contest 233
Approach :- It is same as standard problem where we need to find number of subarrays with sum equal to 'k' , we basically use two pointer to find it in O(n)
*/
#include<bits/stdc++.h>
using namespace std;

long long find(vector<long long>&arr, long long sum)
{   
    int n = arr.size();
    // STL map to store number of subarrays
    // starting from index zero having
    // particular value of sum.
    unordered_map<long long, int> prevSum;
    long long res = 0;
 
    // Sum of elements so far.
    long long currsum = 0;
 
    for (int i = 0; i < n; i++) {
 
        // Add current element to sum so far.
        currsum += arr[i];
 
        // If currsum is equal to desired sum,
        // then a new subarray is found. So
        // increase count of subarrays.
        if (currsum == sum)
            res++;
 
        // currsum exceeds given sum by currsum
        //  - sum. Find number of subarrays having
        // this sum and exclude those subarrays
        // from currsum by increasing count by
        // same amount.
        if (prevSum.find(currsum - sum) != prevSum.end())
            res += (prevSum[currsum - sum]);
 
        // Add currsum value to count of
        // different values of sum.
        prevSum[currsum]++;
    }
 
    return res;
}

int main(){
     int n;
     long long k;
     cin>>n>>k;
     
     vector<long long>A(n);
     for(int i=0;i<n;++i){
         cin>>A[i];
     }
     
     cout<<find(A,k)<<"\n";
}
