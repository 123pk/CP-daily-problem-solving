/*
Platform :- Codeforces
Contest :- Codeforces Global Round 19
Approach :- Since the sum of the two array remains constant of the values we swap , We need to simplify the equation to [ (n-2)*(sum_of_squares_of_all_values) + sum_of_A^2 + sum_of_B^2 ] 
            so we need to minimise the [sum_of_A^2 + sum_of_B^2 ] , So we will use bool array to check if we can get to the value betwee [1 to m*n ] and find 
            min of (i^2 + (m*n-i)^2 )
*/
