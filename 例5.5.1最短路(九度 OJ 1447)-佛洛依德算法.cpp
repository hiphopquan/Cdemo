#include<stdio.h>
#define N 101
int Edge[N][N];
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF&&m!=0&&n!=0){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				Edge[i][j]=-1;
			}
			Edge[i][i]=0;//自己到自己的路初始化为0 
		}
		for(int i=0;i<m;i++){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			Edge[a][b]=c;
			Edge[b][a]=c;
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(Edge[i][k]==-1||Edge[k][j]==-1){
						continue;
					}else if(Edge[i][j]==-1||Edge[i][k]+Edge[k][j]<Edge[i][j]){
						Edge[i][j]=Edge[i][k]+Edge[k][j];
					}
				}
			}
		}
		printf("%d\n",Edge[1][n]);
	}
	
	
	
	return 0;
} 
