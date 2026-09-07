#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
    unordered_map<string, int> mpp;
    vector<vector<string>> ans;
    string b;

private:
    void dfs(string word, vector<string>& seq) {
        // Base Condition: Sequence has successfully tracked back to the beginWord
        if (word == b) {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end()); // Backtrack to find other paths
            return;
        }

        int steps = mpp[word];
        int sz = word.size();

        // Try substituting every character to find the parent word
        for (int i = 0; i < sz; i++) {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;
                // If the modified word is in the map and sits on the exact previous level
                if (mpp.find(word) != mpp.end() && mpp[word] == steps - 1) {
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back(); // Backtrack
                }
            }
            word[i] = original; // Restore original character
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<string> q;
        b = beginWord;

        q.push(beginWord);
        mpp[beginWord] = 1;
        st.erase(beginWord);

        int sz = beginWord.size();

        // Step 1: BFS to map the shortest path level to each word
        while (!q.empty()) {
            string word = q.front();
            int steps = mpp[word];
            q.pop();

            if (word == endWord) break;

            for (int i = 0; i < sz; i++) {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if (st.count(word)) {
                        q.push(word);
                        st.erase(word);
                        mpp[word] = steps + 1;
                    }
                }
                word[i] = original;
            }
        }

        // Step 2: DFS to reconstruct all shortest sequences
        if (mpp.find(endWord) != mpp.end()) {
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        }

        return ans;
    }
};