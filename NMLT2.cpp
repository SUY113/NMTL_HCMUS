#include <iostream>
#include <cmath>
using namespace std;

void cau1(int a){
	double sum= 0;
	if( a <= 100){
		sum = a*1242;
		sum += sum * 0.1;
		cout << "Tien dien " << sum << endl;
	}else if (a >= 101 && a <= 150 ){
		sum = 100*1242 + (a-100)*1304;
		sum += sum * 0.1;
		cout << "Tien dien " << sum << endl;
	}else if ( a >= 151 && a<= 200){
		sum = 100*1242 + 150*1304 +(a-150)*1651;
		sum += sum * 0.1;
		cout << "Tien dien " << sum << endl;
	}else if ( a >= 201 && a<= 300){
		sum = 100*1242 + 150*1304 +200*1651 + (a - 200)*1788;
		sum += sum * 0.1;
		cout << "Tien dien " << sum << endl;
	}else if ( a >= 301 && a<= 400){
		sum = 100*1242 + 150*1304 +200*1651 + 300 * 1788 + (a-300)*1912;
		sum += sum * 0.1;
		cout << "Tien dien " << sum << endl;
	}else if ( a >=400){
		sum = 100*1242 + 150*1304 +200*1651 + 300 * 1788 + 400*1912 + (a-400)*1962;
	sum += sum * 0.1;
		cout << "Tien dien " << sum << endl;
	}
}

int cau2(int b){
	int sum =0;
	if( b < 10000 && b > 99999 ){
		return 0;
	}else{
		int count = 1;
		
		while ( count <= 5){
			sum += b %10;
			b = b /10;
			count ++;
		}
	}
	return sum %10;
}
 
void cau3(){
	int a,b ;
	int sel;
	cout << "Nhap so a " ; cin >> a;
	cout << "Nhap so b " ; cin >> b;
	cout << "Chon cac lua chon sau de tinh toan" << endl;
	cout << "1 . +"<< endl;
	cout << "2 . -"<< endl;
	cout << "3 . *"<< endl;
	cout << "4 . /"<< endl;
	cout << "5 . ^"<< endl;
	cout << "Nhap lua chon cua ban "; cin >> sel;
	switch(sel){
		case 1:
			cout << "Tong cua 2 so la " << a+b;
			break;
		case 2:
			cout << "Hieu cua 2 so la " << abs(a-b);
			break;
		case 3:
			cout << "Tich cua 2 so la " << a*b;
			break;
		case 4:
			cout << "Thuong cua 2 so la " << static_cast<float>(a/b);
			break;
		case 5:
			cout << "Luy thua cua 2 so la " << pow(a,b); 
			break;
		default:
		cout << "Khong co lua chon cua ban";
	}
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

void cau5(){
	int sum =0;
	for( int i = 0; i <=50;i++){
		if(isPrime(i)){
			sum +=i;
		}
	}
	cout << sum;
}
int main(){
	//cau1(400);
	//cout << cau2(13245);
	//cau3();
	cau5();
	return 0;
}
