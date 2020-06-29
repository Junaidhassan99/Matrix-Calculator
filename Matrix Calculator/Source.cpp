#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

struct Matrix
{
	int rows_matrix, cols_matrix;
	char matrix_symbol;
};

void display_order(int r, int c,char s) {

	cout << endl;
	
	cout << "Order of matrix "<<s<<" = " << r << " * " << c;


}

char operation() {

	char operation_symobol;

	cout << "Select an operation to continue:" << endl;
	cout << "+ = SUM"<<endl;
	cout << "- = SUBTRACTION" << endl;
	cout << "* = PRODUCT" << endl;
	cout << endl;
	cout << "Operation = ";

	cin >> operation_symobol;

	if (operation_symobol == '+' || operation_symobol == '*' || operation_symobol == '-') {
		return operation_symobol;
	}
	else {
		return '\0';
	}


	

}

void press_to_continue() {
	cout << endl;
	cout << "Press any key to continue...";
	_getch();
}

void cls() {
	system("CLS");
}

void main() {

	char operation_symbol_main='\0';

	Matrix matrix_A;
	matrix_A.matrix_symbol = 'A';
	cout << "Matrix A:"<<endl;
	cout << "Rows = ";
	cin >> matrix_A.rows_matrix;
	cout << "Columns = ";
	cin >> matrix_A.cols_matrix;

	cout << endl;

	Matrix matrix_B;
	matrix_B.matrix_symbol = 'B';
	cout << "Matrix B:" << endl;
	cout << "Rows = ";
	cin >> matrix_B.rows_matrix;
	cout << "Columns = ";
	cin >> matrix_B.cols_matrix;

	cout << endl;
	
	
	press_to_continue();
	cls();
	
	do {
		display_order(matrix_A.rows_matrix, matrix_A.cols_matrix, matrix_A.matrix_symbol);
		display_order(matrix_B.rows_matrix, matrix_B.cols_matrix, matrix_B.matrix_symbol);


		cout << endl;
		cout << endl;

		operation_symbol_main = operation();

		

		if (operation_symbol_main == '\0') {
			cout  << endl << "ERROR: ***INVALID SELECTION***"<<endl;
		}
		
		cout << "You Selected:";
		switch (operation_symbol_main)
		{
		case '+':
		{
			 cout<<" Sum of MATRICES " ;
			break;
		}
		case '-':
		{
			cout << " Difference of MATRICES ";
			break;
		}
		case '*':
		{
			cout << " Product of MATRICES ";
			break;
		}
		default:
		{
			cout << " INVALID OPERATOR ";
			break;
		}
			
		}

		cout << endl;
		press_to_continue();

		if (operation_symbol_main == '\0') {
			cls();
		}
	} while (operation_symbol_main == '\0');

}

