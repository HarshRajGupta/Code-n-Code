#include <bits/stdc++.h>
using namespace __gnu_debug;

#ifndef debug
#define debug(...)
#endif

class Solution {
    bool differBy1(string &s1, string &s2) {
        int differ = 0;
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) {
                if (++differ == 2) return false;
            }
        }
        return true;
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        vector<int> endExit;
        vector<int> graph[wordList.size() + 1];
        for (int i = 0; i < wordList.size(); ++i) {
            for (int j = i + 1; j < wordList.size(); ++j) {
                if (differBy1(wordList[i], wordList[j])) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
            if (wordList[i] == endWord) {
                endExit = graph[i];
            }
        }

        if (endExit.size() == 0) return {};

        vector<int> visited(wordList.size(), wordList.size() + 1);
        vector<vector<string>> ans;
        queue<pair<int, vector<string>>> q;
        int shortest = wordList.size() + 1;
        q.push({wordList.size() - 1, {}});
        visited[wordList.size() - 1] = 0;

        while (!q.empty()) {
            auto [src, v] = q.front();
            q.pop();
            v.push_back(wordList[src]);
            if (endExit[src]) {
                v.push_back(endWord);
                if (v.size() <= shortest) {
                    shortest = v.size();
                    ans.push_back(v);
                }
                continue;
            }
            if (v.size() >= shortest) continue;
            for (auto &i : graph[src]) {
                if (visited[i] >= v.size()) {
                    visited[i] = v.size();
                    q.push({i, v});
                }
            }
        }
        return ans;
    }
    void test() {
        string a = "hit", b = "cog";
        vector<string> c= {"hot","dot","dog","lot","log","cog"};
        debug(findLadders(a, b, c));
    }
};

/**
 * @ScratchPad
 */

#ifdef __TEST__
__TEST__
#endif