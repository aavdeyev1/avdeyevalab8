#include "lab8.h"



int main(void)
{
  char direction;
  int choice, rotAmount;
  char *origString=NULL, *encryptedString=NULL, *decryptedString=NULL;

  origString = readString();
  printf("The original string is %s\n", origString);
  
  rotAmount = readAmountToShift();
  direction = readDirection();
  encryptedString = encryptString(origString, rotAmount, direction);
  printf("The encrypted string is %s\n", encryptedString);
  


  do
  {
    choice = menu();
    switch(choice)
    {
      case 1: cleanUp(origString);
              origString = readString();
              printf("The original string is %s\n", origString);
              break;
          
      case 2: cleanUp(encryptedString);
              rotAmount = readAmountToShift();
              direction = readDirection();
              encryptedString = encryptString(origString, rotAmount, direction);
              printf("The encrypted string is %s\n", encryptedString);
              break;

      case 3: cleanUp(decryptedString);
              rotAmount = getRotation(encryptedString);
              direction = getDirection(encryptedString);
              decryptedString = decryptString(encryptedString, rotAmount, direction);
              printf("The decrypted string is %s\n", decryptedString);
              break;

      case 4: printf("Quitting Program!\n");
  
    }


  }while(choice != 4);

  cleanUp(origString);
  origString= NULL;
  cleanUp(encryptedString);
  encryptedString=NULL;
  cleanUp(decryptedString);
  decryptedString=NULL;

  return 0;
}