/*****************************************************************************\
*
*  Author:           Rykir Evans
*  Email:            rjevans0408@my.msutexas.edu | rykirjoe@yahoo.com
*  Title:            Secant Root Approximation Method
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
    return (1 / x) - M_PI;
}

int main()
{
    double p0, p1, tol, n0; // Input variables
    double p, q0, q1; // Internal calculation variable

    cout << "Please enter the initial guess of the left bound:" << endl;
    cin >> p0;

    cout << "Please enter the initial guess of the right bound:" << endl;
    cin >> p1;

    cout << "Please enter the desired tolerance for accuracy:" << endl;
    cin >> tol;

    cout << "Please enter the maximum number of iterations before the program will be stopped:" << endl;
    cin >> n0;
    cout << endl;

    auto startTime = chrono::high_resolution_clock::now();

    // Internal function evaluation
    q0 = f(p0);
    q1 = f(p1);


    for(int i = 2; i <= n0; i++)
    {
        // Initial guess given bounds
        p = p1 - q1 * (p1 - p0) / (q1 - q0);

        // Determine guess quality
        if(abs(p-p1) < tol)
        {
            // Within tolerance: Output success
            cout << "Root P achieved at = " << setprecision(10) << p << endl;
            cout << "Achieved in " << i << " steps!" << endl;
            break;
        }
        else
        {
            // Outside of tolerance: Repeate

            // If last iteration: output closest result
            if(i == n0)
            {
                cout << "Error: Could not approximate root within desired maximum iterations" << endl;
                cout << "Closest P achieved => " << setprecision(10) << p << endl;
            }

            // Evaluation of other variables.
            p0 = p1;
            q0 = q1;
            p1 = p;
            q1 = f(p);
        }
    }

    auto endTime = chrono::high_resolution_clock::now();
    auto duration = endTime - startTime;

    auto microseconds = chrono::duration_cast<std::chrono::microseconds>(duration);
    std::cout << "Execution time: " << microseconds.count() << " microseconds" << std::endl;
}