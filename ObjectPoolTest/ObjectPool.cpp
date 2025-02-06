#include "ObjectPool.h"

ObjectPool::ObjectPool()
{
	maxResources = 2;
	for(int i = 0; i < maxResources; i++)
	resources.push_back(new Resource);
}

ObjectPool* ObjectPool::getInstance()
{
	if (instance == 0)
		instance = new ObjectPool;

	return instance;
}

Resource* ObjectPool::getResource()
{
	std::cout << "Resources size: " << resources.size() << std::endl;
	if (!resources.empty())
	{
		//std::cout << "Creating new resource." << std::endl;
		//return new Resource;
		std::cout << "Reusing existing resource from pool." << std::endl;
		Resource* resource = resources.front();
		resources.pop_front();
		return resource;
	}
	else
	{
		std::cout << "Max resources used. Cannot add further resources." << std::endl;
		
	}
}

void ObjectPool::returnResource(Resource* object)
{
	object->reset();
	resources.push_back(object);
}

std::list<Resource*> ObjectPool::getResourceSize()
{
	return resources;
}
