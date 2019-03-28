#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
priority_queue<int ,vector<int> ,greater<int> > Q;
int huf[1000];
int main(){
	int n,ans=0;
	while(scanf("%d",&n)!=EOF){
		int tmp;
		//while(Q.empty==false) Q.pop();
		for(int i=0;i<n;i++){
			scanf("%d",&tmp);
			Q.push(tmp);
		}
		while(Q.size()>1){
			int x,y;
			x=Q.top();
			Q.pop();
			y=Q.top();
			Q.pop();
			ans+=(x+y);
			Q.push(x+y);
		}
		printf("%d",ans);
	}
	
	return 0;
}
