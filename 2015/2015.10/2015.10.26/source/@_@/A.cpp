#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<bitset>
#include<queue>
using namespace std;
const int N=1000011;
int a[N];

/*
10
1 2 1 3 2 4 5 4 2 
20
1 2 1 2 3 2 3 4 2 3 5 2 1 6 5 3 5 6 7
10
1 1 1 2 2 2  3 3 3 
3
1 3
3
1 4

*/
int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
   int n;
   cin>>n;
   //�����ǰҪ��������������һ���Ͳ����� 
   for(int i=1;i<n;i++)
    scanf("%d",&a[i]);
  //������Ϸ� �ǲ��Ϸ���������֮ǰ�ж��ٸ���λ 
   int lala=0;
   int pos=0;//��һ�����ֵ�ǰ���ֵ��λ�� 
   int cnt=0; 
   long long ans=9999999999LL;
   for(int i=1;i<=n;i++)
   {
   	  if(a[i]-lala>2)
		 {
		 	 cout<<"0"<<endl;
		 	 return 0;
		 } 
	  if(a[i]-lala==2)
	    {
	      if(cnt)
	      {
		    cout<<"0"<<endl;
	        return 0;
		  }
	      ans=i-pos,cnt++;
	    }  
	  if(a[i]>lala)lala=a[i],pos=i;
	}  
    if(ans!=9999999999LL)
	{
		cout<<ans<<endl;
		return 0;
	}
	ans=0;  
	lala=0;//��ǰ�����Ѿ��Ϸ� lalaΪ���ֹ������ֵ 
    for(int i=1;i<n;i++)
    {
		ans+=lala+1;
    	lala=max(lala,a[i]);
    }
	ans+=lala+1;
	cout<<ans-n+1<<endl;
	fclose(stdin);
	fclose(stdout);
	
   	
}
