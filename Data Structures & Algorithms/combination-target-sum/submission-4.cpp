class Solution {

    void calcAns(int i, int t, vector<int> tmp,
                 vector<int>& nums, vector<vector<int>>& res){

        if(i >= nums.size() || t < 0) return;

        if(t == 0){
            res.push_back(tmp);
            return;
        }

        tmp.push_back(nums[i]);
        calcAns(i, t - nums[i], tmp, nums, res);

        tmp.pop_back();
        calcAns(i + 1, t, tmp, nums, res);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> tmp;

        calcAns(0, target, tmp, nums, res);

        return res;
    }
};