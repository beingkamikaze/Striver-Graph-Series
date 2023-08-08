Link: https://practice.geeksforgeeks.org/problems/word-ladder/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=word-ladder

int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        queue<pair<string,int>> q;
        q.push({startWord,1});
        unordered_set<string> st(wordList.begin(),wordList.end());
        st.erase(startWord);
        while(!q.empty())
        {
            string word=q.front().first;
            int step = q.front().second;
            q.pop();
            if(word==targetWord)
            return step;
            for(int i=0;i<word.length();i++)
            {
                char og = word[i];
                for(char ch='a';ch<='z';ch++)
                {
                    word[i]=ch;
                    if(st.find(word)!=st.end())
                    {
                        q.push({word,step+1});
                        st.erase(word);
                    }
                }
                word[i]=og;
            }
        }
        return 0;
    }
