#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

// --- Helper & Validation Functions ---

bool validate_input(const char* binary_str) {
    /**
     * Checks if the input string is a valid 8-bit binary number.
     * Returns true if valid, false otherwise.
     * * TODO: Implement this function to handle bad inputs gracefully.
     * - Check if the length is exactly 8 (use strlen).
     * - Check if all characters are either '0' or '1'.
     * - Print an error message if the input is invalid.
    **/
    // For now, assume input is always valid to allow the program to run.
    // Replace this with your actual validation logic.
    if(strlen(binary_str) != 8)
    {
	return false;
    }
    else
    {
	for(int i = 0; i < 8; i++)
	{
		if(*(binary_str+i) == '1' || *(binary_str+i) == '0')
		{
			continue;
		}
		else
		{
			printf("Input invalid!\n");
			return 0;
		}
	}
    }
    return true;
}

// --- ALU Operation Functions ---
// Note: In C, it's common to pass a buffer to be filled with the result.

void alu_add(const char* bin1, const char* bin2, char* result) {
    /**
     * Adds two 8-bit binary numbers.
     * * TODO: Implement the addition logic. A simple way is to convert the binary
     * strings to integers, add them, and convert the result back to an 8-bit
     * binary string, storing it in the 'result' buffer.
    **/
    // Your implementation here. Make sure to write the 8-bit binary string
    // into the 'result' character array. Don't forget the null terminator! 
    int bin1Int = 0, bin2Int = 0, m = 0, sum, carry;
    double  power;
    char *output = malloc(sizeof(char) * 9);

    //Can be optimed by creating a helper function
    for(int i = 0; i < 8; i++)
    {
	power = pow(2.0,8.0-i-1.0);
	bin1Int += ((*(bin1+i) - '0') * power);
	bin2Int += ((*(bin2+i) - '0') * power);
    }

    sum = bin1Int + bin2Int;

    while(1)
    {
    power = pow(2.0,10.0-m-1);
	if(sum == 0 && m == 10)
	{
		break;
	}
	if(power > sum || sum == 0)
	{
		*(output+m) = '0';
	}
	else
	{
		sum -= power;
		*(output+m) = '1';
	}
	//printf("S: %d\tC: %c\tP: %.2lf\n", sum, *(output+m), power);
	m++;
    }
    *(output+m) = '\0';
    
    carry = (m+1) - 9;
    for(int i = carry, k = 0; i <= (m+1); i++, k++)
    {
        *(output+k) = *(output+i);
    }
    
   // printf("%s\n%d\n", output, strlen(output));
    strcpy(result, output); // Placeholder
}

void alu_sub(const char* bin1, const char* bin2, char* result) {
        /**
     * Subtracts the second 8-bit binary number from the first.
     * This must be implemented using two's complement arithmetic.
     * * TODO: Implement the subtraction logic using two's complement.
    **/
    // Your implementation here. Make sure to write the 8-bit binary string
    // into the 'result' character array. Don't forget the null terminator! 
    int bin1Int = 0, bin2Int = 0, m = 0, sum, carry;
    double  power;
    char *output = malloc(sizeof(char) * 9);

    //Can be optimed by creating a helper function
    for(int i = 0; i < 8; i++)
    {
	power = pow(2.0,8.0-i-1.0);
	bin1Int += ((*(bin1+i) - '0') * power);
	bin2Int += ((*(bin2+i) - '0') * power);
    }

    sum = bin1Int - bin2Int;
    
    if(sum < 0)
    {
        sum = 128 - (sum*(-1));
        sum += 128;
    }

    while(1)
    {
    power = pow(2.0,8.0-m-1);
	if(sum == 0 && m == 8)
	{
		break;
	}
	if(power > sum || sum == 0)
	{
		*(output+m) = '0';
	}
	else
	{
		sum -= power;
		*(output+m) = '1';
	}
	//printf("S: %d\tC: %c\tP: %.2lf\n", sum, *(output+m), power);
	m++;
    }
    *(output+m) = '\0';
    
    //printf("%s\n", output);
    strcpy(result, output); // Placeholder
}

void alu_and(const char* bin1, const char* bin2, char* result) {
    /**
     * Performs a  bitwise AND on two 8-bit binary numbers.
     * * TODO: Implement the bitwise AND logic.
    **/
    // Your implementation here
    char *output = malloc(sizeof(char)*9);
    int bitAnd;

    int i;
    for(i = 0; i < 8; i++)
    {
	bitAnd = (*(bin1+i) - '0') & ((*(bin2+i)) - '0');
	*(output+i) = bitAnd + '0';
    }
    *(output+i) = '\0';

    strcpy(result, output); // Placeholder
}

void alu_or(const char* bin1, const char* bin2, char* result) {
    /**
     * Performs a bitwise OR on two 8-bit binary numbers.
     * * TODO: Implement the bitwise OR logic.
    **/
    // Your implementation here
    char *output = malloc(sizeof(char)*9);
    int bitOr;

    int i;
    for(i = 0; i < 8; i++)
    { 
        bitOr = (*(bin1+i) - '0') | ((*(bin2+i)) - '0');
        *(output+i) = bitOr + '0';
    }
    *(output+i) = '\0';

    strcpy(result, output); // Placeholder
}

void alu_xor(const char* bin1, const char* bin2, char* result) {
    /**
     * Performs a bitwise XOR on two 8-bit binary numbers.
     * * TODO: Implement the bitwise XOR logic.
    **/
    // Your implementation here
    char *output = malloc(sizeof(char)*9);
    int bitXor;

    int i;
    for(i = 0; i < 8; i++)
    { 
        bitXor = (*(bin1+i) - '0') ^ ((*(bin2+i)) - '0');
        *(output+i) = bitXor + '0';
    }
    *(output+i) = '\0';

    strcpy(result, output); // Placeholder
}

void alu_not(const char* bin1, char* result) {
    /**
     * Performs a bitwise NOT (one's complement) on an 8-bit binary number.
     * * TODO: Implement the bitwise NOT logic (inverting each bit).
    **/
    // Your implementation here

    char *output = malloc(sizeof(char)*9);
    int bitNot;

    int i;
    for(i = 0; i < 8; i++)
    { 
        bitNot = !(*(bin1+i) - '0');
        *(output+i) = bitNot + '0';
    }
    *(output+i) = '\0';

    strcpy(result, output); // Placeholder
}

void alu_equal(const char* bin1, const char* bin2, char* result) {
    /**
     * Checks if two 8-bit binary numbers are equal.
     * Fills 'result' with '00000001' if equal, '00000000' otherwise.
     * * TODO: Implement the equality check.
    **/
    // Your implementation here
    if(strcmp(bin1, bin2) == 0)
    {
	strcpy(result, "00000001");
    }
    else
    {
	strcpy(result, "00000000");
    }
}

// --- Main Program Loop ---

int main() {
    char op_input[10];
    char num1_input[10];
    char num2_input[10];
    char result[9]; // 8 bits + null terminator

    printf("Welcome to the 8-bit ALU Simulator!\n");

    while (1) {
        printf("\nAvailable operations: ADD, SUB, AND, OR, NOT, XOR, EQUAL\n");
        printf("Type 'EXIT' to quit.\n");
        
        printf("Enter operation: ");
        scanf("%s", op_input);

        // Convert to uppercase for consistent comparison
        for (int i = 0; op_input[i]; i++) {
            if(op_input[i] >= 'a' && op_input[i] <= 'z') {
                op_input[i] = op_input[i] - 32;
            }
        }
        
        if (strcmp(op_input, "EXIT") == 0) {
            break;
        }

        printf("Enter first 8-bit binary number: ");
        scanf("%s", num1_input);
        if (!validate_input(num1_input)) {
            continue;
        }

        if (strcmp(op_input, "NOT") == 0) {
            alu_not(num1_input, result);
        } else if (strcmp(op_input, "ADD") == 0 || strcmp(op_input, "SUB") == 0 ||
                   strcmp(op_input, "AND") == 0 || strcmp(op_input, "OR") == 0  ||
                   strcmp(op_input, "XOR") == 0 || strcmp(op_input, "EQUAL") == 0) {
            
            printf("Enter second 8-bit binary number: ");
            scanf("%s", num2_input);
            if (!validate_input(num2_input)) {
                continue;
            }

            if (strcmp(op_input, "ADD") == 0) alu_add(num1_input, num2_input, result);
            if (strcmp(op_input, "SUB") == 0) alu_sub(num1_input, num2_input, result);
            if (strcmp(op_input, "AND") == 0) alu_and(num1_input, num2_input, result);
            if (strcmp(op_input, "OR") == 0) alu_or(num1_input, num2_input, result);
            if (strcmp(op_input, "XOR") == 0) alu_xor(num1_input, num2_input, result);
            if (strcmp(op_input, "EQUAL") == 0) alu_equal(num1_input, num2_input, result);

        } else {
            printf("Invalid operation. Please try again.\n");
            continue;
        }
            
        printf("Result: %s\n", result);
    }

    return 0;
}
