#include <iostream>
using namespace std;
// bai 1
void NhapMang(int a[], int &n){
	for(int i =0; i<n;i++){
		cout << "Nhap phan tu thu " << i << " :";
		cin >> a[i];
	}
}

void XuatMang(int a[], int n){
	for(int i =0; i<n;i++){
		cout << a[i] << " ";
	}
}

int findX(int a[], int n){
	int x;
	cout << "Nhap x can tim: "; cin >> x;
	for(int i=0; i<n;i++){
		if(a[i]==x){
			return i;
		}
	}
	return -1;
}

// bai 2
void themVaoMang(int a[], int &n, int x){
	if(n < 100){
		a[n] = x;
		n++;
	}else{
		cout <<"out of memory";
	}
}

void xoaPtMang(int a[], int &n, int x){
	for(int i =0; i<=n; i++){
		if(a[i]==x){
			for(;i<=n ;i++){
			a[i] = a[i+1];
		}
		}
	}
	n--;
}

void slitArray(int a[], int b[], int &n){
	int j=0;
	for(int i =0; i< n;i++){
		if(a[i]%2==0){
			b[j]= a[i];
			j++;
			xoaPtMang(a,n,a[i]);			
		}
	}
	XuatMang(b,j);
	cout << endl;
	XuatMang(a,n);
}

// bai 3

float AVG(int a[],int n){
	int sum =0;
	for(int i=0; i<n;i++){
		sum+= a[i];
	}
	return ((float)sum) / n;
}

int MAX(int a[],int n){
	int i =0;
	int max=a[i];
	for(i=1; i<n; i++){
		if(max < a[i]){
			max = a[i];
		}
	}
	return max;
}

int SecondMax(int a[], int n){
	int max= MAX(a,n);
	xoaPtMang(a,n,max);
	return MAX(a,n);
}

// bai 4

void checkX(int a[], int n){
	if(findX(a,n) != -1){
		cout << "Co ton tai";
	}
	else{
		cout << "Khong ton tai";
	}
}

int findClosestNumber(int s[], int n,int x){
	int left = 0;
	int right = n-1;
	
	if(x <= s[left]){
		return s[left];
	}
	if (x>= s[right]){
		return s[right];
	}
	
	while(left <=right){
		int mid = left + (right-left)/2;
		
		if(s[mid] ==x) {
			return x;
		}
		else if(s[mid]<x){
			left = mid +1;
		}
		else{
			right = mid -1;
		}
	}
	
	int closestNumber = (abs(x-s[left]) <= abs(x-s[right])) ? s[left] : s[right];
	return closestNumber;
}

// bai 5

string normalizeString(string &input){
	string result;
	bool isSpace = true;
	
	for(char ch : input){
		if(isspace(ch)){
			if(!isSpace){
				result += ' ';
				isSpace = true;
			}
		}else{
			if(isSpace){
				result += toupper(ch);
			}else{
				result += tolower(ch);
			}
			isSpace = false;
		}
	}
	
	if(!result.empty() && result[0]==' '){
		result.erase(0,1);
	}
	if(!result.empty() && result[result.length()-1]== ' '){
		result.erase(result.length()-1,1);
	}
	return result;
}

int main()
{
	int a[10];
	int b[10];
	int n = 5;
	//NhapMang(a,n);
	//themVaoMang(a,n,6);
	//xoaPtMang(a,n,3);
	//XuatMang(a,n);
	//slitArray(a,b,n);
	//cout << AVG(a,5);
	//cout << MAX(a,n) << endl; 
	//cout << SecondMax(a,n);
	//checkX(a,n);
	//cout << findClosestNumber(a,n,20);
	
	string input;
	cout << "Nhap ho va ten ";
	getline(cin, input);
	string normalizeS= normalizeString(input);
	cout << "Ho ten dc chuan hoa: "<< normalizeS << endl;
	return 0;
}
