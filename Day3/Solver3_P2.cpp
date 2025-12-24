/* Description

given a line of numbers make the largest 12 digit number possible
picking digits from left to right

example: 818181911112111 -> 888911112111

*/

#include <iostream>
#include <fstream>
#include <string>

#define DIGITS 12

using namespace std;

int main() {

	ifstream File("puzzleInput3.txt");
	string lineStr;
	int length; 
	int MaxIndex = -1;
	
	string MaxStr = string();
	long total = 0;
	char MaxChar;
	
	int start;
	int end;
	
	while(getline(File, lineStr)) {
		
		length = lineStr.length();
		MaxIndex = -1;
		
		for(int i = DIGITS; i > 0; i--) { //for each digit of the result
			
			start = MaxIndex + 1;
			end = length - (i+1);		//+1 because of the \r char (would be better to trim data)
			
			MaxChar = lineStr[start];	//assume max is first char in valid range
			MaxIndex = start;			//update max Index to match assumption (in case it is right)
			
			for (int j = start; j <= end; j++) { //walk the line and find max value in valid range
				
				if(lineStr[j] > MaxChar) {
					MaxChar = lineStr[j];
					MaxIndex = j;
					//cout << "MaxChar found: " << MaxChar << endl;
				}	
			}
			
			MaxStr += MaxChar;	//append the found maxchar 		
				
		}
		cout << "line: " << lineStr << endl;
		cout << "Max: " << MaxStr << endl << endl;
		
		total += stol(MaxStr);
		MaxStr = string();
	}
	
	cout << "Total: " << total << "   <-----------------" << endl << endl;

	return 0;
}