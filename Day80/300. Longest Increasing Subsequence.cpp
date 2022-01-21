/*
Platform :- Leetcode
Approach :- We always have atleast a LIS of size '1' which will any item of arry itself , else if we are at 'ith' index then we will go to all the preceding 'j' from (0 to i-1)
            and  if ( arr[i] >  arr[j] ) then we have a LIS till 'i' as LIS[i] = max (LIS[i-1] + 1, LIS[i] ).
            At the end we return the max value out of it .
*/
