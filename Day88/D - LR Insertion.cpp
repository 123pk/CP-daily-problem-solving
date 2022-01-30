/*
Platform :- Atcoder
Contest :- Atcoder Beginner Contest 237
Approach :- We thing this problem as going back from last value which is 'n' to '0' , we use deque for this 
           we reverse the path and change 'L' to 'R' and vice versa as are going in back , now if we have 'L' command the we add to the front else we add to the end of queue,
           we add value 'd' which is 'n' in starting as we decrement it after each operation at the we end we print all the values and that is our desired sequence.
*/
