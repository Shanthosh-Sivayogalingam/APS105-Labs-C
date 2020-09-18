/* File: Lab2.c
 * Author: Shanthosh Sivayogalingam
 * Date: January 23, 2019
 * Description: Determining the monthly payment and total cost of a purchase using a formula which accumulates the interest over a certain period of months
*/

#include <stdio.h>
#include <math.h>

int main()
{
    double purchase_price, interest_rate;
    int number_months;
	//Declaring variables
   
    printf("Enter the purchase price of the item: ");
    scanf("%lf", &purchase_price); //Assigns users input with the variable purchase_price
   
    printf("Enter the interest rate per year as a percentage: ");
    scanf("%lf", &interest_rate); //Assigns users input with the variable interest_rate
   
    printf("Enter the number of months for repayment: ");
    scanf("%d", &number_months); //Assigns users input with the variable number_months
   
    double monthly_payment, rate_decimal,item_cost;
	const int convert_interest =1200;
   
    rate_decimal= interest_rate/convert_interest;
    monthly_payment= ((rate_decimal)/ (1-pow(1+rate_decimal,-number_months)))*purchase_price;
    item_cost= monthly_payment*number_months;
    //Using the given formula and given inputs to calculate the desired outputs
   
    printf("The monthly payment is : %0.2lf \nThe total cost of the purchase is: %0.2lf \n",monthly_payment,item_cost);
    //Displays the new calculated values corrseponding to the inputs
   
    return 0;
   
}