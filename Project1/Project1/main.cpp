#include <iostream>
using namespace std;
int main()
{
	int x[] = { 0,2,3,4 };
	int y[] = { 7,11,28,59 };
	int n= 4;
	int A[4] = { 0 };
	for (int i = 0; i < 4; i++)
	{
		A[i] = y[i];
	}
	int index = 1;
	for (int j = 2; j <= n+1; j++)
	{
		
		for(int i = n-1; i >= 1; i--)
		{
			A[i] = (A[i] - A[i - 1]) / (x[i] - x[i-(j-1)]);
			
		}
		
		index++;
	}
	for (int i = 0; i < 4; i++)
	{
		cout << A[i] << " ";
	}
	return 0;
}