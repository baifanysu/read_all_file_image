#include <iostream>
#include <opencv2/opencv.hpp>
#include <string.h>
#include <io.h>  
#include <iomanip>  
#include <fstream>

using namespace std;
using namespace cv;

void read_csv(const string& filename, vector<Mat>& images);

int main()
{ 
	vector<Mat> image;
	string file_csv = "at.txt";
	read_csv(file_csv,image);
	Mat firstImage;
	firstImage = image.at(0);
	cout <<"imagecols = "<< firstImage.cols <<"  imagerows = "<< firstImage.rows << endl;
	Mat allImage(firstImage.cols*firstImage.rows,400,CV_8UC1);
	for (int i = 0; i < 400; i++)
	{
		Mat tempImage(firstImage.cols*firstImage.rows,1,CV_8UC1);
		tempImage = image.at(i).reshape(0, firstImage.cols*firstImage.rows);
		//tempImage = firstImage.reshape(0, firstImage.cols*firstImage.rows);
		tempImage.copyTo(allImage.col(i));
	}
	waitKey(0);
	return 0;
}

void read_csv(const string& filename, vector<Mat>& images)

{
	ifstream file(filename, ifstream::in);//创建一个输入流对象
	if (!file)   //如果输入流创建失败，则报错，程序终止
	{
		string error_message ="No valid input file was given.";
		CV_Error(CV_StsBadArg, error_message);
	}
	string path;          //string变量，用以存储读出的路径
	while (getline(file,path))      //从文件中读出一行的内容，保存在变量path中
	{
		if (!path.empty())
		{
			images.push_back(imread(path,0));//将对应文件压入图像容器
		}
	}
}





