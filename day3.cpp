/*
--- Day 3: Spiral Memory ---

You come across an experimental new kind of memory stored on an infinite two-dimensional grid.

Each square on the grid is allocated in a spiral pattern starting at a location marked 1 and then counting up while spiraling outward. For example, the first few squares are allocated like this:

17  16  15  14  13
18   5   4   3  12
19   6   1   2  11
20   7   8   9  10
21  22  23---> ...
While this is very space-efficient (no squares are skipped), requested data must be carried back to square 1 (the location of the only access port for this memory system) by programs that can only move up, down, left, or right. They always take the shortest path: the Manhattan Distance between the location of the data and square 1.

For example:

Data from square 1 is carried 0 steps, since it's at the access port.
Data from square 12 is carried 3 steps, such as: down, left, left.
Data from square 23 is carried only 2 steps: up twice.
Data from square 1024 must be carried 31 steps.
How many steps are required to carry the data from the square identified in your puzzle input all the way to the access port?

Your puzzle input is 312051.
*/

#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;

int findNearestSquare(int n){
	int root_of_n = sqrt(n);
	int result = floor(root_of_n);
	result = (result % 2 == 0 ? result - 1: result); //coz we want perfect squares of odd numbers
	return result;
}
int main() {
	int num;
	cout << "Enter the number: ";
	cin >> num;
	int nearestsquare = findNearestSquare(num); //number itself and not the nearest square(less than or =)
	int dist = num - nearestsquare*nearestsquare;
	if(dist == 0) 
		cout << 2*(nearestsquare/2) << endl;
	else {
		int grid_dist = (nearestsquare + 2)/2; //distance of the grid from 1(just moving along x axis)
		int block_dist = dist % (nearestsquare + 1); //distance of this block from the block which passes through imaginary y-axis passing through block with value 1
		cout << grid_dist + abs(block_dist - grid_dist) << endl;
	}
	return 0;
}