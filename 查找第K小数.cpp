#include<stdio.h>
#include<queue>
using namespace std;
priority_queue<int ,vector<int>,greater<int> > Q;
int main(){
	int n,k,ans[1000];
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			int a;
			scanf("%d",&a);
			Q.push(a);
		}
		scanf("%d",&k);
		for(int i=0;i<k;){
			int b=Q.top();
			if(i==0){
				ans[i]=b;
				i++;
			}else{
				if(b==ans[i-1]){
					
				}else{
					ans[i]=b;
					i++;
				}
			}
			Q.pop();
		}
		printf("%d",ans[k-1]);
		
	}
}
 
