#include<stdio.h>

int Tree[1000];
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
	int a,b;
	while(scanf("%d",&n)!=EOF&&n!=0){
		scanf("%d",&m);
		for(int i=1;i<1000;i++){
			Tree[i]=-1;
		}
		while(m-->0){
			scanf("%d%d",&a,&b);
			a=findRoot(a);
			b=findRoot(b); 
			if(a!=b){
				Tree[a]=b;			
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(Tree[i]==-1){
				ans++;
			}
		} 
		
		printf("%d\n",ans-1);
	}
} 
