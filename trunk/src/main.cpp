#include <iostream>
#include <string>
#include <fstream>

#include "HttpControl.h"
#include "parse.h"

using namespace std;

int main(int argc, char* argv[])
{
    if (argc == 1)
    {
        parseStdin(buffer);
    }
    else if (argc == 2)
    {
        parseFile(buffer, argv[1]);
    }
    else if (argc > 2)
    {
        cout << "Syntax error.\n Usage: 'command | ./ezpaste' for stdin,\nor './ezpaste filename' for reading from file.\nExiting..." << endl;
        return 0;
    }

    cout << "Parse finished" << endl;

    HttpControl thisControl("www.google.com", "/", "GET");
    std::string data;
    thisControl.send(data);
    cout << data;

    return 0;
}



