#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int n,m,t1,t2,t3,ans;
int all[1002][1002],p[1002];

void merge(int a[],int l,int m,int r,int temp[]){  
    int i=l;  
    int j=m+1;  
    int k =l;  
    while(i<=m&&j<=r){  
        if(a[i]>a[j]){  
            temp[k++]=a[j++];  
            ans+=m-i+1;  
        }  
        else{  
            temp[k++]=a[i++];  
        }  
    }  
    while (i<=m) temp[k++]=a[i++];  
    while (j<=r) temp[k++]=a[j++];  
    for (int i=l;i<=r;i++) a[i]=temp[i];  
}  
void sort(int a[],int first,int last,int temp[]){  
    if (first<last){  
        int mid=(first+last)/2;  
        sort(a,first,mid,temp); 
        sort(a,mid+1,last,temp);  
        merge(a,first,mid,last,temp); 
    }  
}  

void ms(int a[],int n)  {  
    memset(p,0,sizeof(p));  
    sort(a,1,n,p);  
}  

int main(){
	freopen("lyk.in","r",stdin);
	freopen("lyk.out","w",stdout);
	
	cin>>n;
	for (int i=1;i<=n;i++) cin>>all[1][i];
	cin>>m;
	for (int i=2;i<=m;i++){
		for (int j=1;j<=n;j++){
			all[i][j]=all[1][j];
		}
	}
	
	for (int i=1;i<=m;i++){
		cin>>t1>>t2;
		ans=0;
		for (int j=i;j<=m;j++){
			t3=all[j][t1];
			all[j][t1]=all[j][t2];
			all[j][t2]=t3;
		}
		ms(all[i],n);
		cout<<ans<<endl;
	}
	
	return 0;
}