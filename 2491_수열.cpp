#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int N;
int arr[100001];
int dp[100001][2];

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		scanf("%d", &arr[i]);

	dp[1][0] = 1;
	dp[1][1] = 1;
	for (int i = 2; i <= N; i++) {
		dp[i][0] = 1;
		dp[i][1] = 1;
		if (arr[i - 1] < arr[i]) 
			dp[i][0] = dp[i - 1][0] + 1;
		else if (arr[i - 1] > arr[i]) 
			dp[i][1] = dp[i - 1][1] + 1;
		else if (arr[i - 1] == arr[i]) {
			dp[i][0] = dp[i - 1][0] + 1;
			dp[i][1] = dp[i - 1][1] + 1;
		}
	}

	int result = 0;
	for (int i = 1; i <= N; i++) {
		result = max(result, dp[i][0]);
		result = max(result, dp[i][1]);
	}

	cout << result << endl;
}