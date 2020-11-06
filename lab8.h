#ifndef LAB8_H
#define LAB8_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menu();
char* readString();
int readAmountToShift();
char readDirection();
char* encryptString(char* str, int rotAmount, char direction);
char getDirection(char* encryptedString);
int getRotation(char* encryptedString);
char* decryptString(char* str, int rotAmount, char direction);

// Stu provided these two functions below
void cleanUp(char* str);
void stripCarriageReturn(char* str);


#endif