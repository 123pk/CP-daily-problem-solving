/*
Platform :- Leetcode
Approach :- We maintain a frequency where we add capacity[i] passengers on start of journey and remove capacity[i] from end of journy then we find prefix sum and if at any point
            the sum is >capacity then we cannot fulfill the condition and return false else return true at the end.
*/
