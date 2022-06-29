// TOOD 适配器

/*
    将一个类的接口转换成客户希望的另一个接口, 适配器使得接口不兼容而不能一起工作的类可以一起工作

代码结构:
    1. 继承或依赖已有的对象, 实现想要的目标接口

例子:
    AdvancedMediaPlayer 和 AdvancedMediaPlayer的实体类, 可以播放vlc和mp4格式的文件
    MediaPlayer 接口和 MediaPlayer 实体类 AudioPlayer 可以播放 mp3 格式
    写一个Adapter, 让AudioPlayer可以播放其他格式的文件
*/

#include <string>
#include <iostream>

namespace AdapterSpace {

    class MediaPlayer{
    public:
        virtual void Play(std::string type, std::string fileName) = 0;
    };
    
    class mPlayer {
    public:
        virtual void Play(std::string fileName) = 0;
    };

    class AudioPlayer: public mPlayer{
    public:
        void Play(std::string fileName){
            std::cout << "播放mp3文件 " << fileName << std::endl;
        }
    };

    class AdvancedMediaPlayer {
    public:
        virtual void MediaPlay(std::string fileName) = 0;
    };

    class VlcMediaPlayer: public AdvancedMediaPlayer {
    public:
        void MediaPlay(std::string fileName) {
            std::cout << "播放vlc文件 " << fileName << std::endl;
        }
    };

    class Mp4MediaPlayer: public AdvancedMediaPlayer {
    public: 
        void MediaPlay(std::string fileName) {
            std::cout << "播放mp4文件 " << fileName << std::endl;
        }
    };

    class MediaPlayerAdapter: public AudioPlayer {
   
        AdvancedMediaPlayer* player;
    public:
        ~ MediaPlayerAdapter(){
            std::cout << "删除 指针 mediaPlayer" << std::endl;
            if(player != nullptr)
                delete player;
            player = nullptr;
        }

        void play(std::string type, std::string fileName){
            // 判断
            if(type == "mp3"){
                Play(fileName);
            } else if (type == "mp4"){
                player = new Mp4MediaPlayer();
                player->MediaPlay(fileName);
            } else if (type == "vlc") {
                player = new VlcMediaPlayer();
                player->MediaPlay(fileName);
            }
        }

    };

}