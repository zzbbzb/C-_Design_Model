#include <iostream>
#include <string>

using namespace std;

namespace Factory{
    /*
        工厂 
        生产红色棉布
        生产绿色棉布
        生产蓝色棉布

        多个工厂类, 一个产品抽象类, 利用多态创建不同的产品对象, 避免if-else

        抽象生产工厂
        对每个产品创建一个生产工厂
        直接用对应产品工厂生产产品

        缺点, 产品数量上去后, 增加类也很多, 增加代码复杂度
    */

    class Cotton{
    public:
        virtual ~Cotton(){}

        virtual void Show() = 0;
    };

    class RedCotton: public Cotton{
    public:
        void Show() {
            cout << "红色 棉布" << endl;
        }
    };

    class GreenCotton: public Cotton{
    public:
        void Show() {
            cout << "绿色 棉布" << endl;
        }
    };


    class BlueCotton: public Cotton{
    public:
        void Show() {
            cout << "蓝色 棉布" << endl;
        }
    };

    class Factory {
    public:
        virtual ~Factory(){}
        virtual Cotton* GetIntance() = 0;
    };

    class RedCottonFactory: public Factory{
    public:
        Cotton* GetIntance(){
            return new RedCotton();
        }
    };

    class GreenCottonFactory: public Factory{
    public:
        Cotton* GetIntance(){
            return new GreenCotton();
        }
    };

    class BlueCottonFactory: public Factory{
    public:
        Cotton* GetIntance(){
            return new BlueCotton();
        }
    };

}


