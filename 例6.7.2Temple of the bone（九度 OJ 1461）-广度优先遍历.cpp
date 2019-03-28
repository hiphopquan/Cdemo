#include<stdio.h>
#include<queue>
using namespace std;
struct Node{
	int x,y;
	int t;
};
char str[10][10];
int go[][2]={
	-1,0,
	0,1,
	1,0,
	0,-1
};
int n,m,t;
bool mark[10][10];
queue<Node> Q;
int BFS(){
	while(Q.empty()==false){
		Node newP=Q.front();
		Q.pop();
		for(int i=0;i<4;i++){
			Node tmp;
			tmp.x=newP.x+go[i][0];
			tmp.y=newP.y+go[i][1];
			if(tmp.x<1||tmp.x>n||tmp.y<1||tmp.y>m) continue;
			if(str[tmp.x][tmp.y]=='X') continue;
			if(mark[tmp.x][tmp.y]==true) continue;
			mark[tmp.x][tmp.y]=true;
			tmp.t=newP.t+1;
			if(str[tmp.x][tmp.y]=='D'&&tmp.t==t) return tmp.t;
			Q.push(tmp);
		}
	}
	return -1;
}
int main(){

	while(scanf("%d%d%d",&n,&m,&t)!=EOF){
		getchar();
		if(n==0||m==0||t==0) break;
		while(Q.empty()==false) Q.pop();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				mark[i][j]=false;
				scanf("%c",&str[i][j]);
			}
			getchar();
		}
		mark[1][1]=true;
		Node tmp;
		tmp.x=1;
		tmp.y=1;
		tmp.t=0;
		Q.push(tmp);
		int cnt=BFS();
		if(cnt<=t&&cnt!=-1){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
		
	}
	return 0;
}
