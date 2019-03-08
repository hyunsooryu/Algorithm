#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

/*
def maximizeProfit(nums):
	return 0

def main():
	print(maximizeProfit([1,2,3,4,5,6,7])) # 6
	                      1 1 1 1 1 1 1
						  7 7 7 7 7 7 7
	print(maximizeProfit([7,6,5,4,3,2,1])) # 0
	print(maximizeProfit([1,2,3,4,3,2,1])) # 3
	                      1           1
						    1       2
							  1   3
							    1
								4
	print(maximizeProfit([2,8,19,37,4,5])) # 35
						  2           5
						    2       5
							  2  37
							    2
								37
if __name__ == "__main__":
	main()
*/
int MAX_tmp = 0;
int MIN_tmp = 0;
int MAX_INDEX = 0;
int MIN_INDEX = 0;
int MAX = 0;
const int find_max(vector<int>& A) {
	int size = A.size();
	MAX_tmp = A[0];
	MIN_tmp = A[0];
	for (int i = 1; i < size; i++) {
		if (A[i] > MAX_tmp) {
			MAX_tmp = A[i];
			MAX_INDEX = i;
		}
		if (A[i] < MIN_tmp) {
			MIN_tmp = A[i];
			MIN_INDEX = i;
		}
		if (MAX_INDEX > MIN_INDEX) {
			if (MAX_tmp - MIN_tmp > MAX) {
				MAX = MAX_tmp - MIN_tmp;
			}
		}
	}
	return MAX;
}

int main() {
	vector<int> A = {2,8,19,37,4,5};
	cout << find_max(A) << endl;










	return 0;
}