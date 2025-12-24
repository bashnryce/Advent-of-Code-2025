/* Psuedo Code

given a line of numbers make the largest two digit number possible
the first number picked is the tens place and the second must come after the first in the line

example: 818181911112111 -> 92

get line
	for length of string
		if(line[i] > tens_max) 
			tens_max = line[i]
			tens_max_index = i
	for tens_max_index to length	
		if(line[i] > ones_max) 
			ones_max = line[i]
	max = tens_max + ones_max
	total += stoi(max)
	
print total

*/



#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	
	ifstream File("puzzleInput3.txt");
	string lineStr;
	int length; 
	int tensMaxIndex = 0;
	char tensMaxChar = '0';
	char onesMaxChar = '0';
	
	string Max;
	int total = 0;
	int lineNum = 0;
	
	while(getline(File, lineStr)) {
		length = lineStr.length();
		tensMaxChar = '0';
		onesMaxChar = '0';
		
		for (int i = 0; i < length-2; i++) {
			
			if(lineStr[i] > tensMaxChar) {
				tensMaxChar = lineStr[i];
				tensMaxIndex = i;				
			}	
		}
		for (int j = tensMaxIndex + 1; j < length; j++) {
			
			if(lineStr[j] > onesMaxChar) {
				onesMaxChar = lineStr[j];
			}	
		}
		
		Max = string() + tensMaxChar + onesMaxChar;
		
		cout << "Num: " << lineNum << endl;
		cout << "line: " << lineStr << endl;
		cout << "tens: " << tensMaxChar << endl;
		cout << "ones: " << onesMaxChar <<endl;
		cout << "Max: " << Max << endl << endl;
		total += stoi(Max);
		Max = string();
		lineNum++;

	}
	
	cout << "Total: " << total << "   <-----------------" << endl << endl;

return 0;
}