#include<stdio.h>
int main(){
	int j;
	int num[6];
	//printf("0\n");
	for(int i=1;i<256;i++){
		int n=i*i;
		j=0;
		while(n>0){
			num[j++]=n%10;
			n=n/10;
		}
		j--;
		int flag=0;
		for(int k=0;k<=j/2;k++){
			if(num[k]==num[j-k]){
				
			}
			else{
				flag=1;
				break;
			}
		}
		if(flag==0){
			printf("%d\n",i);
		}
		j=0;
	}
	return 0;
} 
