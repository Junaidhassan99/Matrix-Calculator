#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

struct Matrix
{
	int rows_matrix, cols_matrix;
};

void main() {

	Matrix matrix_A;
	cout << "Matrix A:"<<endl;
	cout << "Rows = ";
	cin >> matrix_A.rows_matrix;
	cout << "Columns = ";
	cin >> matrix_A.cols_matrix;

	cout << endl;

	Matrix matrix_B;
	cout << "Matrix B:" << endl;
	cout << "Rows = ";
	cin >> matrix_B.rows_matrix;
	cout << "Columns = ";
	cin >> matrix_B.cols_matrix;

	cout << endl;

	_getch();
	system("CLS");

	cout << "Order of matrix A = " << matrix_A.rows_matrix << " * " << matrix_A.cols_matrix;
	cout << endl;
	cout << "Order of matrix B = " << matrix_B.rows_matrix << " * " << matrix_B.cols_matrix;


}