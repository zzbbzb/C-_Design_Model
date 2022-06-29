

#include <functional>
#include <chrono>

#define CalFuncExecTime(content, text) Decorator2::FuncTimer<void *, void *>([&](void *) -> void * {\
	do{content}while(false);\
	return nullptr;\
}, text)(nullptr)\

namespace Decorator2{


    int test(int b, int c){
        return b + c;
    };
    /*
    装饰器基类
    FUN_RET_TYPE 函数返回值类型
    FUN_ARGS 函数参数类型
    */
    template<typename FUN_RET_TYPE, typename ... FUN_ARGS>
    class Decorator{
    protected:
        std::function<FUN_RET_TYPE(FUN_ARGS...)> decorated_func;
    public:
        explicit Decorator(const std::function<FUN_RET_TYPE(FUN_ARGS...)>& p_fun) {
            decorated_func = p_fun;
        }

        explicit Decorator(FUN_RET_TYPE(*p_func)(FUN_ARGS... )): Decorator(std::function<FUN_RET_TYPE(FUN_ARGS...)>(p_func)) {}

        virtual FUN_RET_TYPE operator() (FUN_ARGS... args) = 0;
    };

    template<typename FUN_RET_TYPE, typename ... FUN_ARGS>
    class FuncTimer: public Decorator<FUN_RET_TYPE, FUN_ARGS...>{
    private:
        // 计时器的提示字符串
        std::string tip_str;
    public:
        explicit FuncTimer(const std::function<FUN_RET_TYPE(FUN_ARGS... )>& p_func, std::string tip_s = ""): Decorator<FUN_RET_TYPE, FUN_ARGS...>(p_func), tip_str(std::move(tip_s)){}

        // explicit FuncTimer(FUN_RET_TYPE(*p_func)(FUN_ARGS...), std::string tip_s = ""): Decorator<FUN_RET_TYPE, FUN_ARGS...>(p_func), tip_str(std::move(tip_s)){}

        FUN_RET_TYPE operator()(FUN_ARGS... args) {
            // 使用函数前记录时间
            auto before = std::chrono::system_clock::now().time_since_epoch().count();
            FUN_RET_TYPE result = this->decorated_func(args...);
            // 调用函数后记录时间
            auto after = std::chrono::system_clock::now().time_since_epoch().count();
            std::cout << tip_str << after - before << std::endl;
            return result;
        }  
    };
}
