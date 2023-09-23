#include <iostream>
#include <math.h>

using namespace std;

// This Program returns the reverse of number
int rev_int(int number)
{
    int reversed_num = 0;
    int last_digit = 0;

    while (number > 0)
    {
    last_digit = number % 10;
    reversed_num = (reversed_num * 10) + last_digit;
    number = number / 10;
    }
    return reversed_num;
}

//Palindrome will occure if number and the reversed number are same
bool palindrome(int number)
{
    if (number == rev_int(number))
    {
        return true;
    }
    return false;
}

int main()
{

    // int number = 1234321;
    // bool condition = palindrome(number);

    // if (condition)
    // {
    //     cout<<"This is a Palindrome"<<endl;
    // }

    // else
    // {
    //     cout<<"This isn't a Palindrome"<<endl;
    // }

    return 0;
}