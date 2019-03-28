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
	int n,m;
	while(scanf("%d",&n)!=EOF&&n!=0){
		scanf("%d",&m);
		for(int i=1;i<N;i++){
			Tree[i]=-1;
		}
		int max=0;
		for(int i=0;i<m;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			if(a>max&&a>b) max=a;
			if(b>a&&b>max) max=b;
			a=findRoot(a);
			b=findRoot(b);
			if(a!=b){
				Tree[a]=b;
			}
		}
		int count=0;
		for(int i=1;i<=n;i++){
			if(Tree[i]==-1){
				count++;	
			} 
		}	
		if(count==1) printf("YES\n");
		else printf("NO\n");
	}
	return 0; 
}
