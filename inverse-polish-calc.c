#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

char inputs[255];
int values[2];
int operation;
char operationList[5] = {'+', '-', '/', '*', '^'};
int result;

void render() {
    printf("\nReverse Pollish Notation Calculator\n");
    printf("By Rafael Castro\n");
}

void interfaceDiv() {
    printf("\n=============================================");
}

void call_error(int error_code) {
    printf("Error! Error code: x0%d", error_code);
}


void expressionInterpreter(char input[]) {
    int inputLength = strlen(input);
    char selectedOperation;

    int i;

    for (i=inputLength;i > 0;i--){
        selectedOperation = input[i];
        if (selectedOperation != 0 && selectedOperation != '\n' && selectedOperation != ' ') {
            i = 0;
        } else {
            selectedOperation = 0;
        }

    }

    char *pch;

    pch = strtok(input," ");

    int index = 0;
    while (pch != NULL || index < sizeof(values))
    {
        values[index] = atoi(pch);
        pch = strtok (NULL, " ");
        index += 1;
    }
    

    if (selectedOperation != 0) {
        int j;
        for (j = 0; j <  sizeof(operationList); j++)
        {
           if (selectedOperation == operationList[j]) {
                operation = j;
           }
        }
        
    }

    switch (operation)
    {
    case 0:
        result = values[0] + values[1];
        break;

    case 1:
        result = values[0] - values[1];
        break;

    case 2:
        result = values[0] / values[1];
        break;

    case 3:
        result = values[0] * values[1];
        break;

    case 4:
        result = pow(values[0], values[1]);
        break;

    default:
        call_error(0);
        exit;
        break;
    }
}


int main() {

    int maintain = 0;

    while (maintain == 0)
    {
    interfaceDiv();
    render();
    printf("\nInsert your expression:\n");
    fgets(inputs, sizeof(inputs), stdin);
    fflush(stdin);

    expressionInterpreter(inputs);
    interfaceDiv();
    render();
    printf("\nThe result is: %d", result);
    printf("\n#\n#\n0 - NEW EXPRESSION\n1 - EXIT THE PROGRAM\n");
    fflush(stdin);
    scanf("%d",&maintain);
    fflush(stdin);
    }
    exit;
    return 0;
}