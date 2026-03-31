class Solution {

    int helperFunc(vector<int>& nums, int s, int e) {
        if (s == e) return nums[s];

        vector<int> dp(nums.size(), 0);

        dp[s] = nums[s];
        dp[s + 1] = max(nums[s], nums[s + 1]);

        for (int i = s + 2; i <= e; i++) {
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
        }

        return dp[e];
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 0) return 0;
        if (n == 1) return nums[0];

        // Case 1: Exclude last house
        int a = helperFunc(nums, 0, n - 2);

        // Case 2: Exclude first house
        int b = helperFunc(nums, 1, n - 1);

        return max(a, b);
    }
};