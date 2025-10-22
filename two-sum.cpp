class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp; // stores value -> index
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i]; // value needed to reach target
            if (mp.find(complement) != mp.end()) {
                return {mp[complement], i}; // found the pair
            }
            mp[nums[i]] = i; // store current value and its index
        }
        return {}; // should never reach here
    }
};