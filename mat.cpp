#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

//--------------------------------------
// Matrix Processor
// Name: Konrad Kucharek
//--------------------------------------

// the following can be changed and the rest of the code should work
int const R = 3;  // number of rows
int const C = 4;  // number of columns
int const VM = 3; // table entry (vector) length
int const CONVERT = 97;

vector<char>  T[R][C]; // 3 rows and 4 columns table for now 

// ------------------ Functions --------------------------------

int convert(char x)
{
	return (int(x)-CONVERT); // Returns ASCII value of the char being passed minus the ASCII value of 'a' in order to obtain the column # and the corresponding letter value
} 

int readTable()
{  
	int row, col;  // row and col numbers
	char col_c;     // column indicator
	ifstream fin ("lines.txt", ios::in);
 
  // Read in the file into T
   	while (fin >> row) // next line of file
     	{
	       	fin >> col_c; // takes the character from the file and stores it
       		col = convert(col_c);  // converts the character just taken in from the file and converts it, storing that value into another int variable 
       		vector<char> v;  // initialize the vector to be filled
       		char c; // single char from the file

       		for(int i=0;i<VM;i++)
		{
			fin >> c; // Takes in the next character in the .txt file and stores it into a temp char slot to be put in vector v
			v.push_back(c);
		}
        	T[row][col] = v; // Puts the current characters in vector v into their corresponding locations in the matrix
     	}// end of while
}

// Displays a vector or "---" if the vector is empty
void showVector(vector<char> v)
{ 
	if (v.size() == 0)  // empty entry
	for(int i=1;i<=VM;i++) 
	cout << "- ";
	else
	{
		char c; // Temporary character variable. Holds the front char in vector v
        	for(int i=0;i<VM;i++) // Loop for displaying all characters in the vector
		{
			cout << v[i] << ' '; // Display the character most recently popped from the vector v
		}
    	}
}

// Displays T as a table, separating entries with "|" 
void displayTable()
{
	int row=0; // Counter for row displaying
	for(int I=0;I<3;I++) // Loop #1 handles displaying the rows
	{
		cout << row << "| ";
		int col=0; // Counter for column displaying
		for(int i=0;i<4;i++) // Loop #2 handles displaying each column
		{
			showVector(T[row][col]); // Calls the function to display the vector at location [row][col]
			cout << "| ";
			col++; // Increment column counter by 1
		}
      		cout << endl;
      		row++; // Increment row counter by 1
    	}
}

// Driver
int main()
{
	cout << "Reading table from lines.txt ..." << endl; // display message to notify that program has started
	readTable(); // runs the readTable function
	displayTable();  // runs the displayTable function
} // the end
