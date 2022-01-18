#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

int dp[5001];

int main() {
	string str;
	cin >> str;
	int length = str.size();

	if (str[0] == '0') {
		cout << 0 << endl;
		return 0;
	}

	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= length; i++) {
		if (str[i - 1] != '0')
			dp[i] = (dp[i] + dp[i - 1]) % 1000000;

		int sum = (str[i - 2] - '0') * 10 + str[i - 1] - '0';
		if (10 <= sum && sum <= 26)
			dp[i] = (dp[i] + dp[i - 2]) % 1000000;
	}

	cout << dp[length] << endl;
}