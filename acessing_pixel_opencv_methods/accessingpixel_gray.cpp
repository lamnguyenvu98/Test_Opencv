/*
  3 ways to accessing pixel data
  - Using "at"
  - Using "direct address calculation"
  - Using "ptr"
*/
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int, char** argv)
{
  Mat img = imread(argv[1], 0);
  float ratio = 500.0 / img.size().width;
  resize(img, img, Size(500, ratio * img.size().height));
  //cout<<img.size().width<<endl;

  // Cach 1: Using "at"
  cout<<"Cach 1.....\n\n";
  for (int i = 0; i < img.rows; i++)
  {
    cout<<"\n";
    if (i<20)
    {
      for (int j = 0; j < img.cols; j++)
      {
        if (j<20)
        {
          cout<<(int)img.at<uchar>(i,j)<<" ";
          img.at<uchar>(i,j) = 0;
        }
        else break;
      }
    }
    else break;
  }
  imshow("test", img);
  waitKey(0);
  cout<<"\n\n\nCach 2.....\n\n";

  // Cach 2: Using direct address calculaton
  for (int i=0; i<img.rows; i++)
  {
    if (i<50)
    {
      for (int j=0; j<img.cols; j++)
      {
        if (j<50)
        {
          // Dereferencing operator * to access (i,j)th element
          cout<<(int)*(img.data + img.step[0]*i + img.step[1]*j)<<" ";
          *(img.data + img.step[0]*i + img.step[1]*j) = 100;
        }
        else break;
      }
    }
    else break;
  }
  imshow("test", img);
  waitKey(0);
  
  cout<<"Cach 3.....\n\n";
  // Cach 3: Using pointer ptr
  for (int i=0; i<img.rows; i++)
  {  
    cout<<"\n";
    if (i<60)
    {
      // ptrRow hold pointer to ith row
      // so changes to ptrRow intern changes the img
      uchar* ptrRow = img.ptr<uchar>(i); 
      for (int j=0; j<img.cols; j++)
      {
        if (j<40)
        {
          cout<<(int)ptrRow[j]<<" ";
          ptrRow[j] = 120;
        }
	else break;
      }	      
    }
    else break;
  }
  imshow("test", img);
  waitKey(0);
  return 0;
}
