class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> seen(26, 0), lastIdx(26, 0);
        string temp="";

        for(int i=0;i<s.size();++i){
            lastIdx[s[i]-'a'] = i;
        }

        for(int i=0;i<s.size();++i){
            if(seen[s[i]-'a'] != 0) continue;
            while(!temp.empty() && s[i] < temp.back() && lastIdx[temp.back()-'a'] > i){
                seen[temp.back()-'a']--;
                temp.pop_back();
            }
            if(seen[s[i]-'a'] == 0) {
                seen[s[i]-'a']++;
                temp+=s[i];
            }
        }
        return temp;
    }
};