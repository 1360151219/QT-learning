#pragma once
#include <string>
#include <vector>
#include <iostream>


using std::vector;
using std::string;
using std::cout;
using std::endl;


vector<string> testSplit(string srcStr, const string& delim);
unsigned char hexToDec(unsigned char hex);

class INS
{
public:
	INS();
	~INS();
	void getPosition(double &_lat, double &_lng);  //得到经纬度  
	bool valid;
	double latitude, longitude;
	float heading; 
	float yaw,pitch, roll;
	float speed;//Knots/s
	float speed_Course;
	float GyroX;
	float GyroY;
	float GyroZ;  //deg/s
	float accelX;
	float accelY;
	float accelZ;
	uint8_t quality;
	uint8_t SVs;
	float HDOP;
    string payload;
	void read(string parseStr);

private:
    //const string header1 ="$G";// "$GPRMC";  //"$INDYN:"   协议 3.3.11. Ixblue INDYN
    //const string header2 ="$P";// "$GPHDT";
    //const string header3 = "$PR";//"$PRDID";
   // const string header4 = "$PS";//"$PSBGI";
    //const string header5 = "A";//"$GPGGA";
    const string header="$";
	const string footer = "\r\n";

	vector<string> strs;
	
    bool parse(string str,int& parseLen);


    bool checkCRC();
	


};

