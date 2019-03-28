#include<stdio.h>
int n,m;
bool mark[101][101];
int cnt=0;
char str[101][101];
int dre[8][2]={
	-1,1,
	-1,0,
	0,1,
	1,1,
	1,0,
	-1,-1,
	0,-1,
	1,-1
};
void DFS(int x,int y){
	
	for(int i=0;i<8;i++){
		int tmpx=x+dre[i][0];
		int tmpy=y+dre[i][1];
		if(tmpx<1||tmpx>n||tmpy<1||tmpy>m) continue;
		if(str[tmpx][tmpy]!='@') continue;
		if(mark[tmpx][tmpy]==true) continue;
		mark[tmpx][tmpy]=true;
		DFS(tmpx,tmpy);
	}
	return;
}

int main(){
	int c=0;
	while(scanf("%d %d",&n,&m)!=EOF){
		getchar();
		if(n==0||m==0) break;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				scanf("%c",&str[i][j]);
				mark[i][j]=false;
			}
			getchar();	
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(mark[i][j]==true) continue;
				if(str[i][j]=='*') continue;
				mark[i][j]=true;
				DFS(i,j);
//				if(cnt>0) printf("%d\n",cnt);//进入深度优先遍历的都是至少有一个@的 
				cnt++;
			}
		}
		printf("%d\n",cnt);
	}
}
