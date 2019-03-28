#include<stdio.h>
#define N 10000001
int Tree[N];
int findRoot(int x){
	if(Tree[x]==-1) return x;
	else{
		int tmp=findRoot(Tree[x]);
		Tree[x]=tmp;
		return tmp;
	}
}
int count[N];
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int a,b;
		for(int i=1;i<N;i++){
			Tree[i]=-1;
			count[i]=0;
		}
			
		int max=0;
		for(int i=0;i<n;i++){
			if(a>b&&a>max) max=a;
			if(b>a&&b>max) max=b;
			scanf("%d%d",&a,&b);
			a=findRoot(a);
			b=findRoot(b);
			if(a!=b){
				Tree[b]=a;
			}
		}
		for(int i=1;i<=max;i++){
			if(Tree[i]==-1){
				count[i]++;
			}else{
				int r=findRoot(i);
				count[r]++;
			}
		}
		int ans=0;
		for(int i=1;i<=max;i++){
			if(count[i]>ans) ans=count[i];
		}
		printf("%d\n",ans);
		
	}
} 
