#include <stdio.h>
#include <stdbool.h>

void takeInput(char input[]);
void LD(char input[]);
void BRnzp(char input[]);
void ST(char input[]);
int length = 0;


void bin(char n);

int main() {
    int exit = 0;
    while(exit == 0){

        char input[30];

        //By giving the address of input, we can let takeInput modify it
        takeInput(input);

        //Sum the ASCII values of the opcode's characters
        int sum = 0;
        for (int i = 0; i < 30; ++i) {

            //Until first blank space
            if(input[i] == ' ')
                break;
            length++;
            sum = sum + input[i];
        }
        printf("%d", length);

        //Identify opcode
        switch(sum){

            //LD
            case 144:
                LD(input);
                break;

            //ADD
            case 201:
                break;

            //NOT
            case 241:
                break;

            //BR
            case 148:
                break;

            //LDR
            case 226:
                break;

            //ST
            case 167:
                break;

        }
        length = 0;

        exit = 1;

    }

}

void LD(char input[]){

    int bits[16] = {0,0,1,0};

    char reg = input[4];

    //Reset ASCII value. Upcasts reg to int
    reg = reg - 48;

    printf("%d\n", reg);

    //Update destination bits according to register
    if((reg & 1) > 0)
        bits[6] = 1;
    if((reg & 2) > 0)
        bits[5] = 1;
    if((reg & 4) > 0)
        bits[4] = 1;


    
    for (int i = 0; i < 16; ++i) {
        printf("%d", bits[i]);
    }


}

void BRnzp(char input[]){

    int bits[16]={0,0,0,0,1,1,1};
    for (int i = 0; i < 16; ++i) {

    }

}
void ST(char input[]){
    int bits[4]={0,0,1,1};
    for (int i = 0; i < 4; ++i) {
        printf("%d", bits[i]);
    }
    int SR_bits[3]={0,0,0};
    int SR_reg = input[5];
    SR_reg = SR_reg - 48; //reset ASCII value
    // convert SR value to binary





}



//https://www.geeksforgeeks.org/binary-representation-of-a-given-number/
void bin(char n){
    /* step 1 */
    if (n > 1)
        bin(n/2);

    /* step 2 */
    printf("%d", n % 2);
}


void takeInput(char input[]){

    //Space for 29 characters. Scanf reads until \n
    scanf("%29[^\n]s", input);

    //Clears line (\n)
    scanf("%*c");

}












