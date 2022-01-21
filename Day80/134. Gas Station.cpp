/*
Platform :- Leetcode
Approach :- We start from first gas startation and assume it to be the starting point , if at any point we are out of fuel and not able to make till the next station then we
            just move our start station a bit backward which in our case will be last station as they are in cycle , we do this until we found 1 , if there are no station then 
            return -1;
*/
