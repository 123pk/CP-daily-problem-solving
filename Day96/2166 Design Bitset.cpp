/*
Platform :- Leetcode
Approach :- We use two string 's' and 't' where 't' is compleent of 's' , if s = 010 then 't' = 101 , in the beginning we will have 's' = 0000...n and 't' = 11111...n
            for each of the fix and unfix operation we do the changes in 's' and 't' accordingly,
            for 'flip' operation we swap ('s' and 't'), and we also maintian no of set bits in 's' and change in fix and unfix opearting accordingly .
            In 'flip' operation we change the count to ( n - count ) . 
*/
