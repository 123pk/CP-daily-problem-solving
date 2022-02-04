/*
Platform :- Leetcode
Hint :- Hashmap & find 
*/
class Solution{
public:
	int findMaxLength(vector<int> &nums){
		unordered_map<int, int> mp;
		mp[0] = -1;

		int maxx = 0, sum = 0;
		for (int i = 0; i < nums.size(); i++){
			sum += nums[i] ? 1 : -1;
			if (mp.find(sum) != mp.end())
				maxx = max(i - mp[sum], maxx);
			else
				mp[sum] = i;
		}
		return maxx;
	}
};
