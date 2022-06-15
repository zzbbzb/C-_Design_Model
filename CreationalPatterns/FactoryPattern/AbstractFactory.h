#include <iostream>
#include <string>

using namespace std;

namespace AbstractFactory{
    /*
        抽象工厂 , 为了减少工厂子类的数量
        红色棉布
        绿色麻布
        蓝色丝绸

        
        多个工厂类, 多个产品抽象类, 产品子类分组, 

        抽象生产工厂
        对每个产品的类目创建一个生产工厂
        产品中字段由对应的生产工厂生成组装成整产品

        也就是 专门做颜色工厂, 专门做材质的工厂

        缺点, 增加分组简单, 分组中产品扩展困难
    */

    class Color {
    public:
        virtual ~Color(){}
        virtual void Show() {}
    };

    class GreenColor: public Color {
    public:
        void Show(){
            cout << "绿色" << endl;
        }
    };

    class RedColor: public Color {
    public:
        void Show(){
            cout << "红色" << endl;
        }
    };

    class BlueColor: public Color {
    public:
         void Show(){
            cout << "蓝色" << endl;
        }
    };

    class Material{
    public:
        virtual void Show() {}
        virtual ~Material(){}
    };

    class Silk: public Material{
    public:
        void Show(){
            cout << "丝绸" << endl;
        }
    };

    class Cotton: public Material{
    public:
        void Show(){
            cout << "棉布" << endl;
        }
    };

    class Linen: public Material{
    public:
        void Show(){
            cout << "麻布" << endl;
        }
    };
    
    class Factory {
    public:
        virtual ~Factory(){}
        virtual Material * GetMaterial() = 0;
        virtual Color * GetColor() = 0;
    };

    class RedCottonFactory: public Factory{
    public:
        Material* GetMaterial(){
            return new Cotton();
        }

        Color* GetColor(){
            return new RedColor();
        }

    };

    class GreenLinenFactory: public Factory{
    public:
        Material* GetMaterial(){
            return new Linen();
        }

        Color* GetColor(){
            return new GreenColor();
        }
    };

    class BlueSilkFactory: public Factory{
    public:
        Material* GetMaterial(){
            return new Silk();
        }

        Color* GetColor(){
            return new BlueColor();
        }
    };

}


