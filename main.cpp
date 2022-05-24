#include <iostream>
#include "FactoryModel/SimpleFactory.h"
#include "FactoryModel/Factory.h"
#include "FactoryModel/AbstractFactory.h"


int main(int, char**) {
    
    MaterialFactory * factory = new MaterialFactory();
    Material * m = factory->GetIntance("棉布");
    m->Show();


    Factory::Factory* lFactory = new Factory::BlueCottonFactory();
    lFactory->GetIntance()->Show();

    AbstractFactory::Factory* aFactory = new AbstractFactory::GreenLinenFactory();
    aFactory->GetColor()->Show();


    return 0;
}
