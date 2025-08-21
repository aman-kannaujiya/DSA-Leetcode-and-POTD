class Solution {
public:
    // Helper: Count subarrays of all 1s in a vector
    int OneArrayCount(vector<int>& vec) {
        int cons = 0;
        int subCount = 0;

        for (int &val : vec) {
            if (val == 0) {
                cons = 0;
            } else {
                cons++;
            }
            subCount += cons;
        }

        return subCount;
    }

    // Main function: Count submatrices with all 1s
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int result = 0;

        // Choose starting row
        for (int startRow = 0; startRow < m; startRow++) {
            vector<int> vec(n, 1);

            // Expand downwards from startRow
            for (int endRow = startRow; endRow < m; endRow++) {
                for (int col = 0; col < n; col++) {
                    vec[col] = vec[col] & mat[endRow][col];
                }

                // Count valid subarrays in this row band
                result += OneArrayCount(vec);
            }
        }

        return result;
    }
};
