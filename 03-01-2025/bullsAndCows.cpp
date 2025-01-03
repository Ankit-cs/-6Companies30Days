/*
Brute Force:Can be accepted during contest but not good for during interviews
Bulls:

Compare each character of secret and guess at the same index.
If they match, increment bulls and mark both as matched.
Cows:

For each unmatched character in guess, loop through unmatched characters in secret.
If a match is found, increment cows and mark the character in secret as matched.
Return the result in the format "xAyB".

*/

/*
Optimal:using hashing males this question morr easier but not easily be intuted
Bulls Counting:

Iterate through secret and guess.
If secret[i] == guess[i], increment bulls.
Track Unmatched Characters:

If a character does not match, store its frequency in secretCount and guessCount.
Cows Counting:

For each character in guessCount, check if it exists in secretCount. If yes, add the minimum frequency from both counts to cows.
Return the Result:

Combine the bulls and cows counts into the format "xAyB" and return it.

*/
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        unordered_map<char, int> freq;

        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                bulls++;
            } else {
                freq[secret[i]]++;
            }
        }

        for (int i = 0; i < guess.size(); i++) {
            if (secret[i] != guess[i] && freq[guess[i]] > 0) {
                cows++;
                freq[guess[i]]--;
            }
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};