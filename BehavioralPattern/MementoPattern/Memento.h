// TODO 备忘录

/*
 保存一个对象的某个状态, 以便在适当的时候恢复对象
代码结构:
 通过一个备忘录类专门存储对象状态
 发起人角色(Originator): 创建备忘录, 记录自身需要保存的状态, 具备状态回滚功能
 备忘录角色(Memento): 用于存储Originator的内部状态, 可以防止Originator以外的对象访问
 备忘录管理角色(Caretaker): 负责存储，提供管理员备忘录, 无法对备忘录内容进行操作和访问


*/

#include <iostream>
#include <string>
#include <vector>
#include <memory>

namespace MementoSpace {

 class Memento {
 private:
  std::string state;
 public:
  Memento(std::string state): state(state){}
  
  std::string GetState() {
   return state;
  }
 };

 class Originator {
 private:
  std::string state;
 public:
  void SetState(std::string state) {
   this->state = state;
  }

  std::string GetState() {
   return state;
  }

  std::shared_ptr<Memento> SaveStateToMemento() {
   return std::shared_ptr<Memento>(new Memento(state));
  }

  void GetStateFromMemento(std::shared_ptr<Memento> memento) {
   state = memento->GetState();
  }
 };

 class CareTaker {
 private:
  std::vector<std::shared_ptr<Memento>> mementoList;
 public:
  void Add(std::shared_ptr<Memento> m) {
   mementoList.push_back(m);
  }

  std::shared_ptr<Memento> Get(int index) {
   return mementoList[index];
  }
 };

}