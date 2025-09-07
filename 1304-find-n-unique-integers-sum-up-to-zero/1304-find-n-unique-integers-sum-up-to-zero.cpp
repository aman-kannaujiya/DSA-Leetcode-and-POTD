class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> result(n);

        int i = 0;
        int start = 1;
        while(i +1 < n){
            result[i] = start;
            result[i+1] = -start;
            i += 2;
            start++;

        }
        return result;
    }
};