/*****************************************************************************\
*
*  Author:           Rykir Evans
*  Email:            rjevans0408@my.msutexas.edu | rykirjoe@yahoo.com
*  Title:            Bisection Root Approximation Method
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
#include <iomanip>
#include <chrono>

using namespace std;

// Polynomial function for calculation
double f(double x)
{
    return (1/x) - M_PI;
}

// Signum function to effectively determine the sign of a number
int signum(double x)
{
    if(x > 0)
        return 1;
    else if (x < 0)
        return -1;
    else  
        return 0;
}

// I intended on making a function that automatically calculates the minimum number of iterations to get the desired tolerance
// but got sidetracked and needed to do my homework instead.
// int calcMinN(double TOL)
// {
//     return ceil(log(pow(TOL, -1)) / log(2));
// }

int main()
{
    // Variable declaration
    double a, b, tol, p, FP, mid;
    int N;

    // Input prompts and storage
    cout << "Rykir Evans\n" << "Numerical Analysis - Bisection Method Algorithm\n\n";
    cout << "Please input your left end point:\n";
    cin >> a;

    cout << "Please input your right end point:\n";
    cin >> b;

    cout << "Please input your minimum error tolerance in decmial form:\n";
    cin >> tol;

    // cout << "Note that the maximum number of iterations to get within your specified tolerance is: " << calcMinN(tol) << endl << endl;
    cout << "Please input your max limit of iterations:\n";
    cin >> N;

    // Input validation
    while(N <= 0)
    {
        cout << "Invalid input, please enter a number larger than 0" << endl;
        cin >> N;
    }

    auto startTime = chrono::high_resolution_clock::now();

    // Evaluate function at left end point
    double FA = f(a);

    // Runtime loop
    for(int i = 1; i <= N; i++)
    {
        // Calculate midpoint offset
        mid = (b - a) / 2;

        // Add left end point to offset to achieve true midpoint
        p = a + mid;

        // Evaluate function at midpoint
        FP = f(p);

        // If the offset is less than tolerance or the root of the function is at the midpoint, exit
        if(mid < tol || FP == 0)
        {
            // Output complete message with mid point value and number of steps taken.
            cout << "Program complete with p = " << setprecision(10) << p << endl;
            cout << "Steps taken: " << i << endl;
            break;
        }
            
        // If the left end point and midpoint evaluations are positive, then the root is between the
        // midpoint and the right endpoint
        // Vise versa if negative
        if(signum(FA) * signum(FP) > 0)
        {
            // Move left endpoint to midpoint
            a = p;
            FA = FP;
        }
        else
            b = p;
        
        // Error message
        if(i == N)
             cout << "Max number of iterations exceeded, exiting the program with p = " << p << endl;
    }
    
    auto endTime = chrono::high_resolution_clock::now();
    auto duration = endTime - startTime;

    auto microseconds = chrono::duration_cast<std::chrono::microseconds>(duration);
    std::cout << "Execution time: " << microseconds.count() << " microseconds" << std::endl;
}