
/*
    单例模式 
    饿汉模式 程序开始就创建 线程安全, 但是static 的循序有关系
*/

    
class HungryMode {
private:
    HungryMode(){}
    HungryMode(HungryMode& l) = delete;
    HungryMode& operator = (HungryMode& l) = delete;
    static HungryMode* singleMode;
    class HungryModeDeletor{
    public:
        ~HungryModeDeletor(){
            if(singleMode != nullptr){
                delete singleMode;
            }
        }
    };
    static HungryModeDeletor dr;
    
public:
    static HungryMode* GetInstance(){
        return singleMode;
    }
};

HungryMode* HungryMode::singleMode = new HungryMode();