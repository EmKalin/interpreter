#ifndef SCENE_HH
#define SCENE_HH

#include "MobileObj.hh"
#include <map>
#include <memory>

using namespace std;

class Scene
{
private:
    map<string, shared_ptr<MobileObj>> _mobileObjects;

public:
    int mobileObjectsAmount() const{
      return this->_mobileObjects.size();
    }
    shared_ptr<MobileObj> findMobileObject(const string& objectName);
    void addMobileObject(const string& objectName);
    Scene(/* args */);
    ~Scene();
};

#endif
