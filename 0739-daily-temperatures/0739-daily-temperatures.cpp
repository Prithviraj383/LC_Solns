class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        if(n==1) return {0};
        stack<pair<int, int>> st;

        vector<int> res(n, 0);
        res[n-1] = 0;
        st.push({temperatures[n-1], n-1});

        for(int i=n-2;i>=0;--i){

            while(!st.empty() && temperatures[i] >= st.top().first) st.pop();

            if(!st.empty() && temperatures[i] < st.top().first) 
                res[i] = (st.top().second - i);

            else 
                res[i] = 0;
            
            st.push({temperatures[i], i});
        }

        return res;
    }
};