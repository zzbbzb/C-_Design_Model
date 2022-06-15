#include <iostream>
#include <string>

using namespace std;

/*
    简单工厂
    生产棉布
    生产麻布
    生产丝绸

    唯一工厂类，一个产品抽象类，工厂类的创建方法依据入参判断并创建具体产品对象

    对产品共同点进行抽象,
    生产工厂根据产品名生产对应产品

    缺点, 不符合开闭原则, 需要修改getIntance
*/

class Material{
public:
    virtual ~Material(){}

    virtual void Show() = 0;
};

class Silk: public Material{
public:
    void Show() {
        cout << "丝绸" << endl;
    }
};

class Cotton: public Material{
public:

    void Show() {
        cout << "棉布" << endl;
    }
};

class Linen: public Material{
public:
    void Show() {
        cout << "麻布" << endl;
    }
};

class MaterialFactory {
public:
    Material* GetIntance(string name) {
        if(name == "棉布") {
            return new Cotton();
        } else if( name == "麻布") {
            return new Linen();
        } else if ( name == "丝绸") {
            return new Silk();
        }
    }
};

