//11111111111
//10000000001
//10111111101
//10100000101
//10101110101
//10101010101
//10101110101
//10100000101
//10111111101
//10000000001
//11111111111

 
 //中0 外1 
#include<stdio.h>

int main(){
	int n,f=1;
	char a[81][81];
	while(scanf("%d",&n)!=EOF){
		int m=n+1,c=n/2+1;
		char mid,out;
		getchar();
		scanf("%c",&mid);
		getchar();
		scanf("%c",&out);
//		printf("%d",n);
//		printf("%c",mid);
//		printf("%c",out);
		for(int i=1;i<=n/2+1;i++){
			if((c-i)%2!=0){//奇数行列外框 
				//左上角i行i列，右下角12-i行12-i列
				for(int j=i;j<=m-i;j++){
					a[i][j]=out;
					a[m-i][j]=out;
				}
				for(int k=i;k<m-i;k++){
					a[k][i]=out;
					a[k][m-i]=out;
				} 
			}else{//偶数行列中框 
				for(int j=i;j<=m-i;j++){
					a[i][j]=mid;
					a[m-i][j]=mid;
				}
				for(int k=i;k<m-i;k++){
					a[k][i]=mid;
					a[k][m-i]=mid;
				}
			} 
		}
		if(n!=1){//n=1不需要！！！ 
			a[1][1]=' ';
			a[1][n]=' ';
			a[n][1]=' ';
			a[n][n]=' ';	
		}
		if(f){
			f=0;
		}else{
			printf("\n");
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)
				printf("%c",a[i][j]);
			printf("\n");
		}
	}
	
	return 0;
	
}
