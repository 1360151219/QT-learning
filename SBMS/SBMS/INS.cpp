
#include "INS.h"

vector<string> testSplit(string srcStr, const string& delim)
{
    int nPos = 0;
    vector<string> vec;
    nPos = srcStr.find(delim.c_str());
    while (-1 != nPos)
    {
        string temp = srcStr.substr(0, nPos);
        vec.push_back(temp);
        srcStr = srcStr.substr(nPos + 1);
        nPos = srcStr.find(delim.c_str());
    }
    vec.push_back(srcStr);
    return vec;
}

unsigned char hexToDec(unsigned char hex)
{
    if (hex >= 'A')
        return (hex - 'A') + 10;
    else
        return hex - '0';
}

INS::INS()
{
}


INS::~INS()
{
}


bool INS::checkCRC()  //CRC校验
{
    int pos = payload.find('*');
    unsigned char checkSum = 0;
    unsigned char CRC = (hexToDec(payload[pos + 1]) << 4) + hexToDec(payload[pos + 2]);
    for (int i = 1; i < pos; i++)
        checkSum ^= payload[i];
    if (checkSum == CRC)
        return true;
    else
        return false;
}

void INS::read(string parseStr)
{
        int parseLength = 1;
        int len = static_cast<int>(parseStr.length());
        while(len>parseLength)
      {
                    string str = parseStr.substr(parseLength - 1);
                   if(parse(str,parseLength))
                   {
                        if(checkCRC())
                        {
                            strs.clear();
                            strs = testSplit(payload, ",");
                            if (strs[0]=="$GPRMC")
                            {

                                if(strcmp(strs[2].c_str(),"A") == 0)
                                {
                                    valid = true;
                                    int pos = strs[3].find('.');
                                    if(pos != string::npos)
                                        latitude = atof(strs[3].substr(0, 2).c_str()) + atof(strs[3].substr(pos - 2).c_str()) / 60;
                                    pos = strs[5].find('.');
                                    if(pos != string::npos)
                                        longitude = atof(strs[5].substr(0, 3).c_str()) + atof(strs[5].substr(pos - 2).c_str()) / 60;
                                    speed=static_cast<float>(atof(strs[7].c_str()));
                                    speed_Course=static_cast<float>(atof(strs[8].c_str()));
                                    //gnssEKF(GyroZ);
                                }
                                    else
                                        valid = false;


                            }
                            else if (strs[0]=="$GPHDT")  //成立则获取到一条完整的NMEA消息
                            {


                                    yaw=static_cast<float>(atof(strs[1].c_str()));


                            }
                            else if (strs[0]=="$PRDID")  //成立则获取到一条完整的NMEA消息
                            {


                                    heading=static_cast<float>(atof(strs[3].c_str()));
                                    pitch=static_cast<float>(atof(strs[1].c_str()));
                                    roll=static_cast<float>(atof(strs[2].c_str()));


                            }
                            else if(strs[0]=="$PSBGI")
                            {
                                GyroX=static_cast<float>(atof(strs[2].c_str()));
                            }
                        }
                   }

      }
}

/*if(checkCRC(payload2))
{
    strs.clear();
    strs=testSplit(payload2,",");
    yaw=atof(strs[1].c_str());
}*/
bool INS::parse(string str,int& parseLen)
{
    static bool get_header = false;
    if (get_header)
    {
        int pos_footer = str.find(footer);
        if (pos_footer != -1)
        {
            payload += str.substr(0, pos_footer + 2);
            get_header = false;
            parseLen += pos_footer + 2;
            return true;
        }
        else
        {
            payload += str;
            if (payload.length() >= 100)
            {
                payload.clear();
                get_header = false;

            }
            parseLen += str.length();
            return false;

        }
    }
    else
    {
        int pos_header = str.find(header);
        if (pos_header != -1)
        {
            payload.clear();
            get_header = true;
            int pos_footer = str.find(footer, pos_header);
            if (pos_footer != -1)
            {
                payload = str.substr(pos_header, pos_footer - pos_header + 2);
                get_header = false;
                parseLen += pos_footer + 2;
                return true;
            }
            else
            {
                payload += str.substr(pos_header);
                parseLen += str.length();
                return false;
            }
        }
        else
        {
            parseLen += str.length();
            return false;
        }
    }
}


void INS::getPosition(double &_lat, double &_lng)
{
    _lat = latitude;
    _lng = longitude;
}

