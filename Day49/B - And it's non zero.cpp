/*
Platform :- Codeforces
Contest :- Codeforces Global Round 18
Approach :- Pre compute prefix sum of count of binary bits , for all values from 1 to 200000 , you can store details of 32 bits it is sufficient for following constraints
            now for each l and r find the count of bits in range (r-(l+1)) ,  the ( (r-(l+1))-max_count )is our answer
*/
