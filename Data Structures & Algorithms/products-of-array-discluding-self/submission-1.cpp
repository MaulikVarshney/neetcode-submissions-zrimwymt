class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(),1);
    
        for(int i=1;i<nums.size();i++){
            res[i] = nums[i-1]*res[i-1];
        }
        int suffix = 1;
        for(int i=nums.size()-1;i>=0;i--){
            res[i] *= suffix;
            suffix *= nums[i];
        }
        
       return res;
    }

};
//[1,2,4,6]
//[1,1,2,8,48] ->48
//[48,24,12,8]
//[1,1,2,8]
//[48,24,12,8]