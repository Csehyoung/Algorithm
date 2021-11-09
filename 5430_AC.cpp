#include <iostream>
#include <cstdio>
#include <string>
#include <deque>
using namespace std;

string cmd;
string str;
int N;
deque <int> d;

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cmd = "";
		str = "";
		d.clear();
		
		cin >> cmd;
		cin >> N;
		cin >> str;
		
		int length = str.size();
		string num = "";
		for (int i = 0; i < length; i++) {
			if (str[i] != '[' && str[i] != ',' && str[i] != ']')
				num += str[i];
			else if ((str[i] == ',' || str[i] == ']') && num != "") {
				d.push_back(stoi(num));
				num = "";
			}
		}

		bool error = false;
		length = cmd.size();
		int temp = 0;
		for (int i = 0; i < length; i++) {
			if (cmd[i] == 'D' && d.size() == 0) {
				cout << "error" << endl;
				error = true;
				break;
			}

			if (cmd[i] == 'R') {
				if (temp == 0)
					temp = 1;
				else if (temp == 1)
					temp = 0;
			}
			else if (cmd[i] == 'D') {
				if (temp == 0) {
					d.pop_front();
				}
				else if (temp == 1) {
					d.pop_back();
				}
			}
		}

		if (error)
			continue;

		cout << "[";
		length = d.size();
		for (int i = 0; i < length; i++) {
			if (temp == 0) {
				if (i == length - 1)
					printf("%d", d[i]);
				else
					printf("%d,", d[i]);
			}
			if (temp == 1) {
				if (i == length - 1)
					printf("%d", d[length - 1 - i]);
				else
					printf("%d,", d[length - 1 - i]);
			}
		}
		cout << "]" << endl;
	}
}