/*
Brute: It works in O(n^2) bit its a optimal becuse it a Matrix 
Explanation:
*Two Loops to Iterate Over the Image: The two outer loops iterate over each cell of the image (of size m×n).

*Inner Loops to Check Surrounding Cells: For each cell, the inner loops check the neighboring cells (in a 3x3 block around the current cell). The sum of the valid neighboring cells is computed, and the count is updated accordingly. This ensures that we only consider cells within the bounds of the image.

*Calculate the Average: After summing the valid neighbors, the average is calculated by dividing the sum by the number of valid neighbors, and the result is stored in the result matrix smoothieImg.

*Time Complexity:
O(m×n), since we process each cell in the image once and each 3x3 block (at most 9 neighbors) is processed in constant time.
*Space Complexity: 
O(m×n) because we need an output matrix of the same size as the input matrix.
*/
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();
        vector<vector<int>> smoothieImg(m, vector<int>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int sum = 0, count = 0;

                for (int x = i - 1; x <= i + 1; x++) {
                    for (int y = j - 1; y <= j + 1; y++) {
                        if (x >= 0 && x < m && y >= 0 && y < n) {
                            sum += img[x][y];
                            count++;
                        }
                    }
                }

                smoothieImg[i][j] = sum / count;
            }
        }

        return smoothieImg;
    }
};