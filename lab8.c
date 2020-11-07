#include "lab8.h"
#include <ctype.h>
const int MAX = 100;


int menu()
{
  int choice;

    do
    {
        printf("\nMenu:\n1. Read a New String\n2. Encrypt\n3. Decrypt\n4) Quit\nChoose: ");
        scanf("%d", &choice);

        if(choice < 1 || choice > 4)
            printf("\nYou entered an invalid menu choice.");

    }while(choice < 1 || choice > 4);
  
  return choice;
}// end function


char* readString()
{
    char * str, pre_str[MAX]; 
    printf("Enter a String: ");
    fgets(pre_str, MAX, stdin);
    //for(int x = 0; x < strlen(str); x++)
        //printf("pre_str: %c", pre_str[x]);
    printf("%s", pre_str);
    stripCarriageReturn(pre_str);

    str = (char *) calloc(strlen(pre_str) + 1, sizeof(char)); 
    strcpy(str, pre_str);

  return str;
}// end function


int readAmountToShift()
{
    int shift;
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
    char LorR;
    printf("Enter direction L or R: ");
    scanf("%c", &LorR);
    LorR = toupper(LorR);
    while(fgetc(stdin) != '\n'){}
  return LorR;
}// end function


char* encryptString(char* str, int rotAmount, char direction)
{
  char * encryptstr = NULL;
  int rot = rotAmount % 26;
  encryptstr = (char *) calloc(strlen(str), sizeof(char)); 
  strcpy(encryptstr, str);
  if(direction == 'R')
    rot = (-1) * rot;

  for(int i = 0; i < strlen(str); i++)
  {
    if(str[i] >= 'a' && str[i] <= 'z')
    {
        if(str[i] + rot < 97) // if R overflow
            encryptstr[i] = str[i] + 26 + rot;
            
        else if(str[i] + rot > 122) // if L overflow
            encryptstr[i] = str[i] - 26 + rot;
                
        else
            encryptstr[i] = str[i] + rot;
    }
    
  }
  
  

  return encryptstr;
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

