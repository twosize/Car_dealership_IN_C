# Car_dealership_IN_C

In this problem, the customer wishes to purchase a new vehicle from the CSC362 Automated Car Dealership software program; dealer.c. In dealer.c, the customer will enter their annual salary in the command line and the software program will output the cars affordable for the customer. The customer will then be allowed to browse the available vehicles by manufacturer and make/model. Once the customer makes a selection, the program displays the customer's selection along with the monthly payments. 

 

GIVEN: list available vehicles, description of "affordable vehicle" function.

List: Cars-1.txt Download Cars-1.txt 

Function description: Customer can comfortably afford a vehicle with a monthly payment of maximum 15% of gross salary.  A vehicle monthly payment can be describe as: (P+P*Q*R)/(R*12);
P = principle (price of vehicle - down payment), Q = Interest (based on salary), R = rate (5 years). 
For the CSC362 Automated Car Dealership, the interest rates are as followed based on annual salary:

Over 125k/4.79%
125k - over 80k/6.55%
80k - over 45k/9.49%
45k and under/13.28%

------------------------------------------------------

Input:
>>./a.out 60000

Desired Output:
Enter Down Payment: 5000
Available Manufacturers:
1) Toyota     2) Chevrolet     3)VW Group     4) Nissan
Select Manufacturer: 1
Available Make/Model:
1) Toyota Tacoma - $27250.00
2) Toyota Camry - $25945.00
3) Toyota Corolla - $21550.00

Select Make/Model: 2
You selected the Toyota Camry. Your monthly payment is $514.72.
