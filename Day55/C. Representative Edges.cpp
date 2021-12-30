/*
Platform :- Codeforces
Contest :- Good Bye 2021
Approach :- Note that if the array is good ak+2−ak+1=ak+1−ak. In other words, the array form an arithmetic progression.

            We can either fix an arbitrary element and set all other elements equal to it (giving us the lower bound n−1 on the answer).

            Or, to solve the remaining case, we can fix any two elements that are in the answer, derive the formula for an arbitrary element
            of the arithmetic progression, and check the number of elements that we have to change.
*/
