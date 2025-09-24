class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        
        string result;
        
        // Handle sign
        if ((numerator < 0) ^ (denominator < 0)) result += "-";
        
        long long num = abs((long long)numerator);
        long long den = abs((long long)denominator);
        
        // Integer part
        result += to_string(num / den);
        long long remainder = num % den;
        if (remainder == 0) return result;
        
        result += ".";
        
        unordered_map<long long, int> seen;
        while (remainder != 0) {
            if (seen.count(remainder)) {
                result.insert(seen[remainder], "(");
                result += ")";
                break;
            }
            seen[remainder] = result.size();
            remainder *= 10;
            result += to_string(remainder / den);
            remainder %= den;
        }
        
        return result;
    }
};