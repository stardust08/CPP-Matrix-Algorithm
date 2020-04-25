#include <iostream>
#include <math.h>

void draw(int**, int);

int** matrix(int **mt, int size)
{
	int nMatrixSize = (int) pow(size, 2);
	int **nMatrix = new int * [nMatrixSize];

	for(int y = 0; y < nMatrixSize; y++)
		nMatrix[y] = new int[nMatrixSize];
	
	int nX, nY;
	nX = nY = 0;

	for(int y = 0; y < size; y++)
	{
		nY = y * size;

		for(int x = 0; x < size; x++)
		{
			nX = x * size;
			
			for(int yy = 0; yy < size; yy++)
				for(int xx = 0; xx < size; xx++)
					nMatrix[nY + yy][nX + xx] = (mt[y][x] == 0 ? 0 : mt[yy][xx]);
		}
	}		

	return nMatrix;
}

void draw(int **matrix, int size)
{
	for(int y = 0; y < size; y++)
	{
		for(int x = 0; x < size; x++)
		{
			std::cout << matrix[y][x] << " ";
		
			if((x + 1) % (int) sqrt(size) == 0)
				std::cout << " ";
		}	

		std::cout << std::endl;

		if((y + 1) % (int) sqrt(size) == 0)
			std::cout << std::endl;
	}

	std::cout << std::endl;
}

void loop(int **mt, int currentSize)
{
	char o;		
	std::cout << "q for quiting, c for continuing: ";
	std::cin >> o;
	std::cout << std::endl;

	if(o == 'q')
		return;		

	int **nMatrix = matrix(mt, currentSize);
	currentSize = (int) pow(currentSize, 2);

	draw(nMatrix, currentSize);
	loop(nMatrix, currentSize);
}

int main(int argc, char **argv)
{
	system("clear || cls");

	int **mt = new int * [2];
	
	mt[0] = new int[2]{ atoi(argv[1]), atoi(argv[2]) };
	mt[1] = new int[2]{ atoi(argv[3]), atoi(argv[4]) };

	draw(mt, 2);
	loop(mt, 2);

	return 0;
}


