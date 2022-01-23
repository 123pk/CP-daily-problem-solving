/*
Platform :- Codeforces
Contest :- Codeforces Round 767 Div 2
Approach :- Since the size of string is 3, and we need atmax 2 strings to get one palindrom ant aleast one string . Take care of all the cases which will result in palindrome.
            Case 1 :- Size of string is 1,  then it is already a plaindrome 
            Case 2 :- Size is 2 , if both characters are equal then also it is a palindrome , else we need to find "reverse" string of this
            Case 3 :-  Size is 3, if all characters are equal then it is already a palindrome , else we try to find reverse and check if we can find another string of size 2 
                        which will form it palindrome and there are two cases when we add that string to the begiining of it and if at the end take care of that.
*/
