#include<stdio.h>
#include<math.h>
bool juge(int n){
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0){
			return false;
		}
	}
	return true;
}
int main(){
	int n;
	int count=0;
	while(scanf("%d",&n)!=EOF){
		for(int i=2;i<n;i++){
			if(juge(i)){
				if(i%10==1){
					count++;
					if(count==1){
						printf("%d",i);	
					}else{
						printf(" %d",i);
					}
					
				}
			}
		}
		if(count==0){
			printf("-1");
		}
	}
	return 0;
}
