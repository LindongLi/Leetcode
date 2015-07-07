#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/rectangle-area/

Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

Assume that the total area is never beyond the maximum possible value of int.
*/

class Solution
{
public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
	{
		int AE = max(A, E);
		int BF = max(B, F);
		int CG = min(C, G);
		int DH = min(D, H);
		int result = (C - A) * (D - B) + (G - E) * (H - F);
		if ((AE < CG) && (BF < DH))
		{
			result -= (CG - AE) * (DH - BF);
		}
		return result;
	}
};

/*
idea: straight forward in the figure
complexity: O(1)
*/

int main(void)
{
	Solution engine;
	cout << engine.computeArea(-3, 0, 3, 4, 0, -1, 9, 2) << '\n';
	return 0;
}