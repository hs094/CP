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
        else {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return occ;
}

int findShortestSubstring(string s, string p) {
    size_t firstStar = p.find('*');
    if (firstStar == string::npos) return -1;
    size_t secondStar = p.find('*', firstStar + 1);
    if (secondStar == string::npos) return -1;

    string part1 = p.substr(0, firstStar);
    string part2 = p.substr(firstStar + 1, secondStar - firstStar - 1);
    string part3 = p.substr(secondStar + 1);

    vector<int> part1Positions;
    if (part1.empty()) {
        part1Positions.push_back(0);
    } else {
        part1Positions = kmp(s, part1);
        if (part1Positions.empty()) return -1;
    }

    vector<int> part2Positions;
    if (!part2.empty()) {
        part2Positions = kmp(s, part2);
        if (part2Positions.empty()) return -1;
    }

    vector<int> part3Positions;
    if (!part3.empty()) {
        part3Positions = kmp(s, part3);
        if (part3Positions.empty()) return -1;
    }
    int minLength = INT_MAX;
    for (int p1 : part1Positions) {
        int part1End = p1 + part1.length();
        // Handle part2
        int p2, part2End;
        if (part2.empty()) {
            p2 = part1End;
            part2End = part1End;
        } else {
            auto it = lower_bound(part2Positions.begin(), part2Positions.end(), part1End);
            if (it == part2Positions.end()) continue;
            p2 = *it;
            part2End = p2 + part2.length();
        }
        // Handle part3
        int p3, part3Len;
        if (part3.empty()) {
            p3 = part2End;
            part3Len = 0;
        } else {
            auto it = lower_bound(part3Positions.begin(), part3Positions.end(), part2End);
            if (it == part3Positions.end()) continue;
            p3 = *it;
            part3Len = part3.length();
        }
        minLength = min(minLength, (p3 + part3Len) - p1);
    }

    return minLength == INT_MAX ? -1 : minLength;
}

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        string s,p;
        cin >> s >> p;
        cout << findShortestSubstring(s,p) << endl;
    }
}