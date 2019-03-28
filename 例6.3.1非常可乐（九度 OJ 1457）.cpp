#include<stdio.h>
#include<queue>
using namespace std;
int S,N,M;
bool mark[101][101][101];
struct Node{
	int s;
	int n;
	int m;
	int t;
};
queue<Node> Q;
void pour(int a,int &ca,int b,int &cb){//a向b倒 
	if((b-cb)>=ca){//b剩余空间大于a当前溶液体积 
		cb=cb+ca; 
		ca=0;
	}else{//b剩余空间不足 
		ca=ca-(b-cb);
		cb=b;
	}
}
int BFS(int S,int N,int M){
	while(Q.empty()==false){
		Node now=Q.front();//从now状态向S->N S->M N->S N->M M->S M->N六个方向扩展  
		Q.pop();
		int s=now.s;
		int n=now.n;
		int m=now.m;
		pour(S,s,N,n);//S->N
		if(mark[s][n][m]==false){
			mark[s][n][m]=true;
			Node tmp;
			tmp.s=s;
			tmp.n=n;
			tmp.m=m;
			tmp.t=now.t+1;//有now状态扩展而来 
			printf("S->N %d %d %d %d次\n",s,n,m,tmp.t);
			if(s==S/2&&n==S/2) return tmp.t;
			if(s==S/2&&m==S/2) return tmp.t;
			if(n==S/2&&m==S/2) return tmp.t;
			
			Q.push(tmp);
		}
		s=now.s;//扩展结束返回原状态 
		n=now.n;
		m=now.m;
		pour(S,s,M,m);//S->M
		if(mark[s][n][m]==false){
			mark[s][n][m]=true;
			Node tmp;
			tmp.s=s;
			tmp.n=n;
			tmp.m=m;
			tmp.t=now.t+1;//有now状态扩展而来 
			printf("S->M %d %d %d %d次\n",s,n,m,tmp.t);
			if(s==S/2&&n==S/2) return tmp.t;
			if(s==S/2&&m==S/2) return tmp.t;
			if(n==S/2&&m==S/2) return tmp.t;
			
			Q.push(tmp);
			
		} 
		s=now.s;//扩展结束返回原状态 
		n=now.n;
		m=now.m;
		pour(N,n,S,s);//N->S
		if(mark[s][n][m]==false){
			mark[s][n][m]=true;
			Node tmp;
			tmp.s=s;
			tmp.n=n;
			tmp.m=m;
			tmp.t=now.t+1;//有now状态扩展而来 
			printf("N->S %d %d %d %d次\n",s,n,m,tmp.t);
			if(s==S/2&&n==S/2) return tmp.t;
			if(s==S/2&&m==S/2) return tmp.t;
			if(n==S/2&&m==S/2) return tmp.t;
			Q.push(tmp);
			
		} 
		s=now.s;//扩展结束返回原状态 
		n=now.n;
		m=now.m;
		pour(N,n,M,m);//N->M
		if(mark[s][n][m]==false){
			mark[s][n][m]=true;
			Node tmp;
			tmp.s=s;
			tmp.n=n;
			tmp.m=m;
			tmp.t=now.t+1;//有now状态扩展而来 
			printf("N->M %d %d %d %d次\n",s,n,m,tmp.t);
			if(s==S/2&&n==S/2) return tmp.t;
			if(s==S/2&&m==S/2) return tmp.t;
			if(n==S/2&&m==S/2) return tmp.t;
			Q.push(tmp);
			
		} 
		s=now.s;//扩展结束返回原状态 
		n=now.n;
		m=now.m;
		pour(M,m,S,s);//M->S
		if(mark[s][n][m]==false){
			mark[s][n][m]=true;
			Node tmp;
			tmp.s=s;
			tmp.n=n;
			tmp.m=m;
			tmp.t=now.t+1;//有now状态扩展而来 
			printf("M->S %d %d %d %d次\n",s,n,m,tmp.t);
			if(s==S/2&&n==S/2) return tmp.t;
			if(s==S/2&&m==S/2) return tmp.t;
			if(n==S/2&&m==S/2) return tmp.t;
			Q.push(tmp);
			
		} 
		s=now.s;//扩展结束返回原状态 
		n=now.n;
		m=now.m;
		pour(M,m,N,n);//M->N
		if(mark[s][n][m]==false){
			mark[s][n][m]=true;
			Node tmp;
			tmp.s=s;
			tmp.n=n;
			tmp.m=m;
			tmp.t=now.t+1;//有now状态扩展而来 
			printf("M->N %d %d %d %d次\n",s,n,m,tmp.t);
			if(s==S/2&&n==S/2) return tmp.t;
			if(s==S/2&&m==S/2) return tmp.t;
			if(n==S/2&&m==S/2) return tmp.t;
			Q.push(tmp);	
		}
		 
	}
	return -1;
}
int main(){
	while(scanf("%d%d%d",&S,&N,&M)!=EOF){
		if(S%2!=0){
			puts("NO");
			continue;
		}
		if(S==0) break;
		for(int i=0;i<=S;i++){
			for(int j=0;j<=N;j++){
				for(int k=0;k<=M;k++){
					mark[i][j][k]=false;
				}
			}
		}
		Node tmp;
		tmp.s=S;
		tmp.n=0;
		tmp.m=0;
		tmp.t=0;
		while(Q.empty()==false) Q.pop();
		Q.push(tmp);
		mark[S][0][0]=true;
		int ans=BFS(S,N,M);
		if(ans==-1){
			puts("NO");
		}else{
			printf("%d\n",ans);
		}
		
		
	}
	return 0;
} 
