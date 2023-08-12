#include <iostream>

using namespace std;


int caculateTax(int area, int price, int location){
	int result;
	int dientichvuot = 1;
	int million = 1000000;
	int hm1 = 160, hm2 =200, hm3 = 250, hm4 = 300;
	switch(location){
		case 1:
			if(area <= hm1){
				result = (area * 0.03/100)*price*million;	
			}else if( area - hm1 < hm1 *3){
				result = (hm1 * 0.03/100 + (area - hm1) * 0.07/100) * price * million;
			}else if(area - hm1 >= hm1 *3){
				result = (hm1 * 0.03/100 + (area - hm1) * 0.15/100 ) * price * million;
			}
			break;
		case 2:
			if(area <= hm2){
				result = (area * 0.03/100)*price*million;	
			}else if( area - hm2 < hm2 *3){
				result = (hm2 * 0.03/100 + (area - hm2) * 0.07/100) * price * million;
			}else if(area - hm2 >= hm2 *3){
				result = (hm2 * 0.03/100 + (area - hm2) * 0.15/100 ) * price * million;
			}
			break;
		case 3:
			if(area <= hm3){
				result = (area * 0.03/100)*price*million;	
			}else if( area - hm3 < hm3 *3){
				result = (hm3 * 0.03/100 + (area - hm3) * 0.07/100) * price * million;
			}else if(area - hm3 >= hm3 *3){
				result = (hm3 * 0.03/100 + (area - hm3) * 0.15/100 ) * price * million;
			}
			break;
		case 4:
			if(area <= hm4){
				result = (area * 0.03/100)*price*million;	
			}else if( area - hm4 < hm4 *3){
				result = (hm4 * 0.03/100 + (area - hm4) * 0.07/100) * price * million;
			}else if(area - hm4 >= hm4 *3){
				result = (hm4 * 0.03/100 + (area - hm4) * 0.15/100 ) * price * million;
			}
			break;
		defautl:
		cout<< "Khong co khu vuc do ";
	};
};


void NhapThongTin(char name[20], int &area, int &price, int &location){
	cout << "hoten "; //cin.ignore(); 
	cin.getline(name,21);
	cout << "dien tich "; cin >> area;
	cout << "khu vuc " ; cin >> location;
	cout << "gia tien "; cin >> price;
}

void xuatThongTin(char name[20], int area, int price, int location){
	cout << "Ho ten "; cout << name << endl;
	cout << "Tien thue phai nop "<< caculateTax(area,price,location);
}


// bai 2;

typedef struct{
	char id[9];
	char name[20];
	float Marks[3];
	float DTB;
} Student;

void xepLoai(Student S){
	//S.DTB = S.Marks[0] * 0.25 + S.Marks[1] * 0.25 + S.Marks[2] * 0.5;
	
	if(S.DTB < 5){
		cout << "Yeu";
	}else if(5 <= S.DTB && S.DTB < 7){
		cout << "Trung binh";
	}else if(7 <= S.DTB && S.DTB <8){
		cout << "Kha";
	}else{
		cout << "Gioi";
	}
}

void nhap_sv(Student &sv){
	cout << "Nhap id: ";
	cin.get(sv.id,9);
	cin.ignore();
	cout << "Nhap name: ";
	cin.get(sv.name,20);
	cout << "Marks: baitap, giuaky, cuoiky: ";
	for(int i = 0; i<3;i++){
		cin >> sv.Marks[i];
	}
	sv.DTB = sv.Marks[0] * 0.25 + sv.Marks[1] * 0.25 + sv.Marks[2] * 0.5;
}

void xuat_sv(Student sv){
	cout << "id\t  " << "name\t\t\t" <<"baitap\t" << "giuaky\t" << "cuoiky\t" << "DTB" << endl;
	cout << sv.id <<" " << sv.name << "\t\t" << sv.Marks[0] << " \t" << sv.Marks[1] << "\t" << sv.Marks[2] << "\t" << sv.DTB << endl; 
	cout <<"Sinh vien xep loai: " ; xepLoai(sv); cout << endl;
	//cout << endl;
}


void them_sv(Student sv[] , int &n){
	cout << "Nhap thong tin sinh vien thu "<< n+1 << ": " << endl;
	nhap_sv(sv[n]);
	cin.ignore();
}

void xuat_ds_sv(Student sv[], int n){
	cout << endl;
	cout << "Danh sach sinh vien "<< endl;
	if(n <= 0){
		cout << "Danh sach sinh vien rong !!!";
	}else{
		for(int i = 0; i< n ;i++){
			xuat_sv(sv[i]);
		}
	}
}

void xoaSv(Student sv[], int &n){
	int k;
	for(int i = 0; i < n;i++){
		if(sv[i].DTB < 5){
		  for(int j = i ; j<n-1;j++){
		  	sv[j] = sv[j+1];
		  }
		  n--;
		  i--;
		}
	}
	n= n-k;
}

int main(){
	/*char name[20];
	int area,price,location;
	NhapThongTin(name,area,price,location);
	xuatThongTin(name,area,price,location);*/
	Student sv[10];
	int n = 0;
	cout << "Nhap so luong sinh vien ";
	cin >> n;
	cin.ignore();
	int soLuongSv = 0;
	cout << "Them sinh vien " << endl;
	while(soLuongSv < n){
		//cin.ignore();
		them_sv(sv,soLuongSv);
		soLuongSv ++;
	};
	
	xuat_ds_sv(sv,soLuongSv);
	
	xoaSv(sv,soLuongSv);
	cout << "Danh sach sinh vien sau khi xoa sv co DTB < 5" << endl;
	xuat_ds_sv(sv,soLuongSv);
	return 0;
}
