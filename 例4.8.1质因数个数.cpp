#include<stdio.h>
int num[100000];
int index;
int ans[100001];
int inz[30];
int inzm[30];
int inzind;
void init(){
	
	for(int i=2;i<10001;i++){
		if(ans[i]!=1){
			num[index]=i;
			index++;
			int j=i*i;
			while(j<10001){
				ans[j]=1;
				j+=i;
			}
		}
	}
}
int main(){ 
	int n;
	init();
	while(scanf("%d",&n)!=EOF){
		inzind=0;
		for(int i=0;i<index;i++){
			if(n%num[i]==0){
				inzm[inzind]=0;
				inz[inzind]=num[i];
				while(n%num[i]==0){
					inzm[inzind]++;
					n=n/num[i];
				}
				inzind++;
			}
			if(n==1) break;
		}
		if(n!=1){
			inz[inzind]=n;
			inzm[inzind++]=1;
		}
		int ansv=0;
		for(int j=0;j<inzind;j++){
			printf("%d %d\n",inz[j],inzm[j]);
			ansv+=inzm[j];
		}
//		printf("%d\n",ansv);
		inzind=0;
	}
	return 0;
}
