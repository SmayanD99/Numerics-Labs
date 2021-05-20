/*Author Helen Wubneh
Course CSCI-3180
DUE DATE 2/2/2021
*/
#include <iostream>
using namespace std;
//This program implements Horner’s Algorithm for evaluating a polynomial 
double horner(double a[], int n, double x);
int main()
{
    double coffiecient[20] = { 0.0 }; //declare an array to hold the cofficients
    int degree;    //declare degree of the polynomial 
    double x;

    //prompt the user to enter the degree of polynomial
    cout << "Enter the degree of your polynomial: ";
    cin >> degree;
    int count = degree;

    //input the cofficients
    for (int i = 0; i <degree; i++)
    {
        cout << "Coefficient of x^" << count << "?";
        cin >> coffiecient[i]; 
        count--;
    }
    
    int size = 0;
    size = degree + 1;

     cout << "Constant term?";
     cin >> coffiecient[degree];

     //prompt the user x to calculate the value p(x) or 1000 to quit
     do
     {   
         cout << "Enter x at which to evaluate or 1000 to quit: ";
         cin >> x;
         if (x == 1000)
         {
             exit(0);
         }
        //output the value of p(x)
         cout << "p("<<x<<") = "<< horner(coffiecient, size, x) <<endl;
     } while (x != 1000);
   
  
}
//a method horner that evaluates P(n)
//returns double value and takes three parameters
double horner(double a[], int n, double x)
{
    
    double answer = a[0];
    //calculate the value of p(x)
    for (int i = 1; i<n; i++)
    {
        answer = answer * x + a[i]; 
    }
    return answer;
}