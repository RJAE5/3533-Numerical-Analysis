#include <iostream>
#include <cmath>

using namespace std;

// Polynomial function for calculation
double f(double x)
{
    return pow(x,3) - 7 * pow(x,2) + 14 * x - 6;
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
            cout << "Program complete with p = " << p << endl;
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
}