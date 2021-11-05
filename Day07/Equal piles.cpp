/*
Platform :- Topcoder
Contest :- SRM 818
Approach :- sort the array and now itterate through all the unique values from biggest to smallest (descending)order and for current value ,let x = number of value is greater than this 
            and 'k' be the times we have then we can convert min(x,k) values to current value , let 'z' be the total for current value (z = count_of_curr + mix(x,k) ) then ans is max of (ans,z)
*/
