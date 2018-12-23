#include<iostream>
using namespace std;
 
char Xor(char a, char b) 
{ 
	return (a == b)? '0': '1'; 
}
 
char invert(char c) 
{ 
	return (c == '0')? '1': '0'; 
}
 
string binarytoGray(string binary)
{
    string gray = binary[0];
    for (int i = 1; i < binary.length(); i++)
    {
        gray += Xor(binary[i - 1], binary[i]);
    }
    return gray;
}
 
string graytoBinary(string gray)
{
    string binary = gray[0];
    for (int i = 1; i < gray.length(); i++)
    {
        if (gray[i] == '0')
            binary += binary[i - 1];
        else
            binary += invert(binary[i - 1]);
    }
    return binary;
}
 
int main()
{
    string binary = "01001";
    cout << "Gray code of " << binary << " is " << binarytoGray(binary) << endl;
 
    string gray = "01101";
    cout << "Binary code of " << gray << " is " << graytoBinary(gray) << endl;
    
	return 0;
}
