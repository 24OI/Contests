#include<iostream>
using namespace std;

int t,ct;

int main(){
	for(int i=1;i<=30;i++){
		ct=0;
		t=(1^i);
		while (t!=0){
			if (t%2!=0) ct++;
			t=t/2;
		}
		cout<<i<<" "<<(1^i)<<" "<<ct<<endl;
	}
	return 0;
}