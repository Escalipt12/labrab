#include <stdio.h>
#include <ctype.h>

int main() {
    char str[256];
    printf("Введите пример: ");
    fgets(str, 256, stdin);
    
    double result = 0;
    double num = 0;
    char op = '+';
    int i = 0;
    int error = 0;

    while (str[i] != '\n' && str[i] != '\0' && !error) {
        while (str[i] == ' ') i++;
        
        if (isdigit(str[i]) || str[i] == '.') {
            double temp = 0;
            int dot = 0;
            double div = 1;
            
            while (isdigit(str[i]) || str[i] == '.') {
                if (str[i] == '.') {
                    if (dot) { 
                        printf("два знака точки\n");
                        error = 1;
                        break;
                    }
                    dot = 1;
                } else {
                    if (dot) {
                        div *= 10;
                        temp = temp * 10 + (str[i] - '0');
                    } else {
                        temp = temp * 10 + (str[i] - '0');
                    }
                }
                i++;
            }
            
            if (dot) temp /= div;
            num = temp;
        }
        

        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
            if (op == '+') result += num;
            else if (op == '-') result -= num;
            else if (op == '*') result *= num;
            else if (op == '/') {
                if (num == 0) {
                    printf("деление на ноль!\n");
                    error = 1;
                } else {
                    result /= num;
                }
            }
            op = str[i];
            i++;
            num = 0;
        }
    }
    
    if (!error) {
        if (op == '+') result += num;
        else if (op == '-') result -= num;
        else if (op == '*') result *= num;
        else if (op == '/') {
            if (num == 0) printf("деление на ноль!\n");
            else result /= num;
        }
    }
    
    if (!error) printf("Ответ: %g\n", result);
    return 0;
}
