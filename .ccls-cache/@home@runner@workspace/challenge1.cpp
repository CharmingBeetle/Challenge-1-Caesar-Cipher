#include <cmath>
#include <iostream>
#include <string>

// Declare variables
std::string userMessage;
int shiftValue;
char newChar;
std::string newMessage = "";

// Function to take message from user

void myInput(std::string userMessage, int shiftValue) 
{
  std::cout << "\033[96m" << "***NINA'S SUPER CYBER CIPHER PROGRAM***"<< "\033[0m" <<          std::endl;

  std::cout <<""<< std::endl;//line space

  std::cout << "\033[90m" "Enter your secret message: ";
  std::getline(std::cin, userMessage); //getline() accepts a full line of text while cin considers a space as a terminator and can only take in a single word

  std::cout << "Enter the shift value: "<< "\033[0m";
  std::cin >> shiftValue;
  std::cout <<""<< std::endl;


  //for loop to iterate through each element in the string up to the length 
  for (int i = 0; i < userMessage.length(); i++) {
    char messageChar = userMessage[i]; //new variable to represent the value of the element in the string

    //Uppercase letters
    if (messageChar >= 65 && messageChar <= 90) {
      newChar = (((messageChar - 65) + shiftValue) % 26) + 65; // subtract 'a' to give position in the alpha and add the shift value; modulo rep max length of alpha 0-25 >> determines if position is in alpha; add 65 ("a") to turn back into ASCII; ensures newChar loops back around to a (as there will never be a remainder)
      newMessage += newChar; // The empty string is populated with the new ASCII character

    } // Lowercase letters
      else if (messageChar >= 97 && messageChar <= 122) {
      newChar = ((messageChar - 97) + shiftValue) % 26 + 97;
      newMessage += newChar; 
    } 
        // if not a letter, keep the character the same. 
    else if ((messageChar >= 0 && messageChar <=64) || (messageChar >= 91 &&                   messageChar <= 96) || (messageChar >= 123 && messageChar <=127))
      {    
    newMessage += messageChar; 
      } 
  }
    std::cout << "\033[35m" << "🖋  User message: " << userMessage << "\033[0m" << std::endl;
    std::cout << "\033[31m" << "🔑 Shift value: " << shiftValue << "\033[0m" << std::endl;
    std::cout <<""<< std::endl;
    std::cout <<"\033[93m" << "🔒 Encrypted message: " << newMessage << std::endl;

}
int main() {
  myInput(userMessage, shiftValue);
  return 0;
  }

