#include<stdio.h>
#include<stdlib.h>
struct Node{
	Node *lchild;
	Node *rchild;
	int v;
};
//Node *p=NULL;
Node *build(Node *p,int tmp){
	if(p==NULL){
		p=(Node *)malloc(sizeof(Node));
		p->lchild=NULL;
		p->rchild=NULL;
		p->v=tmp;
		return p;
	}else{
		if(tmp>p->v){
			p->rchild=build(p->rchild,tmp);
		}
		if(tmp<p->v){
			p->lchild=build(p->lchild,tmp);
		}
		return p;
		
	}
}
void frontOrder(Node *p){
	printf("%d ",p->v);
	if(p->lchild!=NULL){
		frontOrder(p->lchild);
	}
	if(p->rchild!=NULL){
		frontOrder(p->rchild);
	}
	
}
void midOrder(Node *p){
	
	if(p->lchild!=NULL){
		midOrder(p->lchild);
	}
	printf("%d ",p->v);
	if(p->rchild!=NULL){
		midOrder(p->rchild);
	}
	
}
void postOrder(Node *p){
	
	if(p->lchild!=NULL){
		postOrder(p->lchild);
	}
	if(p->rchild!=NULL){
		postOrder(p->rchild);
	}
	printf("%d ",p->v);
	
}
int main(){
	
	int n;
	while(scanf("%d",&n)!=EOF){
		Node *p=NULL;
		for(int i=0;i<n;i++){
			int tmp;
			scanf("%d",&tmp);
			p=build(p,tmp);
		}
		frontOrder(p);
		printf("\n");
		midOrder(p);
		printf("\n");
		postOrder(p);
		printf("\n");
	}
	
 	return 0;
}
