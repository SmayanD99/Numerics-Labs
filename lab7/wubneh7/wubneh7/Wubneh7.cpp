/*AUTHOR Helen Wubneh
COURSE CSCI3180
LAB # LAB 6
DUE DATE 4/08/2021*/
#include <iostream>
#include <iomanip>
using namespace std;

//This program impliments the bisection method,newthon method and the secant method
//for approximating a root of a function.

//this functions takes a parameter x and returns a f(X) value.
double f(double x)
{
	return (x * x * x) - (2 * x * x) - (5 * x) + 6;
}
//this function takes x and returns the first derivative of f(X)
double fPrime(double x)
{
	return (3 * x * x) - (4 * x) - 5;
}

//this fuction impliments the bisetion method 
void bisectionMethod(double a,double b,int maxIteration,double xTo,double yTo)
{ 
	double x_tolerance = abs(a - b);
	double y_tolerance = abs(f(b) - 0);

	//if f(a)*f(b) less than 0 
	if(f(a) * f(b) < 0)
	{
		double c = (f(a) + f(b)) / 2;
		int i = 0;
		cout << fixed << setprecision(6);
		cout << "========================================" << endl;
		cout << "Interval : [" << a << ", " << b << "]" << endl;
		cout << "----------------" << endl;
		cout << "Bisection Method" << endl;
		cout << "-------------------------------------------------------" << endl;
		//if counter not equal to max iteration of x and y tolerance not 
		//equal to max tolerance keep looping
		while (i != maxIteration || (x_tolerance == xTo && y_tolerance == yTo))
		{
			if (f(c) == 0)
			{
				x_tolerance = abs(c-a);
				y_tolerance = abs(f(c) - 0);
				break;
			}
			else  if (f(a) * f(c) < 0)
			{
				// update the value of b
				b= c;
				x_tolerance = abs(a-b);
				y_tolerance = abs(f(c) - 0);
			}
			else
			{
				a = c;
				x_tolerance = abs(a - b);
				y_tolerance = abs(f(c) - 0);
			}
			// update number of iteration
			i++;
			
		}
		cout << "Iteration   Approx. root    x_tolerance    y_tolerance" << endl;
		cout << "        " << i + 1 << "    " << c << "       " << x_tolerance << "       " << y_tolerance << endl;
		cout << "        Exact root found at " << c << endl;
		cout << "        Number of Iterations: " << i + 1 << endl;
	}
	else
		{
			cout << "========================================"<<endl;
			cout << "Interval : [" << a << ", " << b << "]" << endl;
			cout << "----------------" << endl;
			cout << "Bisection Method" << endl;

			cout << "        found no root on the interval" << endl;
		}
	
}
//this function impliments newtins method
void newtonMethod(double a,double  b, double maxIteration,double  xTo, double yTo)
{
	double x_tolerance = abs(b - a);
	double y_tolerance = abs(f(b) - 0);
	double h = f(a) / fPrime(a);
	double x=a;
	int i = 0;
	cout << fixed << setprecision(6);
	cout << endl;
	cout << "----------------" << endl;
	cout << "Newton's Method" << endl;
	cout << "-------------------------------------------------------" << endl;
	cout << "Iteration   Approx. root    x_tolerance    y_tolerance" << endl;
	while (i != maxIteration || (x_tolerance <= xTo && y_tolerance <= yTo))
	{
		h = f(a) / fPrime(a);
		b = a - h;
		if (f(b) == 0)
		{
			x_tolerance = abs(b-x);
			y_tolerance = abs(f(b) - 0);
			break;
		}
		else
		{   
			x_tolerance = abs(b-a);
			y_tolerance = abs(f(b) - 0);
			// update the value of interval
			x = a;
			a = b;	
		}
		// update number of iteration
		i++;
		cout << "        " << i  << "    " << a << "       " << x_tolerance << "       " << y_tolerance << endl;
	}
	cout << "        Approximted root: " << a << endl;
	cout << "        Number of Iterations: " << i  << endl;
	cout << "        x_tolerance: " << x_tolerance << endl;
	cout << "        y_tolerance: " << y_tolerance << endl;
}
//this function impliments secant method 
void secantMethod(double a, double  b, double maxIteration, double  xTo, double yTo)
{
	double x_tolerance = abs(b - a);
	double y_tolerance = abs(f(b) - 0);
	int i = 0;
	double x;
	cout << fixed << setprecision(6);
	cout << endl;
	cout << "----------------" << endl;
	cout << "Secant Method" << endl;
	cout << "-------------------------------------------------------" << endl;
	cout << "Iteration   Approx. root    x_tolerance    y_tolerance" << endl;

	while (i < maxIteration && (x_tolerance >= xTo && y_tolerance >= yTo))
	{
		x = b - (f(b) * ((b - a) / (f(b) - f(a))));
		// check if x0 is root of equation or not
		if (f(x) == 0)
		{
			x_tolerance = abs(b-x);
			y_tolerance = abs(f(x) - 0);
			cout << "        " << i+1 << "    " << x << "       " << x_tolerance << "       " << y_tolerance << endl;
			cout << "        Exact root found at " << x <<endl;
		    cout << "        Number of iteration: " << i + 1 << endl;
			return;
		}
		else
		{
			x_tolerance = abs(x - b);
			y_tolerance = abs(f(x) - 0);
			// update the value of interval
			a = b;
			b = x;		
		}
		i++;
		cout << "        " << i  << "    " << x << "       " << x_tolerance << "       " << y_tolerance << endl;
	}
	cout << "        Approximted root: " << b << endl;
	cout << "        Number of Iterations: " << i  << endl;
	cout << "        x_tolerance: " << x_tolerance << endl;
	cout << "        y_tolerance: " << y_tolerance << endl;
}
int main() 
{
	
	const int maxIteration = 20; //maximum iteration
	double xTolerance = 0.001;  //max distance between the last 2 approzimations
	double yTolerance = 0.00001; //max distance from f(last approximation to 0)
	double a1=0;
	double b1=4;
	//implementing bisection,newton and secant method on thterval 1
	bisectionMethod(a1, b1, maxIteration, xTolerance, yTolerance);
	newtonMethod(a1, b1, maxIteration, xTolerance, yTolerance);
	secantMethod(a1, b1, maxIteration, xTolerance, yTolerance);

	double a2 = 0;
	double b2 = 2;
	//implementing bisection,newton and secant method on thterval 2
	bisectionMethod(a2,b2 , maxIteration, xTolerance, yTolerance);
	newtonMethod(a2, b2, maxIteration, xTolerance, yTolerance);
	secantMethod(a2, b2, maxIteration, xTolerance, yTolerance);

	double a3 = 2;
	double b3 = 4;
	//implementing bisection,newton and secant method on thterval 3
	bisectionMethod(a3, b3, maxIteration, xTolerance, yTolerance);
	newtonMethod(a3, b3, maxIteration, xTolerance, yTolerance);
	secantMethod(a3, b3, maxIteration, xTolerance, yTolerance);

	double a4 = 0;
	double b4 = 3;
	//implementing bisection,newton and secant method on thterval 4
	bisectionMethod(a4, b4, maxIteration, xTolerance, yTolerance);
	newtonMethod(a4, b4, maxIteration, xTolerance, yTolerance);
	secantMethod(a4, b4, maxIteration, xTolerance, yTolerance);

	double a5 = 1;
	double b5 = 2;
	//implementing bisection,newton and secant method on thterval 5
	bisectionMethod(a5, b5, maxIteration, xTolerance, yTolerance);
	newtonMethod(a5, b5, maxIteration, xTolerance, yTolerance);
	secantMethod(a5, b5, maxIteration, xTolerance, yTolerance);

	double a6 = 2;
	double b6 = 30;
	//implementing bisection,newton and secant method on thterval 6
	bisectionMethod(a6, b6, maxIteration, xTolerance, yTolerance);
	newtonMethod(a6, b6, maxIteration, xTolerance, yTolerance);
	secantMethod(a6, b6, maxIteration, xTolerance, yTolerance);

	double a7 = 10;
	double b7 = 30;
	//implementing bisection,newton and secant method on thterval 7
	bisectionMethod(a7, b7, maxIteration, xTolerance, yTolerance);
	newtonMethod(a7, b7, maxIteration, xTolerance, yTolerance);
	secantMethod(a7, b7, maxIteration, xTolerance, yTolerance);

	return 0;
}