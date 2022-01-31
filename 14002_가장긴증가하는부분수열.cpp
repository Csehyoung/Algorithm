#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int arr[1001];
int dp[1001];
vector <int> v[1001];


int main() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		scanf("%d", &arr[i]);

	for (int i = 1; i <= N; i++) {
		dp[i] = 1;
		v[i].push_back(arr[i]);

		for (int j = 1; j < i; j++) {
			if (arr[i] > arr[j]) {
				if (dp[i] < dp[j] + 1) {
					dp[i] = dp[j] + 1;
					v[i].clear();
					v[i] = v[j];
					v[i].push_back(arr[i]);
				}
			}
		}
	}

	int result = 0;
	int idx = 0;
	for (int i = 1; i <= N; i++) {
		if (result < dp[i]) {
			result = dp[i];
			idx = i;
		}
	}

	cout << result << endl;
	for (int i = 0; i < result; i++) {
		printf("%d ", v[idx][i]);
	}
	cout << endl;
}