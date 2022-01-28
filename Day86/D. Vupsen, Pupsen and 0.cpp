/*
Platform :- Codeforces
Contest :- Codeforces Round 750 Div 2
Approach :- If length is even then we can always do operation on pair of elements (1,2) (3,4) ,  where A[1] = A[2] & A[2] = -A[1] and so on this will given sum of adjacent pairs 
            for to be '0' ,
            If length is odd then we need to find a trio where sum of any two is assign to any one and sum is non zero and other two will get -ve value of this single element
            and for remaining element we do the same we did with the even no of elements.
*/
