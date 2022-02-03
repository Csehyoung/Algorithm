#include <iostream>
#include <cstdio>
using namespace std;

int N;
int arr[101];
long long int dp[101][21];

long long int search(int idx, int sum) {
	if (idx == N - 1) {
		if (sum == arr[idx])
			return 1;
		else
			return 0;
	}

	long long int& ret = dp[idx][sum];
	if (ret != 0)
		return ret;

	if (sum + arr[idx] > 20) {
		if (sum - arr[idx] < 0)
			return 0;
		else
			ret += search(idx + 1, sum - arr[idx]);
	}
	else if (sum - arr[idx] < 0) {
		if (sum + arr[idx] > 20)
			return 0;
		else
			ret += search(idx + 1, sum + arr[idx]);
	}
	else {
		ret += search(idx + 1, sum + arr[idx]);
		ret += search(idx + 1, sum - arr[idx]);
	}

	return ret;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	long long int result = search(1, arr[0]);

	cout << result << endl;
}