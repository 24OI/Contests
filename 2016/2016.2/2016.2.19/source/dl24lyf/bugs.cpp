#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <string>
#include <iostream>
const int maxn = 1111111;
using std::string;
using std::endl;
using std::cin;
using std::cout;
string left = "0";
string right = "1";
string tmp, T;
string love;
string you;
int ans[maxn];
int a, b;
int n, m, p;
int next[maxn];
int now;
int Find(string pattern, string text) {
	int n = pattern.size();
	for (int i = 1; i < n; ++i) {
		int j = i;
		while (j > 0) {
			j = next[j];
			if (pattern[j] == pattern[i]) {
				next[i + 1] = j + 1;
				break;
			}
		}
	}
	int m = text.size(), sum = 0;
	for (int i = 0, j = 0; i < m; ++i) {
		if (j < n && text[i] == pattern[j]) {
			j++;
		} else {
			while (j > 0) {
				j = next[j];
				if (text[i] == pattern[j]) {
					j++;
					break;
				}
			}
		}
		if (j == n) sum++;
	}
	return sum;
}

void iloveyou() {
	for (int i = 1; i < n && right.size() < m - 1; ++i) {
		tmp = right;
		right = left + right;
		left = tmp;
		now = i;
	}
	love = right.substr(right.size() - m + 1, m - 1) + right.substr(0, m - 1);
	a = ans[now + 1] = Find(T, love);
	tmp = right;
	right = left + right;
	left = tmp;
	you = right.substr(right.size() - m + 1, m - 1) + right.substr(0, m - 1);
	b = ans[now + 2] = Find(T, you);
	if (a == 1 && b == 2) {
		for (int i = now + 3; i <= n; ++i) {
			ans[i] = ans[i - 1] + ans[i - 2] + 1;
		}
	} else if (a == 1 && b == 0) {
		b = ans[now + 2] = 1;
		for (int i = now + 3, k = 1; i <= n; ++i) {
			if (k == 1) {
				ans[i] = (ans[i - 1] + ans[i - 2] + 1) % p;
				k = 0;
			} else {
				ans[i] = (ans[i - 1] + ans[i - 2]) % p;
				k = 1;
			}
		}
	} else if (a == 0 && b == 1) {
		for (int i = now + 3, k = 1; i <= n; ++i) {
			if (k == 1) {
				ans[i] = (ans[i - 1] + ans[i - 2]) % p;
				k = 0;
			} else {
				ans[i] = (ans[i - 1] + ans[i - 2] + 1) % p;
				k = 1;
			}
		}
	} else if (a == 0 && b == 0) {
		cout << 0 << endl;
		exit(0);
	}
	cout << ans[n - 1] << endl;
}

void iloveyou2() {
	//cin >> n >> m >> p >> T;
	for (int i = 1; i < n; ++i) {
		tmp = right;
		right = left + right;
		left = tmp;
	}
	cout << Find(T, right) % p << endl;
}

int main(){	
	freopen("bugs.in", "r", stdin);
	freopen("bugs.out", "w", stdout);
	cin >> n >> m >> p >> T;
	if (n <= 20) iloveyou2();
	else iloveyou();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

