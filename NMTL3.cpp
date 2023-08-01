#include <iostream>
#include <cmath>
using namespace std;

void cau1(){
	int n,x;
	int i=1;
	cout << "Nhap n vao: " ; cin >> n;
	cout << "Nhap x vao: " ; cin >>x;
	float sum1, sum2 =0;
	double sum3 = 0,sum5;
	long sum4=1;
	//for(int i = 1; i <= n; i++  ){
	while( i <= n){
		sum1 +=i;
		sum2 += (1.0)/i;
		sum3 += (i*(1.0))/(i+1);
		sum4 *= i;
		sum5 += pow(x,2*i+1);
		i++;
	}
	cout << sum1 <<endl;
	cout << sum2 <<endl;
	cout << sum3 <<endl;
	cout << sum4 <<endl;
	cout << sum5 <<endl;
}

bool isPrime(int number){
	if( number <=1 ){
		return false;
	}
	
	for(int i =2 ; i*i <=number ; i++){
		if(number % i ==0){
			return false;
		}
	}
	return true;
}

void cau2(){
	int sumA =0;
	int sumB =0; 
	for(int i = 1; i<=50;i++){
		if(i % 2 != 0){
			sumA += i;
		}
		if(isPrime(i)){
			sumB += i;
		}
	}
	cout << sumA << endl;
	cout << sumB << endl;
}

int cau3(){
	int n;
	cout << "Nhap so n vao ";
	cin >> n;
	if(n <=1){
		return n;
	}
	int prev = 0;
	int curr = 1;
	int i=2;
	while(i <= n){
		int next = prev + curr;
		prev = curr;
		curr = next;
		i++;
	}
	return curr;
}


void uocSo(int n){
	for(int i = 1; i<= n; i++){
		if(n % i == 0){
			cout << i << " ";
		}
	}
}

int cau4(){
	int a; int b;
	cout<< "Nhap so a: "; cin >> a;
	cout << "Nhap so b: " ; cin >> b;
	if(a <=0 && b<=0 ){
		return 0;
	}
	uocSo(a); cout << endl;
	uocSo(b); cout << endl;
	while(b!=0){
		int temp = b;
		b= a % b;
		a = temp;
	}
	return a;
}

void cau5(){
	char s;
	cout << "Nhap ten cua ban: ";
	cin >>s;
	cout << s;
}
int main(){
	//cau1();
	//cau2();
	//cout << cau3();
	//cout << cau4();
	cau5();
	return 0;
}
