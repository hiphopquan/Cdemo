#include<stdio.h>
int main(){
	long long a,b,c,k;
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%lld%lld%lld%lld",&a,&b,&c,&k);
			long long ans;
			if(a*c==b*b){
				long q=b/a;
				ans=a;
				k--; 
				while(k!=0){
					if(k%2==1){
						ans=ans*q;
					}
					q*=q;
					k/=2;
				}
			}
			else if(a+c==2*b){
				long long d=b-a;
				ans=a+(k-1)*d;
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
