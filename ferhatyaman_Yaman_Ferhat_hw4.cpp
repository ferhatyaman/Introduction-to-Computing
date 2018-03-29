#include<iostream>
#include<string>
using namespace std;

string hiddenMessage(string text, string del); // this is prototype

void TakeOddCharacters(string s, int len, string m) // extract string take odd characters
{
	int i;
	string ExtractedText = "";
	for (i = 0; i <= len; i = i + 2) // in the loop take all odd characters and add all of them
	{
		ExtractedText = ExtractedText + s.substr(i, 1);
	}
	cout << "Extracted String:" << ExtractedText << endl;

	cout << "Hidden Message:"
		<< hiddenMessage(ExtractedText, m) << endl; // call the string function from void
	
}

string hiddenMessage(string text, string del) // delete given characters from extracted text
{
	unsigned int a = del.length();
	for (int i = 0; i < a; i++)
	{
		
		unsigned int location = text.find(del.at(i));
		
		while (location < text.length()) // in while loop, check the find and delete one character
		{
			if (location != string::npos)

			{
				text = text.substr(0, location) + text.substr(location + 1, text.length());
			}

			location = text.find(del.at(i)); // update the location

		}
	}
	return text;
}

int main()
{
	cout << "This program  extracts information from a given scrambled string." << endl; // show the maşn message
	string scrambledText, characterDelete;
	cout << "Scrambled Text:";
	cin >> scrambledText; // take from user scrambled text
	int length = scrambledText.length();
	while (length < 40) // check the lenght of text. it ought to be less than 40
	{
		cout << "Input string must be longer than 40 characters" << endl << "Scrambled Text:";
		cin >> scrambledText; // if is not true ask again and again
		length = scrambledText.length();
	}
	cout << "Characters to be deleted: ";
	cin >> characterDelete;  //take characters which are deleted
	TakeOddCharacters(scrambledText, length, characterDelete); // call the void function from main
	
	
	system("Pause");
	
	return 0;
}