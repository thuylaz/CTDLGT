#include <bits/stdc++.h>
#define max 100
using namespace std;

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



void nhap(sinhvien &s){
	cout<<"ma sv: "; fflush(stdin); gets(s.masv);
	if(strcmp(s.masv, "***")==0) return;
	cout<<"ten sv: "; fflush(stdin); gets(s.ten);
	cout<<"diem: "; cin>>s.diem;
}
void chencuoiadd(List &l){
	sinhvien s;
	nhap(s);
	if(!add(l,s)) return;
}
void nhapds(List &l){
	ini(l);
	sinhvien s;
	int i=1;
	do{
		cout<<"ma sv: "; fflush(stdin); gets(s.masv);
		if(strcmp(s.masv, "***")==0) return;
		cout<<"ten sv: "; fflush(stdin); gets(s.ten);
		cout<<"diem: "; cin>>s.diem;
		if(!add(l,s)) return;
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


//them vtri 2
int chen2(List &l){
	int i;
	sinhvien s;
	int k=1;
	if(l.count!=max-1){
		nhap(s);
		for(int i=l.count; i>=1; i--)
		l.e[i+1]=l.e[i];
		l.e[k]=s;
		l.count++;
		hienthi(l);
	}else cout<<"vi tri khong thich hop"<<endl;
}

void chen3(List &l){
	int k=2;
	sinhvien s;
	int i;
	if(l.count!=max-1){
		nhap(s);
		for(i=l.count; i>=2; i--)
			l.e[i+1]=l.e[i];						
			l.e[k]=s;l.count++;
			hienthi(l);		
	}else cout<<"k chen dc";
}

void xoa2(List &l){
	int k=2;
	int i;
	if(l.count!=-1){
		for(int i=k; i<l.count; i++)
		l.e[i]=l.e[i+1];
		l.count--;
		hienthi(l);
	}else cout<<"k xoa dc";	
}

void sx(List &l){
	for(int i=0; i<=l.count-1; i++){
		int m=i;
		for(int j=i+1; j<=l.count; j++){
			if(strcmp(l.e[j].ten,l.e[m].ten)<0){
				m=j;
			}
		}if(m!=i){
			sinhvien tg=l.e[m];
			l.e[m]=l.e[i];
			l.e[i]=tg;
		}
	}
}

void xoa4(List &l){
	int i,k=1;
	if(l.count!=-1){
		for(int i=k; i<=l.count; i++)
		l.e[i]=l.e[i+1];
		l.count--;hienthi(l);
	}else cout<<"o xoa dc";
}

main(){
	List l;
	nhapds(l);
	hienthi(l);
	chencuoiadd(l);
	hienthi(l);
}
