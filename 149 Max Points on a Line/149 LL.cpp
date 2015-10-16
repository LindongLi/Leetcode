#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;
struct Point
{
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

/*
https://leetcode.com/problems/max-points-on-a-line/

Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
*/

class Solution
{
public:
	int maxPoints(vector<Point>& points)
	{
		int result = 0;
		unordered_map<float, int> map;
		for (int i = 0; (i + result) < points.size(); ++i)
		{
			map.clear();
			int answer = 1, vertical = 1, repeat = 0;
			for (int j = i + 1; j < points.size(); ++j)
			{
				float k = points[j].x - points[i].x;
				if (k == 0.f)
				{
					if (points[j].y != points[i].y)
					{
						++vertical;
					}
					else ++repeat;
				}
				else
				{
					k = (points[j].y - points[i].y) / k;
					if (map.find(k) != map.end())
					{
						++map[k];
						answer = max(answer, map[k]);
					}
					else
					{
						map[k] = 2;
						answer = max(answer, 2);
					}
				}
			}
			answer = max(answer, vertical);
			result = max(result, answer + repeat);
		}
		return result;
	}
};

/*
idea: check every two points, record slope
complexity: Time O(N)
*/

int main(void)
{
	vector<Point> points;
	points.push_back(Point(0, 0));
	points.push_back(Point(0, 1));
	Solution engine;
	cout << engine.maxPoints(points) << '\n';
	return 0;
}