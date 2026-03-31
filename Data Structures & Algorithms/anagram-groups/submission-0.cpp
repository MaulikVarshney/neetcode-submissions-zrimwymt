class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(auto str: strs){
            string temp = str;
            sort(str.begin(),str.end());
            mp[str].push_back(temp);
        }
        vector<vector<string>> ans;
        for(auto [a,b]:mp){
            ans.push_back(b);
        }
        return ans;
    }
};
