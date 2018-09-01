// You have a list of words and a pattern, and you want to know which words in words matches the pattern.
//
// A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.
//
// (Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.)
//
// Return a list of the words in words that match the given pattern.
//
// You may return the answer in any order.
//
//
//
// Example 1:
//
// Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
// Output: ["mee","aqq"]
// Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}.
// "ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation,
// since a and b map to the same letter.
//
//
// Note:
//
// 1 <= words.length <= 50
// 1 <= pattern.length = words[i].length <= 20
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> rslt;
        for (auto word : words) {
            if (match(word, pattern)) rslt.push_back(word);
        }

        return rslt;
    }

    bool match(string word, string pattern) {
        if (word.size() != pattern.size()) return false;

        map<char, char> wtop;
        map<char, char> ptow;

        for (int i = 0; i < word.size(); i++) {
            char w = word[i];
            char p = pattern[i];
            if (wtop.count(w) == 0) {
                if (ptow.count(p)) return false;
                wtop[w] = p;
                ptow[p] = w;
            } else {
                if ((wtop[w] != p) || (ptow.count(p) == 0) || (ptow[p] != w)) return false;
            }
        }

        return true;
    }
};
