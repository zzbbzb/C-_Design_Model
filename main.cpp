#include <iostream>
#include "CreationalPatterns/FactoryPattern/SimpleFactory.h"
#include "CreationalPatterns/FactoryPattern/Factory.h"
#include "CreationalPatterns/FactoryPattern/AbstractFactory.h"
#include "CreationalPatterns/SingletonPattern/HungryModeSingleton.h"
#include "CreationalPatterns/SingletonPattern/LazyModeSingleton.h"
#include "CreationalPatterns/BuilderPattern/Builder.h"
#include "StructuralPattern/DecoratorPattern/Decorator.h"


int main(int, char**) {
    
    MaterialFactory * factory = new MaterialFactory();
    Material * m = factory->GetIntance("棉布");
    m->Show();
    delete factory;
    delete m;

    Factory::Factory* lFactory = new Factory::BlueCottonFactory();
    Factory::Cotton* c = lFactory->GetIntance();
    c->Show();
    delete lFactory;
    delete c;

    AbstractFactory::Factory* aFactory = new AbstractFactory::GreenLinenFactory();
    AbstractFactory::Linen* l = dynamic_cast<AbstractFactory::Linen*>(aFactory->GetMaterial());
    l->Show();
    delete aFactory;
    delete l;

    
    LazyMode* lm = LazyMode::GetInstance();
    cout << "&lm=" << &lm << endl;
    lm = LazyMode::GetInstance();
    cout << "&lm=" << &lm<< endl;

    HungryMode* hm = HungryMode::GetInstance();
     cout << "&hm=" << &hm << endl;
    hm = HungryMode::GetInstance();
    cout << "&hm=" << &hm<< endl;

    
    BuilderPattern::MealBuilder* mealBuilder = new BuilderPattern::MealBuilder();
    BuilderPattern::Meal* vegMeal = mealBuilder->PrepareVegMeal();
    BuilderPattern::Meal* nonVegMeal = mealBuilder->PrepareNonVegMeal();

    vegMeal->ShowItem();
    nonVegMeal->ShowItem();

    mealBuilder->Delete(vegMeal);
    mealBuilder->Delete(nonVegMeal);

    delete mealBuilder;

    shared_ptr<Decorator::Pancake> pancake = shared_ptr<Decorator::Pancake>(new Decorator::BasePancake);
    cout << pancake->GetMsg() << "," << pancake->GetPrice() << endl;

    pancake = shared_ptr<Decorator::EggPancakeDeorator>(new Decorator::EggPancakeDeorator(pancake));
    cout << pancake->GetMsg() << "," << pancake->GetPrice() << endl;
    pancake = shared_ptr<Decorator::EggPancakeDeorator>(new Decorator::EggPancakeDeorator(pancake));
    cout << pancake->GetMsg() << "," << pancake->GetPrice() << endl;
    pancake = shared_ptr<Decorator::SauageDecorator>(new Decorator::SauageDecorator(pancake));
    cout << pancake->GetMsg() << "," << pancake->GetPrice() << endl;

    getchar();
    return 0;
}
