/*
INTUTION:
Just use the map concept of key valu pait =r to storre the nubers abd equivalent character and then ust do backtrack for the leetrs ti vist akk teh numbers 
*/

CODE:
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        
        map<char, string> digitToCharMap = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        
        vector<string> result;
        string currentCombination;
        backtrack(digits, 0, currentCombination, result, digitToCharMap);
        return result;
    }
    
private:
    void backtrack(const string& digits, int index, string& currentCombination, vector<string>& result, unordered_map<char, string>& digitToCharMap) {
        if (index == digits.size()) {
            result.push_back(currentCombination);
            return;
        }
        
        string letters = digitToCharMap[digits[index]];
        for (char letter : letters) {
            currentCombination.push_back(letter);
            backtrack(digits, index + 1, currentCombination, result, digitToCharMap);
            currentCombination.pop_back();
        }
    }
};
