#include <bits/stdc++.h>
using namespace std;
bool ValidPixel(int arr[8][8],int rows,int cols,int x_Co_ordinate,int y_Co_ordinate,int Previous_Color,int New_Color)
{
	if(x_Co_ordinate < 0 || x_Co_ordinate >= rows || y_Co_ordinate < 0 || y_Co_ordinate >= cols || arr[x_Co_ordinate][y_Co_ordinate] != Previous_Color
	|| arr[x_Co_ordinate][y_Co_ordinate]== New_Color)
		return false;
	return true;
}
void function_of_FloodFill_Algo(int arr[][8], int rows, int cols, int x_Co_ordinate , int y_Co_ordinate, int Previous_Color, int New_Color)
{
	vector<pair<int,int>> queue;

	pair<int,int> push(x_Co_ordinate,y_Co_ordinate);
	queue.push_back(push);

	arr[x_Co_ordinate][y_Co_ordinate] = New_Color;

	while(queue.size() > 0)
	{

		pair<int,int> current_Pixel = queue[queue.size() - 1];
		queue.pop_back();

		int Position_of_X = current_Pixel.first;
		int Position_of_Y = current_Pixel.second;

		if(ValidPixel(arr, rows, cols, Position_of_X + 1, Position_of_Y, Previous_Color, New_Color))
		{
			arr[Position_of_X + 1][Position_of_Y] = New_Color;
			push.first = Position_of_X + 1;
			push.second = Position_of_Y;
			queue.push_back(push);
		}
		if(ValidPixel(arr, rows, cols, Position_of_X-1, Position_of_Y, Previous_Color, New_Color))
		{
			arr[Position_of_X-1][Position_of_Y]= New_Color;
			push.first = Position_of_X-1;
			push.second = Position_of_Y;
			queue.push_back(push);
		}

		if(ValidPixel(arr, rows, cols, Position_of_X, Position_of_Y + 1, Previous_Color, New_Color))
		{
			arr[Position_of_X][Position_of_Y + 1]= New_Color;
			push.first = Position_of_X;
			push.second = Position_of_Y + 1;
			queue.push_back(push);
		}

		if(ValidPixel(arr, rows, cols, Position_of_X, Position_of_Y-1, Previous_Color, New_Color))
		{
			arr[Position_of_X][Position_of_Y-1]= New_Color;
			push.first = Position_of_X;
			push.second = Position_of_Y-1;
			queue.push_back(push);
		}
	}
}
int main()
{
	int arr[8][8] ={
	{1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 0, 0},
	{1, 0, 0, 1, 1, 0, 1, 1},
	{1, 7, 7, 7, 7, 0, 1, 0},
	{1, 1, 1, 7, 7, 0, 1, 0},
	{1, 1, 1, 7, 7, 7, 7, 0},
	{1, 1, 1, 1, 1, 7, 1, 1},
	{1, 1, 1, 1, 7, 7, 1, 1}};

    int rows = 8;
	int cols= 8;
	int x_Co_ordinate= 4;
	int y_Co_ordinate = 4;
	int Previous_Color = arr[x_Co_ordinate][y_Co_ordinate];
	int New_Color = 5;
	function_of_FloodFill_Algo(arr, rows, cols,x_Co_ordinate, y_Co_ordinate, Previous_Color,New_Color);
	for(int k = 0; k < rows; k++)
	{
		for(int l = 0; l < cols; l++)
		{
			cout << arr[k][l] << " ";
		}
		cout << endl;
	}

	return 0;
}

