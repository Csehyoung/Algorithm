#include <iostream>
#include <queue>
using namespace std;

int N, K;
queue <int> q;

int main() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		q.push(i);

	cout << "<";

	while (!q.empty()) {
		for (int i = 0; i < K - 1; i++) {
			q.push(q.front());
			q.pop();
		}

		printf("%d", q.front());
		q.pop();

		if (q.size() != 0) 
			printf(", ");
	}

	cout << ">" << endl;
}