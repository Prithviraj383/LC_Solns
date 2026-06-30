class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int ans=0,l=0;
        int a=0,b=0,c=0;

        for(int r=0;r<n;++r){
            char ch = s[r];
            if(ch == 'a')a++;
            else if(ch == 'b')b++;
            else c++;

            while(a>0 && b>0 && c>0) {
                ans += n-r;

                if(s[l] == 'a')a--;
                else if(s[l] == 'b')b--;
                else c--;

                l++;
            }
        }

        return ans;
    }
};