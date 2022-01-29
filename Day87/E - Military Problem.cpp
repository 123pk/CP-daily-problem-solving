/*
Platform :- Codeforces
Contest :- Codeforces Round 498
Approach :- First find the no of nodes in subtree for each node of tree then for each node calculate the no of vlaues till ith node , key idea for answering querie is,
            we will check if there are enough nodes in subtree to trasfer message or not if there are enough nodes then we will try to find the (no_of_nodes_till_u + k ) from root
            will give the answer . So we store the distance of each node from root that will help us in getting the solution to each query in O(1)
*/
