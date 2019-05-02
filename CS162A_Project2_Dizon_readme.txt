*----------------------*
| What is the program? |
*----------------------*

This program is a simulator for deadlock checking and resolving.

*------------*
| How to run |
*------------*

To build it from scratch:
    Compile the project with the following command:
        g++ CS162A_Project2_Dizon_code.cpp -o CS162A_Project2_Dizon_code
To run packaged exe file:
    Run CS162A_Project2_Dizon_code.exe

*------------*
| How to use |
*------------*

From the slides:
First line of input will contain number of test cases.
For each test case,
First line contains number of processes (P) followed by number of resource types (R).
Next line contains R numbers, each representing how much of each resource is available / not yet allocated (first number = first resource type).
Next P lines contain resources currently held by each of the processes (first line = first process).
Next P lines contain resources that each process still needs (again, first line = first process).

*--------------------------*
| Functions and Operations |
*--------------------------*

No implemented functions.