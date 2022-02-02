#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

string str1;
string str2;
int dp[4001][4001];

int main() {
	cin >> str1;
	cin >> str2;

	int result = 0;
	int length1 = str1.size();
	int length2 = str2.size();
	for (int i = 1; i <= length1; i++) {
		for (int j = 1; j <= length2; j++) {
			if (str1[i - 1] == str2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				result = max(result, dp[i][j]);
			}
		}
	}

	cout << result << endl;
}