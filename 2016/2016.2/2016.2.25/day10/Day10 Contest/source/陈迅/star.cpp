#include<iostream>
#include<cstdio>
#include<set>
#include<map>
using namespace std;
#define maxn 1005
#define double long double
struct line{
	double a;
	double b;
	double c;
}e[maxn];
map<pair<double,double>,pair<int,int> > haha;
map<pair<double,double>,pair<int,int> >::iterator it;
pair<double,double> tmpp;
void work(int i,int j){
	if((e[i].a/ e[i].b) == (e[j].a / e[j].b)){
			return;
	}
	double x = ((e[i].b*e[j].c)-(e[j].b*e[i].c)) / (e[i].a*e[j].b - e[i].b*e[j].a);
	double y = (e[i].a*e[j].c-e[j].a*e[i].c) / (-e[i].a*e[j].b+e[j].a*e[i].b);
	tmpp.first = x;
	tmpp.second = y;
	if(haha[tmpp].first == 0){
		haha[tmpp].first++;
		haha[tmpp].second = i;
	}
	else if(i == haha[tmpp].second || j == haha[tmpp].second){
		haha[tmpp].first++;
	}
}
int n;
int a,b,c;
int ans = 1;
int main(){
	freopen("star.in","r",stdin);
	freopen("star.out","w",stdout);
	scanf("%d",&n);
	for(int i =0;i<n;i++){
		scanf("%d %d %d",&a,&b,&c);
		e[i].a = a;
		e[i].b = b;
		e[i].c = c;
	}
	for(int i =0;i<n;i++){
		for(int j =0 ;j<i;j++){
			work(i,j);
		}
	}
	int count = 0;
	int maxnow = 0;
	pair<double,double> maxid;
	for(it = haha.begin();it != haha.end();++it){
		if((*it).second.first > maxnow){
			maxnow = (*it).second.first;
			count = 1;
			maxid = (*it).first;
		}
		else if((*it).second.first == maxnow){
			count++;
		}
	}
	printf("%d %d",ans+maxnow,count);
	return 0;
}
