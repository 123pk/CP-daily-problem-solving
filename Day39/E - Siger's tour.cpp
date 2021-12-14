/*
Platform:- Codeforces
Contest :- Codeforces Round 760 Div 3
Approach :- You need to simplify and you will find that for given 'n' , the sum need to be multiple of (n*(n+1))/2 . 
           * Then we will get the sum of all value of original array from there which is (tot_sum / z) , z = (n*(n+1))/2
           * We just need two equations to get any value ,if we want A[0] we need to simplify (A[0] , A[n-1])
           * then for all other values we simplify (A[i] and A[i-1] )
           
           if there are 3 value . 
           A[0] = x0 + 3*x1 + 2*x2 
           A[1] = 2*x0 + x1 + 3*x2 
           A[2] = 3*x0 + 2*x1 + x2 ,
           we know (x0 + x1 + x2  = tot_sum / z)
           and simplify using these two equations .
*/
