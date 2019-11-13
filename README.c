#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>
void checkinput (int argc, char *argv[], int *keyP);
void encrypt (char plaintext[],char ciphertext[], int *keyP);

int main (int argc, char *argv[])

{
    char plaintext[200];
    int key = 0;
    int*keyP = &key;
    checkinput(argc, argv, &key);
    
    printf("Enter plaintext: ");//prompt for plaintext
    scanf("%[^\n]s", plaintext);//get plaintext
    
    char ciphertext[strlen(plaintext)];
    ciphertext[strlen(plaintext) + 1] = '\0';

    encrypt(plaintext, ciphertext, &key);//encrypt

    printf("ciphertext: %s", ciphertext);

    return 0;
}




void checkinput (int argc, char *argv[], int *keyP)
{

if (argc == 2) //if user inputs correctly:
    {
        for (int i = 0; i < strlen(argv[1]); i++)
        {
          if (isdigit(argv[1][i]))//if each character is indeed a digit
          {}//do nothing
          else
          {
              printf("Usage: ./caesar key\n");
              exit (1); //if incorrect input, elimate the program immediately.
          }
        }
    }
else
    {
        printf("Usage: ./caesar key\n");
        exit (1); //if incorrect input, elimate the program immediately.

    }

    *keyP = atoi(argv[1]);


    return;
}


void encrypt (char plaintext[],char ciphertext[], int *keyP)
{
     for (int i = 0; plaintext[i] != '\0'; i++)
    {
        if (isalpha(plaintext[i]))//if the ith character of the plaintext, shift it by value of key
        {
            if (isupper(plaintext[i]))
            {//minus 65 because we are trying to work within the 1-26 digits range.
                int temp = plaintext[i] - 65;
                ciphertext[i] = ((temp + *keyP) % 26) + 65;
            }
            else if (islower(plaintext[i]))
            {
                int temp = plaintext[i] - 97;
                ciphertext[i] = ((temp + *keyP) % 26) + 97;
            }
            else
            {
                ciphertext[i] = plaintext[i];
            }
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }
    return ;

}


//problem too many extra characters at the
