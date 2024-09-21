#include<bits/stdc++.h>
using namespace std;

struct sv{
	char masv[30];
	char tensv[30];
	float diem;
};

void nhap(sv &s)
{
	cout<<"Ma sv: ";				fflush(stdin);				gets(s.masv);
	cout<<"Ten sv: ";				fflush(stdin);				gets(s.tensv);
	cout<<"Diem: ";												cin>>s.diem;
}

struct node{
	sv infor;
	node *next;
};

typedef node *tro;
tro l;

void nhaplist(tro &l)
{
	int n;
	cout<<"Nhap so luong sinh vien: ";							cin>>n;
	l=NULL;
	tro p,q;
	sv x;
	int i=0;
	do
	{
		nhap(x);
		p=new node;
		p->infor=x;
		p->next=NULL;
		if(l==NULL)
		{
			l=p;
		}
		else
		q->next=p;
		q=p;
	}while(i<n);
}

void xuatlist(tro &l)
{
	tro p;
	p=l;
	while(p!=NULL)
	{
		cout<<setw(15)<<p->infor.masv<<setw(15)<<p->infor.tensv<<setw(15)<<p->infor.diem<<endl;
		p=p->next;
	}
}



void xoasach(tro &l, tro t){
	int d=1;
	tro q=l;
	while(q!=NULL&&d<2){
		t=q;
		q=q->next;
		d++;
	} 
	q=t->next;
	t->next=q->next;
	delete q;
	cout<<endl;
	xuatlist(l);
}

void addsach(tro &l){ 
	sv s;
	cout<<"Nhap thong tin sinh vien can chen: "<<endl;
	nhap(s);
	tro p;
	p=new node;
	p->infor=s;
	
	tro q=l;
		int d=1;
		while(d<1){
			d++;
			q=q->next;
		}
		p->next=q->next;
		q->next=p;
		xuatlist(l);
}

void chensau(tro &l){ 
	sv s;
	cout<<"Nhap thong tin sinh vien can chen: "<<endl;
	nhap(s);
	tro p, q=l;
	p=new node;
	p->infor=s;
	while(q!=NULL && strcmp(s.masv,"j")!=0) q=q->next;
	p->next=q->next;
	q->next=p;
	
		xuatlist(l);
}

void timten(tro l){
	if(l==NULL) return;
	tro q=l;
	int dem=0;
	while(q!=NULL){
		sv s=q->infor;
		if(strcmp(s.masv,"thuy")==0){
			cout<<s.masv<<s.tensv<<endl;
			dem++;
		}q=q->next;
	}if(dem==0) cout<<"k co sv nay";
}



void timten1(tro l){
	int d=0;
	tro q=l;
	while(q!=NULL){
		sv s=q->infor;
		if(strcmp(s.tensv,"u")==0){
			cout<<s.masv<<"\t"<<s.tensv<<endl;
			d++;
		}q=q->next;
	}if(d==0) cout<<"k co";
}

void chenthuy(tro &l){
	sv s;
	tro p,q=l;
	int d=1;
	nhap(s);
	p=new node;
	p->infor=s;
	while(q!=NULL&&d<3){
		d++;
		q=q->next;
		
	}p->next=q->next;
	q->next=p;
	xuatlist(l);
}

void xoathuy(tro &l){
	int d=1;
	tro p, q=l;
	while(q!=NULL&d<2){
		p=q;
		q=q->next;
		d++;
	}q=p->next;
	p->next=q->next;
	delete q;
	xuatlist(l);
}

main()
{
	tro l; tro t;
	nhaplist(l);
	xuatlist(l);
	chenthuy(l);
	xoasach(l,t);
	
}

/*
4
t
h
6
j
u
7
b
g
2
d
s
4
e
d
4


*/
