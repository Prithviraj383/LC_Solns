class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0]; 
        });

        int maxEnd = 0, cnt=0, n = intervals.size();
        for(int i=0;i<n;++i){
            auto &I = intervals[i];

            if(I[1] <= maxEnd) cnt++;
            else maxEnd = I[1];
        }
        return n - cnt;


    }
};