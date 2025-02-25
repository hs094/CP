#include <bits/stdc++.h>
using namespace std;

vector<int> LPS(string pattern) {
    int m = pattern.length();
    vector<int> lps(m, 0);
    int len = 0;
    for (int i = 1; i < m; ) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

vector<int> kmp(string text, string pattern) {
    vector<int> occ;
    if (pattern.empty()) return occ;
    vector<int> lps = LPS(pattern);
    int i = 0, j = 0;
    while (i < text.length()) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
            if (j == pattern.length()) {
                occ.push_back(i - j);
                j = lps[j - 1];
            }
        } 
        else 
            (j != 0) ? j = lps[j - 1] : i++;
    }
    return occ;
}
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

vector<int> computeLPS(string pattern) {
    int m = pattern.length();
    vector<int> lps(m, 0);
    int len = 0;
    for (int i = 1; i < m; ) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

vector<int> kmpSearchAll(string text, string pattern) {
    vector<int> occurrences;
    if (pattern.empty()) return occurrences;

    int n = text.length();
    int m = pattern.length();
    vector<int> lps = computeLPS(pattern);
    int i = 0, j = 0;
    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
            if (j == m) {
                occurrences.push_back(i - j);
                j = lps[j - 1];
            }
        } else {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return occurrences;
}

int shortestMatchingSubstring(string s, string p) {
    size_t firstStar = p.find('*');
    size_t secondStar = p.find('*', firstStar + 1);
    if (firstStar == string::npos || secondStar == string::npos) return -1;
    string part1 = p.substr(0, firstStar), part2 = p.substr(firstStar + 1, secondStar - firstStar - 1), part3 = p.substr(secondStar + 1);
    int len1 = part1.length(), len2 = part2.length(), len3 = part3.length();
    vector<int> part1Positions, part2Positions, part3Positions;
    if (!part1.empty()) {
        part1Positions = kmpSearchAll(s, part1);
        if (part1Positions.empty()) return -1;
    }
    if (!part2.empty()) {
        part2Positions = kmpSearchAll(s, part2);
        if (part2Positions.empty() && !part3.empty()) return -1;
    }
    if (!part3.empty()) {
        part3Positions = kmpSearchAll(s, part3);
        if (part3Positions.empty()) return -1;
    }
    int minLength = INT_MAX;
    if (!part1.empty()) {
        for (int i : part1Positions) {
            int part1End = i + len1;
            if (part2.empty()) {
                int j = part1End;
                int part2End = j;
                if (part3.empty()) {
                    minLength = min(minLength, part2End - i);
                } else {
                    auto it3 = lower_bound(part3Positions.begin(), part3Positions.end(), part2End);
                    if (it3 != part3Positions.end()) {
                        int k = *it3;
                        minLength = min(minLength, (k + len3) - i);
                    }
                }
            } else {
                auto it2 = lower_bound(part2Positions.begin(), part2Positions.end(), part1End);
                while (it2 != part2Positions.end()) {
                    int j = *it2;
                    int part2End = j + len2;
                    if (part3.empty()) {
                        minLength = min(minLength, part2End - i);
                        break;
                    } else {
                        auto it3 = lower_bound(part3Positions.begin(), part3Positions.end(), part2End);
                        if (it3 != part3Positions.end()) {
                            int k = *it3;
                            minLength = min(minLength, (k + len3) - i);
                            break;
                        }
                    }
                    ++it2;
                }
            }
        }
    } else {
        if (part2.empty()) {
            if (part3.empty()) {
                return 0;
            } else {
                if (part3Positions.empty()) return -1;
                minLength = part3.length();
            }
        } else {
            for (int j : part2Positions) {
                int part2End = j + len2;
                if (part3.empty()) {
                    minLength = min(minLength, part2End - j);
                } else {
                    auto it3 = lower_bound(part3Positions.begin(), part3Positions.end(), part2End);
                    if (it3 != part3Positions.end()) {
                        int k = *it3;
                        minLength = min(minLength, (k + len3) - j);
                    }
                }
            }
        }
    }
    return minLength == INT_MAX ? -1 : minLength;
}
int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        string s,p;
        cin >> s >> p;
        cout << shortestMatchingSubstring(s,p) << endl;
    }
}