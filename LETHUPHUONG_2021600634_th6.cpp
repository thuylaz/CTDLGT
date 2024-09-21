#include<bits/stdc++.h>
using namespace std;
struct sinhvien{
	char masv[10];
	char hoten[30];
	float diem;	
};
struct Node{
	sinhvien infor;
	Node *next;
};
typedef Node *tro;
void initialize (tro &L){
	L=NULL;
}
int Empty(tro L){
	return L==NULL;
}
void Nhap(sinhvien &sv){
	cout<<"Nhap ma sv: ";		fflush(stdin);		gets(sv.masv);
	cout<<"Nhap ten sv: ";		fflush(stdin);		gets(sv.hoten);
	cout<<"Nhap diem cua sv: ";						cin>>sv.diem;
	
}
void Nhapds(tro &L){
	initialize(L);
	sinhvien x;
	tro Q, P;
	int n;
	cout<<"\n Nhap so luong sinh vien: ";
	cin>>n;	
		for(int i=0; i<n; i++){
		Nhap(x);
		if(strcmp(x.masv,"***")==0)
		return ;
			P=new(Node);
			P->infor=x;
			P->next=NULL;
			if(L==NULL)
				L=P;
			else
				Q->next=P;
			Q=P;
		}
}
void hienthi(tro L){
	if(L==NULL){
		cout<<"\n Danh sach rong";
		return;
	}
	cout<<setw(10)<<"STT";
	cout<<setw(10)<<"masv";
	cout<<setw(10)<<"hoten";
	cout<<setw(10)<<"diem"<<endl;
	tro Q=L;
	int i=0;
	while(Q!=NULL){
		sinhvien x=Q->infor;
		cout<<setw(10)<<(i+1);
		cout<<setw(10)<<x.masv;
		cout<<setw(10)<<x.hoten;
		cout<<setw(10)<<x.diem<<endl;
		Q=Q->next;
	}
}
//xac dinh chieu dai danh sach
int length(tro L){
	int n=0;
	tro Q=L;
	while(Q!=NULL){
		Q=Q->next;
		n++;
	}
	return n;
}
//ham chen chung vao vtri bat ki
void chen(tro &L, tro Q, sinhvien x){
	tro P;
	P=new(Node);
	P->infor=x;
	P->next=Q->next;
	Q->next=P;
	
}
//chen vao vitri chon
void chenvtrik(tro &L){
	int k;
	sinhvien x;
	//nhap cac thong tin cho sv can chen
	do{
		cout<<"Nhap vitri bs: ";
		cin>>k;
		
	}while(k<1||k>length(L));
	cout<<"Nhap thong tin sv can bo sung:"<<endl;
		Nhap(x);
	//bo sung x vao vtri k
	tro Q=L;
	int d=1;
	while(d<k-1){
		d++;
		Q=Q->next;
		
	}
	//bo sung vao sau nut tro boi Q
	chen(L,Q,x);
	cout<<"danh sach sinh vien sau khi bo sung: "<<endl;
	hienthi(L);		
}

//timsv theo masv
tro timmasv(tro L, char *ma){
	tro Q=L;
	while(Q!=NULL&&strcmp(Q->infor.masv,ma)!=0)
	Q=Q->next;
	return Q;
}
void chenmasv(tro &L){
	sinhvien X;
	tro T=timmasv(L,"sv2");
	//th khong co
	if(T==NULL){
		cout<<"\nkhong co sv co ma sv2 trong danh sach";
		return;
	}
	Nhap(X);
	chen(L,T,X);
	cout<<"\ndanh sach sau chen: ";
	hienthi(L);
}
float timdiemmax(tro &L){
	tro Q=L;
	float max=Q->infor.diem;
	Q=Q->next;
	while(Q!=NULL){
		if(max<Q->infor.diem){
			max=Q->infor.diem;
		}
			Q=Q->next;
	
	}
  		return max;
}
float timdiemmin(tro &L){
	tro Q=L;
	float min=Q->infor.diem;
	Q=Q->next;
	while(Q!=NULL){
		if(min>Q->infor.diem){
			min=Q->infor.diem;
		}
			Q=Q->next;
	
	}
  		return min;
}
void hienthimax(tro L){
	tro Q;
	Q = L;
	float max = timdiemmax(L);
	int i = 0;
	cout<<"Danh sach sinh vien diem lon nhat: "<<endl;
	cout<<"STT";
	cout<<setw(15)<<"Ma";
	cout<<setw(27)<<"Ho ten";
	cout<<setw(32)<<"Diem"<<endl;
	while(Q!=NULL){
		sinhvien X = Q->infor;
		if(X.diem == max){
			cout<<i+1;
			cout<<setw(15)<<X.masv;
			cout<<setw(27)<<X.hoten;
			cout<<setw(33)<<X.diem<<endl;
			i++;
		}
		Q = Q->next;
	}
}

void hienthimin(tro L){
	tro Q;
	Q = L;
	int i = 0;
	float min = timdiemmin(L);
	cout<<"Danh sach sinh vien diem thap nhat: "<<endl;
	cout<<"STT";
	cout<<setw(15)<<"Ma";
	cout<<setw(27)<<"Ho ten";
	cout<<setw(32)<<"Diem"<<endl;
	while(Q!= NULL){
		sinhvien X = Q->infor;
		if(X.diem == min){
			cout<<i+1;
			cout<<setw(15)<<X.masv;
			cout<<setw(27)<<X.hoten;
			cout<<setw(32)<<X.diem<<endl;
			i++;
		}	
		Q=Q->next;
	}
}

void deletediemmax(tro &L){
	tro Q;
	Q = L;
	int i = 0;
	float max = timdiemmax(L);
	cout<<"Danh sach sinh vien da xoa max: "<<endl;
	cout<<"STT";
	cout<<setw(15)<<"Ma";
	cout<<setw(27)<<"Ho ten";
	cout<<setw(32)<<"Diem"<<endl;
	while(Q!= NULL){
		sinhvien X = Q -> infor;
		if(X.diem == max){
			return;
		}else{
			cout<<i+1;
			cout<<setw(15)<<X.masv;
			cout<<setw(27)<<X.hoten;
			cout<<setw(32)<<X.diem<<endl;
			i++;
		}
		Q = Q ->next;
	}
	
	
}


 main(){
	tro L;
	
	Nhapds(L);

	cout<<"\nDanh sach vua nhap : "<<endl;
	hienthi(L);
	
	cout<<"_______________________________"<<endl;
	chenvtrik(L);
	
	cout<<"_______________"<<endl;
	chenmasv(L);
	
	cout<<"_____________sv co diem lon nhat_______________"<<endl;
	hienthimax(L);	
	cout<<"_____________ ds sv co diem nho nhat___________"<<endl;
	hienthimin(L);
	deletediemmax(L);
}

