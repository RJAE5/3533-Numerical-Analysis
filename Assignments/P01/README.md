## P01 - Bisection Method for Root Approximation
### Rykir Evans
### Description:

This program introduces us to the Bisection Algorithm for root approximation in Numerical Analysis. This method takes a given interval, and initially estimates the root at the midpoint. Using the intermediate value theorem, the algorithm uses the `signum` function to determine if the left or right end point should be moved to the midpoint and proceed with the calculation. This continues until the midpoint is within specified tolerance. 

### Usage
For WSL, the following instructions may be used to run the program:
1. Navigate to the directory of the program
2. Use the g++ compiler* along with the program name `G++ main.cpp -o main`
3. Run the program using `./main`
4. Follow the program prompts to enter end points, tolerance, and limit of iterations.

