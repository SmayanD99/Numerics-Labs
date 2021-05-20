/*Author Helen Wubneh
Course CSCI3180
Lab # lab 8
Due Date 4/15/2021*/

#include <iostream>
#include <iomanip>
using namespace std;
//This program impliments the Trapezoid rule,Richardson's extrapolation, and Simpson's rule
//a function that returns the first f(X)
double f1(double x)
{
	return  (1 / (x * x + 2));
}
//a function that returns  the second f(X)
double f2(double x)
{
	return  (1 / (x ));
}
//a function that returns the third f(x)
double f3(double x)
{
	return  pow(2,x);
}

//This function impliments trapezoid rule
double trapezoidRule(double lower,double upper,double h,double (*f )(double x))
{
	int i = 0;
	int n = (upper - lower) / h;
	//calculating the integration value
	double integration = 0.5 * h * (f(lower) + f(upper));
	for ( i = 1; i <=n-1; i++)
	{
		integration = integration + h * (f(lower + h * i));
		
	}
	return integration;
}
//This function impliments Richardson's rule
double richardsonsRule(double upper,double lower,double h,double An, double A2n)
{
	double integral;
	int n = (upper - lower) / h;
	//calculate integral using Richardson's method
	integral = ((4 * A2n) - An) / 3;
	for (int i = 1; i < n; i++)
	{
		integral = ((4 * A2n) - An) / 3;
    } 
	return integral;
}
//This function impliments simpson's rule
double simpsonsRule(double lower, double upper, double h, double (*f)(double x))
{
	int i = 0;
	int n = (upper - lower) / h;
	//calculating the integration value using simpsons rule
	double integration = f(upper)+f(lower);
	for (i = 1; i <= n-1 ; i++)
	{
		if (i % 2 == 0)
			integration += 2 * f(lower + h * i);
		else
			integration += 4 * f(lower + h * i);
	}
	integration = integration * (h / 3);
	
	return integration;
}
int main()
{
	double x = 0.0;
	double lowerLimit=0.0; //lower limit
	double upperlimit=0.0; //upper limit
	double exactValue=0.0;
	int n; //2^n subintervals
	int funChoice;
	cout << fixed << setprecision(15);
	//prompt the user for the input
	cout << "Functions: " << '\n' << " 1 - 1 / (x * x + 2)" << '\n' << " 2 - 1 / x" << '\n' << " 3 - 2^x" << endl;
	cout << "Select a function: ";
	cin >> funChoice;
	cout << "Lower limit of integration: ";
	cin >> lowerLimit;
	cout << "Upper limit of integration: ";
	cin >> upperlimit;
	cout << "Enter n, where 2^n is number of subintervals: ";
	cin >> n;
	cout << "Exact Value: ";
	cin >> exactValue;

	//output the result based on the user function choice
	cout << "i" << " " << "          T[i]" << " " <<"             Et[i]" <<endl;
	for (int i = 0; i <= n; i++)
	{
		double h = (upperlimit - lowerLimit) / pow(2, i);
		switch (funChoice)
		{
		case 1:
			//if user choose function 1 
			cout << i << "   " << trapezoidRule(lowerLimit, upperlimit, h, f1) << "   " << abs(exactValue- trapezoidRule(lowerLimit, upperlimit, h, f1))<< endl;
			break;
		case 2:
			 //if user choose function 2
			cout << i << "   " << trapezoidRule(lowerLimit, upperlimit, h, f2) << "   " << abs(exactValue - trapezoidRule(lowerLimit, upperlimit, h, f2)) << endl;
			break;
		case 3:
			//if user choose function 3
			cout << i << "   " << trapezoidRule(lowerLimit, upperlimit, h, f3) << "   " << abs(exactValue - trapezoidRule(lowerLimit, upperlimit, h, f3)) << endl;
			break;
		default:
			break;
		}
	}
	cout << endl;
	cout << "i" << " " << "          R[i]" << " " << "             Er[i]" << endl;
	for (int i = 0; i <n; i++)
	{
		double h1 = (upperlimit - lowerLimit) / pow(2, i);
		double h2 = (upperlimit - lowerLimit) / (pow(2, i+1));
		double An;
		double A2n;
		switch (funChoice)
		{
		case 1:
			//if user choose function 1
			 An = trapezoidRule(lowerLimit, upperlimit, h1, f1);
			 A2n = trapezoidRule(lowerLimit, upperlimit, h2, f1);
			cout << i+1 << "   " << richardsonsRule(upperlimit, lowerLimit,h1,An, A2n) << "   " << abs(exactValue - richardsonsRule(upperlimit, lowerLimit, h1, An, A2n)) << endl;
			break;
		case 2:
			//if user choose function 2
		    An = trapezoidRule(lowerLimit, upperlimit, h1, f2);
			A2n = trapezoidRule(lowerLimit, upperlimit, h2, f2);
			cout << i + 1 << "   " << richardsonsRule(upperlimit, lowerLimit, h1, An, A2n) << "   " << abs(exactValue - richardsonsRule(upperlimit, lowerLimit, h1, An, A2n)) << endl;
			break;
		case 3:
			//if user choose function 3
		    An = trapezoidRule(lowerLimit, upperlimit, h1, f3);
			A2n = trapezoidRule(lowerLimit, upperlimit, h2, f3);
			cout << i + 1 << "   " << richardsonsRule(upperlimit, lowerLimit, h1, An, A2n) << "   " << abs(exactValue - richardsonsRule(upperlimit, lowerLimit, h1, An, A2n)) << endl;
			break;
		default:
			break;
		}
	}
	cout << endl;
	cout << "i" << " " << "          S[i]" << " " << "             Es[i]" << endl;
	for (int i = 1; i <= n; i++)
	{
		double h = (upperlimit - lowerLimit) / pow(2, i);
		switch (funChoice)
		{
		case 1: 
			//if user choose function 1
			cout << i << "   " << simpsonsRule(lowerLimit, upperlimit, h, f1) << "   " << abs(exactValue - simpsonsRule(lowerLimit, upperlimit, h, f1)) << endl;

			break;
		case 2: 
			//if user choose function 2
			cout << i << "   " << simpsonsRule(lowerLimit, upperlimit, h, f2) << "   " << abs(exactValue - simpsonsRule(lowerLimit, upperlimit, h, f2)) << endl;
			break;
		case 3:
			//if user choose function 3
			cout << i << "   " << simpsonsRule(lowerLimit, upperlimit, h, f3) << "   " << abs(exactValue - simpsonsRule(lowerLimit, upperlimit, h, f3)) << endl;
			break;
		default:
			break;
		}
	}

	return 0;
}

