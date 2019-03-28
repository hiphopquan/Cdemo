#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
vector<int> edge[100];
queue<int> Q;
int inDgree[100];
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		if(n==0&&m==0) break;
		for(int i=0;i<100;i++){//��ʼ�� 
			inDgree[i]=0;
			edge[i].clear();
		}
		while(Q.empty()==false) Q.pop();//�����һ�β����������� 
		for(int i=0;i<m;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			edge[x].push_back(y);
			inDgree[y]++;
		}
		for(int i=0;i<n;i++){//���Ϊ0�洢�ڶ��У��ݴ���ٱ������� 
			if(inDgree[i]==0) Q.push(i);
		}
		int cnt=0;
		while(Q.empty()==false){
			int newP=Q.front();
			cnt++;
			Q.pop();
			for(int i=0;i<edge[newP].size();i++){
				inDgree[edge[newP][i]]--;
				if(inDgree[edge[newP][i]]==0)
					Q.push(edge[newP][i]);
			}
		}
		if(cnt==n)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
} 
