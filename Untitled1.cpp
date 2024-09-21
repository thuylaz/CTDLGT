#include<bits/stdc++.h>
using namespace std;
#define max 100

/*struct sv{
	char masv[20];
	char ten[20];
	int diem;
};

struct List{
	int count;
	sv e[max];
};

void ini(List &l){
	l.count=-1;
}

int full(List l){
	return l.count==max-1;
}

int empty(List l){
	return l.count==-1;
}

int add(List &l, sv s){
	if(!full(l)){
		l.e[l.count+1]= s;
		l.count++;
		return 1;
	}else return 0;
}

void nhap(sv &s){
	cout<<"ma sv: "; fflush(stdin); gets(s.masv);
	if(strcmp(s.masv, "***")==0) return;
	cout<<"ten: "; fflush(stdin); gets(s.ten);
	cout<<"diem: "; cin>>s.diem;
}

void nhapds(List &l){
	ini(l);
	sv s;
	do{
		nhap(s);
		if(strcmp(s.masv, "***")==0) return;
		if(!add(l,s)) return;		
	}while(1);
}

void hienthi(List &l){
	cout<<"ma sv: "
		<<setw(13)<<"ten sv: "
		<<setw(13)<<"diem "<<endl;
	for(int i=0; i<=l.count; i++){
		cout<<l.e[i].masv
			<<setw(13)<<l.e[i].ten
			<<setw(13)<<l.e[i].diem<<endl;
	}
}

int chen(int k,List &l){
	int i;
	sv s;
	if(!full(l)&&k>0&&k<=l.count+1){
		nhap(s);
		for(int i=l.count; i>=k-1; i--)
			l.e[i+1]=l.e[i];
			l.e[k]=s;
			l.count++;
			return 1;		
	}else return 0;
}

int xoa(List &l, int k){
	if(k<=l.count+1 && k>0){
		for(int i=k; i<l.count; i++)
		l.e[i]=l.e[i+1];
		l.count--;	
		return 1;
	}else return 0;	
}

//liet ke sv ten thuy
void lietke(List l){
	int i=0, d=0;
	cout<<"ma sv: "
		<<setw(13)<<"ten sv: "
		<<setw(13)<<"diem "<<endl;
	while(i<=l.count){
		if(strcmp(l.e[i].ten,"thuy")==0){
			cout<<l.e[i].masv
			<<setw(13)<<l.e[i].ten
			<<setw(13)<<l.e[i].diem<<endl;
			d++;
		}i++;
	}if(d==0) cout<<"khong co sv ten thuy";
}

void sort(List &l){
	for(int i=1; i<=l.count; i++){
		for(int j=0; j<=l.count-i; j++){
			if(l.e[j].diem<l.e[j+1].diem)
			swap(l.e[j], l.e[j+1]);
		}
	}
}*/

struct sv{
	char masv[20];
	char ten[20];
	int diem;
};

struct List{
	int count;
	sv e[max];
};

void ini(List &l){
	l.count=-1;
}

int full(List l){
	return l.count==max-1;
}

int empty(List l){
	return l.count==-1;
}

int add(List &l, sv s){
	if(!full(l)){
		l.e[l.count+1]= s;
		l.count++;
		return 1;
	}else return 0;	
}

void nhap(sv &s){
	cout<<"ma sv: "; fflush(stdin); gets(s.masv);
	if(strcmp(s.masv,"***")==0) return;
	cout<<"ten sv: "; fflush(stdin); gets(s.ten);
	cout<<"diem: "; cin>>s.diem;
}

void nhapds(List &l){
	sv s;
	ini(l);
	do{
		nhap(s);
		if(strcmp(s.masv,"***")==0) return;
		if(!add(l,s)) return;
	}while(1);
}

void hienthi(List &l){
	sv s;
	cout<<"ma sv: "
		<<setw(10)<<"ten sv: "
		<<setw(10)<<"diem"<<endl;
	for(int i=0; i<=l.count; i++){
		cout<<l.e[i].masv
		<<setw(10)<<l.e[i].ten
		<<setw(10)<<l.e[i].diem<<endl;
	}
}



main(){
	List l;
	nhapds(l);
	cout<<"danh sach vua nhap la: "<<endl;
	hienthi(l);
	int k, m;
	/*cout<<"nhap vtri can chen: "; cin>>k;
	if(chen(k,l)==1){
		cout<<"danh sach sv sau khi bo sung: "<<endl;
		hienthi(l);
	}else cout<<"vi tri khong thich hop"<<endl;
	*/
	/*cout<<"nhap vtri can xoa: "; cin>>m;
	if(xoa(l,m)==1){
		cout<<"danh sach sv sau khi xoa la: "<<endl;
		hienthi(l);
	}else cout<<"vi tri can xoa k thich hop"<<endl;
	
	lietke(l);
	sort(l);
	hienthi(l);*/
}
/*
e
thuy
3
f
c
5
g
b
4
***
2

*/
