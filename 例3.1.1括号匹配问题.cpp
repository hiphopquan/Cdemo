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
				//if(S.empty()==false&&buf[S.top()]=='('){//�����ж�˳���б���s.top()����ջ�ճ��� 
				if(S.empty()==false){//�����ж��Ƿ�Ϊ�����ţ�ջ��ֻ��������ţ���������ջ�������Ų��� 
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
