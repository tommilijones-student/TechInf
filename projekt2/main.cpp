#include <iostream>

void menu(void) {
    printf("\n");
    printf("0 - Exit\n");
    printf("1 - Add\n");
    printf("2 - Subtract\n");
    printf("3 - Multiply\n");
    printf("4 - Divide\n");
    printf("Select an option:\n");
}

void enterNumbers(int *number1, int *number2) {
    printf("Enter first number: ");
    scanf("%d", number1);
    printf("Enter second number: ");
    scanf("%d", number2);
}

int main() {
    int option = 0;
    int number1 = 0;
    int number2 = 0;
    int result = 0;

    do {
        menu();
        scanf("%d", &option);
        switch (option) {
            case 0:
                printf("Exiting program...\n");
                break;
            case 1:
                enterNumbers(&number1, &number2);
                result = number1 + number2;
                printf("%d + %d = %d\n", number1, number2, result);
                break;
            case 2:
                enterNumbers(&number1, &number2);
                result = number1 - number2;
                printf("%d - %d = %d\n", number1, number2, result);
                break;
            case 3:
                enterNumbers(&number1, &number2);
                result = number1 * number2;
                printf("%d * %d = %d\n", number1, number2, result);
                break;
            case 4:
                enterNumbers(&number1, &number2);
                if (number2 == 0) {
                    printf("Error: Division by zero is not allowed.\n");
                } else {
                    double divResult = (double)number1 / number2;
                    printf("%d / %d = %.2f\n", number1, number2, divResult);
                }
                break;
            default:
                printf("Choose a valid option...\n");
        }
    } while (option != 0);

    return 0;
}
