#include "StringUtils.h"

int StringUtils::levenshteinDistance(const std::string& a, const std::string& b) {
    int m = (int)a.length();
    int n = (int)b.length();

    if (m == 0) return n;
    if (n == 0) return m;

    // Cap phat bang DP - tu cap phat thay vi dung std::vector
    int** dp = new int*[m + 1];
    for (int i = 0; i <= m; ++i) {
        dp[i] = new int[n + 1];
    }

    // Khoi tao bien
    for (int i = 0; i <= m; ++i) dp[i][0] = i;
    for (int j = 0; j <= n; ++j) dp[0][j] = j;

    // Truy hoi:
    //   dp[i][j] = min(
    //       dp[i-1][j]   + 1,   xoa
    //       dp[i][j-1]   + 1,   chen
    //       dp[i-1][j-1] + cost thay the (cost=0 neu trung)
    //   )
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            int cost = (a[i - 1] == b[j - 1]) ? 0 : 1;
            int del  = dp[i - 1][j] + 1;
            int ins  = dp[i][j - 1] + 1;
            int sub  = dp[i - 1][j - 1] + cost;

            int minVal = del;
            if (ins < minVal) minVal = ins;
            if (sub < minVal) minVal = sub;

            dp[i][j] = minVal;
        }
    }

    int result = dp[m][n];

    // Giai phong - phai go theo dung thu tu cap phat
    for (int i = 0; i <= m; ++i) delete[] dp[i];
    delete[] dp;

    return result;
}

std::string StringUtils::toLower(const std::string& s) {
    std::string r = s;
    for (int i = 0; i < (int)r.length(); ++i) {
        if (r[i] >= 'A' && r[i] <= 'Z') {
            r[i] = (char)(r[i] - 'A' + 'a');
        }
    }
    return r;
}

std::string StringUtils::trim(const std::string& s) {
    int start = 0;
    int end = (int)s.length();
    while (start < end && (s[start] == ' ' || s[start] == '\t'
                           || s[start] == '\r' || s[start] == '\n')) {
        ++start;
    }
    while (end > start && (s[end - 1] == ' ' || s[end - 1] == '\t'
                           || s[end - 1] == '\r' || s[end - 1] == '\n')) {
        --end;
    }
    return s.substr(start, end - start);
}

void StringUtils::split(const std::string& s, char delimiter,
                        DynamicArray<std::string>& out) {
    std::string cur;
    for (int i = 0; i < (int)s.length(); ++i) {
        if (s[i] == delimiter) {
            std::string t = trim(cur);
            if (!t.empty()) out.push_back(t);
            cur.clear();
        } else {
            cur += s[i];
        }
    }
    std::string t = trim(cur);
    if (!t.empty()) out.push_back(t);
}
