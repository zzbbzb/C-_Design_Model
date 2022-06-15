
/*
    单例模式 

    懒汉模式 等到用到时候才会创建
*/

// TODO 线程安全

class LazyMode {

    private:
        LazyMode(){}

        LazyMode(LazyMode& l) = delete;
        LazyMode& operator = (LazyMode& l) = delete;

        static LazyMode* lazySingleMode; 
        ~ LazyMode(){}

        class LazyModeDeletor{
        public:
            ~LazyModeDeletor(){
                if(lazySingleMode != nullptr){
                    delete lazySingleMode;
                    lazySingleMode = nullptr;
                }
            }
        };

        static LazyModeDeletor dr;
        
    public:
        static LazyMode* GetInstance(){
            if (lazySingleMode == nullptr){
                return new LazyMode();
            }

            return lazySingleMode;
        }
};

LazyMode* LazyMode::lazySingleMode = nullptr;