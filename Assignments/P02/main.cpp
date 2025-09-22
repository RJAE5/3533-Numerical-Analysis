/*****************************************************************************\
*
*  Author:           Rykir Evans
*  Email:            rjevans0408@my.msutexas.edu | rykirjoe@yahoo.com
*  Title:            Fixed Point Approximation Method
*  Course:           MATH 3533 Numerical Analysis
*  Professor:        Dr. Jeff Hood
*  Semester:         Fall 2025
*
*  Description:
*         This program uses input from the user regarding the bounds of an
*         interval for which to examine the roots of a hard-coded function.
*         Additionally, a parameter for desired accuracy and maximum number
*         of iterations are also requested. The program results with the
*         root location approximation and the number of steps in order to
*         achieve this approximation.
*         
*  Usage:
*         To use this program, first define a polynomial function in the `f()`
*         function. Then you may use some standard C++ compiler and run the
*         program using `./main`. From there, follow the prompts as requested
*         and the results will be displayed.
*         
*  Files: 
*         main.cpp
\******************************************************************************/
#include <iostream>
#include <cmath>

using namespace std;

// Polynomial function for calculation
double f(double x)
{
    return tan(x);
}

int main()
{
    double p0, tol, n0;
    double p;
    cout << "Please enter the initial guess of your fixed point:" << endl;
    cin >> p0;

    cout << "Please enter the desired tolerance for accuracy:" << endl;
    cin >> tol;

    cout << "Please enter the maximum number of iterations before the program will be stopped:" << endl;
    cin >> n0;
    cout << endl;


    for(int i = 1; i < n0; i++)
    {

        p = f(p0);

        if(abs(p-p0) < tol)
        {
            cout << "Fixed point achieved at g(p0) = " << p << endl;
            cout << "p0 = " << p0 << endl;
            cout << "Achieved in " << i << " steps!" << endl;
            break;
        }
        else
        {
            if(i == n0 - 1)
            {
                cout << "Error: Could not approximate fixed point within desired maximum iterations" << endl;
                cout << "Closest g(p0) achieved => " << p << endl;
                cout << "p0 = " << p0 << endl;
            }
            p0 = p;
        }
    
    }

}