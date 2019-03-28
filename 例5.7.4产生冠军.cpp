#include<stdio.h>
#include<string.h> 
struct E{
	char name[20];
	int count;
}edge[1000];
int main(){
	int n;
	while(scanf("%d",&n)!=EOF&&n!=0){
		for(int i=0;i<n;i++){
			edge[i].name[1]='\0';
			edge[i].count=0;
		}
		int size=0;
		for(int i=0;i<n;i++){
			char str1[20];
			char str2[20];
			scanf("%s %s",str1,str2);
			int flag1=-1,flag2=-1;
			for(int j=0;j<size;j++){
				if(strcmp(edge[j].name,str2)==0){//存在str2,入度+1 
					edge[j].count++;
					flag2=j;
				}
				if(strcmp(edge[j].name,str1)==0){//判断是否存在str1 
					flag1=j;
				}
			}
			if(flag1==-1){//不存在str1，录入 
				strcpy(edge[size++].name,str1);
			}
			if(flag2==-1){//不存在str2,录入并入度+1 
				strcpy(edge[size].name,str1);
				edge[size].count++;
				size++;
			}
		}
		int cnt=0;
		for(int i=0;i<n;i++){
			if(edge[i].count==0) cnt++;
		}
		if(cnt==1) printf("Yes\n");
		else printf("No\n"); 
	}
	return 0;
} 
