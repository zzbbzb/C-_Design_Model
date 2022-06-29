#include <iostream>
#include "CreationalPatterns/FactoryPattern/SimpleFactory.h"
#include "CreationalPatterns/FactoryPattern/Factory.h"
#include "CreationalPatterns/FactoryPattern/AbstractFactory.h"
#include "CreationalPatterns/SingletonPattern/HungryModeSingleton.h"
#include "CreationalPatterns/SingletonPattern/LazyModeSingleton.h"
#include "CreationalPatterns/BuilderPattern/Builder.h"
#include "StructuralPattern/DecoratorPattern/Decorator.h"
#include "StructuralPattern/AdapterPattern/Adapter.h"
#include "StructuralPattern/ProxyPattern/Proxy.h"
#include "StructuralPattern/DecoratorPattern/Decorator2.h"

// #define CalFuncExecTime(content, text) Decorator2::FuncTimer<void *, void *>([](void *)-> void* {\
// 	do{content}while(false);\
// 	return nullptr;\
// }, text)(nullptr)\

    int test1(int b, int c){
        return b + c;
    };

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


    AdapterSpace::MediaPlayerAdapter* mp = new AdapterSpace::MediaPlayerAdapter();
    mp->play("mp3", "hello.mp3");
    mp->play("vlc", "vlc.vlc");
    mp->play("mp4", "mp4.mp4");

    delete mp;

    ProxySpace::ProxyImage* pImg = new ProxySpace::ProxyImage("1.png");
    pImg->Display();

    pImg->Display();

    delete pImg;



    string s = "timer1: ";
    Decorator2::FuncTimer<int, int, int> timer1([](int a, int b)->int{return a + b;}, "timer1: ");
    std::cout <<timer1(2,4) << std::endl;
    
    class A{
    public:
        int x;
        explicit A(int x): x(x){}
        int test(int a, int b) const {
            return a + b + x;
        }
    };

    CalFuncExecTime(A a(6);
			                a.test(1, 4);,
	                "A : "
	);

    getchar();
    return 0;
}
