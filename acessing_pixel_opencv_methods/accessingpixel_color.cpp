#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
    Mat img = imread(argv[1]);
    float ratio = 500.0 / img.size().width;
    resize(img , img, Size(500, (int)(ratio * img.size().height)));
    if (argc == 1)
    {
        cout<<"./<execute_file> <path_to_image> \n\n";
        return -1;
    }
    if (!img.data)
    {
        cout<<"Cannot read image file...\n\n";
        return -1;
    }
    // cout<<"Cach 1....\n\n";
    // for (int i=0; i<img.rows; i++)
    // {
    //     if (i<30)
    //     {
    //         for (int j=0; j<img.cols; j++)
    //         {
    //             if (j<40)
    //             {
    //                 cout<<(int)*(img.data + img.step[0]*i + img.step[1]*j)<<" ";
    //                 *(img.data + img.step[0]*i + img.step[1]*j) = 0;
    //             }
    //             else break;
    //         }
    //     }
    //     else break;
    // }
    // imshow("Acessing Pixel", img);
    // waitKey(0);

    // cout<<"\n\nCach 2.....\n\n";
    // vector<Mat> planes;
    // split(img, planes);
    // for (int i=0; i<img.rows; i++)
    // {
    //     if (i<30)
    //     {
    //         for (int j=0; j<img.cols; j++)
    //         {
    //             if (j<30)
    //             {
    //                 planes[0].at<uchar>(i,j) = 0;
    //                 planes[1].at<uchar>(i,j) = 0;
    //                 planes[2].at<uchar>(i,j) = 0;

    //             }
    //             else break;
    //         }
    //     }
    //     else break;
    // }
    // merge(planes, img);
    // imshow("Accessing color", img);
    // waitKey(0);

    cout<<"\n\nCach 3.....\n\n";
    for (int row=0; row<img.rows; row++)
    {
        if (row<30)
        {
            Vec3b *ptrRow = img.ptr<Vec3b>(row);
            for (int col=0; col<img.cols; col++)
            {
                if (col<30)
                {

                    ptrRow[col][0] = 0;
                    ptrRow[col][1] = 0;
                    ptrRow[col][2] = 0;
                }
                else break;
            }
        }
        else break;
    }
    for (int row=0; row<img.rows; row++)
    {
            Vec3b *ptrRow = img.ptr<Vec3b>(row);
            for (int col=0; col<img.cols; col++)
            {
                ptrRow[col] = Vec3b(ptrRow[col][2], ptrRow[col][1], ptrRow[col][0]);
            }
    }
    imshow("Acessing color", img);
    waitKey(0);
    return 0;
}