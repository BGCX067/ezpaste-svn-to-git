#ifndef HTTP_Control
#define HTTP_Control

#include <string>
#include <map>

typedef std::map<std::string, std::string> StringPair;

class HttpControl
{
    public:
        HttpControl(std::string address, std::string url, std::string protocol = "POST", int port = 80);

        void addHTTP(std::string name, std::string data)
        {
            mHTTPData[name] = data;
        }
        void addGet(std::string name, std::string data)
        {
            mGetData[name] = data;
        }
        void addPost(std::string name, std::string data)
        {
            mPostData[name] = data;
        }

        StringPair send(std::string &data);

     private:
        std::string urlencode(StringPair);
        //StringPair urldecode(std::string value);

        StringPair mHTTPData, mGetData, mPostData;

        std::string mAddress, mURL, mProtocol;
        int mPort;

};

#endif
