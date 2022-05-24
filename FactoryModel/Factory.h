#include <iostream>
#include <string>

using namespace std;

namespace Factory{
    /*
        工厂
        生产红色棉布
        生产绿色麻布
        生产蓝色丝绸

        抽象生产工厂
        对每个产品创建一个生产工厂
        直接用对应产品工厂生产产品

        缺点, 不符合开闭原则, 需要修改getIntance
    */

    class Material{
    public:
        string color;
        string name;
        
        Material(string c, string n): color(c), name(n){}
        virtual ~Material(){}

        virtual void Show() = 0;
    };

    class Silk: public Material{
    public:
        Silk(string c, string n): Material(c, n){}
        void Show() {
            cout << color << " " << name << endl;
        }
    };

    class Cotton: public Material{
    public:
        Cotton(string c, string n): Material(c, n){}
        void Show() {
            cout << color << " " << name << endl;
        }
    };


    class Linen: public Material{
    public:
        Linen(string c, string n): Material(c, n){}
        void Show() {
            cout << color << " " << name << endl;
        }
    };

    class Factory {
    public:
        virtual ~Factory(){}
        virtual Material* GetIntance() = 0;
    };

    class CottonFactory: public Factory{
    public:
        Material* GetIntance(){
            return new Cotton("红色", "棉布");
        }
    };

    class LinenFactory: public Factory{
    public:
        Material* GetIntance(){
            return new Linen("绿色", "麻布");
        }
    };

    class SilkFactory: public Factory{
    public:
        Material* GetIntance(){
            return new Silk("蓝色", "丝绸");
        }
    };



}


