/*
Platform :- Leetcode
Apporach :- Find all the indes which are not empty and now binarys search for each value in our sitting arrangement find the min distance between you and sitting person , max out of 
           all such values is our answer.
           
          Approach 2:-  Another approach is that find the max distance between two adjacent sitting person , ans the max distance we can acheive is dist/2 , take care of cases when 
                        you will sit at either end in that case max distance is distance to first sitting person.
*/
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int sol=0;
        
        vector<int>used_seats;
        for(int i=0;i<seats.size();++i){
            if(seats[i]){
                used_seats.push_back(i);
            }
        }
        
        int left,right;
        for(int i=0;i<seats.size();++i){
            auto it = lower_bound(used_seats.begin(),used_seats.end(),i);
            if(it==used_seats.end())it--;
            
            if(it==used_seats.begin()){
                sol=max(sol,abs(*it-i));
            }
            else{
                if(*it==i)continue;
                right = abs(*it-i);
                it--;
                left = abs(*it-i);
                sol=max(sol,min(right,left));
            }
        }
        return sol;
    }
};
