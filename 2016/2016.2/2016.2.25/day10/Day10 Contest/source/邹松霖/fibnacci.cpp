#include<iostream>
#include<cstdio>
using namespace std;
int  array[100000];
long long num[100000];
long long an[50000];
int main()
{  
   freopen("Fibnacci.in","r",stdin);
   freopen("Fibnacci.out","w",stdout);
   int n,m,x,y,flag,pos;
   long long ans;
   array[1]=1;
   array[2]=1;
  ans=0;pos=0;
   for (int i=3;i<=100000;i++)
   array[i]=(array[i-1]+array[i-2])%(1000000000+1);
   scanf("%d %d",&n,&m);
   for (int i=1;i<=n;i++)
   scanf("%d",&num[i]);
   for (int i=1;i<=m;i++)
   {
   scanf("%d %d %d",&flag,&x,&y);
   if (flag==1)
   {
     for(int j=x;j<=y;j++)
     num[j]+=array[j-x+1];
   }
   else
   {
   for(int j=x;j<=y;j++)
   ans+=num[j];
   an[++pos]=ans;
   ans=0;
   }
   }
   for (int i=1;i<=pos;i++)
   cout<<an[i];
  fclose(stdin);fclose(stdout);
}
