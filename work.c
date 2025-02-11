#include <stdio.h>
#include <string.h>
#include <math.h>

// Function to convert binary string to decimal
int binaryToDecimal(char binary[]) {
    int decimal = 0;
    int length = strlen(binary);
    
    for (int i = 0; i < length; i++) {
        if (binary[i] == '1') {
            decimal += pow(2, length - i - 1);
        }
    }

    return decimal;
}

// Function to convert decimal to hexadecimal
void decimalToHexadecimal(int decimal) {
    if (decimal == 0) {
        printf("0");
        return;
    }

    char hex[20];
    int i = 0;
    
    while (decimal != 0) {
        int remainder = decimal % 16;
        
        if (remainder < 10) {
            hex[i] = remainder + '0';  // Store remainder as a character
        } else {
            hex[i] = remainder - 10 + 'A';  // Convert 10-15 to A-F
        }
        
        i++;
        decimal = decimal / 16;
    }
    
    // Print the hexadecimal number in reverse
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hex[j]);
    }
}

int main() {
    char binary[65];
    
    // Input binary number
    printf("Enter a binary number: ");
    scanf("%s", binary);
    
    // Convert binary to decimal
    int decimal = binaryToDecimal(binary);
    
    // Convert decimal to hexadecimal and print
    printf("Hexadecimal equivalent: ");
    decimalToHexadecimal(decimal);
    
    return 0;
}
