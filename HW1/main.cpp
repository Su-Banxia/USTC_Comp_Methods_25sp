#include <iostream>

#include <cmath>

#include <iomanip>

using namespace std;

double get_Term(int k, double x)
{
    return 1 / (k * (k + x));
}

int find_k(double x)
{
    if (x == 0)
    {
        return 1e+6;
    }
    return x / ( exp( x * (1e-6)) - 1 ) + 1;
}

double get_Summation(double x)
{
    double total = 0.0;

    int num = find_k(x);

    for (int k = 1; k <= num; k++)
    {
        total += get_Term(k, x);
    }

    return total;
}


int main()
{
    double testLists[7] = {0.0, 0.5, 1.0, sqrt(2), 10.0, 100.0, 300.0};

    for (int i = 0; i < 7; i++)
    {
        cout << fixed << setprecision(1) << "x = " << testLists[i] << "," 
            << setprecision(15) << "y = " << get_Summation(testLists[i]) << endl;
    }

    return 0;
}