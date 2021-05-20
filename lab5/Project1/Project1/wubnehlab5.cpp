//Name Helen Wubneh
//Course CSCI 3180
//Due Date 3/23/2021
//Lab lab5
// C++ program to demonstrate working of Guassian Elimination
// method
#include <iostream>
#include <fstream>
#include <string>
#define N 3
using namespace std;
//declaring a function prototype
void forwardElim(double mat[N][N], double b[N], ofstream& outFile);
void backSub(double mat[N][N],double b[N], ofstream& outFile);
void backSub2(double mat[N][N], double b[N], ofstream& outFile);
void forwardElim2(double mat[N][N], double b[N], ofstream& outFile);
// Driver program
int main()
{
    string line;
    ifstream myFile; //input file
    ofstream outFile; //output file
    myFile.open("input.dat");
    outFile.open("output.dat");
    double mat[N][N];//matrix a
    double b[N];//matrix b
    /* input matrix */
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            myFile >> mat[i][j];
            
        }
        myFile >> b[i];
    }
    //output
    outFile << "Original Augmented Matrix for System 1 " << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N ; j++)
        {
            outFile << mat[i][j]<<" ";
        }
        outFile << b[i];
        outFile<< endl;
    }
    
     
    forwardElim(mat,b, outFile);
    outFile.close();
    myFile.close();
    return 0;
}



// function to reduce matrix to r.e.f.  Returns a value to 
void forwardElim(double mat[N][N], double b[N], ofstream& outFile)
{
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            double f = mat[j][i] / mat[i][i];
            for (int k = 0; k < N + 1; k++)
            {
                mat[j][k] = mat[j][k] - f * mat[i][k];
            }
            b[j] = b[j] - f * b[i];
        }
    }
    outFile << "Upper triangular Augmented Matrix from N.G.E. " << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            outFile << mat[i][j]<<" ";
        }
        outFile << b[i];
        outFile << endl;
    }
    backSub(mat,b, outFile);
}

// function to calculate the values of the unknowns
void backSub(double mat[N][N],double b[N], ofstream& outFile)
{
    double x[N];  // An array to store solution
    
    /* Start calculating from last equation up to the
       first */
    x[N - 1] = b[N - 1] / mat[N - 1][N - 1];
    for (int i = N - 2; i >=0; i--)
    {
        
        double sum = 0;
        for (int j = i + 1; j < N; j++)
        {
            
            sum = sum + mat[i][j] * x[j];
        }

        /* divide the RHS by the coefficient of the
           unknown being calculated */
        x[i] = (b[i]-sum)/mat[i][i];
    }

    for (int i = 0; i < N; i++)
    {
        outFile <<"Solution from N.G.E x"<<i+1<<": "<< x[i];
        outFile << endl;
    }
}
void backSub2(double mat[N][N], double b[N], ofstream& outFile)
{
    double x[N];  // An array to store solution

    /* Start calculating from last equation up to the
       first */
    x[N - 1] = b[N - 1] / mat[N - 1][N - 1];
    for (int i = N - 2; i >= 0; i--)
    {

        double sum = 0;
        for (int j = i + 1; j < N; j++)
        {

            sum = sum + mat[i][j] * x[j];
        }

        /* divide the RHS by the coefficient of the
           unknown being calculated */
        x[i] = (b[i] - sum) / mat[i][i];
    }

    for (int i = 0; i < N; i++)
    {
        outFile << "Solution from G.E.P.P x" << i + 1 << ": " << x[i];
        outFile << endl;
    }
}
void forwardElim2(double mat[N][N], double b[N], ofstream& outFile)
{
    for (int i = 0; i < N - 1; i++)
    {
        
        for (int j = i + 1; j < N; j++)
        {
            
            double f = mat[j][i] / mat[i][i];
            for (int k = 0; k < N + 1; k++)
            {
                mat[j][k] = mat[j][k] - f * mat[i][k];
            }
            b[j] = b[j] - f * b[i];
        }
    }
    outFile << "Upper triangular Augmented Matrix from G.E.P.P. " << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            outFile << mat[i][j] << " ";
        }
        outFile << b[i];
        outFile << endl;
    }
    backSub2(mat, b, outFile);
}



