#include<stdio.h>
int main(){
	int n,scor[1000],s,count[1000]={0};
	scanf("%d",&n);
	int k=0;
	while(n!=0){
		for(int i=0;i<n;i++){
			scanf("%d",&scor[i]);
		}
		scanf("%d",&s);
		for(int i=0;i<n;i++){
			if(scor[i]==s){
				count[k]++;
			}
		}
		k++;
		scanf("%d",&n);
	}
	for(int i=0;i<k;i++){
		printf("%d\n",count[i]);
	} 
	return 0;
} 
