#include "lab8.h"
#include <ctype.h>
#include <string.h>
#include <stdio.h>
const int MAX = 100;

//abc defghijklmnopqrstuvwx yz

int menu()
{
  int choice;

    do
    {
        printf("\nMenu:\n1. Read a New String\n2. Encrypt\n3. Decrypt\n4. Quit\nChoose: ");
        scanf("%d", &choice);

        if(choice < 1 || choice > 4)
            printf("\nYou entered an invalid menu choice.");

    }while(choice < 1 || choice > 4);
  
  while(fgetc(stdin) != '\n'){}

  return choice;
}// end function


char* readString()
{
    char * str, pre_str[MAX]; 
    printf("Enter a String: ");
    fgets(pre_str, MAX, stdin);
    stripCarriageReturn(pre_str);

    str = (char *) calloc(strlen(pre_str) + 1, sizeof(char)); 
    strcpy(str, pre_str);

  return str;
}// end function


int readAmountToShift()
{//doesnt work with some numbers 5000000000 == 705032704??
    int shift = 0;

    do
    {
    if(shift < 0 || shift > 2000000000)
        printf("error: Number must be between 0 and 2 bill\n");
    printf("Enter amount to shift: ");
    scanf("%d", &shift);
    }while(shift < 0 || shift > 2000000000);

    while(fgetc(stdin) != '\n'){}

  return shift;
}// end function


char readDirection()
{
    char LorR = 'L';

    do
    {
    if(LorR != 'L' && LorR != 'R')
        printf("error: direction must be L or R\n");
    printf("Enter direction L or R: ");
    scanf("%c", &LorR);
    LorR = toupper(LorR);
    }while(LorR != 'L' && LorR != 'R');

    while(fgetc(stdin) != '\n'){}

  return LorR;
}// end function


char* encryptString(char* str, int rotAmount, char direction)
{
  char * encryptstr = NULL;
  int rot = rotAmount % 26;
  encryptstr = (char *) calloc(strlen(str) + 3, sizeof(char)); 
  encryptstr[0] = toupper((char) (rot + 97));
  encryptstr[1] = direction;
  strncpy((encryptstr + 2), str, strlen(str));

  if(direction == 'R')
      rot = (-1) * rot;

  for(int i = 0; i < strlen(str); i++)
  {
    if(str[i] >= 'a' && str[i] <= 'z')
    {
        if(str[i] + rot < 97) // if R overflow
            encryptstr[i + 2] = str[i] + 26 + rot;
            
        else if(str[i] + rot > 122) // if L overflow
            encryptstr[i + 2] = str[i] - 26 + rot;
                
        else
            encryptstr[i + 2] = str[i] + rot;
    }
    
  }

  return encryptstr;
}// end function


char getDirection(char* encryptedString)
{
    char dir;
    dir = encryptedString[1];
  return dir;
}// end function


int getRotation(char* encryptedString)
{
    int rot;
    rot = (int) encryptedString[0] - 65;
  return rot;
}// end function


char* decryptString(char* str, int rotAmount, char direction)
{
    char * decryptstr = NULL, *temp = NULL, *sub=NULL;
    int x;
    sub = strdup(str+2);
  
    if(direction == 'L')
        direction = 'R';
    else
        direction = 'L';

    decryptstr = encryptString(sub, rotAmount, direction);
    temp = (char *) calloc(strlen(decryptstr) - 1, sizeof(char));
    for(x = 0; x < strlen(sub); x++) 
        temp[x] = decryptstr[x + 2];
    //copy the new encrypt str into sub, past 2 bits
    free(decryptstr);
    free(sub);
  return temp;
}// end function






void cleanUp(char* str)
{
  free(str);
  str = NULL;
}// end function


void stripCarriageReturn(char* str)
{
  int len = strlen(str);
  int x = 0;

  while(str[x] != '\0' && x < len)
  {
    if(str[x] == '\r')
      str[x] = '\0';

    else if(str[x] == '\n')
      str[x] = '\0';
    x++;
  }// end while
}// end function

