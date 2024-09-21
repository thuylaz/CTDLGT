#include<bits/stdc++.h>
using namespace std;

struct sach{
    char tensach[20];
	char tg[20];
	char nxb[20];
	int nam;
};

struct node{
    sach infor;
    node *next;
};

typedef node *tro;


void ini(tro &l){
    l= NULL;
}

int empty(tro l){
    return l==NULL;
}

void nhap(sach &s){
    cout<<"ten sach: "; fflush(stdin); gets(s.tensach);
    if (strcmp(s.tensach, "***")==0) return;
    cout<<"ten tac gia: "; fflush(stdin); gets(s.tg);
    cout<<"ten nxb: "; fflush(stdin); gets(s.nxb);
    cout<<"nam: "; cin>>s.nam;
    cout<<endl;
}

void nhapds(tro &l){
    ini(l);
    sach s;
    tro p,q;
    do{
        nhap(s);
        if(strcmp(s.tensach, "***")==0)    return;
        p=new node;
        p->infor= s;
        p->next= NULL;
        if(l==NULL)
            l=p;
        else
            q->next=p;
        q=p;
    }while(1);
}

void hienthi(tro l){
    if(l==NULL){
        cout << "danh sach rong\n";
        return;
    }
    cout<<setw(5)<<"ten sach"
		<<setw(10)<<"tac gia" 
		<<setw(15)<<"nha xuat ban" 
		<<setw(5)<<"Nam"<<endl;
    tro q=l;
    while(q!=NULL){
        sach s= q->infor;
        cout<<s.tensach 
			<<setw(17)<<s.tg 
			<<setw(8)<<s.nxb 
			<<setw(10)<<s.nam<<endl;
        q=q->next;
    }
}

int length(tro l){
    int d=0;
    tro q= l;
    while(q!= NULL){
        q=q->next;
        d++;
    }
    return d;
}


void add1(tro &l, sach s){
    tro p;
    p= new node;
    p->infor= s;
    p->next= l;
    l=p;
}


void chen1(tro &l, tro q, sach s){
    tro p;
    p=new node;
    p->infor= s;
    p->next= q->next;
    q->next= p;
}

void chenk(tro &l){
    int k;
    sach s;
    do{
        cout<<"nhap vi tri can bo sung: "; cin>>k;
    }while (k<1 || k>length(l));
    cout<<"nhap tt can bo sung: \n";
    do{
        nhap(s);
        if(strcmp(s.tensach, "***")==0)
            cout << "ten sach phai khac ***, nhap lai\n";
    }while(strcmp(s.tensach, "***")==0);
    if(k==1)
        add1(l,s);
    else
    {
        tro q= l;
        int d=1;
        while(d<k-1)
        {
            d++;
            q=q->next;
        }
        chen1(l,q,s);
    }
    cout<<"danh sach sau khi them\n";
    hienthi(l);
}
void remove_1node(tro &l, tro q)
{
    tro m;
    if (q==l)
        l=q->next;
    else{
        m=l;
        while(m->next!=q)
            m=m->next;
        m->next = q->next;
    }
    delete q;
}
void delk(tro &l)
{
    int k;
    do
    {
        cout<<"nhap vi tri muon xoa: ";
        cin>>k;
    }while(k<1 || k>length(l));
    tro q= l;
    int d=1;
    while(d<k){
        d++;
        q=q->next;
    }
    remove_1node(l,q);
    cout << "danh sach sau khi xoa\n";
    hienthi(l);
}

tro tim(tro l, char *ma)
{
    tro q=l;
    while(q!=NULL && strcmp(q->infor.tensach, ma)!=0)
        q=q->next;
    return q;
}

void dem(tro &l){
    int d=0;
    tro t = tim(l, "thuy");
    tro q = l;
    if(t!=NULL){
        d++;
        while(q!=NULL){
            q=q->next;
        }
    	cout<<d;
    }else{
        cout<<"khong co \n";
    }
}

main(){
    tro l;
    nhapds(l);
    hienthi(l);
    chenk(l);
    cout<<endl;
    delk(l);
    cout<<"so lan lap lai la: ";
    dem(l);
    return 0;
}

/*
t
r
f
4
thuy
t
d
3
g
h
j
9
***
1
g
t
h
6
2


*/
