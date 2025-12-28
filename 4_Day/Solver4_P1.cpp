/*Pseudo Code and Description

given a grid of @ and . chars find all the @ chars that have less than 4 @ surrounding them
total the amount of @'s that meet the criteria

Example:  (x's are @ chars that meet the criteria) 
..xx.xx@x.
x@@.@.@.@@
@@@@@.x.@@
@.@@@@..@.
x@.@@@@.@x
.@@@@@@@.@
.@.@.@.@@@
x.@@@.@@@@
.@@@@@@@@.
x.x.@@@.x.
Total: 13

Get array from file and load into array of strings (aka 2d array of chars)
run over the array and save it as 1 for @ and 0 for . in a new array

for each row
	for each column
		general case:
			if(array[row][col] = 1)
				surrounding = array[row+1][col+1] + array[row][col+1] + array[row][col-1] + array[row+1][col] + array[row-1][col]
					+ array[row-1][col-1] + array[row+1][col-1] + array[row-1][col+1]
				if surround < 4
					total++;
		
		cases:
			corner 	(row == 1 or max && column == 1 or max)
			edge	(row == 1 or max && column != 1 or max)
			middle 	(row != 1 or max && column != 1 or max)

*/



#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {

	ifstream File("puzzleInput4.txt");
	string lineStr;
	
	int length;
	int rowCount = 1;
	
	vector<vector<int>> grid;
	
	//convert the file to a 2D vector of 1's and 0's
	grid.push_back(vector<int>());
	
	while(getline(File, lineStr)) {
		
		grid.push_back(vector<int>()); //add a new row
		
		//if(rowCount != 0) {
			
			length = lineStr.length();
		
			grid[rowCount].push_back(0);
			
			for(int i = 0; i < length; i++) {
			
				if(lineStr[i] == '@') {
					grid[rowCount].push_back(1);
				}
				else if(lineStr[i] == '.') {
					grid[rowCount].push_back(0);
				}
			
			}
		
			grid[rowCount].push_back(0);
			
		//}
		
		rowCount++;	
		
	}
	
	//pad top and bottom with zeros
	
	grid.push_back(vector<int>());
	
	int rowSize = grid.size();
	int colSize = grid[1].size();
	
	for(int i = 0; i < colSize; i++) { //for each column
		
		grid[0].push_back(0);          //pad zeros on first row
		grid[rowSize-1].push_back(0);  //pad zeros on last row
		
	}
	
	
	//print the grid of numbers
	
	for(int j = 0; j < rowSize; j++) {
		
		for(int k = 0; k < colSize; k++) {
			
			cout << grid[j][k];
			
		}
		cout << endl;
		
	}
	
	
	//working loop to find all spots that match the condition
	int surrounding = 0;
	int total = 0;
	
	for(int j = 1; j < rowSize-1; j++) {
		for(int k = 1; k < colSize-1; k++) {
			
			//for each char in grid
			
			if(grid[j][k] == 1) { //if we are at an @ char
				
				//loop over each char surrounding the current one and add them together in surrounding
				for(int x = -1; x <= 1; x++) { 
					for(int y = -1; y <= 1; y++) {
					
							surrounding += grid[j+x][k+y];		

					}
				}
				surrounding--;		// -1 to exclude the current position (we only want the surrounding)
				if(surrounding < 4) {
					total++;
				}
				
			}
			
			surrounding = 0; //reset value after each element
			
		}		
	}
	
	cout << "Total: " << total << endl << endl;

	File.close();
	return 0;
	
}
