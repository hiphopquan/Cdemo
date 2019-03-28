#include<stdio.h>
#include<algorithm> 
#define N 100
#define M N*(N-1)/2
using namespace std;
int Tree[N];
int Sum[N];
struct Edge{
	int t1;
	int t2;
	int v;
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
			Sum[i]=0;
		}
		for(int i=0;i<m;i++){
			scanf("%d%d%d",&edge[i].t1,&edge[i].t2,&edge[i].v);
		}
		sort(edge,edge+m,cmp);
		for(int i=0;i<m;i++){
			int a=findRoot(edge[i].t1);
			int b=findRoot(edge[i].t2);
			if(a!=b){
				Tree[a]=b;
				Sum[b]=Sum[a]+Sum[b]+edge[i].v;
			}
		}
		for(int i=0;i<n;i++){
			if(Tree[i]==-1){
				printf("%d\n",Sum[i]);
			}
		}

	}
	return 0;
}
