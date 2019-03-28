#include<stdio.h>
#define N 1001
int Tree[N];
int findRoot(int x){
	if(Tree[x]==-1) return x;
	else{
		int tmp=findRoot(Tree[x]);
		Tree[x]=tmp;
		return tmp;
	}
}
int main(){
	int t,n,m;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		scanf("%d%d",&n,&m);
		for(int j=1;j<N;j++) Tree[j]=-1;
		for(int j=0;j<m;j++){
			int a,b;
			scanf("%d%d",&a,&b);
			a=findRoot(a);
			b=findRoot(b);
			if(a!=b) Tree[a]=b;
		}
		int count=0;
		for(int j=1;j<=n;j++){
			if(Tree[j]==-1){
				count++;
			} 
		}
		printf("%d\n",count);
	}
	
	return 0;
}
