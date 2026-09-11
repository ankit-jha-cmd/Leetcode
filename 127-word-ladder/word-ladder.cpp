class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>>q;
        unordered_set<string>st(wordList.begin(), wordList.end());
        q.push({beginWord, 1});
        while(!q.empty()){
            string word=q.front().first;
            int cnt=q.front().second;
            q.pop();
            for(int i=0;i<word.size();i++){
                char letter=word[i];
                for(char j='a'; j<='z'; j++){
                    word[i]=j;
                    if(st.find(word)!=st.end()){
                        if(word==endWord) return cnt+1;
                        q.push({word, cnt+1});
                        st.erase(word);
                    }
                }
                word[i]=letter;
            }
        }
        return 0;
    }
};