/*****************************************************************************\
*
*  Author:           Rykir Evans
*  Email:            rjevans0408@my.msutexas.edu | rykirjoe@yahoo.com
*  Title:            Newton's Root Approximation Method
*  Course:           MATH 3533 Numerical Analysis
*  Professor:        Dr. Jeff Hood
*  Semester:         Fall 2025
*
*  Description:
*         
*         
*  Usage:
*         
*         
*  Files: 
*         main.cpp
\******************************************************************************/
#include <iostream>
#include <cmath>
#include <iomanip>
#include <chrono>

using namespace std;

// Function for calculation
double f(double x)
{
    return (1/x) - M_PI;
}

double fPrime(double x)
{
    return -1 / pow(x,2);
}

int main()
{

    double p0, tol, n0; // Input variables
    double p; // Internal calculation variable

    cout << "Please enter the initial guess of the root:" << endl;
    cin >> p0;

    cout << "Please enter the desired tolerance for accuracy:" << endl;
    cin >> tol;

    cout << "Please enter the maximum number of iterations before the program will be stopped:" << endl;
    cin >> n0;
    cout << endl;


    auto startTime = chrono::high_resolution_clock::now();
    for(int i = 1; i <= n0; i++)
    {

        p = p0 - (f(p0) / fPrime(p0));

        if(abs(p-p0) < tol)
        {
            cout << "Root P achieved at = " << setprecision(10) << p << endl;
            cout << "Achieved in " << i << " steps!" << endl;
            break;
        }
        else
        {
            if(i == n0)
            {
                cout << "Error: Could not approximate fixed point within desired maximum iterations" << endl;
                cout << "Closest P achieved => " << setprecision(10) << p << endl;
                cout << "p0 = " << p0 << endl;
            }
            p0 = p;
        }
    
    }
    auto endTime = chrono::high_resolution_clock::now();
    auto duration = endTime - startTime;

    auto microseconds = chrono::duration_cast<std::chrono::microseconds>(duration);
    std::cout << "Execution time: " << microseconds.count() << " microseconds" << std::endl;

}