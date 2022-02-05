/*
Platform :- Codeforces
Contest :- Codeforces Round 697 Div 3
Approach :- Since we need to select 'k' elements it is always optimal to choose the biggest 'k' elements asthey will give us the largest values,
            so we will sort the value and store the frequency of each element in hashmap , now for each of the 'k' values if there is repeating term
            we will have to choose ( nCr%mod ) where 'n' is total frequency of ith largest value in choosen 'k' values and 'r' is the required 
*/
