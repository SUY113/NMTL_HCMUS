#include<iostream>
#include<cstring>
#include <fstream>
#include<math.h>
using namespace std;
// bai 1;
void xuatMang(int a[],int n){
	cout << "Mang gom cac phan tu" << endl;
	for(int i = 0; i< n;i++){
		cout << a[i]<<" ";
	}
}

void ghiMang(int a[], int n){
	FILE *file = fopen("mangA.txt","w");
	if(file != NULL){
		fprintf(file, "%d\n", n);
		for(int i = 0 ; i<n;i++){
			fprintf(file, "%d\t", a[i]);
		}
		fprintf(file,"\n");
		fclose(file);
	}else{
		cout << "Khong mo duoc file!!!";
		cout << endl;
	}
}

void docMang(){
	FILE *file = fopen("mangA.txt","r");
	int n = 0;
	int a[100];
	if(file != NULL){
		fscanf(file,"%d", &n);
		cout << n << endl;
		for(int i = 0; i < n;i++){
			fscanf(file, "%d\t",&a[i]);
		}
		xuatMang(a,n);
		fclose(file);
	}else{
		cout << "Khong mo duoc file !!!";
		cout << endl;
	}
}

//bai 2;

struct member{
	int id;
	char fname[20];
	char lname[20];
};

void Nhapthongtin(member &p){
	cout << "Nhap id "; cin >> p.id;
	cin.get();
	cout << "Nhap fname "; cin.getline(p.fname,21);
	cout << "Nhap lname "; cin.get(p.lname,21);
}


void ghiFile(member &p){
    FILE *file = fopen("HVList1.bin", "ab");
    if (file != NULL) {
        fwrite(&p, sizeof(member), 1, file);
        fclose(file);
    } else {
        cout << "Khong mo duoc file !!!";
    }
}


void docFile(member p){
 FILE *file = fopen("HVList1.bin", "rb");
    if (file != NULL) {
        fread(&p, sizeof(member), 1, file);
        cout << p.id << " " << p.fname << " " << p.lname << endl;
        fclose(file);
    } else {
        cout << "Khong mo duoc file !!!";
    }
}

void ghiDanhSach(member a[], int &n){
    cout << "Nhap so luong member: ";
    cin >> n;
    cin.ignore(1); // Lo?i b? ký t? newline còn sót l?i trong b? d?m
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin member " << i << ": ";
        Nhapthongtin(a[i]);
        ghiFile(a[i]);
    }
}

void docDanhSach(member a[], int n){
    FILE *file = fopen("HVList1.bin", "rb");
    if (file != NULL) {
        for (int i = 0; i < n; i++) {
            fread(&a[i], sizeof(member), 1, file);
            cout << a[i].id << " " << a[i].fname << " " << a[i].lname << endl;
        }
        fclose(file);
    } else {
        cout << "Khong mo duoc file !!!";
    }
}
//bai 3
int countPowerXY(int X[], int Y[]){
	int n = sizeof(X)/sizeof(X[0]);
	int m = sizeof(Y)/sizeof(Y[0]);
	int count = 0;
	for(int i = 0; i<n;i++){
		for(int j = 0; j<m;j++){
			if(pow(X[i],Y[j])>pow(Y[j],X[i])){
				count++;
				cout << "{(" <<X[i] <<"," <<Y[j] <<")}" << " ";
			}
		}
	}
	return count;
}

//bai 4;
// insertion Sort


void insertionSort(int a[], int n){
	int  i, j, last;
	for(int i = 1; i< n;i++){
		last = a[i];
		j=i;
	while((j>0) && (a[j-1]>last)){
		a[j] = a[j-1];
		j= j-1;}
	a[j]= last;
	}	
}

int findClosestNumber(int a[],int n, int x){
	int left = 0;
	int right = n-1;
	
	if(x<=a[left]){
		return a[left];
	}
	if(x>=a[right]){
		return a[right];
	}
	
	while(left <= right){
		int mid = left + (right-left)/2;
		if(a[mid] == x){
			return a[mid];
		}else if(a[mid] <= x){
			left = mid +1;
		}else{
			right = mid -1;
		}
	}
	
	int closestN = (abs(x-a[left]) <= abs(x-a[right])) ? a[left] : a[right];
	return closestN;
}

//bai 5;

void substring(char s[], int pos, int slen){
	char ch;
	for(int  i = pos; i < pos+slen;i++){
		ch = s[i];
		cout << ch;
	}
}

bool stringcmp(char s1[], char s2[]){
	int i = 0;
	while(s1[i] != '\0' && s2[i] != '\0'){
		if(s1[i] != s2[i]){
			return false;
		}
		i++;
	}
	
	return s1[i] == '\0' && s2[i]=='\0';
}
int main(){
	// khai bao cac bien;
	int a[] = {1,2,6,4,5,3};
	int X[] = {10,19,18};
	int Y[] = {11,15,9};
	member m[10];
	int n = 6;
	member p;
	cout << "Menu lua chon" << endl;
	cout << "Bai 1" << endl;
	cout << "Bai 2" << endl;
	cout << "On tap"<< endl;
	cout << "Bai 3" << endl;
	cout << "Bai 4" << endl;
	cout << "Bai 5" << endl;
	cout << "Nhap lua chon cua ban ";
	int k;
	cin >> k;
	switch(k){
	case 1 :
		ghiMang(a,n);
		docMang();
		break;
	case 2 :
		//ghiFile(p);
		//docFile(p);	
		ghiDanhSach(m,n);
		docDanhSach(m,n);
		break;
	case 3 : 
		cout << "So luong dem duoc la: ";
		cout << countPowerXY(X,Y);
		break;
	case 4 :
		insertionSort(a,n);
		xuatMang(a,n);
		cout << endl;
		cout << findClosestNumber(a,n,2);
		break;
	case 5 :
		substring("Geeks",1,3);
		cout << endl;
		cout << stringcmp("C++","C+");
		break;
	default:
		cout << "Lua chon cua ban khong co chay lai chuong trinh";
	};
	return 0;
}
