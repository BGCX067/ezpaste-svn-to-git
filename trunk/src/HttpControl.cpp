#include "HttpControl.h"

#include "ClientSocket.h"
#include "SocketException.h"

#include <string>
#include <iostream>


HttpControl::HttpControl(std::string address, std::string url, std::string protocol, int port):
    mAddress(address),
    mURL(url),
    mProtocol(protocol),
    mPort(port)
{
    addHTTP("Host",address);
}

StringPair HttpControl::send( std::string &data )
{
    try
    {
        ClientSocket thisSocket(mAddress, mPort);

        thisSocket << mProtocol << " " << mURL << " HTTP/1.1\n";
        for (StringPair::iterator it = mHTTPData.begin(); 
             it != mHTTPData.end(); it++)
        {
            thisSocket << it->first << ": " << it->second << "\n";
        }
        thisSocket << "\n";
        std::string buffer;
//        do
//        {
            thisSocket >> buffer;
            data += buffer;
//        } while (!streamOver(data));
    }
    catch (SocketException& e)
    {
        std::cout << "Exception was caught:" << e.description() << "\n";
    }

    StringPair crap;
    return crap;


}
