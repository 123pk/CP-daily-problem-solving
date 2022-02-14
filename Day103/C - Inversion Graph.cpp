/*
Platform :- Codeforces
Contest :- Codeforces Round 771
Approach :- We need to find the values that are smaller than current values and are to the right of current element and make edge between them , bruteforce will take O(n^2)
           and will be TLE , else alternating thing is to use stack<pair> to store the max and min element in any connected component ,and run a loop from (n-1 to 0)
           if we found any value that is in range of [min,max] of connected componnent then we add this element also in the connected componet and pop all the elements which
           are havingn common range with this and at the end no of element in stack are answer
*/
