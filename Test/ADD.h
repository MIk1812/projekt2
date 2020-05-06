//
// Created by Mikkel Danielsen on 06/05/2020.
//

#ifndef PROJEKT2_ADD_H
#define PROJEKT2_ADD_H

#endif //PROJEKT2_ADD_H

#include "Func.h"
#include "../Opcodes/ADD.h"

void testADD1();
void testADD2();

void testADD(){

    testADD1();
    testADD2();

}

void testADD1(){

    char* testID = "ADD1";
    char* input = "ADD R1, R2, R3";
    char* output = (char*) malloc( 17);

    LD(input, output);
    char* expected = "0001001010000011";

    free(output);
    equals(output, expected, testID);

}

void testADD2(){

    char* testID = "LD1";
    char* input = "LD R1, #-3";
    char* output = (char*) malloc( 17);

    LD(input, output);
    char* expected = "0010001111111101";

    free(output);
    equals(output, expected, testID);

}