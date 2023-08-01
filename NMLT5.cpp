#include <iostream>
#include <cmath>
using namespace std;

void NhapPs(int &a, int &b){
	cout << "Nhap tu so vao: ";  cin >>a;
	cout << "Nhap mau so vao: "; cin >>b;
}

void xuatPs(int a, int b){
	cout << a << " / " << b; 
}


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
			int u = gcd(tuso3, mauso3);
			if(u){
				tuso3 = tuso3 / u;
				mauso3 = mauso3 /u;
			}
	}
	xuatPs(tuso3, mauso3);
}

long long countFact(int N){
	long long result=1;
	if( N < 0){
		return 0;
	}else if( N == 0){
		return 1;
	}else{
		for( int i = 1 ; i <= N ; i++)
		result *=i;
	}
	return result;
}

void NhapMang(int a[], int &n){
	cout << "Nhap so luong phan tu cua mang : " ; cin >> n;
	for(int i = 0; i< n; i++){
		cout << "Nhap phan tu thu " << i << " : " ; cin >> a[i];
	}
}

void XuatMang(int a[], int n){
	cout << "Cac phan tu trong mang la : ";
	for(int i =0 ; i <n; i++){
		cout << a[i] << " ";
	}
	cout << endl;
}

int findIdByX(int a[],int x){
	int p;
	for(int i =0; i <sizeof(a);i++){
		if(a[i]==x){
			p = i;
		}
	}
	return p;
}


bool isHappyNumber(int number){
	int digitCount = floor(log10(number))+1;
	int sum1, sum2 = 0;
	int temp = number;
	
	for(int i = 0; i < digitCount/2 ; i++){
		int digit1 = temp % 10;
		sum1 += digit1;
		temp /= 10;
	}
	for(int i = 0; i < digitCount/2 ; i++){
		int digit2 = temp % 10;
		sum2 += digit2;
		temp /= 10;
	}
	
	return sum1 == sum2;
}

float AVG(int a[], int n){
	int sum = 0;
	for(int i =0 ; i < n; i++){
		sum += a[i];
	}
	return (sum*1.0 / n );
}

int MAX(int a[], int n){
	int temp = 0;
	for(int i = 0; i< n;i++){
		if(temp <= a[i]){
			temp = a[i];
		}
	}
	return temp;
}

int MAX2(int a[], int n){
	int max1 = MAX(a,n);
	int max2=0;
	for(int i = 0 ; i < n ; i++){
		if(max2 < a[i] && a[i] != max1){
			max2 = a[i];
		}
	}
	return max2;
}

bool isXHere(int a[], int n, int x){
	for(int i = 0; i< n; i++){
		if(a[i]== x){
			return true;
		}
	}
	return false;
}


int findClosestNumber(int a[], int n, int x){
	int closest = a[0];
	int minDiff = abs(a[0]-x);
	
	for( int i = 0; i< n ; i++){
		int diff = abs(a[i]-x);
		if(diff < minDiff){
			minDiff = diff;
			closest = a[i];
		}
	}
	return closest;
}
int main(){
	//int a,b,c,d;
	//NhapPs(a,b);
	//NhapPs(c,d);
	//THPS(a,b,c,d);
	//cout << countFact(3); 
	int a[10], n;
	NhapMang(a,n);
	//XuatMang(a,n);
	//cout << "Vi tri cua x la " << findIdByX(a,2);
	//cout << isHappyNumber(1221);
	
	//cout << AVG(a,n)<< endl;
	//cout << MAX(a,n) << endl;
	//cout << MAX2(a,n);
	//cout <<isXHere(a,n, 5);
	cout << findClosestNumber(a,n,30);
	return 0;
}
