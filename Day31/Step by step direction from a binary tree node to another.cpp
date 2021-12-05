/*
Platform :- Leetcode
Contest :- Leetcode Contest 270
Approach :- First find path from "startNode" to "root" and "destNode" to "root" now find the LCA ( lowest common ancestor ) , we can reach from "startnode" to LCA using "U" command
            and we will now back track from dest node to LCA adding "L" and "R" commands.
*/
