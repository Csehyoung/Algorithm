#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

int N;

int main() {
	cin >> N;
	cin.ignore();
	for (int i = 0; i < N; i++) {
		string s;
		
		getline(cin, s);
		s += ' ';

		vector <char> v;
		int length = s.size();
		for (int i = 0; i < length; i++) {
			if (s[i] != ' ') {
				if (i == length - 1)
					break;

				v.push_back(s[i]);
			}
			else {
				int len = v.size();
				for (int j = 0; j < len; j++) {
					printf("%c", v.back());
					v.pop_back();
				}

				printf(" ");
			}
		}

		cout << endl;
	}
}