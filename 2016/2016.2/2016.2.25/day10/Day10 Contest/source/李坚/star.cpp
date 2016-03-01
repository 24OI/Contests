#include<iostream>
#include<cstdio>
//#include<cmath>
using namespace std;
int n;
struct line
{
  int A,B,C;
  double k,b;
};
struct point
{
	int x,y,num;
};
int Max=0;
line l[10001];
point map[1000001];
int trunc(double x)
{
	if (x-int(x)>=0.5)
		return int(x)+1;
	else return int(x);
}
int init()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>l[i].A>>l[i].B>>l[i].C;
		if (l[i].B!=0)
		{
		l[i].k=-(l[i].A/l[i].B);
		l[i].b=-(l[i].C/l[i].B);
	  }
	}
}
int main()
{
	freopen("star.in","r",stdin);
	freopen("star.out","w",stdout);
	init();
  for (int i=1;i<=n;i++)
  {
    for (int j=i+1;j<=n;j++)
    {
    	if (l[i].k!=l[j].k)
    	{
             bool p=true;
             double x;
             double y;
            if (l[i].B!=0 && l[j].B!=0)
    		    {
             x=(l[i].b-l[j].b)/(l[j].k-l[i].k);
             y=x*l[i].k+l[i].b;
            }
            else 
            {
              if (l[i].B==0)
              {
                x=-(l[i].C/l[i].A);
                y=x*l[j].k+l[j].b;
              }
              if (l[j].B==0)
              {
                 x=-(l[j].C/l[j].A);
                y=x*l[i].k+l[i].b;
              }
              if (l[i].B==0 && l[j].B==0)
              {
                p=false;
              }
            } 

            if (p==true)
            {
            double X=x;
            double Y=y;
           
            bool b=true;
            for (int i=1;i<=map[0].num;i++)
            {
             if (map[i].x==X && map[i].y==Y)
             {
             	b=false;
             	map[i].num++;
             	Max=max(Max,map[i].num);
             	break;
             }         
            }
            if (b==true)
            {
              map[0].num++;
              map[map[0].num].x=X;
              map[map[0].num].y=Y;
              map[map[0].num].num=2;
              Max=max(Max,map[map[0].num].num);
            }
          }
    	}
    }
  }
  int num=0;
  for (int i=1;i<=map[0].num;i++)
  {
     if (map[i].num==Max)
     {
		 num++;
     }
  }
  cout<<Max<<" "<<num<<endl;
}
