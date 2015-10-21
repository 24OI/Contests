#include <cstdio>
#include <cmath>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

int n, a[100086];
int l[100086], r[100086];
int vis[100086];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		l[i] = i - 1, r[i] = i + 1;
	}
	r[n] = 0;
	l[0] = n;
	r[0] = 1;
	queue<int> ll;
	for(int i = 2; i <= n; i++) if(a[i - 1] > a[i]) ll.push(i);
	int cnt = 0;
	while(ll.size()){
		int f = 0;
		queue<int> tt;
		while(ll.size()){
			int x = ll.front();
			ll.pop();
			if(vis[x]) continue;
			vis[x] = 1;
			f = 1;
			r[l[x]] = r[x];
			l[r[x]] = l[x];
			if(r[x] && a[l[x]] > a[r[x]]) tt.push(r[x]);
		}
		cnt += f;
		ll = tt;
	}
	printf("%d\n", cnt);
	return 0;
}
