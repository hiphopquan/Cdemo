#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
struct Node{
	Node *lchild;
	Node *rchild;
	int v;
};
void build(Node *&p,int tmp){
	if(p==NULL){
		p=(Node *)malloc(sizeof(Node));
		p->lchild=NULL;
		p->rchild=NULL;
		p->v=tmp;
		return;
	}
	Node *s;
	s=p;
	int flag=0;
	Node *t;
	t=p;
	while(s){
		if(tmp>s->v){
			t=s;
			flag=1;
			s=s->rchild;
		}
		else if(s!=NULL&&tmp<s->v){
			t=s;
			flag=-1;
			s=s->lchild;
		}
	}
	t=(Node *)malloc(sizeof(Node));
	s=t;
//	s=(Node *)malloc(sizeof(Node));
//	s->v=tmp;
//	s->lchild=NULL;
//	s->rchild=NULL;
//	if(flag==1){
//		t->rchild=s;
//		flag=0;
//	}
//	if(flag==-1){
//		t->lchild=s;
//		flag=0;
//	}	
	
		
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
		Node *p;
		p=NULL;
		for(int i=0;i<n;i++){
			int tmp;
			scanf("%d",&tmp);
			build(p,tmp);
		}
		frontOrder(p);

	}
	
 	return 0;
}
