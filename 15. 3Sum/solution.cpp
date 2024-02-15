class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int left = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> triplets;
        while (left < n) {
            int right = left + 1;
            int compensator = n - 1;
            while (right < compensator) {
                int required = nums[left] + nums[right] + nums[compensator];
                if (required == 0) {
                    triplets.insert({nums[left], nums[right], nums[compensator]});
                    right++;
                    compensator--;
                } else if (required < 0)
                    right++;
                else
                    compensator--;
            }
            left++;
        }
        vector<vector<int>> ans;
        for (auto v : triplets) {
            ans.push_back(v);
        }
        return ans;
    }
};