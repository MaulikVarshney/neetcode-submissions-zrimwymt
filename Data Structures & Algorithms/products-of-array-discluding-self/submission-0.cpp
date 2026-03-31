class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size());
        vector<int> pre(nums.size());
        vector<int> suf(nums.size());
        pre[0] = suf[nums.size()-1] = 1;

        for(int i=1;i<nums.size();i++){
            pre[i] = nums[i-1]*pre[i-1];
        }
        for(int i=nums.size()-2;i>=0;i--){
            suf[i] = suf[i+1]*nums[i+1];
        }
        for(int i=0;i<nums.size();i++){
            res[i] = pre[i]*suf[i];
       }
       return res;
    }

};
//[1,2,4,6]
//[1,1,2,8,48] ->48
//[48,24,12,8]
//[1,1,2,8]
//[48,24,12,8]