// Name: ±iµq¶v (B11030202@mail.ntust.edu.tw)
// Date: April 19, 2023
// Last Update: April 19, 2023
// Problem statement: Levenshtein Distance

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

// Indent: Calculate Levenshtein Distance
// Pre: The variables word1 and word2 are input string
// Post: The function returns Levenshtein distance between word1 and word2
int levenshteinDistance(string word1, string word2) {
    int m = word1.length();
    int n = word2.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) {
                dp[i][j] = j;
            }
            else if (j == 0) {
                dp[i][j] = i;
            }
            else if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = 1 + min({ dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1] });
            }
        }
    }

    return dp[m][n];
}

int main()
{
    for (string str1, str2; getline(cin, str1) && getline(cin, str2);)
        cout << levenshteinDistance(str1, str2) << endl;

    return 0;
}