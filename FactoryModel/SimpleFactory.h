#include <iostream>
#include <string>

using namespace std;

/*
    简单工厂
    生产红色棉布
    生产绿色麻布
    生产蓝色丝绸

    对产品共同点进行抽象,
    生产工厂根据产品名生产对应产品

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

class MaterialFactory {
public:
    Material* GetIntance(string name) {
        if(name == "红色棉布") {
            return new Cotton("红色", "棉布");
        } else if( name == "绿色麻布") {
            return new Linen("绿色", "麻布");
        } else if ( name == "蓝色丝绸") {
            return new Silk("蓝色", "丝绸");
        }
    }
};

