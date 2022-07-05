// TODO 命令模式

/*
 

代码结构:
 定义3个角色
 1. received 真正命令执行的对象
 2. Command
 3. invoker 使用命令对象的入口
缺点:
 会导致过多具体的Command类

例子:
 去餐厅吃饭, 我们通过服务员来点单, 具体谁来做这些菜, 和什么时候完成, 不知道
 我们是菜单的请求者, 厨师是菜单的实现者, 两者是松耦合的
*/

#include <iostream>
#include <memory>
#include <vector>

namespace CommandSpace {
 class Chef {

 public:
  void BarbecueMeat() {
   std::cout << "烤肉" << std::endl;
  }

  void Fried() {
   std::cout << "炒菜" << std::endl;
  }
 };
 class ICommand {
 protected:
  std::shared_ptr<Chef> chef;
 public:
  ICommand(std::shared_ptr<Chef> chef) :chef(chef) {}
  virtual void Execute() = 0;
 };

 class BarbecueCommand : public ICommand {
 
 public:
  BarbecueCommand(std::shared_ptr<Chef> chef):ICommand(chef){}

  void Execute() {
   chef->BarbecueMeat();
  }
 };

 class FriedDishCommand : public ICommand {

 public:
  FriedDishCommand(std::shared_ptr<Chef> chef) :ICommand(chef){}

  void Execute() {
   chef->Fried();
  }
 };

 class Waiter {
 private:
  std::vector<std::shared_ptr<ICommand>> commondList;
 public:
  void SetOrder(std::shared_ptr<ICommand> command) {
   commondList.push_back(command);
  }

  void Notify() {
   for (int i = 0; i < commondList.size(); i++) {
    commondList[i]->Execute();
   }
  }
 };
}