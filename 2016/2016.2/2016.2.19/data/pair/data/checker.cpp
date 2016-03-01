#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<fstream>
using namespace std;
//ofstream out("C:\\TEST\\2014820\\data\\pair\\DEBUG.txt");
FILE *fscore,*freport,*fstd,*fin,*fout;
const int N=20010;
const int M=400010;
int u[M],v[M];
int n,m,i,j,k,l,lose,ans[M],vis[M],Xor[N],save[N],deep[N];
int head[N],list[M],next[M],tot=1;
void add(int a,int b)
{
	tot++;
	list[tot]=b;
	next[tot]=head[a];
	head[a]=tot;
}
int dfs(int x,int fa)
{
	deep[x]=deep[list[fa]]+1;
	vis[x]=1;
	for(int i=head[x];i;i=next[i])
	if(i!=fa)
	{
		if(vis[list[i]])
		{
			if(deep[list[i]]<deep[x])
			{
				Xor[list[i]]^=1;
				ans[i>>1]=i&1;
			}
		}
		else
		{
			Xor[list[i]]^=1;
			ans[i>>1]=i&1;
			int k=dfs(list[i],i^1);
			Xor[x]^=k;
		}
	}
	if(Xor[x])ans[fa>>1]^=1;
	return Xor[x];
}
int calc()
{
	int i,j,k;
	fscanf(fin,"%d%d",&n,&m);
	for(i=1;i<=m;i++)
	{
		fscanf(fin,"%d%d",&j,&k);
		//out<<j<<' '<<k<<endl;
		u[i]=j;v[i]=k;
		add(j,k);add(k,j);
	}
	for(i=1;i<=n;i++)
	if(!vis[i]&&dfs(i,0)!=0)lose++;
	return (m-lose)/2;
}

bool Judge()
{
	int ans=calc();
	int i,j,k,n;
	fscanf(fout,"%d",&n);
	if(n!=ans)
	{
		fprintf(freport,"The number of match is %d.Your answer is %d.\n",ans,n);
		return false;
	}
	memset(vis,0,sizeof(vis));
	while(n--)
	{
		if(fscanf(fout,"%d%d",&i,&j)==EOF)
		{
			fprintf(freport,"Input Error");
			return false;
		}
		if(i<=0||i>m||j<=0||j>m||vis[i]||vis[j])
		{
			if(i<=0||i>m||j<=0||j>m)
			fprintf(freport,"Input Wrong.");
			if(vis[i]>0)
			fprintf(freport,"Edge %d appeared twice.",i);
			if(vis[j]>0)
			fprintf(freport,"Edge %d appeared twice.",j);
			return false;
		}
		vis[i]=vis[j]=1;
		if(u[i]!=u[j]&&u[i]!=v[j]&&v[i]!=u[j]&&v[i]!=v[j])
		{
			fprintf(freport,"Wrong type 2.");
			return false;
		}
	}
	return true;
}

int main(int argc,char *argv[])
{
	fscore=fopen("score.log","w");//�򿪵÷��ļ�
	freport=fopen("report.log","w");//�򿪱����ļ�
	fstd=fopen(argv[2],"r");//�򿪲��Ե��׼����ļ�
	int score=atoi(argv[1]);//ȡ�ò��Ե�ķ���
	
	fin=fopen("pair.in","r");//�򿪲��Ե��׼�����ļ�
	fout=fopen("pair.out","r");//���û�����������ļ�
	if (!fout)
	{
		fprintf(fscore,"%d",0);//����0��
		fprintf(freport,"no output");//����Judge���Ϊno output
	}
	else if (Judge())//Judge����Ϊ��
	{
		fprintf(fscore,"%d",score);//��������
		fprintf(freport,"right");//����Judge���Ϊright
	}
	else
	{
		fprintf(fscore,"%d",0);//����0��
		fprintf(freport,"wrong");//����Judge���Ϊwrong
	}
	
	fclose(fscore);//�رյ÷��ļ�
	fclose(freport);//�رձ����ļ�
	return 0;
}
