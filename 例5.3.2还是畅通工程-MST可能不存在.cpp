#include<stdio.h>
#include<algorithm>
#define M 101
using namespace std;
int Tree[M];
int Sum[M];
struct Edge{
	int t1;
	int t2;
	int v;
}edge[5000]; 
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
	int n,m;//道路条数n,村庄数m 
	while(scanf("%d",&n)!=EOF&&n!=0){
		scanf("%d",&m);
		for(int i=1;i<=m;i++){
			Tree[i]=-1;
			Sum[i]=0;	
		} 
		for(int i=0;i<n;i++){
			scanf("%d %d %d",&edge[i].t1,&edge[i].t2,&edge[i].v);
		}
		sort(edge,edge+n,cmp);
		for(int i=0;i<n;i++){
			int a=findRoot(edge[i].t1);
			int b=findRoot(edge[i].t2);
			if(a!=b){
				Tree[a]=b;
				Sum[b]=Sum[b]+Sum[a]+edge[i].v;
			}
		}
		int flag=0,k=0;
		for(int i=1;i<=m;i++){
			if(Tree[i]==-1){
				flag++;
				k=i;
			}
		}
		if(flag==1){
			printf("%d\n",Sum[k]);
		}else{
			printf("?\n");
		}
	}
}
