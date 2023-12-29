/*
 * Name:        Alan Fung
 * Date:        December 2023
 * Purpose:     Terminal Calculator Program, in C Programming Language
 */

/* header file */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* defining mathematical operators to a corresponding number */
#define EXPONENT 1
#define MULTIPLY 2
#define DIVIDE 3
#define ADD 4
#define SUBTRACT 5

/* function prototypes */
int getOperation(char symbol);
double doOperation(int operation, double firstoperand, double secondoperand);
int findOperator(char array[]);

int main() {

    char input[50];
    char secondnum[50];
    char *afterfirstnum;
    char *endinput;
    double operand1, operand2, finalans;
    int operationType, operationindex;

    printf("Enter any operation, with two numbers (Enter 'end' to stop program): ");

    //record user input
    fgets(input, 50, stdin);

    //keep going until user inputs 'end' (accounting for newline)
    while (strcmp(input,"end") != 10) {

        //converts string not a space before mathematical operator to double
        operand1 = strtod(input, &afterfirstnum);

    //printf("\n%lf", operand1);

        strcpy(secondnum, afterfirstnum);

        //find index of operator
        operationindex = findOperator(secondnum);

        //find which type of operator (e.g. multiplication, addition, etc.)
        operationType = getOperation(secondnum[operationindex]);

    //printf("\n%s", secondnum);

        secondnum[operationindex] = ' ';

        //converts after mathematical operator to double
        operand2 = strtod(secondnum, &endinput);

    //printf("\n%lf", operand2);

        //compute mathematical operation
        finalans = doOperation(operationType, operand1, operand2);

        //print answer to user
        printf("\nYour answer is %lf!\n", finalans);

        //ask again
        printf("Enter any operation, with two numbers: ");
        fgets(input, 50, stdin);
    }

    printf("\nThanks for using!");

    return 0;
}

/*
 * Function:    getOperation
 * Purpose:     given a char symbol, determine type of numerical operator
 * Parameter:   symbol - a char that is the operation inputted by user
 * Return:      1 for EXPONENT,
 *              2 for MULTIPLY,
 *              3 for DIVIDE,
 *              4 for ADD, or
 *              5 for SUBTRACT
 */
int getOperation(char symbol) {

    int answer;

    if (symbol == '^') answer = EXPONENT;
    else if (symbol == '*' || symbol == 'x') answer = MULTIPLY;
    else if (symbol == '/') answer = DIVIDE;
    else if (symbol == '+') answer = ADD;
    else answer = SUBTRACT;

    return answer;
}

/*
 * Function:    doOperation
 * Purpose:     given two numbers and an operator, calculate the mathematical expression
 * Parameter:   operation      - number corresponding to operation (1 for EXPONENT, 2 for MULTIPLY,
 *                               3 for DIVIDE, 4 for ADD, or 5 for SUBTRACT)
 * Parameter:   firstoperand   - first number of operation
 * Parameter:   secondoperand  - second number of operation
 * Return:      the numerical result of the operation of the two numbers
 */
double doOperation(int operation, double firstoperand, double secondoperand) {
    double answer;

    if (operation == EXPONENT) answer = pow(firstoperand, secondoperand);
    else if (operation == MULTIPLY) answer = firstoperand * secondoperand;
    else if (operation == DIVIDE) answer = firstoperand / secondoperand;
    else if (operation == ADD) answer = firstoperand + secondoperand;
    else answer = firstoperand - secondoperand;

    return answer;
}


/*
 * Function:    findOperator
 * Purpose:     finds the index of a mathematical operator in a string
 * Parameter:   array - a string
 * Return:      the index where a mathematical operator is located in a string
 */
int findOperator(char array[]) {

    int answer;

    for (int count = 0; array[count] != '\0'; count++) {
        if (array[count] == '^' || array[count] == '*' || array[count] == 'x' || array[count] == '/' || array[count] == '+' || array[count] == '-') answer = count;
    }

    return answer;
}
