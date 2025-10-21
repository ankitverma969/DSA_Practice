class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = 2*nums.size();
        vector<int>ans(n);
        int index = 0;

        for(int i=0;i<2;i++){
            for(int j=0;j<nums.size();j++){
                ans[index]=nums[j];
                index++;
            }
        }
        return ans;


    }
};