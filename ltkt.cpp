#include <bits/stdc++.h>
#define Max 100
using namespace std;
struct sv
{
    char masv[10];
    char hodem[22];
    char ten[10];
    int namsinh;
    float diemtk;
};

struct List
{
    int count;
    sv e[Max];
};

//khoi tao dsach rong
void Initialize(List &L)
{
    L.count = -1;
}

//ktra daylight
int Full(List L)
{
    return L.count == Max -1;
}

int Empty(List L)
{
    return L.count == -1;
}

// them mot sinh vien vao cuoi dsach
int Add(List &L, sv x)
{
    if(Full(L))
        return 0;
    else
    {
        L.count++;
        L.e[L.count] = x;
        return 1;
    }
}

void nhapsv(sv &sv)
{
    cout << "nhap ma sv: "; fflush(stdin); gets(sv.masv);
    if (strcmp(sv.masv, "***")==0)
        return;
    cout << "nhap ho dem: "; fflush(stdin); gets(sv.hodem);
    cout << "nhap ten: "; fflush(stdin); gets(sv.ten);
    cout << "nhap nam sinh: "; cin >> sv.namsinh;
    cout << "nhap diem tk: "; cin >> sv.diemtk;
    cout << endl;
}

//nhap dsach sv
void nhapds(List &L)
{
    Initialize(L);
    sv x;
    do
    {
        nhapsv(x);
        if(strcmp(x.masv, "***")==0)
            return;
        if(!Add(L,x))
            return;
    }while(1);
}

void hiends(List L)
{
    cout << setw(5) << "STT" << setw(10) << "Ma sv" << setw(25) << "Ho va ten" << setw(10) << "Nam sinh" << setw(10) << "Diem TK" << endl;
    for(int i = 0; i <= L.count; i++)
        cout << setw(5) << i+1 << setw(10) << L.e[i].masv << setw(17) << L.e[i].hodem << setw(8) << L.e[i].ten << setw(10) << L.e[i].namsinh << setw(10) << L.e[i].diemtk << endl;
}

void Remove(int h, List &L)
{
    for(int i=h-1; i<L.count;i++)
        L.e[i]=L.e[i+1];
    L.count--;
    hiends(L);
}

//them 1 phan tu vao vi tri k trong danh sach
int Insert(int k, List &L)
{
    int i;
    sv x;
    if(!Full(L)&& k<=L.count+1 && k>=1)
    {
        cout << "\nNhap tt can bo sung\n";
        nhapsv(x);
        for(int i=L.count; i>=k-1; i--)
            L.e[i+1]=L.e[i];
        L.count++;
        L.e[k-1] = x;
        return 1;
    }
    return 0;
}
void sua(List &L)
{
    int i=0, d=0;
    while(i<=L.count)
    {
        if(strcmp(L.e[i].masv,"sv01")==0)
        {
            strcpy(L.e[i].ten, "TAM");
            d++;
        }
        i++;
    }
    if(d==0)
        cout<<"ko co sv nay\n";
}
int main()
{
    List L;
    nhapds(L);
    cout << "Dsach sau khi nhap\n";
    hiends(L);
    int k,h;
    /*cout << "Nhap vi tri muon chen: ";
    cin >> k;
    cout << endl;
    Insert(k,L);
    hiends(L);
    cout << endl;
    cout << "Nhap vi tri muon xoa: ";
    cin >> h;
    cout << endl;
    Remove(h,L);*/
    sua(L);
    hiends(L);
    return 0;
}
