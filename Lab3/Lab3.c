/*File: Lab3.c
 * Author: Shanthosh Sivayogalingam
 * Date: September 30, 2019
 * Description: The following code is used to help a user determine how much coffee they can buy every month involving the aspect of coupons which can be redeemed for free coffees.
*/
#include <stdio.h>

int main()
{
    double coffeePrice, userMoney;
    int couponsForCoffee; // Number of coupons needed to redeem one free coffee
   
    printf("How much does a coffee cost?\n");
	scanf("%lf", &coffeePrice); //Assigns users input to the indicated variable
	if (coffeePrice <0.01) //This line identifies whether the users input fits the condition stated and then continues with the code
	{
		printf("Invalid Input. \n");
		return 0;
	}
       
	printf("How many coupons does it take to get a free coffee?\n");
	scanf("%d", &couponsForCoffee); //Assigns users input to the indicated variable
	if (couponsForCoffee <1) //This line identifies whether the users input fits the condition stated and then continues with the code
	{
		printf("Invalid Input. \n");
		return 0;
	}
           
           
	printf("How much money do you have to spend on coffee this month?\n");
	scanf("%lf", &userMoney); //Assigns users input to the indicated variable
	if (userMoney <0) //This line identifies whether the users input fits the condition stated and then continues with the code
	{
		printf("Invalid Input. \n");
		return 0;
	}
	
    int numberCoffee= (int) (userMoney/coffeePrice);
	int freeCoffee;
    int couponBalance= numberCoffee;
	
	//The following while loop is used to create a condition when if the total number of coupons the user has is greater than the number of coupons needed for a free coffee,
	//the code will add 1 to both the total number of coupons(new) and to the number of free coffees they receive. 
	while (couponBalance>=couponsForCoffee)
	{
		couponBalance-= couponsForCoffee;
		couponBalance++;
		freeCoffee++;
	}
	
	//The following lines of code determine when the variables meet the indicated condition then print the final output statements.
	if (userMoney>coffeePrice)
    {
		printf("This month, you can purchase %d coffees at $%0.2lf each.\n", numberCoffee,coffeePrice);
    }
	
		
	if (freeCoffee>=1)
	{
        printf("You will be able to redeem an additional %d coffee(s) from coupons.\n",freeCoffee);
	}
	else
	{  
		printf("You will not be able to redeem any additional coffees from coupons this month. \n");
	}
	
	double moneyRemainder= userMoney-(coffeePrice*numberCoffee);
	printf("At the end of the month, you will have $%0.2lf and %d coupon(s) remaining. \n",moneyRemainder,couponBalance);
	
	//This if statement is used to determine if whether the user has enough money to even purchase 1 coffee and if not it outputs a value of 0 for the average cost. (all other outputs are also 0)
	int totalCoffees= numberCoffee +freeCoffee;
	if (userMoney>coffeePrice)
	{
		double averageCost= (coffeePrice*numberCoffee)/(totalCoffees);
		printf("On average, you spent $%0.2lf on each cup of coffee this month. \n",averageCost);
	}
	else
	{
		printf("On average, you spent $0 on each cup of coffee this month. \n");
	}
	
return 0;

}