#include <iostream>
using namespace std;
double f(double x)
{
	return 1 / ((x*x)+ 1);
}
int main()
{
	double* b = new double[20];
	double* y = new double[20];
	double* h = new double[20];
	double* v = new double[20];
	double* u = new double[20];
	double t1[] = { -4,-2,0,2,4 };
	int len2 = sizeof(t1) / sizeof(t1[0]);
	for (int i = 0; i < len2; i++)
	{
		y[i] = f(t1[i]);	
		cout << y[i] << " ";
	}
	cout << "Data points (ti , yi)" << endl;
	for (int i = 0; i < len2; i++)
	{
		cout << "(" << "t" << i << ", y" << i << ") " << "= " << "(" << t1[i] << "," << y[i] << ")" << endl;
	}

	/*double t[] = { -8,-7,-6,-5,-4,-3,-2,-1,0,1,2,3,4,5,6,7,8 };
	int len = sizeof(t) / sizeof(t[0]);
	
	for (int i = 0; i < len; i++)
	{
		y[i] = f(t[i]);
		h[i] = t[i + 1] - t[i];
	}
	

	for (int i = 1; i < len; i++)
	{
		v[i] = 6 * ((y[i + 1] / h[i]) - y[i]) - ((y[i] - y[i - 1]) / h[i - 1]);
		u[i] = 2 * (h[i - 1] + h[i]);

	}
	cout << "TriDiagonal system for z1 throughz(n-1)" << endl;
	for (int i = 1; i < len; i++)
	{
		cout << u[i] << " " << h[i] << " " << v[i]<<endl;
	}
	*/
	return 0;
}