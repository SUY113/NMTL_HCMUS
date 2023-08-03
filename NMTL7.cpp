#include<iostream>
using namespace std;
// bai 1;

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

int findXPosittion(int s[], int n){
	int x;
	int j =0;
	int b[10];
	cout << "Nhap x can tim: "; cin >> x;
	for(int i=0; i<n;i++){
		if(s[i]==x){
			 b[j] = i;
			 j++;
		}
	}
	if(j != 0){
		XuatMang(b,j);
	}else{
		cout << -1;
	}
}

int closestNumber(int s[], int n, int x){
	int left = 0;
	int right = n - 1 ;
	
	if(x < s[left]){
		return s[left];
	}
	if(x > s[right]){
		return s[right];
	}
	
	while(left <= right){
		int mid = left + (right - left) /2;
		
		if(s[mid]== x){
			return mid;
		}
		else if(s[mid] < x){
			left = mid +1;
		}
		else{
			right = mid -1;
		}
	}	
	int closestN = abs(x-s[left]) <= abs(x-s[right]) ? left : right ;
	return closestN; 	
}

// bai 2;

string normalizeString(string &input){
	string result;
	bool isSpace = true;
	for(char ch : input){
		if(isspace(ch)){
			if(!isSpace){
				result+= " ";
				isSpace = true;
			}
		}else{
			if(isSpace){
				result += toupper(ch);
			}
			else{
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


void nhapTen(){
	string input;
	cout << "Nhap ten vao: ";
	getline(cin,input);
	string normalS = normalizeString(input);
	cout << normalS;
}


// bai 3;
void inputMatrix(int &n, int &m, int a[][100]){
	for(int i =0 ;i <n;i++){
  		for(int j =0; j < m ;j++){
  			cout << "Nhap phan tu thu [" << i <<"][" << j << "]: ";
			cin >> a[i][j]; 
		  }
	  }
}

void outputMaxtrix(int n, int m, int a[][100]){
	for(int i = 0; i< n; i++){
		for(int j = 0; j < m ; j++){
			cout << a[i][j] << " ";
		}
		cout << endl;	
	}
}

int sumBorder(int n, int m, int a[][100]){
	int sum = 0;
	
	for(int j = 0; j < m; j++){
		sum += a[0][j];
		sum += a[n-1][j];
	}
	
	for(int i = 1; i < n -1 ;i ++){
		sum += a[i][0];
		sum += a[i][m-1];
	}
	
	return sum;
}

int sumRowIndex(int n, int m, int a[][100], int k){
	int sum = 0;
	for(int j = 0 ; j < m ; j ++){
		sum += a[k][j];
	}
	return sum;
}

int indexOfMaxSumRow(int n, int m, int a[][100]){
	int max = sumRowIndex(n,m,a,0);
	int index = 0;
	for(int i = 1; i < n;i++){
		if(max < sumRowIndex(n,m,a,i)){
			index = i;
		};
	}
	return index;
}



int isSaddlePoint(int n, int m, int a[][100], int row, int col){
	int value = a[row][col];
	
	bool row_max = true;
	bool col_min = true;
	
	for(int j = 0 ; j < m ;j++){
		if(a[row][j] > value){
			row_max = false;
			break;
		}
	}
	
	for(int i =0 ; i < n; i++){
		if(a[i][col] <value){
			col_min = false;
			break;
		}
	}
	
	return (row_max && col_min);
}

void findSaddlePoint(int n, int m , int a[][100]){
	bool found = false;
	
	for(int i = 0 ; i < n;i++){
		for(int j = 0 ; j <m ; j++){
			if(isSaddlePoint(n,m,a,i,j)){
				cout << "Gia tri yen ngua la: " << a[i][j] <<endl;
				found = true;
			}
		}
	}
	
	if(!found){
		cout << "Khong tim thay ";
	}
}


// bai 4 ;

void sumMatrix(int rA, int cA, int a[][100],int rB, int cB ,int b[][100]){
	if(rA!=rB && cA != cB){
		cout << "Khong hop le";
	}else{
		int sum[100][100];
		for(int i = 0 ; i < rA; i++){
			for(int j = 0; j < cA; j++){
				sum[i][j]=a[i][j]+b[i][j];
			}
		}
			outputMaxtrix(rA,cA,sum);
	}

}

int main(){
	int a[10][100];
	int b[10][100];
	int n = 2;
	int m = 2;
	//NhapMang(a,n);
	//XuatMang(a,n);
	//cout << endl;
	//findXPosittion(a,n);
	//cout << closestNumber(a,n,20);
	//nhapTen();
	inputMatrix(n,m,b);
	outputMaxtrix(n,m,b);
	cout << endl;
	inputMatrix(n,m,b);
	outputMaxtrix(n,m,b);
	sumMatrix(n,m,a,n,m,b);
	//cout <<sumBorder(n,m,b);
	//cout << indexOfMaxSumRow(n,m,b);
	//findSaddlePoint(n,m,b);
	return 0;
}
