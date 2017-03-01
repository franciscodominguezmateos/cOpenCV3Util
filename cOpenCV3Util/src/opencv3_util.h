/*
 * opencv3_util.h
 *
 *  Created on: Oct 30, 2016
 *      Author: francisco
 */

#ifndef OPENCV3_UTIL_H_
#define OPENCV3_UTIL_H_
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include "opencv2/core/core.hpp"

using namespace std;
using namespace cv;

string type2str(int type) {
 string r;

 uchar depth = type & CV_MAT_DEPTH_MASK;
 uchar chans = 1 + (type >> CV_CN_SHIFT);

 switch ( depth ) {
   case CV_8U:  r = "8U"; break;
   case CV_8S:  r = "8S"; break;
   case CV_16U: r = "16U"; break;
   case CV_16S: r = "16S"; break;
   case CV_32S: r = "32S"; break;
   case CV_32F: r = "32F"; break;
   case CV_64F: r = "64F"; break;
   default:     r = "User"; break;
 }

 r += "C";
 r += (chans+'0');

 return r;
}
string toString(float i){
	string result;          // string which will contain the result
	ostringstream convert;   // stream used for the conversion
	convert.precision(2);
	convert << i;      // insert the textual representation of 'Number' in the characters in the stream
	result = convert.str();
	return result;
}
string toString(int i){
	string result;          // string which will contain the result
	ostringstream convert;   // stream used for the conversion
	convert.precision(2);
	convert << i;      // insert the textual representation of 'Number' in the characters in the stream
	result = convert.str();
	return result;
}
Mat stackH(Mat im1,Mat im2){
	Size sz1 = im1.size();
	Size sz2 = im2.size();
	Mat im3(sz1.height, sz1.width+sz2.width, CV_8UC3);
	Mat left(im3, Rect(0, 0, sz1.width, sz1.height));
	im1.copyTo(left);
	Mat right(im3, Rect(sz1.width, 0, sz2.width, sz2.height));
	im2.copyTo(right);
	return im3;
}
Mat stackV(Mat im1,Mat im2){
	Size sz1 = im1.size();
	Size sz2 = im2.size();
	Mat im3(sz1.height+sz2.height, sz1.width, CV_8UC3);
	Mat top(im3, Rect(0, 0, sz1.width, sz1.height));
	im1.copyTo(top);
	Mat down(im3, Rect(0, sz1.height, sz2.width, sz2.height));
	im2.copyTo(down);
	return im3;
}
vector<string> getLinesFromFile(string fileName){
	vector<string> lines;
	ifstream myfile(fileName.c_str());
	string str;
	while (getline(myfile,str))
		lines.push_back(str);
	return lines;
}
vector<string> split(string line){
	string str;
	istringstream ss(line);
	vector<string> words;
	while(ss>> str)
		words.push_back(str);
	return words;
}
#endif /* OPENCV3_UTIL_H_ */
