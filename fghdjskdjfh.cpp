#include<bits/stdc++.h>
using namespace std;

struct sv{
	char msv[20];
	int diem;
};

struct node{
	sv infor;
	node *next;
};

typedef node *tro;
tro l;

void nhap(sv &s){
	cout<<"msv: "; fflush(stdin); gets(s.msv);
	cout<<"diem: "; cin>>s.diem;
}


void nhapds(tro &l){
	int n;
	do{
		cin>>n;
	}while(n>7);
	sv s;
	tro p,q;
	l=NULL;
	int i=0;
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

void xuatlist(tro &l)
{
	tro p;
	p=l;
	while(p!=NULL)
	{
		cout<<setw(15)<<p->infor.msv<<setw(15)<<p->infor.diem<<endl;
		p=p->next;
	}
}

void hthi(tro l){
	if(l==NULL) return;
	tro q=l;
	int dem=0;
	while(q!=NULL){
		sv s=q->infor;
		if(strcmp(s.msv,"t")==0){
			cout<<s.msv<<s.diem<<endl;
			dem++;
		}q=q->next;//q cu tiep tuc chay
	}if(dem==0) cout<<"k co";
}


void xoa(tro &l,tro p){
	tro q=l;
	int d=1;
	if(q==NULL) return;
	while(q!=NULL&&d<3){
		p=q;
		q=q->next;
		d++;
	}
	q=p->next;
	p->next=q->next;
	delete q;
	cout<<endl;
	xuatlist(l);
}

void chen5(tro &l){
	sv s;
	nhap(s);
	tro p, q=l;
	p=new node;
	p->infor=s;
	int d=1;
	while(d<2){
		d++;
		q=q->next;
	}
	p->next=q->next;
	q->next=p;
	xuatlist(l);
}

void chen3(tro &l){
	sv s;
	nhap(s);
	tro p,q=l;
	p=new node;
	p->infor=s;
	int d=0;
	while(d<2){
		d++;
		q=q->next;
	}
	p->next=q->next;
	q->next=p;
}





void chen34(tro &l){
	sv s;
	nhap(s);
	int d=1;
	tro p, q=l;
	p=new node;
	p->infor=s;
	if(l==NULL) return;
	while(d<2){
		q=q->next;
		d++;
	}
	p->next=q->next;
	q->next=p;
	xuatlist(l);
}

void xoaa(tro &l){
	if(l==NULL) return;
	int d=1;
	tro p,q=l;
	while(q!=NULL&&d<3){
		p=q;
		q=q->next;
		d++;
	}
	q=p->next;
	p->next=q->next;
	delete q;
	xuatlist(l);
}

main(){
	tro l,p;
	nhapds(l);
	xuatlist(l);
	xoaa(l);
}


/*
3
r
5
t
6
y
7

*/
