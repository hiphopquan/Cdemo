#include<stdio.h>
#include<string.h>
char str[10];
bool mark[10];
char ans[10]; 
void output(){
    printf("%s\n",ans+1);
}
void DFS(int num){
	if(num==strlen(str)){
		ans[num+1]='\0';
		output();
		return;
	}
	for(int i=0;i<strlen(str);i++){
		if(mark[i]==true) continue;
		mark[i]=true;
		ans[num+1]=str[i];
		DFS(num+1);
		mark[i]=false;
	}
	return;
}

int main(){
	while(scanf("%s",str)!=EOF){
		for(int i=0;i<strlen(str);i++){
			mark[i]=false;
		}
		for(int i=0;i<strlen(str);i++){
			mark[i]=true;
			ans[1]=str[i];
			DFS(1);
			mark[i]=false;
		}
	}
	return 0;
}
