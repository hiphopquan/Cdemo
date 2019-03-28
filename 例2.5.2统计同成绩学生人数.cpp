#include<stdio.h>
int main(){
	int n,s[101]={0};
	while(scanf("%d",&n)!=EOF&&n!=0){
		for(int i=0;i<n;i++){
			int x;
			scanf("%d",&x);
			s[x]++;
		}
		int y;
		scanf("%d",&y);
		printf("---------%d----------\n",s[y]);
	}
	return 0;
}
