// TODO 代理模式

/*
代码结构:
    实现, 被代理类组合
注意事项:
    1. 和适配器的区别: 适配器模式主要改变所考虑对象的接口, 代理模式不能改变所代理类的接口
    2. 和装饰器的区别: 装饰器模式为了增强功能, 代理模式为了加以控制
例子:
    创建一个Image接口和实现Image接口的实体类
    ProxyImage来获取要加载的Image对象
*/

#include <iostream>
#include <string>
#include <unistd.h>

namespace ProxySpace {

    class Image {
    public:
        virtual void Display() = 0;
    };

    class RealImage: public Image {
    private:
        std::string fileName;
    public:
        RealImage(std::string fileName) {
            this->fileName = fileName;
            loadImgFromDisk(fileName);
        }
        void loadImgFromDisk(std::string fileName){
            std::cout << "加载 " << fileName << "的图片" << std::endl;
            sleep(2);
        }

        void Display() {
            std::cout << "展示 " << fileName << "图片" << std::endl;
        }
    };

    class ProxyImage: public Image {
    private:
        std::string fileName;
        Image* image;

    public:
        ProxyImage(std::string fileName){
            this->fileName = fileName;
            image = nullptr;
        }

        ~ProxyImage(){
            std::cout << "释放realImg" << std::endl; 
            delete image;
        }

        void Display() {
            if(image == nullptr) {
                image = new RealImage(fileName);
            }
            image->Display();
        }
    };

}