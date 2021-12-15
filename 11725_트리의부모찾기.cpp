#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int N;
vector <int> v[100001];
int check[100001];

void search(int idx) {
	int length = v[idx].size();
	for (int i = 0; i < length; i++) {
		int next = v[idx][i];

		if (check[next] == 0) {
			check[next] = idx;
			search(next);
		}
	}
}


int main() {
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int from, to;
		scanf("%d %d", &from, &to);
		v[from].push_back(to);
		v[to].push_back(from);
	}

	check[1] = 1;

	search(1);

	for (int i = 2; i <= N; i++)
		printf("%d\n", check[i]);
}