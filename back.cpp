#include <iostream>
using namespace std;
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iomanip>

//Shelly Huang
//Recursion and backtracking waas used!~

int excl = -1;
void Print(int** arr, int n){
	cout << endl;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << setw(3) << arr[i][j];
		}
		cout << endl;
	}
}
int** CreateGrid(int n){
	int** arr = new int*[n];		
	for(int i = 0; i < n; i++){
		arr[i] = new int[n];
	}
	for(int k = 0; k < n; k++){
		for(int m = 0; m < n; m++){
			arr[k][m] = 0;
		} 
	}
	return arr;
}
bool CanWe(int** arr, int x, int y, int n){
	for(int i = 0; i < x; i++){
		if(arr[x][y] == arr[i][y]) return false; 
	}
	for(int j = 0; j < y; j++){
		if(arr[x][y] == arr[x][j]) return false;
	}
	return true;
}
bool Iterate(int** arr, int &x, int &y, int n){
	for(x = 0; x < n; x++){
		for(y = 0; y < n; y++){
			if(arr[x][y] == 0) return true;
		}
	}
	return false;
}
bool Solve(int** arr, int n){	 
	int x, y;			
	srand(time(NULL));
	if(Iterate(arr, x, y, n) == false) return true;
	
	arr[x][y] = (rand()%n)+1;
	for(int k = 1; k <= n; k++){
		if(k == excl) continue;
		//check if original number is ok
		if(CanWe(arr, x, y, n)){
			if(Solve(arr, n)) return true;
		}
		arr[x][y] = k;
		//check if number iterated through array is ok
		if(CanWe(arr, x, y, n)){
			if(Solve(arr, n)) return true;
		}
	}
	//if all possible choices are exhausted 
	excl = arr[x][y];
	//label element as untouched, to start again
	arr[x][y] = 0;
	return false;
						
}
int main(){
	int n;
	cout << "Enter dimension";
	cin >> n;
	int** arr = CreateGrid(n);
	Solve(arr, n);
	Print(arr, n);
	
}
