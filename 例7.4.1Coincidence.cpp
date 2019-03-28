#include<stdio.h>
#include<string.h>

int main(){
	char str1[110];
	char str2[110];
	int dp[110][110];
	while(scanf("%s",str1)!=EOF){
		scanf("%s",str2);
		int len1=strlen(str1);
		int len2=strlen(str2);
		for(int i=0;i<=len1;i++)
			dp[i][0]=0;
		for(int i=0;i<=len2;i++)
			dp[0][i]=0;
		for(int i=1;i<=len1;i++){
			for(int j=1;j<=len2;j++){
				if(str1[i-1]==str2[j-1]){
					dp[i][j]=dp[i-1][j-1]+1;
				}else{
					if(dp[i][j-1]>dp[i-1][j]){
						dp[i][j]=dp[i][j-1];
					}else{
						dp[i][j]=dp[i-1][j];
					}
				}
			}
		}
		printf("%d\n",dp[len1][len2]);
	}
	return 0;
} 
