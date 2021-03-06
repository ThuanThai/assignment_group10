#include "iofile.h"
#include "controller.h"
#include <iostream>
#include <iomanip>

int main(int argc, char* argv[]) {
	// check argument count
	if (argc != 2) {
		cerr << "Wrong compiling method!!!\n" << "Please compile as follow: assignment1_group10.exe <filename>.csv" << endl;
		return 0;
	}

	// create two objects
	myArray col1, col2;
	// read data from file
	// and store data in arrays
	// if file cannot be opened -> return false
	if (!read_csvFile(argv[1], col1, col2))
		return 0;

	// delete redundant memory locations
	col1.shrinkSize(); col2.shrinkSize();

	col1.findSum(); col2.findSum();
	// find mean of each data set
	col1.findMean(); col2.findMean();
	// find covariance of two data sets
	col1.findCovariance(col2);

	// doing the main calculations
	col1.start(); col2.start();

	// print out the descriptive statistic
	cout << "\n\t\tDescriptive Statistics" << endl;
	cout << setprecision(4) << fixed << "median_x =  " << col1.getMedian() << "\t - median_y =  " << col2.getMedian() << endl;
	cout << setprecision(4) << fixed << "mode_x =  " << col1.getMode() << "\t - mode_y =  " << col2.getMode() << endl;
	cout << setprecision(4) << fixed << "var_x =  " << col1.getVariance() << "\t - var_y =  " << col2.getVariance() << endl;
	cout << setprecision(4) << fixed << "stdev_x =  " << col1.getStandardDeviation() << "\t - stdev_y =  " << col2.getStandardDeviation() << endl;
	cout << setprecision(4) << fixed << "mad_x =  " << col1.getMad() << "\t - mad_y =  " << col2.getMad() << endl;
	cout << setprecision(4) << fixed << "Q3_x =  " << col1.getThirdQuartile() << "\t\t - Q3_y =  " << col2.getThirdQuartile() << endl;
	cout << setprecision(4) << fixed << "Skew_x =  " << col1.getSkewness() << "\t - Skew_y =  " << col2.getSkewness() << endl;
	cout << setprecision(4) << fixed << "Kurt_x =  " << col1.getKurtosis() << "\t - Kurt_y =  " << col2.getKurtosis() << endl;

	// print out the inferential statistic
	cout << "\n\t\tInferential Statistics" << endl;
	cout << setprecision(4) << fixed << "cov(x_y) =  " << col1.getCovariance() << endl;
	cout << setprecision(4) << fixed << "r(x_y) =  " << col1.findPearson(col2) << endl;
	cout << "Linear Regression: " << col1.findLinearRegression(col2) << endl;

	// delete two arrays
	end(col1, col2);

	cout << "\n\t\tASSIGNMENT 1 GROUP 10" << endl;
	cout << "s3877819, s3877819@rmit.edu.vn, Phong, Le" << endl;
	cout << "s3877798, s3877798@rmit.edu.vn, Anh, Nguyen" << endl;
	cout << "s3877024, s3877024@rmit.edu.vn, Thuan, Thai" << endl;
	cout << "s3761910, s3761910@rmit.edu.vn, Dat, Phan" << endl;

	return 0;
}