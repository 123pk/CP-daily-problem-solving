/*
Platform :- Codeforces
Contest :- Codeforces Round 752 Div 2
Approach :- A[i]%(i+1) !=0 if (i+1) is not a mulitple fo A[i], since A[i] is upto 10^9 so we can have upto 16 factorial , basic idea idea is to check from (i+1) to max(0,(i+1)-17)
            if still A[i] is divisible then answer doesnot exit .
*/
