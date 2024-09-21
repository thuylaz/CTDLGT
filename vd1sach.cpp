#include<bits/stdc++.h>
using namespace std;
#define max 100

struct sinhvien{
	char masv[20];
	char ten[20];
	int diem;
};

struct List{
	int count;
	sinhvien e[max];
};

//khoi tao dsach rong
void ini(List &l){
	l.count=-1;
}

//kiem tra dsach day
int full(List l){
	return l.count==max-1;
}

//kiem tra dsach rong
int empty(List l){
	return l.count==-1;
}

//them thong tin cuoi dsach
int add(List &l, sinhvien x){
	if(full(l)) return 0;
	else{
		l.count++;
		l.e[l.count]= x;
		return 1;
	}
}

void nhap(sinhvien &sv){
	cout<<"ma sv: "; fflush(stdin); gets(sv.masv);
	if(strcmp(sv.masv, "***")==0) return;
	cout<<"ten: "; fflush(stdin); gets(sv.ten);
	cout<<"diem: "; cin>>sv.diem;
}

//nhap danh sach sinh vien
void nhapds(List &l){
	ini(l);
	sinhvien x;
	int i=1;
	do{
		cout<<"nhap sv thu "<<i<<endl;
		nhap(x);
		if(strcmp(x.masv, "***")==0) return;
		if(!add(l,x)) return;
		i++;
	}while(1);
}

void hienthi(List l){
	cout<<"ma sv"
		<<setw(10)<<"ten"
		<<setw(10)<<"diem"<<endl;
		for(int i=0; i<=l.count; i++){
			cout<<l.e[i].masv
			<<setw(12)<<l.e[i].ten
			<<setw(12)<<l.e[i].diem<<endl;
		}
}

//xoa dau
void xoa1(List &l){
	if(empty(l)) return;
	for(int i=1; i<=l.count; i++){
		l.e[i-1]= l.e[i];
		l.count--;
	}
}

//xoa sv co ma "  " trong dsach
int search(List l, char *ma){
	int i=0; 
	while(i<=l.count && strcmp(l.e[i].masv,ma)!=0)
	i++;
	if(i<=l.count) return i+1;
	else return 0;
}

void remove(int k, List &l){
	for(int i=k-1; i<l.count; i++)
	l.e[i]= l.e[i+1];
	l.count--;
}

int xoa_sv(List &l){
	int k=search(l, "thuy");
	if(k==0) return 0;
	remove(k,l);
	return 1;
}

void nhapds(List &l){
	ini(l);//khoi tao ds rong
	sinhvien x; //goi sinhvien x
	int i=1;
	do{
		cout<<"sinh vien thu "<<i<<endl;
		nhap(x);
		if(strcmp(x.masv)=="***") return;
		if(!add(l,x)) return;
		else i++; 
	}while(1);
	
}

main(){
	List l;
	nhapds(l);
	hienthi(l);
	cout<<"danh sach sau khi xoa sinh vien dau tien: "<<endl;
	xoa1(l);
	hienthi(l);
	if(xoa_sv(l)==1){
		cout<<"danh sach sau khi xoa sv thuy la: "<<endl;
		hienthi(l);
	}else cout<<"khong co sinh vien thuy"<<endl;
}
