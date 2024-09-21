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

void ini(List &l){
	l.count=-1;
}

int full(List l){
	return l.count==max-1;
}

int empty(List l){
	return l.count==-1;
}

int add(List &l, sinhvien s){
	if(!full(l)){
		l.e[l.count+1]= s;
		l.count++;
		return 1;
	}else return 0;	
}

void nhapds(List &l){
	ini(l);
	sinhvien s;
	int i=1;
	do{
		cout<<"nhap sv thu "<<i<<endl;
		nhap(s);
		if(strcmp(s.masv, "***")==0) return;
		if(!add(l,s)) return;
		i++;
	}while(1);
}


void hienthi(List &l){
	cout<<"ma sv: "
		<<setw(13)<<"ten sv "
		<<setw(13)<<"diem: "<<endl;
	for(int i=0; i<=l.count; i++){
		cout<<l.e[i].masv
			<<setw(13)<<l.e[i].ten
			<<setw(13)<<l.e[i].diem<<endl;
	}
}


int chen(int k, List &l){
	int i;
	sinhvien s;
	if(!full(l)&&k>0&&k<=l.count+1){
		cout<<"nhap tt can chen: "; nhap(s);
		for(i=l.count; i>=k-1; i--)
		l.e[i+1]= l.e[i];
		l.e[k]=s;
		l.count++;
		return 1;
	}else return 0;
}



main(){
	List l;
	nhapds(l);
	hienthi(l);
	int k;
	cout<<"nhap vtri can chen: "; cin>>k;
	if(chen(k,l)==1){
		cout<<"dsach sv sau khi chen la: "<<endl;
		hienthi(l);
	}else cout<<"vi tri khong thich hop"<<endl;
}

/*
sv1
thuy
3
sv2
nhung
4
sv4
thien
4
sv5
ha
4
***
sv3
thien
7

*/
