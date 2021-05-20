/*Author Helen Wubneh
Course CSCI3180
Lab # 6
Due Date 4/1/2021*/
#include <iostream>
#include <iomanip>
using namespace std;
//The following progrM CALCULATES TRIDIAGONAL SYSTEM

//A function the calculates the y value
double f(double x)
{
	return 1 / ((x * x) + 1);
}
//A function that solve forward elimination
double* forwardElm2(double* d, double* l, double* u, double* b, int n)
{
	//declare a multiplier and calculate the l,d,and b values
	double m = 0;
	for (int i = 0; i < n; i++)
	{
		m = l[i + 1] / d[i];
		l[i] = l[i] - (d[i] * m);
		d[i + 1] = d[i + 1] - (u[i] * m);
		b[i + 1] = b[i + 1] - (b[i] * m);
	}
	
	//a loop that solve z using back substitution 
	double* z = new double[(int)n + 2]{ 0 };
	z[n] = b[n - 1] / d[n - 1];
	for (int i = n - 1; i > 0; i--)
	{
		z[i] = (b[i - 1] - z[i + 1] * u[i - 1]) / d[i - 1];
	}
	return z;
}
//forward elimination function to output tri-diagonal a return 2
double * forwardElm(double *d,double *l,double *u, double* b,int n)
{
	//declare values for z1-zn
	double* z1 = new double[10]{ 0 };
	double* z2 = new double[10]{ 0 };
	double* z3 = new double[10]{ 0 };
	double* z4 = new double[10]{ 0 };
	double* z5 = new double[10]{ 0 };
	double* z6 = new double[10]{ 0 };
	double* z7 = new double[10]{ 0 };
	//calculate forward elimination
	double m =0;
	for (int i = 0; i <n; i++)
	{
		m = l[i+1] / d[i];
		l[i] = l[i]-(d[i] * m);
		d[i+1] = d[i+1] - (u[i] * m);
		b[i+1] = b[i+1] - (b[i] * m);
	}
	z1[0] = d[0];
	z1[1] = l[0];
	z2[0] = u[0];
	z2[1] = d[1];
	z2[2] = l[1];
	z3[1] = u[1];
	z3[2] = d[2];
	z3[3] = l[2];
	z4[2] = u[2];
	z4[3] = d[3];
	z4[4] = l[3];
	z5[3] = u[3];
	z5[4] = d[4];
	z5[5] = l[4];
	z6[4] = u[4];
	z6[5] = d[5];
	z6[6] = l[5];
	z7[6] = u[6];
	z7[7] = d[6];
	//output tri-diagonal matrix after Forward Elimination
	cout << "Tri-diagonal system after Forward Elimination" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << z1[i] << " " << z2[i] << " " << z3[i] << " " << z4[i] << " " << z5[i] << " " << z6[i] << " " << z7[i] << " " << b[i] << endl;
	}
	//calculate backward substitution
	double* z = new double[int(n) + 2]{ 0 };
	z[n] = b[n-1] / d[n-1];
	for (int i =n-1; i>0; i--)
	{
		z[i] = (b[i-1] - z[i+1] * u[i-1]) / d[i-1];
	}
	cout << "Solutions for s''(ti)=zi" << endl;
	cout << "----------------------------------------------------" << endl;
	for (int i = 0; i < n+2; i++)
	{
		cout << "z" << i << ":" << z[i] << endl;
	}
	return z;
}

int main()
{
	//declare all the values
	double x[] = { -8,-6,-4,-2,0,2,4,6,8 };
	int length = sizeof(x) / sizeof(x[0]);
	double* h = new double[10]{ 0 };
	double* u = new double[10]{ 0 };
	double* l = new double[10]{ 0 };
	double* y = new double[10]{ 0 };
	double* vprime = new double[10]{ 0 };
	double* v = new double[10]{ 0 };
	double* uprime = new double[10]{ 0 };
	double* d = new double[10]{ 0 };
	int n = length-2;
	double* A = new double[length];
	double* B = new double[length];
	double* c = new double[length];
	double* D = new double[length];
	double* z1 = new double[10]{ 0 };
	double* z2 = new double[10]{ 0 };
	double* z3 = new double[10]{ 0 };
	double* z4 = new double[10]{ 0 };
	double* z5 = new double[10]{ 0 };
	double* z6 = new double[10]{ 0 };
	double* z7 = new double[10]{ 0 };
	double *Z= new double[10]{ 0 };
	
	
	
	//calculate  y value
	for (int i = 0; i < length; i++)
	{
		y[i] = f(x[i]);
	}
	cout << "Data points (ti, yi)" << endl;
	for (int i = 0; i < length; i++)
	{
		cout << "(t" << i << ", " << "y" << i << ") = " << "(" << x[i] << ", " << y[i] << ")" << endl;
	}
	//calculate h value
	for (int i = 0; i < length - 1; i++)
	{
		h[i] = x[i + 1] - x[i];
		
	}
	//calculate the v and u values
	for (int i = 0; i < length - 2; i++)
	{
		vprime[i] = 6*(((y[i + 1] - y[i]) / h[i]) - ((y[i] - y[i - 1])/h[i-1]));
		uprime[i] = 2 * (h[i - 1] + h[i]);

	}
	//calculate l and d values
	for (int i = 0; i < length-1; i++)
	{
		v[i] = vprime[i+1];
		d[i] = uprime[i+1];
		u[i] = h[i + 1];
		l[i]= h[i + 1];
		
	}
	
	z1[0] = d[0];
	z1[1] = l[0];
	z2[0] = u[0];
	z2[1] = d[1];
	z2[2] = l[1];
	z3[1] = u[1];
	z3[2] = d[2];
	z3[3] = l[2];
	z4[2] = u[2];
	z4[3] = d[3];
	z4[4] = l[3];
	z5[3] = u[3];
	z5[4] = d[4];
	z5[5] = l[4];
	z6[4] = u[4];
	z6[5] = d[5];
	z6[6] = l[5];
	z7[6] = u[6];
	z7[7] = d[6];
	
	//output the tri diagonal matrix
	cout << "Tri-diagonal system for z1 through z(n-1)" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << z1[i] << " " << z2[i] << " " << z3[i] << " " <<z4[i]<<" "<< z5[i]<<" "<<z6[i]<<" "<<z7[i]<<" "<<v[i] << endl;
	}
	
	//call forwardElm method to solve Z
	Z = forwardElm(d, u, l, v, n);
	//Calculate A,B,C,D values
	for (int i = 0; i < length; i++)
	{
		A[i] = y[i];
		B[i] = (y[i + 1] - y[i] / h[i]) - (h[i] / 3) - ((h[i] * Z[i + 1]) / 6);
		c[i] = Z[i] / 2;
		D[i] = (Z[i + 1] - Z[i]) / (6 * h[i]);
	}
	//output A,B,C,D
	cout << "Coefficients for Natural Cubic Spline in nested form" << endl;
	cout << "----------------------------------------------------" << endl;
	for (int i = 0; i <= n; i++)
	{
		cout << "A" << i << ":  " << A[i] << "  B" << i << ":  " << B[i] << "   C" << i << ":   " << c[i] << "   D" << i << ":   " << D[i] << endl;
	}
	//Output cubic spline
	cout << "Natural Cubic Spline in nested form" << endl;
	cout << "----------------------------------------------------" << endl;
	int num = x[length - 1];
	for (int i = 0; i <= n; i++)
	{
		cout << "S" << i << ":  " << A[i] << "+ (x+"<<num<<") * (" <<B[i] << "+ (x+" << num<< ") * (" << c[i] << "+ (x+" << num << ") * ("<< D[i] << endl;
		num-= 2;
	}
	//outpot original spline
	cout << "Evaluation of Original and Spline functions and the absolute errors" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "i        << xi<          f(xi)           s(xi)        |f(xi)-S(xi)|" << endl;
	cout << "----------------------------------------------------" << endl;
	//declaring values for the bigger x
	double x2[] = { -8,-7,-6,-5,-4,-3,-2,-1,0,1,2,3,4,5,6,7,8 };
	int length2 = sizeof(x2) / sizeof(x2[0]);
	double* h2 = new double[10]{ 0 };
	double* y2 = new double[10]{ 0 };
	double* u2 = new double[10]{ 0 };
	double* l2 = new double[10]{ 0 };
	double* vprime2 = new double[10]{ 0 };
	double* v2 = new double[10]{ 0 };
	double* uprime2 = new double[10]{ 0 };
	double* d2 = new double[10]{ 0 };
	int n2 = length2 - 2;
	double* zz = new double[length] {0};
	double* A2 = new double[length2];
	double* B2 = new double[length2];
	double* c2 = new double[length2];
	double* D2 = new double[length2];
	double* ZZ = new double[10]{ 0 };

	//calculating the y value
	for (int i = 0; i < length2; i++)
	{
		y2[i] = f(x2[i]);
	}
	//calculating h value
	for (int i = 0; i < length2- 1; i++)
	{
		h2[i] = x2[i + 1] - x2[i];
	}
	//calculating u and v values
	for (int i = 0; i < length - 2; i++)
	{
		vprime2[i] = 6 * (((y2[i + 1] - y2[i]) / h2[i]) - ((y2[i] - y2[i - 1]) / h2[i - 1]));
		uprime2[i] = 2 * (h2[i - 1] + h2[i]);

	}
	//calculating d and l values
	for (int i = 0; i < length2 - 1; i++)
	{
		v2[i] = vprime2[i + 1];
		d2[i] = uprime2[i + 1];
		u2[i] = h2[i + 1];
		l2[i] = h2[i + 1];

	}
	//calculating the second z for the bigger data
	ZZ = forwardElm2(d2, u2, l2, v2, n2);
	for (int i = 0; i < length2; i++)
	{
		A2[i] = y2[i];
		B2[i] = (y2[i + 1] - y2[i] / h2[i]) - (h2[i] / 3) - ((h2[i] * ZZ[i + 1]) / 6);
		c2[i] = ZZ[i] / 2;
		D2[i] = (ZZ[i + 1] - ZZ[i]) / (6 * h2[i]);
		
	}
	double* S = new double[length2] {0};
	int count = (n2+1)/2;
	//calculating S 
	for (int i = 0; i < length2; i++)
	{
		int num2 = (count + x2[i]);
		S[i] = A2[i] + num2 * (B2[i] + num2 * (c[i] + num2 * D[i]));
		count-=1;
	}
	for (int i = 0; i < length2; i++)
	{
		cout<<fixed<<setprecision(6)<<i<<"    "<<x2[i]<<"        "<<y2[i]<<"      "<<S[i]<< "      "<<abs(y2[i]-S[i])<<endl;
	}
	return 0;
}