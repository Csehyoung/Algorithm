#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

string str1;
string str2;
int dp[1001][1001];
string lcs[1001][1001];

int main() {
	cin >> str1 >> str2;

	int length1 = str1.size();
	int length2 = str2.size();
	int idx = 1;
	for (int i = 1; i <= length1; i++) {
		for (int j = 1; j <= length2; j++) {
			if (str1[i - 1] == str2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				lcs[i][j] = lcs[i][j] + lcs[i - 1][j - 1] + str1[i - 1];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			
				if (lcs[i - 1][j].length() > lcs[i][j - 1].length())
					lcs[i][j] = lcs[i - 1][j];
				else
					lcs[i][j] = lcs[i][j - 1];
			}
		}
	}

	cout << dp[length1][length2] << endl;
	cout << lcs[length1][length2] << endl;
}