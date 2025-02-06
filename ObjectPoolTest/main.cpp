#include <iostream>

#include "ObjectPool.h"
//#include "Resource.h"

ObjectPool* ObjectPool::instance = 0;

int main()
{
    ObjectPool* pool = ObjectPool::getInstance();

    Resource* one;
    Resource* two;
    Resource* three;

    one = pool->getResource();
    one->setValue(10);
    std::cout << "one = " << one->getValue() << " [" << one << "]" << std::endl;

    two = pool->getResource();
    two->setValue(20);
    std::cout << "two = " << two->getValue() << " [" << two << "]" << std::endl;

    // in this case it's a little more complicated addind and removing a resource over the limit
    // for the engine, the resource size will hit a max on the real Voice pool and then fill the 
    // virtual voice pool. if the virtual voice pool is full, stop filling.
    if (pool->getResourceSize().size() !=0)
    {
    three = pool->getResource();
    three->setValue(30);
    std::cout << "three = " << three->getValue() << " [" << two << "]" << std::endl;
    }

    pool->returnResource(one);
    pool->returnResource(two);
    //pool->returnResource(three);

   //one = pool->getResource();
   //std::cout << "one = " << one->getValue() << " [" << one << "]" << std::endl;
   //two = pool->getResource();
   //std::cout << "two = " << two->getValue() << " [" << two << "]" << std::endl;

    return 0;
}