#include <iostream>
#include <cstdio>
using namespace std;

int A, B, C;

int main() {
	cin >> A >> B >> C;

	if (B >= C)
		cout << -1 << endl;
	else {
		int result = A / (C - B) + 1;
		cout << result << endl;
	}
}