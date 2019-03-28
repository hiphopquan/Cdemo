#include<stdio.h>
#include<stack>
using namespace std;
stack<int> S;
char buf[110],ind[110];
int main(){
	while(scanf("%s",buf)!=EOF){
		int i;
		for(i=0;buf[i]!=0;i++){
			if(buf[i]=='('){
				S.push(i);
				ind[i]=' ';
			}else if(buf[i]==')'){
				//if(S.empty()==false&&buf[S.top()]=='('){//两个判断顺序有别，先s.top()会因栈空出错 
				if(S.empty()==false){//不必判断是否为左括号，栈内只会存左括号，左括号入栈，右括号不入 
					S.pop();
					ind[i]=' ';	
				}else{
					ind[i]='?';
				}		
			}else{
				ind[i]=' ';
			}
		}
		while(S.empty()==false){
			ind[S.top()]='$';
			S.pop();
		}
		ind[i]=0;
		puts(buf);
		puts(ind);
		
	}
	
	return 0;
} 
