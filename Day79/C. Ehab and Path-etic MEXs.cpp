/*
Platform :- Codeforces
Contest :- Codeforces Round 628 Div 2
Approach :- If you will carefully analyse the problem you will find that if 
            i .( max_degree_node  < 3 )  then we cannot do anything because we have linear tree , and we will assign value from 0 to n-2 in any order
            ii. we will get any node with ( degree >= 3 ) and assign all the edges from it value from (0 to x  , x=no of edges from this node) and randomly assign values to remmaining edges
                here the max MEX will not be >2 .
*/
