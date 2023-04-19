// Name: ±iµq¶v (B11030202@mail.ntust.edu.tw)
// Date: April 19, 2023
// Last Update: April 19, 2023
// Problem statement: Shisensho

#include "Point.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

enum class direction :int { UP, DOWN, RIGHT, LEFT };

// Mapping direction to point which used to move "one block"
Point mapDirection(direction dir)
{
    switch (dir)
    {
    case direction::UP:
        return Point(0, -1);
    case direction::DOWN:
        return Point(0, 1);
    case direction::RIGHT:
        return Point(1, 0);
    case direction::LEFT:
        return Point(-1, 0);
    }
}

// Reset the path that already had been walked
void resetGraph(vector<vector<int>>& graph)
{
    for (auto& v : graph)
        for (auto& i : v)
            if (i == -1)
                i = 0;
}

bool dfs(vector<vector<int>>& graph, Point now, const Point& end, direction nowFace, int turnTimes)
{
    vector<direction> dirs = { direction::UP, direction::DOWN, direction::RIGHT, direction::LEFT };
    for (const auto& d : dirs)
    {
        Point temp = now + mapDirection(d);
        // Handle direction limit
        int turnTemp = (int)(d != nowFace) + turnTimes;

        // Reach end
        if (temp == end)
        {
            resetGraph(graph);
            if (turnTemp <= 2)
                return true;
            else
                return false;
        }

        // Not reach end
        if (temp.inRange(8) && graph[temp._y][temp._x] == 0 && turnTemp <= 2)
        {
            graph[temp._y][temp._x] = -1;

            // If next step can reach end then this step can as well
            if (dfs(graph, temp, end, d, turnTemp))
            {
                resetGraph(graph);
                return true;
            }
        }
    }
    resetGraph(graph);
    return false;
}

// true: error | false: no problem
bool foolproofInput(const vector<vector<int>>& graph, const Point& start, const Point& end)
{
    if (!start.inRange(7) || !end.inRange(7))
        return true;

    if (start == end)
        return true;

    int startNum = graph[start._y][start._x], endNum = graph[end._y][end._x];

    if (startNum != endNum)
        return true;

    if (startNum == 0 || endNum == 0)
        return true;

    return false;
}

int main()
{
    vector<vector<int>> graph(8, vector<int>(8, 0));

    for (int i = 1; i < 7; i++)
    {
        for (int j = 1; j < 7; j++)
            cin >> graph[i][j];
    }

    for (Point start, end; cin >> start >> end;)
    {
        if (foolproofInput(graph, start, end))
        {
            cout << "bad pair" << endl;
            continue;
        }

        // Start from every direction
        bool flag = false;
        vector<direction> dirs = { direction::UP, direction::DOWN, direction::RIGHT, direction::LEFT };
        for (const auto& d : dirs)
        {
            Point temp = start + mapDirection(d);
            if (graph[temp._y][temp._x] == 0)
            {
                graph[temp._y][temp._x] = -1;
                if (dfs(graph, temp, end, d, 0))
                    flag = true;
            }
            else if (temp == end)
                flag = true;
        }

        if (flag)
        {
            // Clear matched number
            graph[start._y][start._x] = 0;
            graph[end._y][end._x] = 0;
            cout << "pair matched" << endl;
        }
        else
            cout << "bad pair" << endl;
    }

    return 0;
}