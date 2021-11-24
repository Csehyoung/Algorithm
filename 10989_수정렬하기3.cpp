#include <iostream>
#include <cstdio>
using namespace std;

int N;
int arr[10001];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int n;
		scanf("%d", &n);
		arr[n]++;
	}

	for (int i = 1; i < 10001; i++) {
		if (arr[i] != 0) {
			for (int j = 0; j < arr[i]; j++) {
				printf("%d\n", i);
			}
		}
	}
}