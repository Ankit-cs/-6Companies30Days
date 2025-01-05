/*intution:
*Adjust the Column Number: Subtract 1 from the column number to handle 1-based indexing.
*Get the Letter: Use columnNumber % 26 to find the remainder and map it to a letter (0 -> 'A', 1 -> 'B', ..., 25 -> 'Z').
*Prepend the Letter: Prepend the letter to the result string.
*Update the Column Number: Divide the column number by 26 to process the next "digit".
*Repeat: Continue until the column number is reduced to 0.
*/
class Solution {
public:
  string convertToTitle(int n) {
    string res=""; 
   
    while (n > 0) {
        n--; 
        res= char(n % 26 + 'A')+ res ; 
        n /= 26;
     }
    return res; 
}
};