#include<stdio.h>
int ans[18];
bool mark[18];
int s[13]={2,3,5,7,11,13,17,19,23,29,31,37,41}; 
int n;
bool judge(int x){
	for(int i=0;i<13;i++){
		if(s[i]==x) return true;
	}
	return false;
}

void check(){
	if(judge(ans[n]+ans[1])==false) return;
	for(int i=1;i<=n;i++){
		if(i==1) printf("%d",ans[i]);
		else printf(" %d",ans[i]);
	} 
	printf("\n");
}

void DFS(int num){
	if(num>1){
		if(judge(ans[num]+ans[num-1])==false) return;
	}
	if(num==n){
		check();
		return;
	}
	for(int i=2;i<=n;i++){
		if(mark[i]==false){
			mark[i]=true;
			ans[num+1]=i;
			DFS(num+1);
			mark[i]=false;
		}
	}
}

int main(){
	int cse=0;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<=n;i++){
			mark[i]=false;
			ans[i]=0;
		}
		cse++;
		ans[1]=1;
		mark[1]=true;
		printf("Case%d:\n",cse);
		DFS(1);
		
	}
}
