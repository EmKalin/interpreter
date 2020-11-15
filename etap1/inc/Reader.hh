#ifndef READER_HH
#define READER_HH

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <map>
using namespace std;

typedef map<string,string> params;
typedef pair<string,params> command;
typedef vector<command> commandSet;

class Reader
{
private:
  string _path;
  commandSet _commandSet;

public:
  Reader(string currentPath){
    this->_path = currentPath;
  };
  commandSet readFile();
};

#endif
