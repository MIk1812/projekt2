#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "Test/Start.h"
#include "Opcodes/LD.h"
#include "Opcodes/ADD.h"
#include "Opcodes/BR.h"
#include "Opcodes/ST.h"
#include "Opcodes/NOT.h"

char* takeInput(void);

#define inputSize 30
#define outputSize 16

int main() {

    testEverything();

    //Initialize input and output
    FILE *inStream;
    FILE *outputStream;
    outputStream = fopen("C:\\Users\\volka\\CLionProjects\\projekt2\\testout.txt","w");
    inStream = fopen("C:\\Users\\volka\\CLionProjects\\projekt2\\testFil.txt","r");
    if (inStream!=NULL&&outputStream!=NULL){
        printf("File read success!\n");
    }
    //Reads and saves in fromfile
       //char *fromFile = readFile(inStream);



    char* output = (char*) calloc(1, outputSize +1);

    int exit = 0;
    while(exit < 4){

        //By giving the address of input, we can let takeInput modify it
        //char* input = takeInput();
        char* input = readFile(inStream);

        directives(input,output);

        //Sum the ASCII values of the opcode's characters
        int sum = 0;
        for (int i = 0; i < inputSize; ++i) {

            //Until first blank space
            //todo hvordan alle disse
            if(input[i] == ' '|| input[i] == 110 || input[i] == 122 || input[i] == 112)
                break;
            sum = sum + input[i];
        }



        //Identify opcode
        switch(sum){

            //LD
            case 144:
                LD(input, output);
                break;

            //ADD
            case 201:
                ADD(input, output);
                break;

            //NOT
            case 241:
                NOT(input, output);
                break;

            //BR
            case 148:
                BR(input, output);
                break;

            //LDR
            case 226:
                break;

            //ST
            case 167:
                ST(input, output);
                break;

        }

        printf("%s", output);


        fprintf(outputStream,"%s",output);
        fprintf(outputStream,"\n",output);

        exit++;

    }



}

char* takeInput(void) {

    char* input = (char*) calloc(1,inputSize + 1);

    //Space for 30 characters. Scanf reads until \n
    scanf("%30[^\n]s", input);

    //Clears line (\n)
    scanf("%*c");

    return input;
}
















