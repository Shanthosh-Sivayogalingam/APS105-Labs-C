/*File:Lab4.c
 * Author: Shanthosh Sivayogalingam
 * Date: February 6th, 2019
 * Description: The following program will determine the approximate integral value for the given function using left,right and mid point rules using user inputs for the lower bound, upper bound, and the number of intervals
*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

//The following lines of code are used to create the validateInput function which is called upon later in the main in order to validate the user inputs

bool validateInput(double leftBound, double rightBound, int numRectangles)
{
    if (leftBound == 0 && rightBound == 0 && numRectangles == 0)
    {
        return true;
    }
    else if (leftBound < -10 || rightBound > 10 || leftBound >= rightBound || numRectangles<=0)
    {
        printf("Invalid Inputs...\n");
        return false;
    }
    else
    {
        return true;
    }
}

//The following lines of code are used to create the evalFunc function which is called upon later in order to evaluate specifc points of x into the given function for which we are approximating the integral

double evalFunc(double x)
{
    return (2*(pow(x,2)) - (7*x) - 2);
}

int main()
{
    double leftBound, rightBound, delta, sumL, sumR, sumM;
    int numRectangles;
    
    sumL= 0;
    sumR= 0;
    sumM= 0;
    
    //The following lines are used to ask the user for inputs for the left bound, right bound and the number of rectangles
    printf("Enter the Left boundary: a, Right boundary: b, and No. of rectangles to use.\nTo exit enter 0 0 0\n");
	scanf("%lf", &leftBound);
    scanf("%lf", &rightBound);
    scanf("%d", &numRectangles);
    
    //The following while loop runs only when the validateInput function is equivalent to a false (boolean) and is used to run the printed message multiple times until the user inputs valid inputs
    while ((validateInput(leftBound,rightBound,numRectangles) == false))
    {
        printf("\nEnter the Left boundary: a, Right boundary: b, and No. of rectangles to use.\nTo exit enter 0 0 0\n");
        scanf("%lf",&leftBound);
        scanf("%lf",&rightBound);
        scanf("%d",&numRectangles);
    }
    
    //The following if statement is used to help the user exit the program by being able to input 0 for all entries 
    if (leftBound == 0 && rightBound == 0 && numRectangles == 0)
    {
        printf("Invalid Inputs...\n \nTerminating main!\n");
        return 0;
    }
    
    
    delta = (rightBound - leftBound)/numRectangles;
    //The following lines of code determines the approximate integral evaluation for the given funtion using the left point rule for which i represents a counter
    for (int i=0;i<numRectangles;i++)
    {
        
        double area,point;
        
        point = leftBound +(delta*i);
        area = evalFunc(point) * delta;
        sumL = sumL + area;
    }
    
    
    //The following lines of code determines the approximate integral evaluation for the given funtion using the right point rule
    for (int i=0;i<numRectangles;i++)
    {
        
        double area,point;
        
        point = leftBound+delta +(delta*i);
        area = evalFunc(point) * delta;
        sumR = sumR + area;
    }

    
    //The following lines of code determines the approximate integral evaluation for the given funtion using the mid point rule
    for (int i=0;i<numRectangles;i++)
    {
        
        double area,point;
        
        point = (leftBound +delta/2) +(delta*i);
        area = evalFunc(point) * delta;
        sumM = sumM + area;
    }

    //These lines print the final output statements which include the values for the approximated integrals for each method
    printf("With Step Size: %0.4lf\nThe approximate integral of the f(x) = 2(x^2)-7x-2\nBound between %.2lf and %.2lf, using %d rectangles is as follows\n",delta,leftBound,rightBound,numRectangles);
    printf("\nMid point evaluation approximate: %.4lf\nLeft point evaluation approximate: %.4lf\nRight point evaluation approximate: %.4lf\n",sumM,sumL,sumR);

return 0;
}