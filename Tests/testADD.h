//
// Created by Mikkel Danielsen on 06/05/2020.
//

#ifndef PROJEKT2_ADD_H
#define PROJEKT2_ADD_H

#endif //PROJEKT2_ADD_H

#include "../Functionality/FuncTest.h"
#include "../Opcodes/ADD.h"

void testADD1();
void testADD2();
void testADD3();

void testADD(){

    testADD1();
    testADD2();
    testADD3();

}

void testADD1(){

    char* testID = "ADD1";
    char* input = "ADD R1, R2, R3";
    char* output = (char*) calloc(1, sizeof(char) * 17);

    ADD(input, output, 0);
    char* expected = "0001001010000011";

    equals(output, expected, testID);
    free(output);

}

void testADD2(){

    char* testID = "ADD2";
    char* input = "ADD R1, R2, #10";
    char* output = (char*) calloc(1, sizeof(char) * 17);

    ADD(input, output, 0);
    char* expected = "0001001010101010";

    equals(output, expected, testID);
    free(output);

}

void testADD3(){

    char* testID = "ADD3";
    char* input = "ADD R1, R2, #-10";
    char* output = (char*) calloc(1, sizeof(char) * 17);

    ADD(input, output, 0);
    char* expected = "0001001010110110";

    equals(output, expected, testID);
    free(output);

}