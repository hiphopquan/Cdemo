#include<stdio.h>
#include<vector>
using namespace std; 
struct E{
	int next;
	int c;
	int co;
}; 
int Dis[1001];
bool mark[1001];
int Cost[1001];
vector<E> edge[1001];
int main(){
	int n,m;
	int s,t;
	while(scanf("%d%d",&n,&m)!=EOF){
		if(n==0&&m==0) break;
		for(int i=1;i<=n;i++) edge[i].clear(); 
		for(int i=0;i<m;i++){
			int a,b,c,cos;
			scanf("%d%d%d%d",&a,&b,&c,&cos);
			E tmp;
			tmp.next=b;
			tmp.c=c;
			tmp.co=cos;
			edge[a].push_back(tmp);
			tmp.next=a;
			edge[b].push_back(tmp);
		}
		for(int i=1;i<=n;i++){
			Dis[i]=-1;
			mark[i]=false;
			Cost[i]=0;
		}
		scanf("%d%d",&s,&t);
		Dis[s]=0;
		mark[s]=true;
		int newP=s;
		for(int i=1;i<n;i++){
			for(int j=0;j<edge[newP].size();j++){
				int t=edge[newP][j].next;
				int c=edge[newP][j].c;
				int co=edge[newP][j].co;
				if(mark[t]==true) continue;
				if(Dis[t]==-1||Dis[t]>Dis[newP]+c||Dis[t]==Dis[newP]+c&&Cost[t]>Cost[newP]+co){//路径变短或路径不变消费降低，更新 
					Dis[t]=Dis[newP]+c;
					Cost[t]=Cost[newP]+co;
				}
			}
			int min=123123123;
			for(int j=1;j<=n;j++){
				if(mark[j]==true) continue;
				if(Dis[j]==-1) continue;
				if(Dis[j]<min){
					min=Dis[j];
					newP=j;
				}
			}
			mark[newP]=true;
		}
		printf("%d %d\n",Dis[t],Cost[t]);
	}
	return 0;
}
