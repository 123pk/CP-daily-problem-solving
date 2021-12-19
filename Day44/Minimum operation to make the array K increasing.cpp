/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 272 
Approach :- It is slight variation of Longest Increasing subsequence .
            For a given 'k' we want A[ i - k ] < = A[ i ] for all valid i. So let no of elements in array be 6 and k=2 , 
            the following condition is needed to be satisfied ( A[1] <= A[3] <= A[5] ) and ( A[2] <= A[4]<= A[6]) so we can 
            see we want to make these subsequece of arrays in non- decreasing order which is just a slight variation of longest increasing subsequence .
            The minimum no of changes we need to make is ( length of such array- Longest non decreasing subsequece) in (nlogn) .
*/
int lis(vector<int> const& a) {
    int n = a.size();
    const int INF = 1e9;
    vector<int> d(n+1, INF);
    d[0] = -INF;

    for (int i = 0; i < n; i++) {
        int j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (d[j-1] <= a[i] && a[i] <= d[j])
            d[j] = a[i];
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (d[i] < INF)
            ans = i;
    }
    return ans;
}

class Solution {
public:
    int kIncreasing(vector<int>& arr, int k) {
        int ans=0;
        int d;
        vector<int>temp;
        for(int i=0;i<k;++i){
            temp.clear();
            d=0;
            for(int j=i;j<arr.size();j+=k){
                temp.push_back(arr[j]);
                d++;
            }
            ans+=(d-lis(temp));
        }
        
        return ans;
    }
};
