/*Author Helen Wubneh
Course CSCI-3180
DUE DATE 3/2/2021
*/
#include <iostream>
#include <iomanip>
using namespace std;
/*this program tests the three methods to
find numerical solutions to the ODE’s*/



/*this function returns the result of the ODE */
double f(double ti, double x)
{
	return ti - x;
}

/*this function returns the result of the ODE */

double f2(double ti, double x)
{
	return x / (1 + ti);
}
/*this function returns the result of the ODE */

double f3(double ti, double x)
{
	return ti + x;
}
/*this function returns the result of the ODE */

double f4(double ti, double x)
{
	return (ti - x) / (ti + x);
}
/*this function calculates the given ODE using Euler's Method*/
double * euler(double t0, double x,int N,double h,double abserr,
	             double analyticerror,double(*fun)(double,double))
{
	
	double k[100] = { 0.0 }; //an array to hold the calculated valus.
	double ti=t0;
	double relerr = 0.0;
	//calculate the ODE using Euler's algorithm
	for (int i = 0; i < N; )
	{

		k[i] = x + h * f(ti, x);
		x = k[i];
		i++;
		ti = t0 + (i * h);
		if (i < 10 || i == N)
		{
			cout << ti <<" "<< k[i - 1] << endl;
		}
	}
	//calculate the absolute error
	abserr = abs(analyticerror - k[N - 1]);
	//calculate the relative error
	relerr = abserr / analyticerror;
	//output and relative error
	
	cout << "Relative Error: " << fixed << setprecision(10) << relerr << "\n\n";
	return k;
}
/*this function calculates the given ODE using Heun's Method*/
double * huns(double t0, double x, int N, double h, double abserr,
	double analyticerror, double(*fun)(double, double))
{
	 double k[101] = { 0 }; //an array to hold k
	 double k2[101] = { 0 }; //an array to hold x(t+h)

	double ti = t0;
	//calculates the ODE using Heun's algorithm
	for (int i = 0; i < N; )
	{
		ti = t0 + i * h;
		k[i] = x + h * f(ti, x);
		k2[i] = x + h * (0.5) * (f(ti, x) + f(ti + h, k[i]));
		x = k2[i];
		i++;
		ti = t0 + i * h;	
		if (i < 10||i==N)
		{
			cout << ti << k2[i - 1] << endl;
		}

	}
	//calculate the absolute error
	abserr = abs(analyticerror - k2[N - 1]);
	//calculate the relative error
	double relerr = abserr / analyticerror;
	//output ti,x(t), and relative error
	
	cout << "Relative Error: " << fixed << setprecision(10) << relerr << "\n\n";
	return k;
}

/*this function calculates the given ODE using Runge-Kutta Method: */
double* rungeKutta(double t0, double x, int N, double h, double abserr,
	double analyticerror, double(*fun)(double, double))
{
	
	double k1;
	double k2;
	double k3;
	double k4;
	static double k5[10] = { 0.0 };//an array to hold x(t+h)
	double ti = t0;
	//calculates the ODE using Runge-Kutta's algorithm
	for (int i = 0; i <N;)
	{
		
		k1 = h * f(ti, x);
		k2 = h * f(ti + 0.5 * h, x + 0.5 * k1);
		k3 = h * f(ti + 0.5 * h, x + 0.5 * k2);
		k4 = h * f(ti + h, x + k3);
		k5[i] = x + 1 / 6.0 * (k1 + 2 * k2 + 2 * k3 + k4);
		x = k5[i];
		i++;
		ti = t0 + i * h;
		if (i < 10 || i == N)
		{
			cout << ti << k5[i - 1] << endl;
		}
		
	}
	//calculate the absolute error
	abserr = abs(analyticerror - k5[N - 1]);
	//calculate the relative error
	double relerr = abserr / analyticerror;
	cout << "Relative Error: " << fixed << setprecision(10) << relerr << "\n\n";
	return k5;
}

int main()
{
	
	double h = 0.0;
	double t0 = 0;
	double x = 0;
	double * k2;
	double* k3;
	double* k1;
	double tb = 0.0;
	double abserr = 0.0;
	double analyticerror = 0.0;
	double relativerr = 0.0;
	int choice = 0;
	int N = 0;

	//prompt the user for the input
	cout << "Which ODE would you like to use ?" << endl;
	cout << "1. x' = x / (1 + t)" << endl;
	cout << "2. x' = t + x" << endl;
	cout << "3. x' = t - x" << endl;
	cout << "4. x' = (t - x) / (t + x)" << endl;
	cout << "choice: ";
	cin >> choice;
	cout << "Enter the analytical solution:";
	cin >> analyticerror;
	cout << "Enter the lower bound of the interval(a) :";
	cin >> t0;
	cout << "Enter the upper bound of the interval (b):";
	cin >> tb;
	cout << "Enter the initial value:";
	cin >> x;
	cout << "Enter the number of sub intervals: ";
	cin >> N;
    //calculate h 
	h = (tb - t0) / double(N);

	switch(choice)
	{      
		    //if case one onvoke each method with f2
	case 1: cout << "Euler's Method:" << endl;
	        k2 = euler(t0, x, N, h, abserr, analyticerror,f2);
	        cout << "Heun's Method: " << endl;
	        k1 = huns(t0, x, N, h, abserr, analyticerror, f2);
	        cout << "Runge-Kutta Method: " << endl;
	        k3 = rungeKutta(t0, x, N, h, abserr, analyticerror, f2);
			break;
	case 2:
		    //if case one onvoke each method with f3
		    cout << "Euler's Method:" << endl;
		    k2 = euler(t0, x, N, h, abserr, analyticerror, f3);
		    cout << "Heun's Method: " << endl;
			k1 = huns(t0, x, N, h, abserr, analyticerror, f3);
			cout << "Runge-Kutta Method: " << endl;
			k3 = rungeKutta(t0, x, N, h, abserr, analyticerror, f3);
	case 3:
		    //if case one onvoke each method with f
			cout << "Euler's Method:" << "\n";
			k2 = euler(t0, x, N, h, abserr, analyticerror, f);
			cout << "Heun's Method: " << endl;
			k1 = huns(t0, x, N, h, abserr, analyticerror, f);
			cout << "Runge-Kutta Method: " << endl;
			k3 = rungeKutta(t0, x, N, h, abserr, analyticerror, f);
	case 4:
		    //if case one onvoke each method with f4
			cout << "Euler's Method:" << endl;
			k2 = euler(t0, x, N, h, abserr, analyticerror, f4);
			cout << "Heun's Method: " << endl;
			k1 = huns(t0, x, N, h, abserr, analyticerror, f4);
			cout << "Runge-Kutta Method: " << endl;
			k3 = rungeKutta(t0, x, N, h, abserr, analyticerror, f4);
	default:
			break;
	}

}
