#pragma once

#include <iostream>
#include <list>

#include "Resource.h"

class ObjectPool
{
private:
	std::list<Resource*> resources;
	int maxResources;
	static ObjectPool* instance;
	ObjectPool();

public:
	static ObjectPool* getInstance();
	Resource* getResource();
	void returnResource(Resource* object);
	std::list<Resource*> getResourceSize();
};

