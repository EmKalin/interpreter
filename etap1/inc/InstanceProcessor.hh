#ifndef INSTANCEPROCESSOR_HH
#define INSTANCEPROCESSOR_HH

#pragma once

using namespace std;
#include <map>
#include <memory>
#include <dlfcn.h>
#include <cassert>
#include "MobileObj.hh"
#include "Scene.hh"
#include "Interp4Command.hh"

struct LibInterface
{
private:
    string _CmdName;
    void *_pLibHnd;
    Interp4Command *(*pCreateCmd)(void);
public:
    LibInterface();
    bool execActions(shared_ptr<MobileObj>, command);
    bool initInterface(const std::string& CmdName);
    ~LibInterface();
};

class InstanceProcessor
{
private:
    map<string, shared_ptr<LibInterface>> _LibInterfaces;
    Scene _scene;
public:
    InstanceProcessor();
    bool InstanceProcessorStart(commandSet);
    shared_ptr<LibInterface> findInterface(const string& libName);
    bool addInterface(const string& libname);
    ~InstanceProcessor();
};

#endif
