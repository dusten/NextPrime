/*********************************
 * Find the next prime in C.
 *
 * To Compile `gcc prime.c -lm`
 *
 * writen by https://github.com/dusten
 *
 *********************************/

#include <stdio.h>
#include <stdbool.h>
#include <tgmath.h>

bool isEven(int IsEven)	// Simple test to return true of false if the number under test is even
{
  if(IsEven&1)		// Bitwise AND on the fisrt bit to see if it's set as to have an odd number it must be set
    return false;
  else
    return true;
}

bool isPrime(int IsPrime)		// Main test for prime number return a true or false if prime or not
{
  int i;				// Used for for loop as the test value
  int TestResults = -1;
  int MaxTest = ceill(sqrt(IsPrime));	// Max number to test to which is the Celling of the SquareRoot of the number under test

  for(i=3; i<MaxTest; i++)		// Main Loop
  {
    if(isEven(i))			// We don't need to test any of the even numbers as they all reduce to 2
      continue;

    TestResults = IsPrime % i;		// Number under test divided by the test value

    if(TestResults == 0)		// if you have a remainder that is 0 that means you found something that has dvided evenly into the number under test
      return false;      		// Return that it's not prime
  }
  return true;				// If you have made it out of the loop that means there is nothing that can devide into the number under test and it must be prime
}

main()
{
  int 	InputNumber = -1;	//This is the number given and the goal is to find the next prime number
  int	Result = -1;		//This is where to store the result, should be change to something lager then an int
  bool	IsPrime = false; 	// Used to controll the while search for the next prime

  printf("\n\n Where do you want to start your Prime Search:");
  scanf("%d", &InputNumber);

  /* Preform Basic Checks: Positive Whole Number */
  if(InputNumber < 0)
  {
    printf("\n The entered value was not a positive number.\n\n\n");
    return 0;
  }

  /* Preform Check: If 0 1 2 3 as they are special cases.*/
  switch (InputNumber)
  {
    case 0:
    {
      Result = 1;
      break;
    }
    case 1:
    {
      Result = 2;
      break; 
    }
    case 2:
    {
      Result = 3; 
      break;
    }
    case 3:
    {
      Result = 5; 
      break;
    }
    default:
    {
      Result = InputNumber;
      while(!IsPrime)                   // Master While loop to test the next number if it's prime
      {
        Result++;                               // Add 1 to the input number and keep adding 1 until you find a prime number

        if(isEven(Result))                      // We don't need the even numbers so skip them
          continue;
    
        IsPrime = isPrime(Result);              // Test to see if the number is prime.
      }
    }
  }

  printf("\n\n Next Prime Number is:%d\n\n",Result);
}
