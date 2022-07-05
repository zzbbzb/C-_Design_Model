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
#include "BehavioralPattern/ObserverPattern/Observer.h"
#include "BehavioralPattern/CommandPattern/Command.h"
#include "BehavioralPattern/MementoPattern/Memento.h"

int test1(int b, int c){
    return b + c;
};

int main(int, char**) {
    
    MaterialFactory * factory = new MaterialFactory();
    Material * m = factory->GetIntance("棉布");
    m->Show();
    delete factory;
    delete m;

    // ======================================
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

    // ======================================
    LazyMode* lm = LazyMode::GetInstance();
    cout << "&lm=" << &lm << endl;
    lm = LazyMode::GetInstance();
    cout << "&lm=" << &lm<< endl;

    HungryMode* hm = HungryMode::GetInstance();
     cout << "&hm=" << &hm << endl;
    hm = HungryMode::GetInstance();
    cout << "&hm=" << &hm<< endl;

    // ======================================
    BuilderPattern::MealBuilder* mealBuilder = new BuilderPattern::MealBuilder();
    BuilderPattern::Meal* vegMeal = mealBuilder->PrepareVegMeal();
    BuilderPattern::Meal* nonVegMeal = mealBuilder->PrepareNonVegMeal();

    vegMeal->ShowItem();
    nonVegMeal->ShowItem();

    mealBuilder->Delete(vegMeal);
    mealBuilder->Delete(nonVegMeal);

    delete mealBuilder;

    // ======================================
    shared_ptr<Decorator::Pancake> pancake = shared_ptr<Decorator::Pancake>(new Decorator::BasePancake);
    cout << pancake->GetMsg() << "," << pancake->GetPrice() << endl;

    pancake = shared_ptr<Decorator::EggPancakeDeorator>(new Decorator::EggPancakeDeorator(pancake));
    cout << pancake->GetMsg() << "," << pancake->GetPrice() << endl;
    pancake = shared_ptr<Decorator::EggPancakeDeorator>(new Decorator::EggPancakeDeorator(pancake));
    cout << pancake->GetMsg() << "," << pancake->GetPrice() << endl;
    pancake = shared_ptr<Decorator::SauageDecorator>(new Decorator::SauageDecorator(pancake));
    cout << pancake->GetMsg() << "," << pancake->GetPrice() << endl;


    // ======================================
    AdapterSpace::MediaPlayerAdapter* mp = new AdapterSpace::MediaPlayerAdapter();
    mp->play("mp3", "hello.mp3");
    mp->play("vlc", "vlc.vlc");
    mp->play("mp4", "mp4.mp4");

    delete mp;

    // ======================================
    ProxySpace::ProxyImage* pImg = new ProxySpace::ProxyImage("1.png");
    pImg->Display();

    pImg->Display();

    delete pImg;

    // ======================================
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

    // ======================================
    shared_ptr<ObserverSpace::Subject> subject = shared_ptr<ObserverSpace::Subject>(new ObserverSpace::Subject());

    shared_ptr<ObserverSpace::Observer> observer1 = shared_ptr<ObserverSpace::BinaryObserver>(new ObserverSpace::BinaryObserver(subject));
    shared_ptr<ObserverSpace::Observer> observer2 = shared_ptr<ObserverSpace::HexObserver>(new ObserverSpace::HexObserver(subject));
    shared_ptr<ObserverSpace::Observer> observer3 = shared_ptr<ObserverSpace::OctalObserver>(new ObserverSpace::OctalObserver(subject));

    subject->Attach(observer1);
    subject->Attach(observer2);
    subject->Attach(observer3);

    std::cout << "First state change: 15" << std::endl;
    subject->SetState(15);
    std::cout << "Second state change: 10" << std::endl;
    subject->SetState(10);

    // ======================================
    std::shared_ptr<CommandSpace::Chef> chef = std::shared_ptr<CommandSpace::Chef>(new CommandSpace::Chef);
    std::shared_ptr<CommandSpace::ICommand> c1 = std::shared_ptr<CommandSpace::BarbecueCommand>(new CommandSpace::BarbecueCommand(chef));
    std::shared_ptr<CommandSpace::ICommand> c2 = std::shared_ptr<CommandSpace::FriedDishCommand>(new CommandSpace::FriedDishCommand(chef));

    std::shared_ptr<CommandSpace::Waiter> waiter = std::shared_ptr<CommandSpace::Waiter>(new CommandSpace::Waiter);
    waiter->SetOrder(c1);
    waiter->SetOrder(c2);

    waiter->Notify();

    // ======================================
    std::shared_ptr<MementoSpace::Originator> orignator = std::shared_ptr<MementoSpace::Originator>(new MementoSpace::Originator());
    std::shared_ptr<MementoSpace::CareTaker> careTable = std::shared_ptr<MementoSpace::CareTaker>(new MementoSpace::CareTaker);

    orignator->SetState("State #1");
    orignator->SetState("State #2");

    careTable->Add(orignator->SaveStateToMemento());

    orignator->SetState("State #3");

    careTable->Add(orignator->SaveStateToMemento());

    orignator->SetState("State #4");

    std::cout << "Current State: " << orignator->GetState() << std::endl;

    orignator->GetStateFromMemento(careTable->Get(0));
    std::cout << "First saved state: " << orignator->GetState() << std::endl;

    orignator->GetStateFromMemento(careTable->Get(1));
    std::cout << "Second saved state: " << orignator->GetState() << std::endl;

    
    getchar();
    return 0;
}
