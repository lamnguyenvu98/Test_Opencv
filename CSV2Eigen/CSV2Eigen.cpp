#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <Eigen/Dense>
using namespace std;
using namespace Eigen;

int main()
{
	ifstream fs("matrix.csv");
	string line, word;
	int rowCount = 0, rowIdx = 0;
	while (getline(fs, line)) {
		rowCount++;
	}
	vector<string> myvec[3];
	vector<double> mydata;
	fs.clear();
	fs.seekg(fs.beg);
	while (getline(fs, line))
	{
		stringstream ss(line);
		string value;
		while (getline(ss, value, ','))
		{
			myvec[rowIdx].push_back(value);
		}
		rowIdx++;
	}
	fs.close();
	int colNum = 0;
	int rownum = 0;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 1; j < 4; j++)
		{
			mydata.push_back(stod(myvec[i][j]));
		}
		rownum++;
		//cout << myvec[i][colNum] << " ";
	}
	MatrixXd copiedMatrix = Eigen::Map<Matrix<double, Dynamic, Dynamic, RowMajor>>(mydata.data(), rownum, mydata.size() / rownum);
	cout << copiedMatrix << endl;
	return 0;
}