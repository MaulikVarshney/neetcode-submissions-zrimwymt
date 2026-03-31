class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        vector<int> ans;
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto [a,b]: mp){
            pq.push({b,a});
        }
        for(int i=0;i<k;i++){
            ans.push_back(pq.top().second);

            pq.pop();
        }
        return ans;
    }
};
