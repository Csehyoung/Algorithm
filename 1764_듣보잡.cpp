#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

int N, M;

int main() {
	cin >> N >> M;
	vector <string> v;
	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;
		v.push_back(str);
	}

	sort(v.begin(), v.end());

	vector <string> result;
	string str2;
	for (int i = 0; i < M; i++) {
		cin >> str2;
		if (binary_search(v.begin(), v.end(), str2))
			result.push_back(str2);
	}

	sort(result.begin(), result.end());

	int cnt = result.size();
	cout << cnt << endl;
	for (int i = 0; i < cnt; i++) {
		cout << result[i] << endl;
	}
}