#include <iostream>
#include "Interp4Command.hh"
#include "InstanceProcessor.hh"
#include "Reader.hh"

#define _PATH "movements.cmd"

using namespace std;

int main()
{
  Reader *reader = new Reader(_PATH);
  commandSet readData =  reader->readFile();

  InstanceProcessor *proccessor = new InstanceProcessor();
  proccessor->InstanceProcessorStart(readData);

  delete reader;
}
