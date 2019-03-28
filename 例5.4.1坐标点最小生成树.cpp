#include<stdio.h>
#include<algorithm>
#include<math.h> 
#define N 101
#define M 5000
using namespace std;
struct Point{//点集 
	double x;
	double y;
}point[N];

struct Edge{//边集 
	int p1;
	int p2;
	double v;
}edge[M];
int cmp(Edge a,Edge b){
	return a.v<b.v;
}
int Tree[N];//连通分量 
int findRoot(int x){
	if(Tree[x]==-1) return x;
	else{
		int tmp=findRoot(Tree[x]);
		Tree[x]=tmp;
		return tmp;
	}
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int m=0;
		for(int i=1;i<=n;i++) Tree[i]=-1;
		for(int i=1;i<=n;i++){
			scanf("%lf%lf",&point[i].x,&point[i].y);//double用%lf输入，%f输入出错 
		}
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				double len;
				len=pow((point[i].x-point[j].x),2)+pow((point[i].y-point[j].y),2);
				len=sqrt(len);
				edge[m].p1=i;
				edge[m].p2=j;
				edge[m].v=len;
				m++;
			}
		}
		sort(edge,edge+m,cmp);
		double ans=0;
		for(int i=0;i<m;i++){
			int a=findRoot(edge[i].p1);
			int b=findRoot(edge[i].p2);
			if(a!=b){
				Tree[a]=b;
				ans+=edge[i].v;
			}
		}
		printf("%.2lf\n",ans);
	}
}
