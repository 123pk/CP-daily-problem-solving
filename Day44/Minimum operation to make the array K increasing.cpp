/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 272 
Approach :- It is slight variation of Longest Increasing subsequence .
            For a given 'k' we want A[ i - k ] < = A[ i ] for all valid i. So let no of elements in array be 6 and k=2 , 
            the following condition is needed to be satisfied ( A[1] <= A[3] <= A[5] ) and ( A[2] <= A[4]<= A[6]) so we can 
            see we want to make these subsequece of arrays in non- decreasing order which is just a slight variation of longest increasing subsequence .
            The minimum no of changes we need to make is ( length of such array- Longest non decreasing subsequece) in (nlogn) .
*/
