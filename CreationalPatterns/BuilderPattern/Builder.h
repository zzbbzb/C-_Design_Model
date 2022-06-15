// TODO

#include <vector>
#include <string>
#include <iostream>

/*
    建造者模式
    
    多个简单对象构建成一个复杂对象

    基本部件不会变, 组合会变
    
    例子: 
    快餐店 套餐是 汉堡 和 冷饮
    汉堡分为 素食汉堡 和 鸡肉汉堡 , 并用纸盒包装
    冷饮分为 可口可乐 和 百事, 用瓶子包装

    创建菜单, 根据不同组合生成不同的套餐    
*/

namespace BuilderPattern {


    using namespace std;

    class Packing {
    public:
        virtual string GetName() = 0;
    };

    class Item {
    public:
        Packing* p;
        virtual string Name() = 0;
        virtual Packing* GetPacking() = 0;
        virtual float Price() = 0;
        virtual ~Item() {};
    };

    class Wrapper : public Packing {
    public:
        string GetName() {
            return "纸盒包装";
        }
    };

    class Bottle: public Packing {
    public:
        string GetName() {
            return "瓶子包装";
        }
    };

    class Burger: public Item {
    public:
        virtual Packing* GetPacking(){
            p = new Wrapper();
            return p;
        }

        virtual ~Burger(){
            cout << "释放" << p->GetName() << endl;
            delete p;
            p = nullptr;
        }
    };

    class ColdDrink: public Item{
    public:
        virtual Packing* GetPacking(){
            p = new Bottle();
            return p;
        }
        virtual ~ColdDrink(){
            cout << "释放" << p->GetName() << endl;
            delete p;
            p = nullptr;
        }
    };

    class VegBurger: public Burger{
    public:
        virtual string Name(){
            return "蔬菜汉堡";
        }

        virtual float Price() {
            return 10.0;
        }
    };

    class ChickenBurger: public Burger{
    public:
         virtual string Name(){
            return "鸡肉汉堡";
        }

        virtual float Price() {
            return 20.0;
        }
    };

    class Coke: public ColdDrink{
    public:
         virtual string Name(){
            return "可口可乐";
        }

        virtual float Price() {
            return 5.0;
        }
    };

    class Pepsi: public ColdDrink{
    public:
         virtual string Name(){
            return "百事可乐";
        }

        virtual float Price() {
            return 5.0;
        }
    };

    class Meal {
    public:
        vector<Item*> items;

 
        void AddItem(Item* item){
            items.push_back(item);
        }

        float GetCost(){
            float totalCost = 0.0;
            for(int i = 0; i < items.size(); i++)
            {
                totalCost += items[i]->Price();
            }
            return totalCost;
        }

        void ShowItem(){
            for(int i = 0; i < items.size(); i++)
            {
                cout << items[i]->GetPacking()->GetName() << items[i]->Name() << items[i]->Price() << endl;
            } 
        }
    };

    class MealBuilder{
    public:
        Meal* PrepareVegMeal(){
            Meal* meal = new Meal();
            meal->AddItem(new VegBurger());
            meal->AddItem(new Coke());
            return meal;
        }

        Meal* PrepareNonVegMeal(){
            Meal* meal = new Meal();
            meal->AddItem(new ChickenBurger());
            meal->AddItem(new Pepsi());
            return meal;
        }

        void Delete(Meal* meal){
            cout << "Delete" << endl;
            for(int i = 0; i < meal->items.size(); i++)
            {
                delete meal->items[i];
            }

            delete meal;
        }

        ~MealBuilder(){
            cout << "deleted MealBuilder" << endl;
        }
    };

}