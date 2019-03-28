#include<stdio.h>
#include<queue>
#include<vector>
using namespace std; 
priority_queue<int ,vector<int>,greater<int> >Q;//小顶堆存储，在入度为0的点中，每次取编号较小的 
int inDgree[501];
vector<int> edge[501];
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i=1;i<501;i++){
			inDgree[i]=0;
			edge[i].clear();
		}
		while(Q.empty()==false) Q.pop();
		for(int i=0;i<m;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			edge[a].push_back(b);
			inDgree[b]++;
		}
		for(int i=1;i<=n;i++){
			if(inDgree[i]==0) Q.push(i);
		}
		int flag=1;
		while(Q.empty()==false){
			if(flag==1){
				int newP=Q.top();
				printf("%d",newP);
				Q.pop();
				flag++;
				for(int i=0;i<edge[newP].size();i++){
					inDgree[edge[newP][i]]--;
					if(inDgree[edge[newP][i]]==0) Q.push(edge[newP][i]);
				}
			}else{
				int newP=Q.top();
				printf(" %d",newP);
				Q.pop();
				flag++;
				for(int i=0;i<edge[newP].size();i++){
					inDgree[edge[newP][i]]--;
					if(inDgree[edge[newP][i]]==0) Q.push(edge[newP][i]);
				}
			}
			
		}
	}
	return 0;
} 
 
