#include<stdio.h>
int n,m,t;
char str[10][10];
int mark[10][10];
int go[][2]={
	-1,0,
	0,1,
	1,0,
	0,-1
};
int flag;
void DFS(int x,int y){
	for(int i=0;i<4;i++){
		int tmpx=x+go[i][0];
		int tmpy=y+go[i][1];
		if(tmpx<0||tmpx>=n||tmpy<0||tmpy>=m) continue;
		if(mark[tmpx][tmpy]==true) continue;
		if(str[tmpx][tmpy]=='X') continue;
		t--;
		mark[tmpx][tmpy]=true;
		if(t==0&&str[tmpx][tmpy]!='D') return;
		if(t==0&&str[tmpx][tmpy]=='D'){
			printf("YES\n");
			flag=1;
			return;	
		} 
		DFS(tmpx,tmpy);
		if(flag==1){
			return;	
		}
		mark[tmpx][tmpy]=false;
	}
} 

int main(){
	while(scanf("%d%d%d",&n,&m,&t)!=EOF){
		flag=0;
		getchar();
		if(n==0||m==0||t==0) break;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				scanf("%c",&str[i][j]);	
				mark[i][j]=false;
			}
			getchar();
		}
		mark[0][0]=true;
		DFS(0,0);
		if(flag==0) printf("NO\n");
		
	}
	return 0;
}
