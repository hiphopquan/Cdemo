#include<stdio.h>
#include<limits.h>
int haff(int *a,int *b,int n){
	int temp;
	for(int i=0;i<2;i++){
		for(int j=0;j<n-1;j++){
			if(a[j]<a[j+1]){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	b[0]=a[n-1];
	b[1]=a[n-2];
	a[n-2]=b[0]+b[1];
	a[n-1]=INT_MAX;
	return a[n-2];
}
int main(){
	int n,a[1000],b[2],sum=0,i,j;
	for(i=0;i<1000;i++){
		a[i]=INT_MAX;
	}
	scanf("%d",&n);
	if(n<2||n>1000){
		printf("ÊäÈë´íÎó");
		return 0;
	}else{
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
	}
	int k=0;
	while(a[1]!=INT_MAX){
		sum+=haff(a,b,n-k);
		k++;
	}
	printf("%d",sum);
	

} 
