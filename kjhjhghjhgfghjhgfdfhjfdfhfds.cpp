#include<bits/stdc++.h>
using namespace std;

struct cuahang{
	char tench[20], tenchu[20];
	int doanhthu;
};

struct node{
	cuahang infor;
	node *next;
};

typedef node *tro;


void nhap(cuahang &s){
	cout<<"ten ch: "; fflush(stdin); gets(s.tench);
	cout<<"ten chu: "; fflush(stdin); gets(s.tenchu);
	cout<<"doanh thu: "; cin>>s.doanhthu;
}

void nhapds(tro &l){
	cuahang s;
	tro p,q;
	int i=0;l=NULL;
	int n;
	cin>>n;
	do{
		nhap(s);
		p=new node;
		p->infor=s;
		if(l==NULL) l=p;
		else q->next=p;
		q=p;
		i++;
	}while(i<n);	
}

void xuat(tro &l){
	tro p;
	p=l;
	if(l==NULL) return;
	while(p!=NULL){
		cuahang s=p->infor;
		cout<<s.tench<<"\t"<<s.tenchu<<"\t"<<s.doanhthu<<endl;
		p=p->next;
	}
}


void hthia(tro l){
	tro q=l;
	if(l==NULL) return;
	int dem=0;
	while(q!=NULL){
		cuahang s=q->infor;
		if(s.doanhthu>100){
			cout<<s.tench<<"\t"<<s.tenchu<<"\t"<<s.doanhthu<<endl;
			dem++;
		}q=q->next;
	}if(dem==0) cout<<"k co";
}

void chen5(tro &l){
	if(l==NULL) return;
	cuahang s;
	nhap(s);
	tro p,q=l;
	p=new node;
	p->infor=s;
	int d=1;
	while(d<4){
		q=q->next;
		d++;
	}p->next=q->next;
	q->next=p;
	xuat(l);
}

void 

main(){
	tro l;
	nhapds(l);
	xuat(l);
	hthia(l);
	chen5(l);
}

/*
5
t
r
6
h
g
700
d
s
234
r
e
4
h
g
789

*/
