#include<stdio.h>
#include<queue>
using namespace std; 
struct N{
	int x;
	int y;
	int z;
	int t;
};
int go[6][3]={
	1,0,0,
	-1,0,0,
	0,1,0,
	0,-1,0,
	0,0,1,
	0,0,-1
};
queue<N> Q; 
int mark[50][50][50];
int maze[50][50][50];
int BFS(int a,int b,int c){
	while(Q.empty()==false){
		N now=Q.front();//�Ӷ���ȡ��һ��״̬ 
		Q.pop();
		for(int i=0;i<6;i++){//����6������ 
			int tmpx=now.x+go[i][0];
			int tmpy=now.y+go[i][1];
			int tmpz=now.z+go[i][2];
			if(mark[tmpx][tmpy][tmpz]==true) continue;
			if(maze[tmpx][tmpy][tmpz]==1) continue;
			if(tmpx<0||tmpx>a-1||tmpy<0||tmpy>b-1||tmpz<0||tmpz>c-1) continue;
			N tmp;
			tmp.x=tmpx;
			tmp.y=tmpy;
			tmp.z=tmpz;
			tmp.t=now.t+1;
			Q.push(tmp);//��� 
			mark[tmpx][tmpy][tmpz]=true;//�ѱ������ 
			if(tmpx==a-1&&tmpy==b-1&&tmpz==c-1) return tmp.t; 
		}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		int a,b,c,t;
		scanf("%d %d %d %d",&a,&b,&c,&t);
		for(int i=0;i<a;i++){
			for(int j=0;j<b;j++){
				for(int k=0;k<c;k++){
					scanf("%d",&maze[i][j][k]);
					mark[i][j][k]=false;
				}
			}
		}
		while(Q.empty()==false) Q.pop();
		N f;
		f.x=f.t=f.y=f.z=0;
		Q.push(f);//��ʼ״̬��� 
		mark[0][0][0]=true;//�������
		int bfs=BFS(a,b,c);
		if(bfs<=t)
			printf("%d\n",bfs);
		else
			printf("-1\n"); 
		
	}
	return 0;
}
