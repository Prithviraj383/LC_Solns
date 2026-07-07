class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n==0) return 0;
        string temp = to_string(n);

        int i=0;
        int sum=0;
        string res;
        while(i<temp.size()){
            if(temp[i] != '0'){
                res.push_back(temp[i]);
                sum+=temp[i]-'0';
            } 
            i++;
        }
        cout << sum << endl;
        long long x = stoll(res);

        long long ans = sum*x;
        return ans;
    }
};