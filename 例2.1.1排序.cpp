#include<stdio.h>
int main(){
	int n,a[100],temp;
	while(scanf("%d",&n)!=EOF){//∂‡◊È ‰»Î 
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(int j=0;j<n-1;j++){
			for(int k=0;k<n-1-j;k++){
				if(a[k]>a[k+1]){
					temp=a[k];
					a[k]=a[k+1];
					a[k+1]=temp;
				}
			}
		}
		for(int l=0;l<n;l++)
			printf("%d ",a[l]);
		printf("\n");
	}
	return 0;	
} 
