#include<stdio.h>
#include<algorithm>
#define N 100
#define M N*(N-1)/2
using namespace std;
int Tree[N];
struct Edge{
	int t1;
	int t2;
	int v;
	int f;
}edge[M];

int findRoot(int x){
	if(Tree[x]==-1) return x;
	else{
		int tmp=findRoot(Tree[x]);
		Tree[x]=tmp;
		return tmp;
	}
}

int cmp(Edge a,Edge b){
	return a.v<b.v;
}

int main(){
	int n;
	while(scanf("%d",&n)!=EOF&&n!=0){
		int m=n*(n-1)/2;
		for(int i=0;i<n;i++){
			Tree[i]=-1;
		}
		for(int i=0;i<m;i++){
			scanf("%d%d%d%d",&edge[i].t1,&edge[i].t2,&edge[i].v,&edge[i].f);
		}
		sort(edge,edge+m,cmp);
		int k=0;
		for(int i=0;i<m;i++){
			int a=findRoot(edge[i].t1);
			int b=findRoot(edge[i].t2);
			if(edge[i].f==1){
				Tree[a]=b;
				k++;
			}
		}
		int ans=0;
		for(int i=0;i<m;i++){
			int a=findRoot(edge[i].t1);
			int b=findRoot(edge[i].t2);
			if(edge[i].f==0){
				if(a!=b&&k<n-1){
					Tree[a]=b;
					ans+=edge[i].v;
					k++;
				}
			}
		}
		printf("%d\n",ans);
	}
}
