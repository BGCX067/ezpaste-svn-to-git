#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string buffer[2000];

void parseStdin(string buffer[]);
int parseFile(string buffer[], char* filename);

int parseFile(string buffer[], char* filename)
{
  ifstream fileStream;
  fileStream.open(filename);
  if (!fileStream)
  {
    cout << "Error opening " << filename << endl;
    return(1);
  }
  int i = 0;
  while (fileStream)
  {
    string input;
    getline(fileStream, input);
    buffer[i] = input;
    i++;
  }
  fileStream.close();
  for (int y = 0; y < i; y++)
  {
    cout << buffer[y] << endl;
  }
  return(0);
}

void parseStdin(string buffer[])
{
  int i = 0;
  while(cin)
  {
    string input;
    getline(cin, input);
    buffer[i] = input;
    i++;
  }
  for (int y = 0; y < i; y++)
  {
    cout << buffer[y] << endl;
  }
}



