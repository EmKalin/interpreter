#include "Reader.hh"

command readMoveCmd(istream *myfile)
{
  string temporaryString;
  params tempParams;
  *myfile >> temporaryString;
  tempParams["objName"] = temporaryString;
  *myfile >> temporaryString;
  tempParams["Velocity"] = temporaryString;
  *myfile >> temporaryString;
  tempParams["PathLength"] = temporaryString;
  return command(make_pair("Move",tempParams));
}

command readRotateCmd(istream *myfile)
{
  string temporaryString;
  params tempParams;
  *myfile >> temporaryString;
  tempParams["objName"] = temporaryString;
  *myfile >> temporaryString;
  tempParams["angVelocity"] = temporaryString;
  *myfile >> temporaryString;
  tempParams["angle"] = temporaryString;

  return command(make_pair("Rotate",tempParams));
}

command readSetCmd(istream *myfile)
{
  string temporaryString;
  params tempParams;
  *myfile >> temporaryString;
  tempParams["objName"] = temporaryString;
  *myfile >> temporaryString;
  tempParams["coorX"] = temporaryString;
  *myfile >> temporaryString;
  tempParams["coorY"] = temporaryString;
  *myfile >> temporaryString;
  tempParams["angleOZ"] = temporaryString;

  return command(make_pair("Set",tempParams));
}

command readPauseCmd(istream *myfile)
{
  string temporaryString;
  params tempParams;

  *myfile >> temporaryString;
  tempParams["pauseTime"] = temporaryString;

  return command(make_pair("Pause",tempParams));
}

commandSet Reader::readFile(){
  ifstream myfile (this->_path);
  if (!myfile.is_open()) cerr << "Unable to open file";

  string keyWord;
  command temporary;
  commandSet setOfActions;
  myfile >> keyWord;
  
  while(!myfile.fail()){
    if(keyWord == "Move"){
      temporary = readMoveCmd(&myfile);
      this->_commandSet.push_back(temporary);
    } else if(keyWord == "Rotate"){
      temporary = readRotateCmd(&myfile);
      this->_commandSet.push_back(temporary);
    } else if(keyWord == "Set"){
      temporary = readSetCmd(&myfile);
      this->_commandSet.push_back(temporary);
    } else if(keyWord == "Pause"){
      temporary = readPauseCmd(&myfile);
      this->_commandSet.push_back(temporary);
    } else { cerr << "Wrong commend!" << endl;}

    myfile >> keyWord;
  }
  myfile.close();
  return this->_commandSet;
}
