# Records of learning the game engine_Hazel  
# (学习 游戏引擎_榛子 的记录)
Description: This is a personal log of learning a game engine, with the aim of recreating the Hazel game engine developed by The Cherno.  
(描述：这是一个学习游戏引擎的个人记录，目标是复现由 The Cherno 编写的 Hazel 游戏引擎。)  
To avoid misunderstandings, I would like to reiterate that this record is mostly machine-translated.In the text, including but not limited to: the Chinese or English parts, the expressions may not be accurate.  
(为了避免误会,再次声明,且该记录多为机翻.文中，包括但不限于：中文或英文部分，表达的可能不准确。)
# This is a record of learning the Hazel game engine, The original creator of the Hazel game engine is The Cherno. (这是学习Hazel游戏引擎的记录，Hazel游戏引擎的原始创建者是The Cherno。)
# Original Project(原始项目): The original Hazel game engine can be found at: https://github.com/TheCherno/Hazel (原始的Hazel游戏引擎可以在以下地址找到：https://github.com/TheCherno/Hazel)  
## License(许可证)
This project is licensed under the Apache License, Version 2.0. See the LICENSE file for details. (本项目根据 Apache 许可证第 2.0 版进行许可。详细信息请参阅 LICENSE 文件。)  
### Third-party library reference declaration(第三方库引用声明)  
  Special thanks to the authors of the third-party libraries used in engine learning: The logging system is based on the spdlog project by gabime [url = https://github.com/gabime/spdlog.git]  
  额外鸣谢在引擎学习中所使用的第三方库作者:  
  日志系统引用库 来自 gabime的spdlog项目[url = https://github.com/gabime/spdlog.git]  
  
Add a new line commit in VsCode.  
Test Markdown syntax for line breaks//"空格空格回车"  Set as a heading level//"井号空格"
alt+shift+stay_Click ->框选  
### Learning objectives(学习目标):  
# The Cherno's Game Engine Tutorial (The Cherno的游戏引擎教程):  
YouTube platform link: <https://www.youtube.com/watch?v=JxIZbV_XjAs&list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT>  
哔哩哔哩 平台翻译后的链接: <https://www.bilibili.com/video/BV1mw41187Ac?vd_source=19057ea4478296c5eac97eb7dcf4e71e> 译者:SPEAUTY  
### Current progress and key points of the personal study tutorial(个人学习教程的当前进度和重点记录):  
[ ] 1-3:  No code, skip(无代码,跳过),Among them are the 3 design levels: timestamp 20:50(其中3设计层级:时间戳 20:50).  
[ ] 4_项目设置:    03:22->创建仓库和声明(Apache License 2.0)  
      {对开源协议不懂,跳转到相关教程:  
      【常见的开源许可证及主要区别（包括GPL许可证，Apache许可证，BSD许可证，MIT许可证，Mozilla许可证，MulanPSL许可证）】https://www.bilibili.com/video/BV1KW4y1r7rX?vd_source=19057ea4478296c5eac97eb7dcf4e71e  
      08:50正式开始介绍 Apache License 2.0:【Apache协议】https://www.bilibili.com/video/BV17G411m7v7?vd_source=19057ea4478296c5eac97eb7dcf4e71e  
      }  
         06:34->创建Hazel项目  
                  08:12->拉取库,将创建的 .sln 移动到库  
                  09:33->介绍动态链接与静态链接的区别:更加详细跳转:【The cherno(C++课程) part1】https://www.bilibili.com/video/BV1bmbZzqEg7?vd_source=19057ea4478296c5eac97eb7dcf4e71e  
                  10:56->项目设置(right_Click: Learn_Hazel -> Properties)  
                  11:50->(Configuration Manager)删掉不需要的平台,如X86,Win32  
                  12:12->配置类型(General->Configuration Type: exe->dll): Dynamic Library(.dll)  
                  12:32->跳转->关于如何在Windows上设置C++的视频:
                  13:06->设置 输出,中间目录(Output Directory: $(SolutionDir)$(Platform)\$(Configuration)\ -> $(SolutionDir)bin\$(Configuration)-$(Platform)\$(ProjectName)\ , Intermediate Directory: $(Platform)\$(Configuration)\ -> $(SolutionDir)bin\int\$(Configuration)-$(Platform)\$(ProjectName)\ )  
                  15:41->添加项目Sandbox(right_Click: Solution 'Learn_Hazel' -> Add->New Projects... ->Empty Project) -> 同上项目设置  
                  16:36->设置Sandbox为启动项(right_Click: Sandbox -> Set as Startup Project)  
                  17:17->通过VS Code 打开 Learn_Hazel.sln ->将Sandbox从列表的第二项移到第一项  
                  18:05->设置Sandbox的引用(right_Click: Sandbox -> Add->Reference->勾选Lean_Hazel)  
                  18:27->设置连接器(right_Click: Learn_Hazel -> Properties -> Linker -> Command Line ?应该有Learn_Hazle.dll但是没有?)  
                  19:24->设置项目筛选器
                  20:07->创建命名空间: namespace Learn_Hazel  
                  21:12->构建(先构建Learn_Hazel 然后将Learn_Hazel.dll(Learn_GameEngine_Hazel\Learn_Hazel\bin\Debug-x64\Learn_Hazel)移到Sandbox输出exe里(Learn_GameEngine_Hazel\Learn_Hazel\bin\Debug-x64\Sandbox),然后构建Sandbox)->成功后终端输出Hello...  
      !!!: 出现了2个问题:1.项目设置dll时未采用All Configurations, 2. 命名空间的使用你在调用   Print   函数时，使用了   Learn_Hazel:Print()  ，这是错误的。在 C++ 中，命名空间的正确使用方式是   Learn_Hazel::Print()  ，其中   ::   是作用域解析运算符。
  
[ ] 5_入口点:     02:42->解释上一章代码  
                  04:48->创建c++类:Application,获取Application 类,并将其放入命名空间  
                  05:42->写一个Run,插入循环,控制程序运行  
                  05:57->将虚构方法变为虚方法,因为这个类会被Sandbox程序继承  
                  06:17->必须根据dll的写入位置来设置__declspec(dllexport)或declspec(dllimport)  
                  07:01->在Core.h中定义平台,免去繁琐的__declspec(dllexport)或declspec(dllimport),替换为HAZEL_API,然后定义平台,(right_Click: Learn_Hazel -> Properties ->从C\C++ ->Preprocessor-> Preprocessor Definitions:HZ_PLATFORM_WINDOWS;HZ_BUILD_DLL; ,right_Click: Sandbox ->Properties ->从C\C++ ->Preprocessor-> Preprocessor Definitions:HZ_PLATFORM_WINDOWS;)   
                  09:29->代码转折  
                  10:58->设置包含目录(right_Click -> Sandbox -> Properties -> C/C++ -> General -> Additional Include Directories: $(SolutionDir)Learn_Hazel\src; ) ->这样包含时用不用叫角号都可以  
                  11:45->创建Sandbx类  
                  13:19->视频中修复了他之前的2个错误(HZ_BUILD_DLL被误写成了HAZEL_BUILD_DLL, void main() 变为int main(),记得更新Dll)  
      ...: 在本项目中,修改了部分代码,使成功显示更直观,成功应无限刷新输出 Hello Learn Hazel !  
                  14:19->创建入口点  
                  15:15->创建Hazel应用,这里用argc, argv作为参数, 需要去搜索创建应用程序的方法  
                  16:25->Application* CreateApplication(); //To be defined in client  
                  17:39->auto app = Hazel::CreateApplication();
                  18:40->更改了一个疏忽:Hazel::Application* CreateApplication()应改为Hazel::Application* Hazel::CreateApplication()  
      ...: 成功运行,成功应无限刷新输出 Hello Learn Hazel !  
                  18:15->入口点设置成功  
      ...: 成功运行,成功应输出:Hazel Engine was started !  
                              Hello Learn Hazel !  
                              Hazel Engine is being updated !Hello Learn Hazel !  
                              Hazel Engine is being updated !Hello Learn Hazel !  
                              Hazel Engine is being updated !Hello Learn Hazel !...  
                  21:37->关于git的一些使用：创建.gitignore,使其提交时忽略：.vs/, bin/,bin-int/ 三个文件夹，和*.user等用户文件  
                     
[ ] 6_日志:     为什么引入:可以使知道 1.消息来源, 2.严重程度 ->这就需要一个string_format函数,即需要明确 字符串格式 -> 所以引入库 spdlog  
                  05:47->下载 spdlog 跳转链接:https://github.com/gabime/spdlog.git  
                  06:07->查看示例  
                  06:42->关于MIT许可证 -> {对开源协议不懂,跳转到相关教程:  
      【常见的开源许可证及主要区别（包括GPL许可证，Apache许可证，BSD许可证，MIT许可证，Mozilla许可证，MulanPSL许可证）】https://www.bilibili.com/video/BV1KW4y1r7rX?vd_source=19057ea4478296c5eac97eb7dcf4e71e  
      08:50正式开始介绍 【MIT、WTFPL协议】https://www.bilibili.com/video/BV1Ch4y1z784?vd_source=19057ea4478296c5eac97eb7dcf4e71e  
      }  
                  07:42->选择构建系统: 1.CMake, 2.Premake 等 以及或者使用: git submodule  
                  10:05->此处应该添加跳转链接:关于git子模块的视频  
                  10:26->使用git submodule add 加目标库链接 加存放地址: Hazel/vendor/spdlog (命令: git submodule add https://github.com/gabime/spdlog.git Learn_Hazel/vendor/spdlog)  
      ...: 成功会出现一个 .gitmodules 文件  
                  11:52->添加地址到附加包含目录-> (right_Click: Learn_Hazel -> Properties ->C/C++ -> General -> Additional Include Directories : $(SolutionDir)Learn_Hazel\vendor\spdlog\include; , right_Click -> Sandbox -> Properties -> C/C++ -> General -> Additional Include Directories: $(SolutionDir)Learn_Hazel\src;$(SolutionDir)Learn_Hazel\vendor\spdlog\include;)   
                  13:23->改变第三方库的API,换成HAZEL_API,方便后续变更库->使在不改变客户端代码的情况下切换  
                  14:17->所以需要创建一个 日志类 ->包含spdlog-> 调用静态函数 (基本就是搞 包装器)  
                  14:28->实现 日志类 (Class Log)  
                  15:38->在Log.h中引入spdlog/spdlog.h  
                  17:00->创建: static void Init(); inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; } inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
                  17:34->要包含#include <memory> 这样可以使用头指针  
                  18:00->将std::shared_ptr < spdlog::logger > s_CoreLogger;非静态 添加static 变成静态，因为上面引用为静态  
                  19:00->Init() spdlog::set_pattern("%^[%T] %n:%v%$"); ->设置消息时间戳，日志名等  
                  19:29->参考https://github.com/gabime/spdlog 中的Usage samples 编写void Log::Init(){};  
                  20:05-> 设置日志级别 s_CoreLogger->set_level(spdlog::level::trace);  
                  21:46->在Hazle.h中包含#include "Hazel/Log.h"  
                  22:02->调试错误(因为the cherno没有及时更新Hazel.dll)  
                  22:29->在EntryPoint.h中使用 	 Hazel::Log::Init(); 
	                                          Hazel::Log::GetCoreLogger()->warn("Initialized log !");
	                                          Hazel::Log::GetClientLogger()->info("Hello App !");  
             ...: 注释掉Application.cpp中//printf("Hello Learn Hazel !\nHazel Engine is being updated !"); 以免刷屏后推掉开始的log信息.  
             ...: 成功运行,成功应输出: 
                              [10:46:47] HAZEL:Initialized log ! (文本应是黄色)
                              [10:46:47] APP:Hello App !(文本应是绿色)
                              Hello Learn Hazel !
                              Hazel Engine was started !  
                  23:16->创建宏 -> 替换 Hazel::Log::GetCoreLogger() 如在Log.g中定义: // Core log macros
                                        #define HZ_CORE_TRACE(...)	::Hazel::Log::GetCoreLogger()->trace(__VA_ARGS__)  
                  26:06->在定义宏后,EntryPoint.h中用宏替换掉Hazel::Log::GetCoreLogger() ->变为:  
                                    	Hazel::Log::Init();
	                                    HZ_CORE_WARN("Initialized log !");
	                                    HZ_CLIENT_INFO("Hello App !");
	                                    int a =5;
	                                    HZ_INFO("Hello! Var={0}",a);
	                                    printf("Hello Learn Hazel !\nHazel Engine was started !\n");  
              ...: 注: 在上一次提交中，Log.h中 HZ_CLIENT_...没有大写，本次提交整正  
              ...: 成功运行,成功应输出: [11:24:03] HAZEL:Initialized log !
                                      [11:24:03] APP:Hello App !
                                      [11:24:03] APP:Hello! Var=5
                                      Hello Learn Hazel !
                                      Hazel Engine was started !   
                  26:52->补充说明:建议从发行版中剔除CoreLog->用:  
                  //if dist build  
                  #define HZ_CORE_INFO  
                                  
                        
            
                  

		
                  






