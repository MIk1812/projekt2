#include <stdio.h>
#ifndef PROJEKT2_STRINGZ_H
#define PROJEKT2_STRINGZ_H

#endif //PROJEKT2_STRINGZ_H

#pragma once
#include "../Functionality/FuncOpcodes.h"

void STRINGZ(LineInfo li, FILE *outputStream, int* lineCount){
    int countchars = 0;
    for (int i = 10 + li.firstIndex; i <li.lineLength ; ++i) {

        if (li.input[i] == '"') {
            break;
        } else{
            countchars++;
            (*lineCount)++;
        }
    }

    for (int k = 0; k < countchars ; ++k) {
        int charIndex = (9 + li.firstIndex+k);

        int pcoff = singleCharToInt(li.input,charIndex);
        writeIntBits(li.output,pcoff, 15, 16);

        fprintf(outputStream, "%s\n", li.output);

    }

    fprintf(outputStream, "%s\n", "0000000000000000");


}

