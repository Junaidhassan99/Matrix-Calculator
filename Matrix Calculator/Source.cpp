#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<iomanip>

using namespace std;


//Matrix structure which defines rows, columns and symbol of a matrix
struct Matrix
{
	int rows_matrix, cols_matrix;
	char matrix_symbol;

};

//maximum size of a matrix
const int general_order_of_matrices = 20;


//display order of a given matrix
void display_order(Matrix m) {

	cout << endl;
	
	cout << " Order of matrix "<<m.matrix_symbol<<" = " << m.rows_matrix << " * " << m.cols_matrix;


}

//gets an operation to perform fro the user and return the symbol of that operation
char operation() {

	char operation_symobol;

	cout << " Select an option to continue:" << endl<<endl;
	cout << " + = SUM"<<endl;
	cout << " - = SUBTRACTION" << endl;
	cout << " * = PRODUCT" << endl;
	cout << " L = Solve Linear Equations" << endl;
	cout << endl;
	cout << " Operation = ";

	cin >> operation_symobol;

	if (operation_symobol == '+' || operation_symobol == '*' || operation_symobol == '-'
		|| operation_symobol =='l'||operation_symobol=='L') {
		return operation_symobol;
	}
	else {
		return '\0';
	}


	

}

//displays Press any key to continue...
void press_to_continue() {
	cout << endl;
	cout << " Press any key to continue...";
	_getch();
}

//clear screen
void cls() {
	system("CLS");
}

//get order of 2 matrices i.e. A and B from the user and returns that using reference operators
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


//prints the output matrix of sum,pro and diff.
//Note: for sum and diff put m=n
void display_result(float result[general_order_of_matrices][general_order_of_matrices],Matrix m,Matrix n,char op) {

	//cout << endl;

	

	cout << "\tA"<<op<<"B = ";
	

	

		for (int i = 0; i < m.rows_matrix; i++) {
			if (i == 0) {
				cout << "  ";
			}
			else {
				cout << " " ;
			}
			for (int j = 0; j < n.cols_matrix; j++) {
				cout << result[i][j] << "\t";
			}

			cout << " " << endl;
			cout << "\t\t";

		}
	
	
}

void display_matrix(Matrix m,float arr[general_order_of_matrices][general_order_of_matrices]) {

	//display all elements of matrix B
	cout << endl;
	cout << "\t" << m.matrix_symbol << " = ";
	for (int i = 0; i < m.rows_matrix; i++) {
		cout << " \t" ;
		for (int j = 0; j < m.cols_matrix; j++) {
			cout << arr[i][j];

			//to make a proper form of matrix
			if (j != m.cols_matrix - 1) {
				cout << "\t";
			}

		}

		cout << "  " << endl;
		cout << setw(7)<<"\t";
	}
}

//Two matix calculator which gets two matrices from the user, 
//perform the given operation +,- or * on them and display the results
void get_Matrix(char operation) {

	//defined insatance of matrix A and B
	Matrix A;
	Matrix B;
	//invalid is false when the given order is correct according to given operation
	//otherwise it is true
	bool invalid = false;

	//arrays of matix A and B for storing their elements in 2-D array
	float arr_A[general_order_of_matrices][general_order_of_matrices] = { 0 };
	float arr_B[general_order_of_matrices][general_order_of_matrices] = { 0 };


	do {
		cls();
		invalid = false;

		//get order of both matrices from the user
		get_order_of_matrix(A, B);

		//display the order obtained
		cout << " Order of Matrix:" << endl << endl;

		display_order(A);
		display_order(B);

		


		cout << endl << endl;

		//checking validity of matrix using its order
		if (operation == '+' || operation == '-') {
			if (A.rows_matrix != B.rows_matrix || A.cols_matrix != B.cols_matrix) {
				invalid = true;
			}
		}
		else if (operation == '*') {
			if (A.cols_matrix != B.rows_matrix) {
				invalid = true;
			}
		}

		//Runs for an invalid order or invalid operation
		if (invalid) {
			
			cout << endl << " ** Error: INVALID ORDER **"<<endl;
			press_to_continue();
			
		}

	} while (invalid);
	

	//runs for a valid order
	if (!invalid) {
		cout << " Elements of Matrix " << A.matrix_symbol << ": " << endl << endl;

		//get all elements of matrix A
		for (int i = 0; i < A.rows_matrix; i++) {
			for (int j = 0; j < A.cols_matrix; j++) {
				cout <<" "<< A.matrix_symbol << " [ Row = " << i + 1 << " ][ Col = " << j + 1 << " ] = ";
				cin >> arr_A[i][j];
			}
		}

		//display all elements of matrix A
		display_matrix(A, arr_A);

		cout << endl << endl;


		cout << " Elements of Matrix " << B.matrix_symbol << ": " << endl << endl;

		//get all elements of matrix B
		for (int i = 0; i < B.rows_matrix; i++) {
			for (int j = 0; j < B.cols_matrix; j++) {
				cout <<" "<< B.matrix_symbol << " [ Row = " << i + 1 << " ][ Col = " << j + 1 << " ] = ";
				cin >> arr_B[i][j];

			}
		}

		//display all elements of matrix A
		display_matrix(B, arr_B);

		
	}

	//do addition of A and B matrix and display the result 
	//also checks validation of matrices according to given order
	if (operation == '+'&&A.rows_matrix==B.rows_matrix&&A.cols_matrix==B.cols_matrix) {
		cout << endl << endl;
		float arr_sum[general_order_of_matrices][general_order_of_matrices] = { 0 };

		for (int i = 0; i < A.rows_matrix; i++) {
			for (int j = 0; j < A.cols_matrix; j++) {
				arr_sum[i][j]=arr_A[i][j] + arr_B[i][j];
			}
		}

		display_result(arr_sum, A, A, operation);

		
	}
	//do subtraction of A and B matrix and display the result 
	//also checks validation of matrices according to given order
	else if (operation == '-' && A.rows_matrix == B.rows_matrix && A.cols_matrix == B.cols_matrix) {
		cout << endl << endl;
		float arr_sub[general_order_of_matrices][general_order_of_matrices] = { 0 };

		for (int i = 0; i < A.rows_matrix; i++) {
			for (int j = 0; j < A.cols_matrix; j++) {
				arr_sub[i][j] = arr_A[i][j] - arr_B[i][j];
			}
		}

		display_result(arr_sub, A, A, operation);
	}
	//do product of A and B matrix and display the result 
	//also checks validation of matrices according to given order
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

		display_result(arr_pro, A, B, operation);

		

	}
	//Runs for an invalid order or invalid operation
	else {
		cout << endl  <<"** Error: INVALID ORDER **";
	}

	


}

void solve_linear_eqs() {
	
		int a, b, c, n;

		Matrix L;
		
		


		bool validation;
		do {
			validation = true;
			cout << "\n Number of equations = ";
			cin >> n;

			if (n < 1) {
				cout << endl << " ** NEGATIVE NUMBERS OR ZERO NOT ALLOWED **"<<endl;
				validation = false;
				
				press_to_continue();
				cls();
			}
		} while (!validation);

		L.matrix_symbol = 'L';
		L.cols_matrix = n+1;
		L.rows_matrix = n;


		float matrix[general_order_of_matrices-1][general_order_of_matrices ];
		float display_augmented[general_order_of_matrices - 1][general_order_of_matrices];
		float resolve[general_order_of_matrices];

		//get the matrix
		cout << "\n Enter the elements of the augmented matrix: ";
		cout << endl << endl;
		for (a = 0; a < n; a++)
		{
			for (b = 0; b < n + 1; b++)
			{
				cout << " Element [ Row = " << a + 1 << " ][ Col = " << b + 1 << " ] = ";
				cin >> matrix[a][b];
				display_augmented[a][b] = matrix[a][b];
			}
			cout << endl;
		}
		

		for (a = 0; a < n; a++)
		{
			for (b = a + 1; b < n; b++)
			{
				if (abs(matrix[a][a]) < abs(matrix[b][a]))
				{
					for (c = 0; c < n + 1; c++)
					{
						//swap matrix
						matrix[a][c] = matrix[a][c] + matrix[b][c];
						matrix[b][c] = matrix[a][c] - matrix[b][c];
						matrix[a][c] = matrix[a][c] - matrix[b][c];
					}
				}
			}
		}

		//Guass elimination
		for (a = 0; a < n - 1; a++)
		{
			for (b = a + 1; b < n; b++)
			{
				float f = matrix[b][a] / matrix[a][a];
				for (c = 0; c < n + 1; c++)
				{
					matrix[b][c] = matrix[b][c] - f * matrix[a][c];
				}
			}
		}

		//Backword substitution
		for (a = n - 1; a >= 0; a--)
		{
			resolve[a] = matrix[a][n];

			for (b = a + 1; b < n; b++)
			{
				if (a != b)
				{
					resolve[a] = resolve[a] - matrix[a][b] * resolve[b];
				}
			}
			resolve[a] = resolve[a] / matrix[a][a];
		}

		cout <<endl <<" Augmented Matrix: "<<endl<<endl;
		display_matrix(L, display_augmented);


		//show resultant vector
		cout << endl << endl << " Resultant Vector:" << endl << endl;
		cout << "\tV = ";
		for (a = 0; a < n; a++)
		{
			cout << "\t" << resolve[a] << endl<<"\t";
		}
	

	
}



//Methods that activate sum,difference and pro of matrices
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

	char start_over;
	

	do {
		cls();

		char operation_symbol_main = '\0';



		do {




			//get operation from the user
			operation_symbol_main = operation();


			//check validity of given operation
			if (operation_symbol_main == '\0') {
				cout << endl << " ERROR: *** INVALID SELECTION ***" << endl;
			}

			cout << endl;

			//display the selected operation and do the work
			cout << " You Selected:";
			switch (operation_symbol_main)
			{
			case '+':
			{
				cout << " SUM of MATRICES " << endl;
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
			case 'l':
			case 'L':
			{
				cout << " Solve LINEAR EQUATIONS using augmented matrix" << endl;
				press_to_continue();
				cls();
				solve_linear_eqs();
				break;
			}
			default:
			{
				cout << " INVALID OPERATOR " << endl;
				break;
			}

			}


			cout << endl;
			press_to_continue();

			//check validation of operation to run the loop again or not 
			if (operation_symbol_main == '\0') {
				cls();
			}
		} while (operation_symbol_main == '\0');

		bool loop = false;
		do {
			
			cls();
			loop = false;
			cout << endl << " Start Over ? [y/n] = ";
			cin >> start_over;

			

			if (start_over != 'y' && start_over != 'Y' && start_over != 'n' && start_over != 'N') {
				loop = true;
				cout << endl << endl << " ** INVALID ENTRY **";
				cout << endl;
				press_to_continue();

			}
		} while (loop);

		
	} while (start_over=='y' || start_over=='Y');

}

