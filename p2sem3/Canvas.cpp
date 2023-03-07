#include "Canvas.h"
#include <Windows.h>
Canvas::Canvas(int width, int height)
{
	w = width;
	h = height;
    matrix = new char*[h];
	for (int i = 0; i < h; i++)
		matrix[i] = new char[w];
	Clear();
}

void Canvas::Print()
{
	Sleep(200);
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cout << matrix[i][j];
		}
		cout << endl;
	}
}

void Canvas::Clear()
{
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			matrix[i][j] = ' ';
} 

void Canvas::SetPoint(int x, int y, char ch)
{
	if((x>0&&x<w)&&(y<h&&y>0))
	matrix[x][y] = ch;
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	if(left>0&&right<w&&right>left&&top>0&&bottom<h&&top<bottom)
	for (int i = top; i <= bottom; i++)
	{
		for (int j = left; j <= right; j++)
		{
			if (i == top || i == bottom || j == left || j == right)
			{
				matrix[i][j] = ch;
			}
		}
	}
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	if (left > 0 && right<w && right>left && top > 0 && bottom < h && top < bottom)
		for (int i = top; i <= bottom; i++)
		{
			for (int j = left; j <= right; j++)
			{
				if (i != top && i!= bottom && j != left && j != right)
				{
					matrix[i][j] = ch;
				}
			}
		}
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			int dx = j - x;
			int dy = i - y;
			if (dx * dx + dy * dy == ray * ray)
			{
				matrix[i][j] = ch;
			}
		}
	}
}

void Canvas:: FillCircle(int x, int y, int ray, char ch)
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			int dx = j - x;
			int dy = i - y;
			if (dx * dx + dy * dy < ray*ray)
				matrix[i][j] = ch;
		}
	}
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);
	int sx = (x1 < x2) ? 1 : -1;
	int sy = (y1 < y2) ? 1 : -1;
	int err = dx - dy;
	while (true) {
		SetPoint(x1, y1, ch);
		if (x1 == x2 && y1 == y2) {
			break;
		}
		int e2 = 2 * err;
		if (e2 > -dy) {
			err -= dy;
			x1 += sx;
		}
		if (e2 < dx) {
			err += dx;
			y1 += sy;
		}
	}
}
