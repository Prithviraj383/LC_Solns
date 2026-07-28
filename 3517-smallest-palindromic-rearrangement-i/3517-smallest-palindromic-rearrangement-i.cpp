class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();

        sort(s.begin(), s.begin() + n / 2);
        
        int k = 0;
        if(n % 2 == 0) k = n / 2;
        else k = n / 2 + 1;

        sort(s.begin() + k, s.end(), greater<char>());

        return s;
    }
};