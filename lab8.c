#include "lab8.h"

const int MAX = 100;


int menu()
{
  //1. Read a New String 2. Encrypt
//3. Decrypt
//4. Quit
  
  
  
  return 4;
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
{
  return 0;
}// end function


char readDirection()
{
  return 'R';
}// end function


char* encryptString(char* str, int rotAmount, char direction)
{
  return NULL;
}// end function


char getDirection(char* encryptedString)
{
  return 'L';
}// end function


int getRotation(char* encryptedString)
{
  return 0;
}// end function


char* decryptString(char* str, int rotAmount, char direction)
{
  return NULL;
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

