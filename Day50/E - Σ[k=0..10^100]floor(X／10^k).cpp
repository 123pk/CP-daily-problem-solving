/*
Platform :- Atcoder 
Contest :- Atcoder Beginner Contest 233
Approach :- If you will carefully analyse the problem you will find that 
            let a example  ( 1239) 
            1 2 3 9
              1 2 3
                1 2
           +      1
           --------
            1 3 7 5
            You can observe that last digit of our value is sum of all the (digits % 10), 
            then second last digit is ( sum of first n-1 digits + carry ) %10..and so on
*/
