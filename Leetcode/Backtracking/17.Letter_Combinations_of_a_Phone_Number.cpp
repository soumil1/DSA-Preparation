class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        unordered_map<char, string> digitToCharacter = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "qprs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        // Recursive backtracking function
        function<void(int, string)> backtrack = [&](int i, string curStr) {
            if (curStr.length() == digits.length()) {
                result.push_back(curStr);
                return;
            }
            for (char c : digitToCharacter[digits[i]]) {
                backtrack(i + 1, curStr + c);
            }
        };

        if (!digits.empty()) {
            backtrack(0, "");
        }

        return result;
    }
};
