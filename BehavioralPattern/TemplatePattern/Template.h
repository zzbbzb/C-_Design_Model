// TODO 模板

/*
 一个抽象类公开定义了执行它的方法的方式/模板, 它的子类按需要重写方法实现
代码结构:
 抽象类实现
例子:
 定义操作的Game抽象类, 其中模板设置为final, 不会被重写
 Cricket和Football是扩展Game的实体类, 重写抽象类的方法
*/

#include <iostream>

namespace TemplateSpace {

 class Game {
 public:
  virtual void Initialize() = 0;
  virtual void StartPlay() = 0;
  virtual void EndPlay() = 0;

  virtual void Play() final {
   // 初始化游戏
   Initialize();

   // 开始游戏
   StartPlay();

   // 结束游戏
   EndPlay();
  }
 };

 class Cricket : public Game {

  void EndPlay() override {
   std::cout << "Cricket Game Finished!" << std::endl;
  }

  void Initialize() override {
   std::cout << "Cricket Game Initialized! Start playing." << std::endl;
  }

  void StartPlay() override {
   std::cout << "Cricket Game Started. Enjoy the game!" << std::endl;
  }
 };

 class FootBall : public Game {

  void EndPlay() {
   std::cout << "Football Game Finished!" << std::endl;
  }

  void Initialize() {
   std::cout << "Football Game Initialized! Start playing." << std::endl;
  }

  void StartPlay() {
   std::cout << "Football Game Started. Enjoy the game!" << std::endl;
  }
 };
}