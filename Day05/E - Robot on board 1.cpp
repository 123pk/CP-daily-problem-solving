/*
Platform :- Codeforces
Contest :- Codeforces Contest 753 Div 3
Approach :- First find the index upto which our robot can execute the command , now start from cell (1,1) and reach out to the end adjusting the starting index accordingly.
             I took the command from that index to 0 and changed 'U'-->'D','L'-->'R' and vice versa and started from index (1,1) and accordingly shifted the position executing the command
             if some command cannont be executed I leaved that and moved to next command since I know he will be able to attend that command and reach it the final position at end.
             
*/
