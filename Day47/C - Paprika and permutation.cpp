/*
Platform :- Codeforces
Contest :- Codeforces Round 761 Div 2
Approach :- we run a loop from 1 to n and mark all those which are present in array and we now try to change the remaining values after sorting in increasing order to
            ith with the mod operation , we can do so if the 
            z = (value+1)/2 , if (z-1) is < i then we cannot covert it to that index .else we increment our count. 
*/
