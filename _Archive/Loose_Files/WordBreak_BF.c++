#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        
        // Build a map: character → list of indices in s
        unordered_map<char, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[s[i]].push_back(i);
        }

        // Boolean array to track reachable positions in s
        vector<bool> reachable(n + 1, false);
        reachable[0] = true; // empty prefix is reachable

        // Iterate over reachable positions
        for (int i = 0; i < n; i++) {
            if (!reachable[i]) continue;

            // Try each word in the dictionary
            for (string word : wordDict) {
                string temp = "";
                bool inWord = false;

                // Parse quotes if present
                for (char ch : word) {
                    if (ch == '"') {
                        inWord = !inWord; // toggle inWord flag
                    } else if (inWord || ch != '"') {
                        temp.push_back(ch);
                    }
                }
                if (temp.empty()) temp = word; // fallback if no quotes

                // Check if first char exists in s at/after i
                char firstChar = temp[0];
                if (mp.find(firstChar) != mp.end()) {
                    // Try each position in s where firstChar occurs
                    for (int pos : mp[firstChar]) {
                        if (pos != i) continue; // only try current reachable position
                        if (i + temp.size() > n) continue; // word too long

                        bool match = true;
                        for (int j = 0; j < temp.size(); j++) {
                            if (s[i + j] != temp[j]) {
                                match = false;
                                break;
                            }
                        }

                        if (match) {
                            reachable[i + temp.size()] = true; // mark new reachable position
                        }
                    }
                }
            }
        }

        return reachable[n]; // true if full string can be segmented
    }
};

int main() {
    Solution sol;
    string s = "leetcode";
    vector<string> wordDict = {"\"leet\"", "\"code\""}; // dictionary words

    if (sol.wordBreak(s, wordDict)) {
        cout << "String can be broken into dictionary words.\n";
    } else {
        cout << "String cannot be broken into dictionary words.\n";
    }
    return 0;
}
