#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node{
	Node *lchild;
	Node *rchild;
	char c;
};
int flag1=0;
int flag2=0;
char order[2][15];//存放参照序列前后序字符串 
Node *insert(Node *p,char tmp){
	if(p==NULL){
		p=(Node *)malloc(sizeof(Node));
		p->lchild=p->rchild=NULL;
		p->c=tmp;
		return p;
	}
	if(tmp>p->c){
		p->rchild=insert(p->rchild,tmp);
	}
	if(tmp<p->c){
		p->lchild=insert(p->lchild,tmp);
	}
	return p;
}
void frontOrder(Node *p,char *str){
	str[flag1++]=p->c;
	if(p->lchild!=NULL){
		frontOrder(p->lchild,str);
	}
	if(p->rchild!=NULL){
		frontOrder(p->rchild,str);
	}
}
void midOrder(Node *p,char *str){
	if(p->lchild!=NULL){
		midOrder(p->lchild,str);
	}
	str[flag2++]=p->c;
	if(p->rchild!=NULL){
		midOrder(p->rchild,str);
	}
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF&&n!=0){
		Node *p;
		p=NULL;
		char str[15];//存放参照序列 

		char ind[15];
		scanf("%s",str);
		for(int i=0;i<strlen(str);i++){//建立二叉排序树 
			p=insert(p,str[i]);
		}
		frontOrder(p,order[0]);//前序序列 
		order[0][flag1]='\0';
		midOrder(p,order[1]);//中序序列 
		order[1][flag2]='\0';
		for(int i=0;i<n;i++){
			char tmp[15];
			Node *t;
			t=NULL;
			scanf("%s",tmp);
			for(int j=0;j<strlen(tmp);j++){//建立二叉排序树 
				t=insert(t,tmp[j]);
			}
			flag1=0;
			flag2=0;
			char cn[2][15];
			frontOrder(t,cn[0]);
			cn[0][flag1]='\0';
			if(strcmp(cn[0],order[0])==0){
				midOrder(t,cn[1]);
				cn[1][flag2]='\0';
				if(strcmp(cn[1],order[1])==0){
					puts("YES");
				}else{
					puts("NO");
				}	
			}else{
				puts("NO");
			}
			
		} 

	}
	return 0;
}
