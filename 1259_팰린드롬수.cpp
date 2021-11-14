#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

int main() {
	while (1) {
		vector <char> v;
		string s;
		cin >> s;
		if (s == "0")
			break;

		int temp = 0;

		int length = s.size();
		for (int i = 0; i < length; i++) {
			if (length % 2 == 1 && i == length / 2) {
				continue;
			}
			
			if (i < length / 2)
				v.push_back(s[i]);
			else{
				if (v.back() == s[i])
					v.pop_back();
				else {
					cout << "no" << endl;
					temp = 1;
					break;
				}
			}
		}

		if(temp == 0)
			cout << "yes" << endl;
	}
}