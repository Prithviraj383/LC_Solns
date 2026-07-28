class Solution {
public:
    string smallestPalindrome(string s) {
        char odd;
        int n = s.size();
        int freq[26] = {0};

        sort(s.begin(), s.end());
        string pre, mid;

        for(int i=0;i<n;++i){
            freq[s[i] - 'a']++;
        }

        for(int i=0;i<26;++i){
            if(freq[i] == 0) continue;
            if(freq[i] % 2) odd = i + 'a';
            
            if(freq[i] > 1){

                char x = i + 'a';
                int times = (freq[i] / 2);
                pre.append(times, x);
            }
        }

        string suf(pre.rbegin(), pre.rend());
        mid.append(1, odd);

        if(n%2) return pre + mid + suf;
        else return pre + suf;
        // rev = pre;
        // if(n%2 == 0) return pre+rev;
        // else return pre+to_string(odd)+rev;
        
    }
};