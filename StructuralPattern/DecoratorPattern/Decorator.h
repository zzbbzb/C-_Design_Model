// TODO 装饰器

/*
    动态的给对象添加一些额外的职责
    在不想增加很多子类的情况下扩展类

代码结构:
    1. 要修饰的component类充当抽象角色, 不应该具体实现
    2. 修饰类需要继承引用component类

使用场景:
    扩展一个类的功能
    动态增加功能, 动态撤销

例子:
    煎饼增加
    煎饼增加2个鸡蛋一根香肠

参考:
    https://blog.csdn.net/d303577562/article/details/118112043
    https://blog.csdn.net/qq_43605388/article/details/119962335

 */

#include <string>
#include <memory>

namespace Decorator{
    using namespace std;
    class Pancake{
    public:
        virtual string GetMsg() = 0; 
        virtual int GetPrice() = 0;
    };

    class BasePancake: public Pancake{
    public:
        string GetMsg() {
            return "煎饼";
        }

        int GetPrice() {
            return 5;
        }
    };

    class PancakeDecorator: public Pancake {
    // 记录函数, 可以方便删除和添加

    protected:
        shared_ptr<Pancake> pancake;
    public:
        PancakeDecorator(){}
        PancakeDecorator(shared_ptr<Pancake> p){
            pancake= shared_ptr<Pancake>(p);
        }
        string GetMsg(){
            return pancake->GetMsg();
        }

        int GetPrice() {
            return pancake->GetPrice();
        }
    };

    class EggPancakeDeorator: public PancakeDecorator {
    public:
        EggPancakeDeorator(shared_ptr<Pancake> p){
            pancake = shared_ptr<Pancake>(p);
        }

        string GetMsg() {
            return pancake->GetMsg() + " 加鸡蛋";
        }

        int GetPrice() {
            return pancake->GetPrice() + 1;
        }
    };

    class SauageDecorator: public PancakeDecorator {
    public:
        SauageDecorator(shared_ptr<Pancake> p):PancakeDecorator(p){
            std::cout << p->GetMsg()  << std::endl;
        }
        string GetMsg() {
            return pancake->GetMsg() + " 加香肠";
        }

        int GetPrice() {
            return pancake->GetPrice() + 5;
        }
    };
}






// #define CalFuncExecTime(content, text) 
// FuncTimer<void *, void *>(
// [&](void *_) -> void * {\
// 	do{content}while(false);\
// 	return nullptr;\
// }, text)(nullptr)\
