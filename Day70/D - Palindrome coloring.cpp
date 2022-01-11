/*
Platform :- Codeforces
Contest :- Codeforces Round 764 Div 3
Approach :- Find no of pairs of equal characters we can make , take count of uniqueue or charactre with odd frequency .
            let x = no of pair
            y = no of unique character 
            if we want 'k' palindrome strings then we need to distribute x/k to each of 'k' .
            then there would be some extraa values if (x%k) if (x%k)*2+y>=k then d=1 and max lenth is (x/k)*2+d
*/
