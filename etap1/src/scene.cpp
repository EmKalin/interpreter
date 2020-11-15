#include "Scene.hh"

Scene::Scene()
{

}

Scene::~Scene()
{

}

shared_ptr<MobileObj> Scene::findMobileObject(const string& objectName)
{
    auto iter = this->_mobileObjects.find(objectName);
    if(iter != this->_mobileObjects.end())
    {
        return iter->second;
    }
    return nullptr;
}

void Scene::addMobileObject(const string& objectName)
{
    if(!findMobileObject(objectName))
    {
        auto mobileObject = std::make_shared<MobileObj>();
        mobileObject->SetName(objectName);
        this->_mobileObjects.insert({objectName, mobileObject});
    }
}
