// TODO 观察者模式

/*

一对多关系, 一个对象被修改, 会自动通知依赖它的对象

代码结构:
    在抽象类中有列表存放观察者


例子:
    Subject对象绑定观察者,解绑观察者
    Observer观察者
*/

#include <vector>
#include <memory>
#include <iostream>
#include <bitset>

namespace ObserverSpace{
    class Subject;

    class Observer{
    protected:
        std::shared_ptr<Subject> subject;
    public:
        virtual void Update() = 0;
    };

    class Subject {
    private:
        std::vector<std::shared_ptr<Observer>> observers;
        int state;
    public:
        int GetState(){
            return state; 
        }

        void SetState(int state){
            this->state = state;
            NotifyAllObservers();
        }

        void Attach(std::shared_ptr<Observer> observer){
            observers.push_back(observer);
        }

        void Disattach(Observer* observer) = delete;

        void NotifyAllObservers(){
            for(int i = 0; i < observers.size(); i++){
                observers[i]->Update();
            }
        }
    };

    class OctalObserver: public Observer{
    public:
        OctalObserver(std::shared_ptr<Subject> subject){
            this->subject = subject;
        }

        void Update(){
            std::cout << "Octal string :" << std::oct << subject->GetState() << std::endl;
        }
    };


    class BinaryObserver: public Observer{
    public:
        BinaryObserver(std::shared_ptr<Subject> subject){
            this->subject = subject;
        }

        void Update(){
            std::cout << "Octal string :" << std::bitset<16>(subject->GetState()) << std::endl;
        }
    };

    class HexObserver: public Observer{
    public:
        HexObserver(std::shared_ptr<Subject> subject){
            this->subject = subject;
        }

        void Update() {
            std::cout << "Hex string:" << std::hex << subject->GetState() << std::endl;
        }
    };
}



