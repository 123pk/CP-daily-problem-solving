/*
Platform :- Codeforces
Contest :- Educational Round 122
Approach :- First precalculate the min cost of making value 'i' from '1' , now we change each of the value in input with their min cost and now the problem is turned down to 
            dp 01 knap sack and to avoid MLE (Memory limit exceeded ) find the sum of all the elemets cost in input and if the ( k > sum_min_operations) then simply our answer is (sum_of_cost)
*/
