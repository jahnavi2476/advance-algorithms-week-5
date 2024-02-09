#include <vector>
#include <string>
#include <iostream>
using namespace std;

string calculateCarsAndLength(const string &str1, const string &str2)
{
    int n = str1.size(), m = str2.size();
    vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0));
    int maxLen = 0, endPos = 0;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLen)
                {
                    maxLen = dp[i][j];
                    endPos = i - 1;
                }
            }
        }
    }

    return str1.substr(endPos - maxLen + 1, maxLen);
}

int main()
{
    string str1, str2;
    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;

    string res = calculateCarsAndLength(str1, str2);
    cout << "The longest substring is: " << res << " with length: " << res.size() << "\n";
    return 0;
}
