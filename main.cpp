#include <iostream>
#include "FactoryModel/SimpleFactory.h"
#include "FactoryModel/Factory.h"


int main(int, char**) {
    
    MaterialFactory * factory = new MaterialFactory();
    Material * m = factory->GetIntance("红色棉布");
    m->Show();


    Factory::Factory* lFactory = new Factory::LinenFactory();
    lFactory->GetIntance()->Show();

    

    return 0;
}
