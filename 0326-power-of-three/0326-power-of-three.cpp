class Solution {
public:
    bool isPowerOfThree(int n) {

        //<.............Approach -1-...........>
    //    if(n  <= 0)
    //    return false;

    //    if(n==1)
    //    return true;

    //    if(n%3 != 0)
    //    return false;

    //    return isPowerOfThree(n/3);

    //<..........Approach -2-....................>
    // if(n<=0)
    // return false;

    // while(n%3==0){
    //  n /= 3;
    // }
    // return n == 1;
    // }


    // Approach-> 3

    if(n<=0)
    return false;
    double x = log10(n) / log10(3);

    return x == (int)x;
    }
};