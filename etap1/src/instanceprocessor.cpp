#include "InstanceProcessor.hh"

LibInterface::LibInterface()
{

}

bool LibInterface::initInterface(const string& CmdName)
{
    string libName("libInterp4");
    libName.append(CmdName);
    libName.append(".so");
    _pLibHnd = dlopen(libName.c_str(),RTLD_LAZY);
    if(!_pLibHnd) {
      return false;
    }
    void *pFun;

    pFun = dlsym(_pLibHnd,"CreateCmd");

    if(!pFun) return false;

    pCreateCmd = *reinterpret_cast<Interp4Command* (**)(void)>(&pFun);


    return true;
}

bool LibInterface::execActions(shared_ptr<MobileObj> currentObject, command currentCommand)
{
    Interp4Command *pCmd = pCreateCmd();
    cout << endl;
    cout << "COMMAND EXEC FUNCTION: " << endl;
    //pCmd->PrintSyntax();

    if(!pCmd->ReadParams(currentCommand.second))
    {
        return false;
    }

    cout << "   Command line: ";
    pCmd->PrintCmd();
    cout << "   Cmd name: " << pCmd->GetCmdName();
    cout << endl;
    cout << "   Captured object name: " << currentObject->GetName();
    cout << endl;
    pCmd->PrintParams();
    cout << "===========" << endl;

    // std::cout << "Wykonanie dla obiektu: " << mobileObject->GetName() << std::endl;
    // std::cout << std::endl;
    // pCmd->PrintCmd();
    // std::cout << std::endl;
    cout << endl;
    delete pCmd;
    return true;
}

LibInterface::~LibInterface()
{
    if(_pLibHnd)
    {
        dlclose(_pLibHnd);
    }
}

InstanceProcessor::InstanceProcessor()
{

}

bool InstanceProcessor::InstanceProcessorStart(commandSet data)
{
  command currentCommand;
  string objectName;
  for (int i = 0; i < static_cast<int>(data.size()); i++)
  {
    currentCommand = data[i];
    objectName = currentCommand.second["objName"];

    auto mobileObject = this->_scene.findMobileObject(objectName);
    if(!mobileObject)
    {
      this->_scene.addMobileObject(objectName);
    }
    mobileObject = this->_scene.findMobileObject(objectName);

    cout << "---Scene size: " << this->_scene.mobileObjectsAmount();

    auto interface = findInterface(currentCommand.first);
     if(!interface)
     {
       bool addedLibSuccesfully = addInterface(currentCommand.first);
       if(!addedLibSuccesfully)
       {
          cerr << "couldnt init lib: "  << currentCommand.first << "\n";
          return false;
       }
       interface = findInterface(currentCommand.first);
     }

     if(!interface->execActions(mobileObject, currentCommand))
     {
       cerr << "couldnt execute action" << endl;
       return false;
     }
  }
  return true;
}

shared_ptr<LibInterface> InstanceProcessor::findInterface(const string& libName)
{
    auto iter = this->_LibInterfaces.find(libName);
    if (iter != this->_LibInterfaces.end())
    {
        return iter->second;
    }

    return nullptr;
}

bool InstanceProcessor::addInterface(const std::string& libname)
{
    shared_ptr<LibInterface> libInterface = make_shared<LibInterface>();
    if(!libInterface->initInterface(libname))
    {
        return false;
    }
    this->_LibInterfaces.insert({libname, libInterface});
    return true;
}
