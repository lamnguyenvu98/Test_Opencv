#include <Eigen/Dense>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <string>

//using namespace Eigen;
using namespace std;

int main()
{
	ifstream fs;
	fs.open("matrix.csv");
	string line, word;
	int rownum = 0;
	vector<double> matrixEntries;
	while (!fs.eof())
	{
		fs >> line;
		stringstream ss(line);
		while (getline(ss, word, ','))
		{
			matrixEntries.push_back(stod(word));
		}
		rownum++;
	}
	MatrixXd copiedMatrix = Eigen::Map<Matrix<double, Dynamic, Dynamic, RowMajor>>(matrixEntries.data(), rownum, matrixEntries.size() / rownum);
	cout << copiedMatrix << endl;
	return 0;

}