#include <iostream>
#include <string>
using namespace std;
int gcd(int a, int b){
	if(a <= 0 && b<= 0){
		return 0;
	}
	
	while(b!=0){
		int temp = b;
		b= a% b;
		a = temp;
	}
	return a;
}

int lcm(int a, int b){
	return (a*b)/gcd(a,b);
}

int THPS(int tuso1, int mauso1, int tuso2, int mauso2){
	int tuso3, mauso3; 
	if(mauso1==0 && mauso2 ==0){
		return 0;
	}else{
		if(mauso1 == mauso2){
			tuso3 = tuso1 +tuso2;
			mauso3= mauso1;
		}else{
			tuso3 = tuso1 * mauso2 + tuso2 * mauso1;
			mauso3 = mauso1 * mauso2;
		}
	}
	cout << tuso3 << "/" << mauso3;
}

string converIntToBin(int N){
	string s;
	while(N>0){
		int remainder = N % 2;
		s = to_string(remainder) + s;
		N /= 2;
	}
	return s;
}

void swap(int &a, int &b){
	int temp = b;
	b = a;
	a = temp;
}

int main(){
	//cout << gcd(10,5) << endl;
	//cout << lcm(3,9) << endl;
	//THPS(1,2,1,2); cout<<endl;
	//cout << converIntToBin(21);
	int a = 5;
	int b = 6;
	swap(a,b);
	cout << a << " " << b;
	
	return 0;
}
