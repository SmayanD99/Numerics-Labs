/*Author Helen Wubneh
* Instructor Suk Jai Seo
* Projuct# Projuct2
* Due Date 2/11/2021
*/
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

/*This program evaluates f(X)=x(sqrt(x+1)-sqrt(x))*/
float fOfX1(float x)
{
    float res;
    //evaluate result and return
    res = x * (sqrt(x + 1) - sqrt(x));
    return res;
}
float fOf2X1(int x)
{
    float res;
    ////evaluate result and return
    res = x * (sqrt(x + 1));
    return res;
}
double fOfX2(int x)
{
    double res;
    //evaluate result and return
    res = x * (sqrt(x + 1) - sqrt(x));
    return res;
}
double fOf2X2(double x)
{
    double res;
    //evaluate result and return
    res = x * (sqrt(x + 1));
    return  res;
}
int main()
{
	//output the result
	cout << "         X         " << "            f(x)    " << "                              f2(x)         " << endl;
    int r = 1000000000;
    for (int i = 1; i <= r; i = i * 10)
    {
        if (i >= 10000000)
            cout <<fixed<< setprecision(15)<<i << "\t\t" << fOfX1(i) << "\t\t\t" << fOfX2(i) << endl;
        else if (i == 1)
            cout << fixed<<setprecision(15)<< i << "\t\t\t" << fOfX1(i) << "\t\t\t" << fOfX2(i) << endl;
        else
            cout << fixed<<setprecision(15)<<i << "\t\t\t" << fOfX1(i) << "\t\t\t" << fOfX2(i) << endl;

    }
    cout << endl;
    cout << "         X         " << "            f(x)    " << "                               f2(x)         " << endl;
     //output the result
    for (int i = 1; i <= r; i = i * 10)
    {
        if (i >= 10000000)
        cout << fixed << setprecision(15) << i << "\t\t" << fOf2X1(i) << "\t\t" << fOf2X2(i) << endl;
        else if (i == 1)
        cout << fixed << setprecision(15) << i << "\t\t\t" << fOf2X1(i) << "\t\t\t" << fOf2X2(i) << endl;
        else
        cout << fixed << setprecision(15) << i << "\t\t\t" << fOf2X1(i) << "\t\t\t" << fOf2X2(i) << endl;
    }
    
	return 0;
}