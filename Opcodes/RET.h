//
// Created by Mikkel Danielsen on 07/05/2020.
//

#ifndef PROJEKT2_RET_H
#define PROJEKT2_RET_H

#endif //PROJEKT2_RET_H

#pragma once
#include "Func.h"

void RET(char* input, char* output){

    //RET

    char* str = "1100000111000000";

    for (int i = 0; i < 16; ++i) {
        output[i] = *(str+i);
    }

}