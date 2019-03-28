#include<stdio.h>
#include<vector>
using namespace std;
struct E{
	int next;
	int t;
};
vector<E> edge[10001];
int Dis[601];
int Camp[601];
bool mark[601];
int main(){
	int n,m;
	while(scanf("%d",&n)!=EOF){
		if(n==0) break;
		scanf("%d",&m);
		for(int i=1;i<=n;i++){
			edge[i].clear();
			Dis[i]=-1;
			mark[i]=false;
		}
		for(int i=0;i<m;i++){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			E tmp;
			tmp.next=b;
			tmp.t=c;
			edge[a].push_back(tmp);
			tmp.next=a;
			edge[b].push_back(tmp);
		}	
		for(int i=1;i<=n;i++){
			scanf("%d",&Camp[i]);
		}
		Dis[1]=0;
		mark[1]=true;
		int newP=1;
		for(int i=1;i<n;i++){
			for(int j=0;j<edge[newP].size();j++){
				int t=edge[newP][j].next;
				int c=edge[newP][j].t;
				if(mark[t]==true) continue;
				if((Dis[t]==-1||Dis[t]>Dis[newP]+c)&&!(Camp[newP]==2&&Camp[t]==1)){//Ö»ÔÊÐí1->2 1->1 2->2 
					Dis[t]=Dis[newP]+c;
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
		if(mark[2]==false){
			printf("-1\n");
		}else{
			printf("%d\n",Dis[2]);
		}
	}
}
