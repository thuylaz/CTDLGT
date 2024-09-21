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
	sv s;
	int i;
	tro p, q;
	l=NULL;
	int n;
	do{
		cin>>n;
	}while(n>7);
	do{
		nhap(s);
		p=new node;
		p->infor=s;
		p->next=NULL;
		if(l==NULL) l=p;
		else q->next=p;
		q=p;
		i++;		
	}while(i<n);
}

void hthi(tro l){
	tro p,q=l;
	int dem=0;
	if(l==NULL) return;
	while(q!=NULL){
		sv s=q->infor;
		if(strcmp(s.msv,"t")==0){
			cout<<s.msv<<s.diem<<endl;
			dem++;
		}q=q->next;
	}if(dem==0) cout<<"k co";
}

void xuat(tro l){
	tro p=l;
	while(p!=NULL){
		sv s=p->infor;
		cout<<s.msv<<setw(15)<<s.diem<<endl;
		p=p->next;
	}
}

void chen5(tro &l){
	sv s;
	tro p,q=l;
	nhap(s);
	p=new node;
	p->infor=s;
	int d=1;
	while(d<2){
		d++;
		q=q->next;
	}p->next=q->next;
	q->next=p;
	xuat(l);
}

void xoa(tro &l){
	tro p, q=l;
	if(l==NULL) return;
	int d=1;
	while(q!=NULL&&d<2){
		p=q;
		q=q->next;
		d++;
	}
	q=p->next;
	p->next=q->next;
	delete q;
	xuat(l);
}

main(){
	tro l;
	nhapds(l);
	//hthi(l);
	xuat(l); cout<<endl;
	chen5(l); cout<<endl;
	xoa(l);
}


/*
3
r
4
t
5
y
6
w
2

*/
