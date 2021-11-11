#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector <char> v;

int main() {
	string s;
	while (!cin.eof()) {
		getline(cin, s);
		if (s.length() == 1 && s[0] == '.') 
			break;
		v.clear();

		int length = s.size();
		for (int i = 0; i < length; i++) {
			if (s[i] == '[' || s[i] == '(') {
				v.push_back(s[i]);
				continue;
			}
			
			if (s[i] == ']') {
				if (v.size() == 0) {
					cout << "no" << endl;
					break;
				}

				if (v.back() == '[')
					v.pop_back();
				else {
					cout << "no" << endl;
					break;
				}
			}
			if (s[i] == ')') {
				if (v.size() == 0) {
					cout << "no" << endl;
					break;
				}

				if (v.back() == '(')
					v.pop_back();
				else {
					cout << "no" << endl;
					break;
				}
			}

			if (i == length - 1) {
				if (v.size() == 0)
					cout << "yes" << endl;
				else
					cout << "no" << endl;
			}
		}
	}
}