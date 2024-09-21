#include<bits/stdc++.h>
using namespace std;
#define max 100

struct sinhvien{
	char masv[20];
	char hodem[20];
	char ten[20];
	char gt[20];
	int nam;
	float diem;
};

//khai bao kieu su lieu sinhvien
struct List{
	int count;
	sinhvien e[max];
};

//khoi tao danh sach rong
void ini(List &l){
	l.count=-1;
}

//kiem tra danh sach rong
int empty(List l){
	return l.count==-1;
}

//ktra danh sach day
int full(List l){
	return l.count == max-1;
}

//chen ptu cuoi dsach
int addcuoi(sinhvien x, List &l){
	if(!full(l)){
		l.e[l.count+1]= x;
		l.count= l.count+1;
		return 1;
	}else return 0;
}

//nhap thong tin sinh vien
void nhap(sinhvien &sv){
	cout<<"ma sv: "; fflush(stdin); gets(sv.masv);
	cout<<"ho dem: "; fflush(stdin); gets(sv.hodem);
	cout<<"ten: "; fflush(stdin); gets(sv.ten);
	cout<<"gioi tinh: "; fflush(stdin); gets(sv.gt);
	cout<<"nam sinh: "; cin>>sv.nam;
	cout<<"diem: "; cin>>sv.diem;
}

//nhap mang sinh vien
void arr(List &l){
	ini(l);
	sinhvien x;
	do{
		nhap(x);
		if(strcmp(x.masv,"***")==0) return;
		if(!addcuoi(x,l)) return;
	}while(1);
}

void hienthi(List l){
	cout<<"ma sv: "
	<<setw(12)<<"ho dem"
	<<setw(12)<<"ten"
	<<setw(12)<<"gioi tinh"
	<<setw(12)<<"nam sinh"
	<<setw(12)<<"diem"<<endl;
	
	for(int i=0; i<l.count; i++){
		cout<<l.e[i].masv
		<<setw(12)<<l.e[i].hodem
		<<setw(12)<<l.e[i].ten
		<<setw(12)<<l.e[i].gt
		<<setw(12)<<l.e[i].nam
		<<setw(12)<<l.e[i].diem<<endl;
		
	}
}

//xac dinh do dai danh sach
int length(List l){
	int d=0;
	for(int i=0; i<=l.count; i++){
		d++;
		return d;
	}
}

//xoa ptu vtri k
int xoak(int k, List &l){
	cout<<"nhap k: "; cin>>k;
	if(k>=1&&k<=l.count+1){
		for(int i=k-1; i<l.count; i++)
			l.e[i]= l.e[i+1];			
		
		l->count= l->count-1;
		return 1;
	}else return 0;
}

//chen phan tu vao vi tri k
int chenk(int k, sinhvien x, List &l){
	if(!full(l) && k<=l.count+1 && k>=1){
		for(int i=l.count; i>=k; i--){
			l.e[i+1]= l.e[i];
		}
		l.count=l.count+1;
		l.e[k-1]= x;
		return 1;
	}else return 0;
}

//duyet de tim kiem 1 phan tu trong danh sach
int search(sinhvien x, List l){
	while(int i<=l.count && l.e[i]!= x)
		i++;
	if(int i<=l.count) return i;
	else return -1;
}

main(){
	List l;
	arr(&l);
	cout<<"danh sach vua nhap la: "<<endl;
	hienthi(l);
	
}
