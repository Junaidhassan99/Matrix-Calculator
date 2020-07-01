#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<iomanip>

using namespace std;

struct Matrix
{
	int rows_matrix, cols_matrix;
	char matrix_symbol;

};

const int general_order_of_matrices = 20;

void display_order(int r, int c,char s) {

	cout << endl;
	
	cout << " Order of matrix "<<s<<" = " << r << " * " << c;


}

char operation() {

	char operation_symobol;

	cout << " Select an option to continue:" << endl<<endl;
	cout << " + = SUM"<<endl;
	cout << " - = SUBTRACTION" << endl;
	cout << " * = PRODUCT" << endl;
	cout << endl;
	cout << " Operation = ";

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
	cout << " Press any key to continue...";
	_getch();
}

void cls() {
	system("CLS");
}

void get_order_of_matrix(Matrix &matrix_A,Matrix &matrix_B) {

	cout << " Order of Matrix:" << endl << endl;

	matrix_A.matrix_symbol = 'A';
	cout << " Matrix A:"<<endl;
	cout << " Rows = ";
	cin >> matrix_A.rows_matrix;
	cout << " Columns = ";
	cin >> matrix_A.cols_matrix;

	cout << endl;


	matrix_B.matrix_symbol = 'B';
	cout << " Matrix B:" << endl;
	cout << " Rows = ";
	cin >> matrix_B.rows_matrix;
	cout << " Columns = ";
	cin >> matrix_B.cols_matrix;

	


	press_to_continue();
	cls();
}

void get_Matrix(char operation) {

	Matrix A;
	Matrix B;
	bool invalid = false;


	get_order_of_matrix(A, B);

	cout << " Order of Matrix:" << endl << endl;

	display_order(A.rows_matrix, A.cols_matrix, A.matrix_symbol);
	display_order(B.rows_matrix, B.cols_matrix, B.matrix_symbol);


	float arr_A[general_order_of_matrices][general_order_of_matrices] = { 0 };
	float arr_B[general_order_of_matrices][general_order_of_matrices] = { 0 };


	cout << endl << endl;

	if (operation == '+' || operation == '-') {
		if (A.rows_matrix != B.rows_matrix && A.cols_matrix != B.cols_matrix) {
			invalid = true;
		}
	}
	else if (operation == '*') {
		if (A.cols_matrix != B.rows_matrix) {
			invalid = true;
		}
	}

	if (!invalid) {
		cout << " Elements of Matrix " << A.matrix_symbol << ": " << endl << endl;

		for (int i = 0; i < A.rows_matrix; i++) {
			for (int j = 0; j < A.cols_matrix; j++) {
				cout <<" "<< A.matrix_symbol << " [ Row = " << i + 1 << " ][ Col = " << j + 1 << " ] = ";
				cin >> arr_A[i][j];
			}
		}

		cout << endl;
		cout <<" "<< A.matrix_symbol << " = ";
		for (int i = 0; i < A.rows_matrix; i++) {
			cout << "| " << "\t";
			for (int j = 0; j < A.cols_matrix; j++) {
				cout << arr_A[i][j] << "\t";
			}

			cout << " |" << endl;
			cout << setw(7);
		}

		cout << endl << endl;


		cout << " Elements of Matrix " << B.matrix_symbol << ": " << endl << endl;

		for (int i = 0; i < B.rows_matrix; i++) {
			for (int j = 0; j < B.cols_matrix; j++) {
				cout <<" "<< B.matrix_symbol << " [ Row = " << i + 1 << " ][ Col = " << j + 1 << " ] = ";
				cin >> arr_B[i][j];
			}
		}

		cout << endl;
		cout <<" "<< B.matrix_symbol << " = ";
		for (int i = 0; i < B.rows_matrix; i++) {
			cout << "| " << "\t";
			for (int j = 0; j < B.cols_matrix; j++) {
				cout << arr_B[i][j] << "\t";

			}

			cout << " |" << endl;
			cout << setw(7);
		}
	}

	if (operation == '+'&&A.rows_matrix==B.rows_matrix&&A.cols_matrix==B.cols_matrix) {
		cout << endl << endl;
		float arr_sum[general_order_of_matrices][general_order_of_matrices] = { 0 };

		for (int i = 0; i < A.rows_matrix; i++) {
			for (int j = 0; j < A.cols_matrix; j++) {
				arr_sum[i][j]=arr_A[i][j] + arr_B[i][j];
			}
		}

		cout << " A+B = " << endl << endl;

		for (int i = 0; i < A.rows_matrix; i++) {
			cout << " | " << "\t";
			for (int j = 0; j < A.cols_matrix; j++) {
				cout << arr_sum[i][j] << "\t";
			}
			
			cout << " |" << endl ;

		}
	}
	else if (operation == '-' && A.rows_matrix == B.rows_matrix && A.cols_matrix == B.cols_matrix) {
		cout << endl << endl;
		float arr_sub[general_order_of_matrices][general_order_of_matrices] = { 0 };

		for (int i = 0; i < A.rows_matrix; i++) {
			for (int j = 0; j < A.cols_matrix; j++) {
				arr_sub[i][j] = arr_A[i][j] - arr_B[i][j];
			}
		}

		cout << " A-B = " << endl<<endl;

		for (int i = 0; i < A.rows_matrix; i++) {
			cout << " | " << "\t";
			for (int j = 0; j < A.cols_matrix; j++) {
				cout << arr_sub[i][j] << "\t";
			}
			
			cout << " |" << endl ;

		}
	}
	else if (operation == '*'&&A.cols_matrix==B.rows_matrix) {
		cout << endl << endl;
		float arr_pro[general_order_of_matrices][general_order_of_matrices] ;

		for (int r = 0; r < A.rows_matrix; r++) {
			for (int c = 0; c < B.cols_matrix; c++) {
				arr_pro[r][c]=0;
			}
		}

		for (int r = 0; r < A.rows_matrix; r++) {
			for (int c = 0; c < B.cols_matrix; c++) {
				for (int k = 0; k < A.cols_matrix; k++) {
					arr_pro[r][c] += arr_A[r][k] * arr_B[k][c];
				}
			}
		}

		cout << " A*B = " << endl << endl;

		for (int r = 0; r < A.rows_matrix; r++) {
			cout << " | " << "\t";
			for (int c = 0; c < B.cols_matrix; c++)
			{
				cout << arr_pro[r][c] << "\t";
			}
			cout << " |" << endl;
		}

		

	}
	else {
		cout << endl << "** Error: INVALID ORDER **";
	}

	


}




void sum() {
	get_Matrix('+');
}
void diff() {
	get_Matrix('-');
}
void pro() {
	get_Matrix('*');
}

void main() {

	char operation_symbol_main='\0';

	
	
	do {
		


		

		operation_symbol_main = operation();

		

		if (operation_symbol_main == '\0') {
			cout  << endl << " ERROR: *** INVALID SELECTION ***"<<endl;
		}
		
		cout << endl;

		cout << " You Selected:";
		switch (operation_symbol_main)
		{
		case '+':
		{
			 cout<<" SUM of MATRICES "<< endl;
			 press_to_continue();
			 cls();
			 sum();
			 break;
		}
		case '-':
		{
			cout << " DIFFERENCE of MATRICES " << endl;
			press_to_continue();
			cls();
			diff();
			break;
		}
		case '*':
		{
			cout << " PRODUCT of MATRICES " << endl;
			press_to_continue();
			cls();
			pro();
			break;
		}
		default:
		{
			cout << " INVALID OPERATOR " << endl;
			break;
		}
			
		}

		
		press_to_continue();

		if (operation_symbol_main == '\0') {
			cls();
		}
	} while (operation_symbol_main == '\0');

}

