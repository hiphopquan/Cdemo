#include<stdio.h>
#include<algorithm>
using namespace std;
int remin(int a,int b){
	return a < b ? a : b;  
}
int n,k;
int w[2000];
int d[1001][2000];
int main(){
	while(scanf("%d%d",&n,&k)!=EOF){
		for(int i=1;i<=n;i++){
			scanf("%d",&w[i]);
		}
		sort(w+1,w+1+n);
		for(int i=0;i<=n;i++)
			d[0][i]=0;
		for(int i=1;i<=k;i++){
			for(int j=2*i;j<=n;j++){
				if(j>2*i){//大于后两个物品才可以不配对 
					d[i][j]=remin(d[i-1][j-2]+(w[j]-w[j-1])*(w[j]-w[j-1]),d[i][j-1]);
				}else{
					d[i][j]=d[i-1][j-2]+(w[j]-w[j-1])*(w[j]-w[j-1]);
				} 
			}
		}
		printf("%d\n",d[k][n]);
	}
	return 0;
}
