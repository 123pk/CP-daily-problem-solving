/*
Platform :- Leetcode
Contest :- Leetcode weekly contest 273
Approach :- I messed up in this problem ,my fomuale is bit messy.
            First I found diff array for each value , where dif[i] contains difference in index between two consecutive similar values,
            then I found prefix sum array of it and the suffix sum of this prefix sum array
            similary I found suffix sum array of it and the prefix sum of this suffix sum array
            then for firt element the ans[i]  = first element of suffix_prefix[ arr[i] ][0]
            and for last element the ans[i] = last element of prefix_suffix[ arr[i] ][ size-1 ]
            then for all other values ans[i]  =  ( suf_pref[arr[i]][j]-(pref[arr[i]][j-1]*sz) )  + (pre_suf[arr[i]][j-1]-(suff[arr[i]][j]*j));
*/
