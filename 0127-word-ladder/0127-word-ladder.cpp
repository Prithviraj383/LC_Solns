class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //inserting string into set
        unordered_set<string> st(wordList.begin(), wordList.end());

        //queue to store string and level number
        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        //no need of beginWord in the list again
        st.erase(beginWord);


        //st bfs from the beginWord
        while(!q.empty()){
            auto [word, steps] = q.front();
            q.pop();

            if(word == endWord) return steps;

            for(int i=0;i<word.size();++i){
                char original = word[i];

                for(char ch = 'a'; ch <= 'z';++ch){
                    word[i] = ch;
                    if(st.find(word) != st.end()){
                        st.erase(word);
                        q.push({word, steps+1});
                    }
                }

                word[i] = original;
            }
        }
        return 0;
    }
};