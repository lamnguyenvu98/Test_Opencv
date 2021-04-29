#include <iostream>
#include <opencv2/opencv.hpp>
#include <cmath>

using namespace std;
using namespace cv;

void Chuyen_Doi_Gamma(Mat& out, double gamma, double c)
{
    for (int row=0; row < out.rows; row++)
    {   
        uchar* ptrRow = out.ptr<uchar>(row);
        for (int col=0; col < out.cols; col++)
        {
            //ptrRow[col] = 255 - ptrRow[col];
            ptrRow[col] = c * pow(ptrRow[col], gamma);
        }
    }
}

void Dao_Anh(Mat& out)
{
    for (int row=0; row < out.rows; row++)
    {   
        uchar* ptrRow = out.ptr<uchar>(row);
        for (int col=0; col < out.cols; col++)
        {
            ptrRow[col] = 255 - ptrRow[col];
        }
    }
}

void Chuyen_Doi_Logarit(Mat& out, float c)
{
    for (int row=0; row < out.rows; row++)
    {   
        uchar* ptrRow = out.ptr<uchar>(row);
        for (int col=0; col < out.cols; col++)
        {
            ptrRow[col] = c * log(1 + ptrRow[col]);
        }
    }
}



int main(int, char** argv)
{
    Mat src = imread(argv[1]);
    int gamma = 0, c = 0;
    float ratio = 500.0 / src.size().width;
    resize(src, src, Size(500, (int)(ratio * src.size().height)));
    //src.copyTo(result);
    cvtColor(src, src, COLOR_BGR2GRAY);
    threshold(src, src, 100, 255, THRESH_BINARY_INV);
    Chuyen_Doi_Gamma(src, 0.8, 1);
    //Chuyen_Doi_Gamma(src, 0.9, 1);
    //Chuyen_Doi_Logarit(src, 0.2);
    imshow("Result", src);
    waitKey(0);
    return 0;
}