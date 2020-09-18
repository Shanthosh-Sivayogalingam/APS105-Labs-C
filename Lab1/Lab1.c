/*File: Lab1.c
 * Author: Shanthosh Sivayogalingam
 * Date: January 16, 2019
 * Description: Calculating the product, difference and sum of the squares of two inputed positive numbers from the user
*/

#include <stdio.h>
#include <math.h>

int main()                                                                                                                          
{
    double pos_number1,pos_number2,multiply,difference,sums;          //Defining the variables as doubles
    printf("Enter two positive numbers: ");                                     //Outputs a message for the user to input two postive numbers
    scanf("%lf %lf", &pos_number1, &pos_number2);                                    //Takes the users two numbers and assigns them with the corrseponding variables
    multiply = pos_number1*pos_number2;                                                     //Multiplies the two numbers inputed by the user
    difference = pos_number1-pos_number2;                                                        //Subtracts the two numbers inputed by the user
    sums = sqrt(pos_number1) + sqrt(pos_number2);                                                   //Adds the sums of the sqaure root of the two numbers inputed by the user
    printf("The product is: %0.2lf, the difference is: %0.2lf and the sum of roots is: %0.2lf \n",multiply,difference,sums); /*Outputs a message for the user indicating the following:
                                                                                                                              *product of the two numbers,
                                                                                                                              *the difference, and the sum of the sqaure roots
                                                                                                                              */
    return 0;
}