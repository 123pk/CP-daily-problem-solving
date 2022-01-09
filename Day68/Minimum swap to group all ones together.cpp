/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 275
Approach :- Append the current array to the end of it , nums+nums , now store the no of ones till ith index using prefix array , also count no of ones in original array , since we
            need to group them together , let c = total_no_of_ones in original array then we want to choose that subarray of size 'c' where no of '0' isminimum and that is our ansewr
            because we need to replace 0s .
*/
