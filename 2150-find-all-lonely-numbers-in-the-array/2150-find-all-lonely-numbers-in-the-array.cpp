class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        vector<int> res;
        unordered_map<int, int> mp;
        for(auto val:nums) mp[val]++;

        for(auto [key, val]:mp){
            if(mp.find(key+1) == mp.end() && mp.find(key-1) == mp.end() && mp[key] == 1) res.push_back(key);
        }
        return res;
    }
};