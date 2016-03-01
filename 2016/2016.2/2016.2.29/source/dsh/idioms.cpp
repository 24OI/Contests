#include<cstdio>
#include<cstring>
#include<vector>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

vector<int>was[100002];
vector<int>table[802];
char all[50002][4];
int n,d,sum,tm;

bool check(int a,int b){
	tm=min(a,b);
	for (int i=0;i<was[a+b].size();i++){
		if (was[a+b][i]==tm) return 0;
	}
	was[a+b].push_back(tm);
	int ct=0;
	if (all[a][0]==all[b][0]) ct++;
	if (all[a][1]==all[b][1]) ct++;
	if (all[a][2]==all[b][2]) ct++;
	if (all[a][3]==all[b][3]) ct++;
	if (ct==d) return 1;
	return 0;
}

int main(){
	freopen ("idioms.in","r",stdin);
	freopen ("idioms.out","w",stdout);
	
	scanf ("%d%d",&n,&d);
	for (int i=1;i<=n;i++) scanf ("%s",all[i]);
	
	for (int i=1;i<=n;i++){
		table[all[i][0]].push_back(i);
		table[all[i][1]*2].push_back(i);
		table[all[i][2]*3].push_back(i);
		table[all[i][3]*4].push_back(i);
	}
	
	for (int i='0';i<='9';i++){
		for (int j=0;j<table[i].size();j++){
			for (int k=j+1;k<table[i].size();k++){
				if (check(table[i][j],table[i][k])) sum++;
			}
		}
	}
	
	for (int i='a';i<='z';i++){
		for (int j=0;j<table[i].size();j++){
			for (int k=j+1;k<table[i].size();k++){
				if (check(table[i][j],table[i][k])) sum++;
			}
		}
	}
	
	for (int i='0';i<='9';i++){
		for (int j=0;j<table[i*2].size();j++){
			for (int k=j+1;k<table[i*2].size();k++){
				if (check(table[i*2][j],table[i*2][k])) sum++;
			}
		}
	}
	
	for (int i='a';i<='z';i++){
		for (int j=0;j<table[i*2].size();j++){
			for (int k=j+1;k<table[i*2].size();k++){
				if (check(table[i*2][j],table[i*2][k])) sum++;
			}
		}
	}
	
	for (int i='0';i<='9';i++){
		for (int j=0;j<table[i*3].size();j++){
			for (int k=j+1;k<table[i*3].size();k++){
				if (check(table[i*3][j],table[i*3][k])) sum++;
			}
		}
	}
	
	for (int i='a';i<='z';i++){
		for (int j=0;j<table[i*3].size();j++){
			for (int k=j+1;k<table[i*3].size();k++){
				if (check(table[i*3][j],table[i*3][k])) sum++;
			}
		}
	}
	
	for (int i='0';i<='9';i++){
		for (int j=0;j<table[i*4].size();j++){
			for (int k=j+1;k<table[i*4].size();k++){
				if (check(table[i*4][j],table[i*4][k])) sum++;
			}
		}
	}
	
	for (int i='a';i<='z';i++){
		for (int j=0;j<table[i*4].size();j++){
			for (int k=j+1;k<table[i*4].size();k++){
				if (check(table[i*4][j],table[i*4][k])) sum++;
			}
		}
	}
	
	printf ("%d",sum);
	
	return 0;
}













