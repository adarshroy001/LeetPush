class Solution {
public:
    char sign = '+';
    long long ans = 0;
    bool started = false;

    void helper(string &s, int i) {
        if (i >= s.size()) return;

        if (!started && s[i] == ' ') {
            helper(s, i + 1);
            return;
        }

        // sign 
        if (!started && (s[i] == '+' || s[i] == '-')) {
            sign = s[i];
            started = true;
            helper(s, i + 1);
            return;
        }

        // If digit found
        if (s[i] >= '0' && s[i] <= '9') {
            started = true;
            int digit = s[i] - '0';
            ans = ans * 10 + digit;

            if (ans > (long long)INT_MAX + 1) ans = (long long)INT_MAX + 1;
            helper(s, i + 1);
            return;
        }
        return;
    }

    int myAtoi(string s) {
        sign = '+';
        ans = 0;
        started = false;

        helper(s, 0);

        long long res = (sign == '-') ? -ans : ans;
        if (res > INT_MAX) return INT_MAX;
        if (res < INT_MIN) return INT_MIN;
        return (int)res;
    }
};
