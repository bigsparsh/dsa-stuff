Problem Statement: Calculate Overtime Pay Using Loop in C++
Objective: Create a C++ program to calculate the overtime pay for employees based on their hours worked. The program should repeatedly prompt for employee hours until a sentinel value is entered.

Requirements:

Inputs:

The number of hours worked by each employee (integer).
The sentinel value to stop the input (e.g., -1).
Constants:

Standard working hours per week: 40 hours.
Overtime pay rate: 1.5 times the regular pay rate.
Regular pay rate (can be assumed or set as a constant, e.g., $20/hour).
Outputs:

For each employee, display the total pay, including regular and overtime pay.
If the hours worked are less than or equal to the standard working hours, display only the regular pay.
If the hours worked exceed the standard working hours, calculate and display both the regular and overtime pay.
Procedure:

Use a loop to repeatedly prompt the user to enter the number of hours worked by each employee.
For each input, check if it is the sentinel value. If it is, exit the loop.
If the input is not the sentinel value, check if the hours worked exceed the standard working hours.
Calculate the total pay:
If hours worked are less than or equal to 40, multiply the hours by the regular pay rate.
If hours worked exceed 40, calculate the regular pay for 40 hours and the overtime pay for the extra hours.
Display the calculated pay for the employee.
Repeat until the sentinel value is entered.
Example:

Assuming the regular pay rate is $20/hour:

For 35 hours worked: Total pay = 35 _ $20 = $700
For 45 hours worked: Total pay = (40 _ $20) + (5 _ $20 _ 1.5) = $800 + $150 = $950
