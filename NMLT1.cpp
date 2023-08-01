#include<iostream>

using namespace std;

void cau2(int a, int b, int c){
	cout << "Trung binh cong" << (a+b+c)/3 << endl;
	if(a >b && a> c && b>c){
		cout <<"So lon nhat:"<< a << endl;
		cout << "So nho nhat:" << c << endl;
	}else if(a >b && a> c && c>b ){
			cout <<"So lon nhat:"<< a << endl;
		cout << "So nho nhat:" << b << endl;
	}else if(b >a && b> c && a>c ){
			cout <<"So lon nhat:"<< b << endl;
		cout << "So nho nhat:" << c << endl;
	}else if(b >a && b> c && c>a ){
			cout <<"So lon nhat:"<< b << endl;
		cout << "So nho nhat:" << a << endl;
	}else if(c >a && c> b && a>b ){
			cout <<"So lon nhat:"<< c << endl;
		cout << "So nho nhat:" << b << endl;
	}else if(c >a && c> b && b>a ){
			cout <<"So lon nhat:"<< c << endl;
		cout << "So nho nhat:" << a << endl;
	}
}

void cau3(float baiTap, float giuaKy, float cuoiKy ){
	float diemTb = baiTap * 0.25 + giuaKy * 0.25 + cuoiKy * 0.5;
	if(diemTb >= 9 ){
		cout << "Xep loai A" << endl;
	}else if (diemTb >= 8.0 && diemTb <= 8.9){
		cout << "Xep loai B" << endl;
	}else if (diemTb >= 6.0 && diemTb <= 7.9){
		cout << "Xep loai C" << endl;
	}else  if (diemTb >= 3.3 && diemTb <=5.9){
		cout << "Xep loai D" << endl;
	}else if (diemTb <= 3.2){
		cout << "Xep loai F" << endl;
	}
}

int cau4(int num){
	int count =1;
	if(num < 10000 && num > 99999){
		return 0;
	}else{
		while(count <= 5){
			cout << num % 10 << " ";
			num = num /10;
			count ++;
		}
	}
}

int main(){
	int R = 10;
	float pi = 3.14;
	cout << "Dien tich hinh tron la " << pi * R * R;
	cout << endl;
	cout << "Chu vi hinh tron la :" << 2*pi*R << endl;
	cau2(10,20,15); cout << endl;
	cau3(10,9.5,9); cout << endl;
	cau4(112345);
	return 0;
}
