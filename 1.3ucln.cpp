#include<bits/stdc++.h>
using namespace std;

int ucln(int a, int b){
	if(b==0) return a;
	if(a%b==0) return b;
	return ucln(b, a%b);
}

main(){
	int a,b;
	cout<<"a, b= "; cin>>a>>b;
	cout<<"ucln la: "<<ucln(a,b);
}
