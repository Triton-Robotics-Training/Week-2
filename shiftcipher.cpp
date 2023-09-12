#include "mbed.h"

#define MAXIMUM_BUFFER_SIZE     32

static DigitalOut led(LED1);

static char inputString[] = "zestyembeddedmarinarasauce"; //this test string should output aftuzfncfeefenbsjobsbtbvdf

//puts a character into the output buffer
//remember that nothing will show until you print a newline.
void putc(char c){
    printf("%c", c);
}

//returns a number for a corresponding letter 
//a is 0, b is 1, all the way to z is 25
int letterToNumber(char c){ 
    return c - 'a';
}

//returns a letter to the corresponding number
//a is 0, b is 1, all the way to z is 25
char numberToLetter(char i){ 
    return i + 'a';
}

int main(void)
{
    //CODE GOES HERE 
    putc('\n');
}
