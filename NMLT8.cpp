#include<iostream>
#include<string.h>
#define MAX 100
using namespace std;

struct sinhVien{
	char name[30];
	int id;
	float marks[3];
};

typedef  sinhVien SV;

void nhapThongTinSinhVien(SV &sv);
void nhapSinhVien(SV a[], int n);
void showStudent(SV a[], int n);
void nhapThongTinSinhVien(SV &sv){
	cout << "Nhap ten sinh vien: ";
	cin.ignore();
	cin.getline(sv.name,30);
	cout << "Nhap id sinh vien: ";
	cin >> sv.id;
	for(int i = 0; i < 3; i++){
		cout << "Nhap diem he so " << i+1 << " : ";
		cin >> sv.marks[i]; 
	}
}


void nhapSinhVien(SV a[], int n){
	cout << "Nhap sinh vien thu " << n + 1 << " :";
	nhapThongTinSinhVien(a[n]);
}

float avg(float marks[]){
	return (marks[0] + marks[1] + marks[2]) /3.0;
}

void showStudent(SV a[], int n){
	cout << endl;
	cout <<"Danh sach sinh vien:" << endl;
	for(int i = 0; i < n; i++){
		cout << a[i].name << "   " << a[i].id << "  " << a[i].marks[0] << "  " << a[i].marks[1] << "  " << a[i].marks[2] << endl;
		cout << "Diem trung binh " << avg(a[i].marks) << endl;
	}
}

void showSvWithId(SV a[], int n , int id){
	cout << "Sinh vien can tim voi id :" << id << " la :" << endl;
	for(int  i = 0 ; i < n; i++){
		if(a[i].id == id){
			cout << a[i].name << "   " << a[i].id << "  " << a[i].marks[0] << "  " << a[i].marks[1] << "  " << a[i].marks[2] << endl;
		}
	}
}

void showSvWithName(SV a[], int n){
	char nameF[30];
	cout << "Nhap ten can tim: ";
	cin.ignore();
	cin.getline(nameF,30);
	cout << "Sinh vien can tim voi ten :" << nameF << " la :" << endl;
	for(int  i = 0 ; i < n; i++){
		if(strcmp(a[i].name, nameF)==0){
			cout << a[i].name << "   " << a[i].id << "  " << a[i].marks[0] << "  " << a[i].marks[1] << "  " << a[i].marks[2] << endl;
		}
	}
}

void findMaxAvgSv(SV a[], int n){
	int max =0;
	int index =-1;
	for(int i =0 ; i < n;i++){
		float avgM = avg(a[i].marks);
		if(max < avgM){
			max = avgM;
			index = i;
		}
	}
	if(index != -1 ){
	cout << a[index].name << "   " << a[index].id << "  " << a[index].marks[0] << "  " << a[index].marks[1] << "  " << a[index].marks[2] << endl;
	}
}

// bai 2;

struct PhanSo{
	int tuso, mauso;
};

typedef PhanSo PS;

void NhapPhanSo(PS &ps){
	cout << "Nhap tu so vao: ";
	cin>> ps.tuso;
	cout << "Nhap mau so vao: ";
	cin >> ps.mauso;	
}

bool checkLogic(PS &ps){
	if(ps.mauso == 0){
		return false;		
	}
	return true;
}


void XuatPhanSo(PS &ps){
	if(checkLogic(ps)){
		cout << "Nhap lai phan so ";
		NhapPhanSo(ps);
	}
	cout << ps.tuso << "/" <<ps.mauso << endl;
}

void sumPhanSo(PS &ps1, PS &ps2){
	PS result;
	if(ps1.mauso == ps2.mauso){
		result.tuso = ps1.tuso + ps2.tuso;
	}
	else{
		result.tuso = ps1.tuso * ps2.mauso + ps2.tuso * ps1.mauso;
		result.mauso = ps1.mauso * ps2.mauso;
	}
	
	cout << "Tong 2 phan so tren la: ";
	cout << result.tuso << "/" << result.mauso;
}


void soSanhPS(PS ps1, PS ps2){
	if(ps1.mauso == ps2.mauso){
		if(ps1.tuso < ps2.tuso){
			cout << "Phan so 2 lon hon phan so 1";
		}else{
			cout << "Phan so 1 lon hon phan so 2";
		}
	}
	else{
		if((ps1.tuso * ps2.mauso) < (ps2.tuso * ps1.mauso)){
			cout << "Phan so 2 lon hon phan so 1";
		}else{
			cout << "Phan so 1 lon hon phan so 2";
		}	
	}
}

void NhapMangPhanSo(PS a[], int n){
	cout << "Nhap phan so thu " << n+1 << ": ";
	NhapPhanSo(a[n]);
}

void ShowArrayPs(PS a[], int n){
	cout << endl;
	cout << "Danh sach cac phan so la: ";
	for(int i = 0; i < n;i++){
		cout << a[i].tuso << "/" << a[i].mauso << " ";	
	}
}

void FindMaxPs(PS a[], int n){
	int index = 0;
	float max= a[0].tuso / a[0].mauso;
	for(int i = 1; i < n ;i++){
		float temp =(a[i].tuso / a[i].mauso);
		if(max < (temp)){
			max= temp;
			index = i;
		}
	}
	cout << "Phan so lon nhat la: " << a[index].tuso << "/" << a[index].mauso;
}

// Phan 2 
// Bai 1;

void xuatMang(int a[], int n){
	for(int i = 0; i < n; i++){
		cout << "a[" << i << "]=" <<a[i] << " ";
	}
	cout << endl;
}

void swap(int & a, int &b){
	int temp = a;
	a = b;
	b= temp;
}

void sortArray(int a[], int n){
	for(int i = 0 ; i < n; i++){
		for(int j = 0 ; j < n - i -1 ;j++){
			if(a[j] < a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
}


void ghiMangChan(int a[], int n){
	FILE *file = fopen("daysochan.txt", "w");
	if(file != NULL){
		fprintf(file,"%d\n", n);
		for(int i = 0; i< n ;i++){
			if(a[i] % 2 == 0){
				fprintf(file, "%d\t", a[i]);
			}
		}
		fclose(file);
	}else{
		cout << "Khong the mo file !!!";
		cout << endl;
	}
}

void ghiMang(int a[], int n){
	FILE *file = fopen("dayso.txt","w");
	if(file != NULL){
		fprintf(file, "%d\n",n);
		//fprintf(file,"[");
		for(int i = 0; i< n -1;i++){
			fprintf(file, "%d\t", a[i]);
		}
		fprintf(file, "%d", a[n-1]);
		fprintf(file, "\n");
		
		fclose(file);
	}else{
		cout << "Khong mo dc file !!!";
		cout << endl;
	}
}

void ghiMangSort(int a[], int n){
		FILE *file = fopen("dayso.txt","a");
	if(file != NULL){
		fprintf(file, "%s\n","Day sau khi sap xep la");
		//fprintf(file,"[");
		for(int i = 0; i< n ;i++){
			fprintf(file, "%d\t", a[i]);
		}
		fprintf(file, "\n");
		
		fclose(file);
	}else{
		cout << "Khong mo dc file !!!";
		cout << endl;
	}
}
 
static void docMang(){
	FILE * file = fopen("dayso.txt", "r");
	
	int n = 0;
	int a[100];
	
	if(file != NULL){
		fscanf(file,"%d",&n);
		cout << n << endl;
		for(int i = 0; i < n; i++){
			fscanf(file, "%d", &a[i]);
		}
		ghiMangChan(a,n);
		sortArray(a,n);
		ghiMangSort(a,n);
		xuatMang(a,n);
		fclose(file);
	}else{
		cout << "Khong mo dc file !!!";
	}
}

// bai 2;

struct phanSo{
	int tuso;
	int mauso;
};

typedef phanSo ps;

void sort(ps a[], int n, float c[]){
	for(int i = 0;i<n;i++){
		for(int j = 0; j<n-i-1;j++){
			if(c[j] > c[j+1]){
				swap(a[j],a[j+1]);
				swap(c[j],c[j+1]);
			}
		}
	}
	
}
static void ghiList(ps a[], int n){
	FILE *file = fopen("phanso.txt","a");
	if(file != NULL){
		fprintf(file, "\n");
		fprintf(file, "%s\n","------- Danh sach phan so da sap xep");
		for(int i = 0; i< n ;i++){
			fprintf(file, "%d %d \n ", a[i].tuso,a[i].mauso);
		}
		fprintf(file, "\n");
		fclose(file);
	}else{
	 cout << "Khong mo dc file!!!";
	 cout << endl;	
	}
}
static void docList(){
	FILE *file = fopen("phanso.txt","r");
	int n = 0 ;
	ps a[10];
	float c[10];
	if(file != NULL){
		fscanf(file,"%d",&n);
		cout << n << endl;
		
		for(int  i = 0; i< n;i++){
			fscanf(file, "%d %d",&a[i].tuso,&a[i].mauso);
			cout << a[i].tuso << "/" << a[i].mauso << endl;
			c[i] = (float)a[i].tuso / a[i].mauso;
		}
		sort(a,n,c);
		for(int  i = 0; i<n;i++){
			cout << a[i].tuso << "/" << a[i].mauso << "  ";
		}
		ghiList(a,n);
		fclose(file);
	}else{
		cout<< "Khong mo duoc file !!!";
	}
}

int main(){
	//SV arraySV[MAX];
	//int n;
	//cout << "Nhap so luong sinh vien: ";
	//cin >> n;
	//int soLuongSv = 0;
	/*while(soLuongSv < n){
	cout << "Them sinh vien " << endl;
	nhapSinhVien(arraySV,soLuongSv);
	soLuongSv++;
	}
	showStudent(arraySV,soLuongSv);
	cout << endl;
	//showSvWithId(arraySV,n, 20120405);
	//showSvWithName(arraySV,n);
	findMaxAvgSv(arraySV,n)*/;
	/*PS ps1, ps2;
	PS arrayPs[MAX];
	int n;
	cout << "Nhap so luong phan so vao: ";
	cin >> n;
	int soLuongPs = 0;
	while(soLuongPs < n){
		cout << "Them phan so " << endl;
		NhapMangPhanSo(arrayPs,soLuongPs);
		soLuongPs ++;
	}
	
	ShowArrayPs(arrayPs,n);
	FindMaxPs(arrayPs, n);*/
	//docMang();
	//int a[]={10,15,20,25,30,35,40,50};
	//int n = sizeof(a)/4;
	//sortArray(a,n);
	//xuatMang(a,n);
	//ghiMang(a,n);
	//docMang();
	
	docList();
	
	return 0;
}




/*#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int numerator;
    int denominator;
} Fraction;

int main() {
    FILE* file = fopen("phanso.txt", "r");

    if (file == NULL) {
        fprintf(stderr, "Khong the mo tap tin.\n");
        return 1;
    }

    int numFractions; // so luong phan so n
    if (fscanf(file, "%d", &numFractions) != 1) {
        fprintf(stderr, "Loi khi doc so luong phan so.\n");
        fclose(file);
        return 1;
    }

    Fraction* fractions = (Fraction*)malloc(numFractions * sizeof(Fraction));
    if (fractions == NULL) {
        fprintf(stderr, "Khong du bo nho.\n");
        fclose(file);
        return 1;
    }

    for (int i = 0; i < numFractions; ++i) {
        if (fscanf(file, "%d %d", &fractions[i].numerator, &fractions[i].denominator) != 2) {
            fprintf(stderr, "Loi khi doc phan so thu %d.\n", i + 1);
            fclose(file);
            free(fractions);
            return 1;
        }
    }

    fclose(file);

    printf("Cac phan so duoc doc tu tap tin:\n");
    for (int i = 0; i < numFractions; ++i) {
        printf("%d/%d\n", fractions[i].numerator, fractions[i].denominator);
    }

    free(fractions);

    return 0;
}*/

