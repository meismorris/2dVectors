#include <iostream>
#include <vector>

using namespace std;


/**********************************************************
*
* Creates 2d matrices based on user input. They are
* also allowed to add or multiply it. 
*_________________________________________________________
* This code takes in a row and column integer value
* from the user input as the size of the matrix, as well as the values inside
*_________________________________________________________
* INPUT:
*   row: rows in matrix
*   column: columns in matrix
*   matrixFill(): filling in the contents of that matrix
* OUTPUT:
*   m3: placeholder for newer items in the matrix
***********************************************************/

// FUNCTION PROTOTYPES

/*****************************************************************************
 * displayMatrix
 * This function prints out every individual element inside the matrix
 *    
 *****************************************************************************/
/*****************************************************************************
 * matrixFill
 * currently fills in an empty vector passed in the arguments
 *****************************************************************************/
/*****************************************************************************
 * matrixAddition
 * Adds two matrices together, and stores new sum into a third vector
 *****************************************************************************/
/*****************************************************************************
 * createVectors
 * Creates a new matrix based on int r and c, size of their rows and columns
 * returns an temporary vector.
 *****************************************************************************/

/*****************************************************************************
 * matrixMultiplication
 * This function is responsible for multiplying vector A and B, and inputting it into
 * a vector C.
 *	no return
 *****************************************************************************/



//FUNCTION DEFINITIONS

/**********************************************************
*
* FUNCTION matrixFill
*_________________________________________________________
* This function receives an int type vector
*_________________________________________________________
* PRE-CONDITIONS
*   The following need previously defined values:
* v: empty vector v
*
* POST-CONDITIONS
*    This function soon loads the preexisting matrix v with 
* its own sets of values inside this function.
***********************************************************/

void matrixFill(vector<vector<int> >& v)
{
    int val;

    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[0].size(); j++) {
            cin >> val;
            v[i][j] = val;
        }
    }
}

/**********************************************************
*
* FUNCTION displayMatrix
*_________________________________________________________
* This function receives an int type vector much like the previous function
*_________________________________________________________
* PRE-CONDITIONS
*   The following need previously defined values:
*   v: empty vector v
*
* POST-CONDITIONS
*  This function displays all of the item inside the argument vector int v
***********************************************************/

void displayMatrix(const vector< vector<int> >& v)  //IN - a vector
{
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << " "; //displays item in matrix from each row and column
        }
        cout << endl;
    }
}


/**********************************************************
*
* FUNCTION matrixAddition
*_________________________________________________________
* This function receives 3 int type vectors, and uses it to add and 
* and pushes it into vector c.
*_________________________________________________________
* PRE-CONDITIONS
*   The following need previously defined values:
*   a: defined values in vector a
*   b: defined values in vector b
*   c: empty vector c
*
* POST-CONDITIONS
*  This function adds elements from a and b into vector c.
***********************************************************/

void matrixAddition(const vector <vector<int>> & a, const vector <vector<int>> & b,
vector <vector<int>> & c)
{
    {     

    c.resize(a.size());
    for (int r = 0; r < a.size(); r++) {
        for (int col = 0; col < a[r].size(); col++) {
            c[r].push_back(a[r][col] + b[r][col]); // pushes back sum of point in vector a and b
          }
        }
    }
}


/**********************************************************
*
* FUNCTION createVectors
*_________________________________________________________
* This function receives in r and c as a way to create a vector based on its size.
*_________________________________________________________
* PRE-CONDITIONS
*   The following need previously defined values:
*   r: defined int r
*   c: defined int c
*
* POST-CONDITIONS
*  This function returns a new tempVec based on the size of r and c.
***********************************************************/

vector< vector<int> > createVectors (int r,   // in - num of rows
                                     int c)// in - num of columns
 {
    vector< vector<int> > tempVec;
    tempVec.resize(r);

    for (int i = 0; i < r; i++) 
        tempVec[i].resize(c);
    
    return tempVec;
}

/**********************************************************
*
* FUNCTION matrixMultiplication
*_________________________________________________________
* This function receives in r and c as a way to create a vector based on its size.
*_________________________________________________________
* PRE-CONDITIONS
*   a: defined values in vector a
*   b: defined values in vector b
*   c: empty vector c
*
* POST-CONDITIONS
*  This function newly multiplied vector from vec a and b.
***********************************************************/

void matrixMultiplication(const vector< vector<int> >& a,   // in - first vector
                          const vector< vector<int> >& b,   // in - second vector
                          vector< vector<int> >& c) {       // out - third new vector
    int value = 0 ;
    vector <int> tempVec;

    for (int i = 0; i < a.size(); i++) {    //loops rows of a
        for (int j = 0; j < b.size(); j++) {    //loops rows of b
            for (int k = 0; k < b[0].size(); k++)  {    
                value+= (a[i][k] * b[k][j]);   // * values inside the vectors
            }
            tempVec.push_back(value);  
            value = 0;
        }
        c.push_back(tempVec);  //inputs element into temp vector
        tempVec.clear();
    }
}


int main() {
   
    int row;  
    int column; 
    vector <vector<int>> m3;  

  
    cout << "Enter the number of rows and columns of the matrices to add: ";
    cin >> row >> column;

  
    vector <vector<int>> m1 = createVectors(row,column);
    vector <vector<int>> m2 = createVectors(row,column);

  
    cout << "Enter matrix A: ";
    matrixFill(m1);
    cout << "For matrix A you entered: ";
    displayMatrix(m1);
    cout << "Enter matrix B: ";
    matrixFill(m2);
    cout << "For matrix B you entered: ";
    displayMatrix(m2);

   
    cout << "sum of A and B is: ";
    matrixAddition(m1, m2, m3);


    displayMatrix(m3);
    cout << endl << endl;


    m1.clear();
    m2.clear();
    m3.clear();

    cout << "Now for multiplication.\n";


    do {
        cout << "Enter the number of rows and columns of matrix A: ";
        cin >> row >> column;
        m1 = createVectors(row, column);

        cout << "Enter the number of rows and columns of matrix B: ";
        cin >> row >> column;

        m2 = createVectors(row, column);

       
        if (m1[0].size() != m2.size()) {
            cout << "The number of columns of matrix A must be the same as the number of rows of matrix B.\n";
        }
    } while (m1[0].size() != m2.size());

    
    cout << "Enter matrix A: ";
    matrixFill(m1);
    cout << "For matrix A you entered: ";
    displayMatrix(m1);

    cout << "Enter matrix B: ";
    matrixFill(m2);
    cout << "For matrix B you entered: ";
    displayMatrix(m2);


    cout << "product of A and B is: ";
    matrixMultiplication(m1, m2, m3);


    displayMatrix(m3);
    return 0;
}