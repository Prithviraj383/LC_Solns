class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0,j=n-1;
        int ans = 0;
        while(i<j){
            int h = min(height[i], height[j]);
            int w = abs(j-i);
            int capacity = h*w;

            if(height[i] < height[j]) i++;
            else j--;
            ans = max(ans, capacity);
        }
        return ans;
    }
};