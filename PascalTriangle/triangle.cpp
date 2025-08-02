class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result(numRows);
        for(int i = 0; i < numRows; i++){
            result[i] =vector<int>(i+1,1);
            for(int j = 1; j < i;  j++){
                result[i][j] =result[i-1][j] + result[i-1][j-1];
            }
        }
        return result;
    }
};

#Explanation
We aim to generate Pascal’s Triangle up to a given number of rows, where each row is a list of integers representing the coefficients in the binomial expansion.

We create a 2D vector (a list of lists) called the result, with a size equal to the number of rows. Each row will eventually contain the appropriate number of elements.

For each row (from 0 to numRows - 1), we initialize the row with i + 1 elements, all set to 1. This is because in Pascal’s Triangle, the first and last elements of every row are always 1.

We then iterate through the inner positions of each row (ignoring the first and last), and calculate their values based on the values in the previous row.

The value at any position (except the edges) is computed as the sum of the two values directly above it: one from the same column and one from the column before in the previous row.

This structure follows the mathematical rule of Pascal’s Triangle:
element(i, j) = element(i-1, j-1) + element(i-1, j)

By doing this for all rows up to the given number, we successfully build Pascal’s Triangle level by level, using only previously computed values.

The outer loop ensures that all rows are processed, and the inner loop only runs for inner elements since the edges are already set to 1.

The approach is efficient as it builds the triangle incrementally using only addition and previously stored values, without recomputation.

Finally, the filled 2D list representing Pascal's Triangle is returned, where each row contains the correct binomial coefficients.

