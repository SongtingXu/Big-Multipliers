#include <iostream>
#include <cstdio>
#include <string.h>
#define MAXLENGTH 256
#define CHARTOINT(x) (x - 48)
#define INTTOCHAR(x) (x + 48)
using namespace std;
int reverseString(char str[], int length){
    for(int i = 0; i < length/2; i++){
        char temp = str[i];
        str[i] = str[length - 1 - i];
        str[length - 1 - i] = temp;
    }
    return 1;
}
int main()
{
    char multiplier1[MAXLENGTH], multiplier2[MAXLENGTH], product[2*MAXLENGTH];
    cout << "Input 2 numbers, both of which are no more than 255 digits:" << endl;
    gets(multiplier1);
    gets(multiplier2);
    int length1 = strlen(multiplier1);
    int length2 = strlen(multiplier2);
    int prolength = length1 + length2;
    //reverse string
    reverseString(multiplier1, length1);
    reverseString(multiplier2, length2);
    //product(i+j) = multiplier1(i) * multiplier2(j);
    int carry = 0;
    for(int s = 0; s < prolength; s++){
        int temp = 0;
        for(int i = 0; i <= s; i++){
            if(i < length1 && (s-i) < length2 ){
                temp += CHARTOINT(multiplier1[i]) * CHARTOINT(multiplier2[s-i]);
            }
        }
        temp += carry;
        carry = temp / 10;
        product[s] = INTTOCHAR(temp % 10);
    }
    product[prolength] = '\0';
    if(product[0] == '0'){
        product[1] = '\0';
    }
    else if(product[prolength - 1] == '0'){
        for(int i = prolength - 2; i >= 0; i--){
            if(product[i] != '0'){
                product[i+1] = '\0';
                break;
            }
        }
    }
    reverseString(product, strlen(product));
    cout << product << endl;

}
