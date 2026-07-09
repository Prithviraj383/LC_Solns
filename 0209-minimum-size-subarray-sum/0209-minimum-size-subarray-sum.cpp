class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int i=0, sum=0, ans=INT_MAX;

        for(int j=0;j<n;++j){
            sum += nums[j];

            while(sum >= target){
                ans = min(ans, j-i+1);
                sum-=nums[i];
                i++;
            }
        }
        return ans == INT_MAX ? 0:ans;
    }
};