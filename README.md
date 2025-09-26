# Records of learning the game engine_Hazel  
# (学习 游戏引擎_榛子 的记录)
Description: `This is a personal log of learning a game engine`, with the aim of recreating the Hazel game engine developed by The Cherno.  
(描述：`这是一个学习游戏引擎的个人记录`，目标是复现由 The Cherno 编写的 Hazel 游戏引擎。)  
To avoid misunderstandings, I would like to reiterate that this record is mostly machine-translated.In the text, including but not limited to: the Chinese or English parts, the expressions may not be accurate.  
(为了避免误会,再次声明,且该记录多为机翻.文中，包括但不限于：中文或英文部分，表达的可能不准确。)
# This is a record of learning the Hazel game engine, The original creator of the Hazel game engine is `The Cherno`. (这是学习Hazel游戏引擎的记录，Hazel游戏引擎的`原始创建者是The Cherno`。)
# `Original Project(原始项目)`: The original Hazel game engine can be found at: https://github.com/TheCherno/Hazel (原始的Hazel游戏引擎可以在以下地址找到：https://github.com/TheCherno/Hazel)  
## License(许可证)
This project is licensed under the Apache License, Version 2.0. See the LICENSE file for details. (本项目根据 Apache 许可证第 2.0 版进行许可。详细信息请参阅 LICENSE 文件。)  
### Third-party library reference declaration(第三方库引用声明)  
  Special thanks to the authors of the third-party libraries used in engine learning: The logging system is based on the spdlog project by gabime [url = https://github.com/gabime/spdlog.git]  
  额外鸣谢在引擎学习中所使用的第三方库作者:  
  1. 日志系统引用库 来自 gabime的spdlog项目[url = https://github.com/gabime/spdlog.git]  
  2. 构建库:premake 来自premake的premake-core项目[url =https://github.com/premake/premake-core.git]  

小贴士:在vs中alt+shift+stay_Click ->框选  这种快捷键很好用.
### Learning objectives(学习目标):  
# The Cherno's Game Engine Tutorial (The Cherno的游戏引擎教程):  
YouTube platform link: <https://www.youtube.com/watch?v=JxIZbV_XjAs&list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT>  
哔哩哔哩 平台翻译后的链接: <https://www.bilibili.com/video/BV1mw41187Ac?vd_source=19057ea4478296c5eac97eb7dcf4e71e> 译者:SPEAUTY  
### Current progress and key points of the personal study tutorial(个人学习教程的当前进度和重点记录):  
1. ~No code, skip(无代码,跳过)
2. ~No code, skip(无代码,跳过)
3. ~No code, skip(无代码,跳过),  
 Among them are the 3 design levels: timestamp 20:50(其中3设计层级:时间戳 20:50).  
4. 项目设置:  
* [ ] 03:22->创建仓库和声明(Apache License 2.0)  
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
  
5. 入口点:  
* [ ] 02:42->解释上一章代码  
                  04:48->创建c++类:Application,获取Application 类,并将其放入命名空间  
                  05:42->写一个Run,插入循环,控制程序运行  
                  05:57->将虚构方法变为虚方法,因为这个类会被Sandbox程序继承  
                  06:17->必须根据dll的写入位置来设置__declspec(dllexport)或declspec(dllimport)  
                  07:01->在Core.h中定义平台,免去繁琐的__declspec(dllexport)或declspec(dllimport),替换为HAZEL_API,然后定义平台,(`right_Click: Learn_Hazel -> Properties ->从C\C++ ->Preprocessor-> Preprocessor Definitions:HZ_PLATFORM_WINDOWS;HZ_BUILD_DLL; ,right_Click: Sandbox ->Properties ->从C\C++ ->Preprocessor-> Preprocessor Definitions:HZ_PLATFORM_WINDOWS;`)   
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
      ...: 成功运行,成功应输出:  

    Hazel Engine was started !  
    Hello Learn Hazel !  
    Hazel Engine is being updated !Hello Learn Hazel !  
    Hazel Engine is being updated !Hello Learn Hazel !  
    Hazel Engine is being updated !Hello Learn Hazel !  
    ...    

  21:37->关于git的一些使用：创建`.gitignore`,使其提交时忽略：.vs/, bin/,bin-int/ 三个文件夹，和*.user等用户文件  
                     
6. 日志:  
* [ ] 为什么引入:可以使知道 1.消息来源, 2.严重程度 ->这就需要一个string_format函数,即需要明确 字符串格式 -> 所以引入库 spdlog  
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
                  22:29->在EntryPoint.h中使用  
```
Hazel::Log::Init();  
Hazel::Log::GetCoreLogger()->warn("Initialized log !");  
Hazel::Log::GetClientLogger()->info("Hello App !");    
```
...: 注释掉Application.cpp中//printf("Hello Learn Hazel !\nHazel Engine is being updated !"); 以免刷屏后推掉开始的log信息.  
...: 成功运行,成功应输出: 
```
    [10:46:47] HAZEL:Initialized log ! (文本应是黄色)  
    [10:46:47] APP:Hello App !(文本应是绿色)  
    Hello Learn Hazel !  
    Hazel Engine was started !    
```
23:16->创建宏 -> 替换 Hazel::Log::GetCoreLogger() 如在Log.g中定义:  
    // Core log macros
    #define HZ_CORE_TRACE(...)	::Hazel::Log::GetCoreLogger()->trace(__VA_ARGS__)  

26:06->在定义宏后,EntryPoint.h中用宏替换掉Hazel::Log::GetCoreLogger() ->变为:  

    Hazel::Log::Init();  
    HZCORE_WARN("Initialized log !");  
    HZ_CLIENT_INFO("Hello App !");  
    int a =5;  
    HZ_INFO("Hello! Var={0}",a);  
    printf("Hello Learn Hazel !\nHazel Engine was started !\n");  _

...: 注: 在上一次提交中，Log.h中 HZ_CLIENT_...没有大写，本次提交整正  
...: 成功运行,成功应输出:  
```
[11:24:03] HAZEL:Initialized log !  
[11:24:03] APP:Hello App !  
[11:24:03] APP:Hello! Var=5  
Hello Learn Hazel !  
Hazel Engine was started !     
```
26:52->补充说明:建议从发行版中剔除CoreLog->用:
```
    //if dist build  
    #define HZ_CORE_INFO  
```
7. premake:  
* [ ] 使用项目生成器,而非手动  
                  04:55->开始 使用premake来设置 Hazle  
                  05:26->查看premake和其版权声明(需要版权声明被保留),premake项目链接: https://github.com/premake/premake-core.git  
                  05:39->去Release下载premake.exe,如在视频中The cherno所下载的Premake 5.0 alpha 13  
                  06:22->在外层Learn_Hazel中再创建一个vendor,不同于内层Learn_Hazel下的vendor(只包含用于Hazel的部分),在外层的vendor适用于全局 -> 将premake5.exe和LICENSE.txt复制到Learn_Hazel\vendor\bin\premake  
                  07:36->在Wiki中查看如何使用  
                  09:08->创建premake5.lua
                  12:58->关于标准(Token),去Wiki中搜索如何使用  
                  18:57->Turns out you can instead write systemversion "latest"  
                  20:30->关于postbuildcommands指令操作(去Wiki上查例子)  
                ...: 弹幕备注:  
{COPY}这个指令现在好像已经弃用了，取而代之的是{COPYDIR}，语法是类似的。  
COPY不可用，需要改成COPYFILE并且在复制前创建sandbox   ("{MKDIR} ../bin/" .. outputdir .. "/Sandbox"),  
beta版本的copy会显示创建文件夹失败，可以使用mkdir手动创建文件夹  
                  23:11->关于MT(多线程运行时库)  
                  26:31->使用premake构建  
                  27:25->the cherno 将之前漏掉的includedirs补上了  
                  29:05->将Sandbox再次设置为启动项目的这一步是有意义的，不要忽略(来自弹幕)  
...: 后续应该将premake5.exe也用 git submodule add 引用  
  
8. 事件系统计划:  
* [ ] No code, skip(无代码,跳过),Among them are the 3 design levels: timestamp 02:21(其中3设计层级:时间戳 20:50).  
                  02:21->开始规划图   
                  07:20->关于 阻塞事件  
                  08:01->关于缓冲事件系统  
9.  事件系统:    
  * 03:40->正式开始:
  * 04:43->关于预编译头文件(引擎越往下发展,越难集成到预编译头文件.)  
  * 07:24->关于事件类型:  
```C++
	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};
	enum EventCategory
	{
		None = 0,
		EventCategoryApplication	= BIT(0),
		EventCategoryInput			= BIT(1),
		EventCategoryKeyboard		= BIT(2),
		EventCategoryMouse			= BIT(3),
		EventCategoryMouseButton	= BIT(4)
	};
```

  * 08:39->在Core.h定义:(就是说如果执行BIT(1),会在位置上有一个比特,位字段?)
```C++
#define BIT(x) (1 << x)
```
* 10:30->事件的传递: (`bool m_Handled = false;`用于判断事件是否被处理过)
```C++
#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
	virtual EventType GetEventType() const override { return GetStaticType(); }\
	virtual const char* GetName() const override { return #type; }
#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override {return category;}
	class HAZEL_API Event
	{
		friend class EventDispatcher;
	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category)
		{
			//如果它的类别与传入的类别相同，则返回true
			return GetCategoryFlags() & category;
		}
		bool m_Handled = false;
	protected:
		//bool m_Handled = false;
	};
```
  * 11:48->关于`GetCategoryFlags()`部分可能的优化  
  * 13:17->关于`std::string ToString()`等,不应被实际游戏使用,运行时只用于调试  
  * 13:49->关于`KeyEvent.h`的解释.
  * 15:33->开始`KeyEvent.h`的代码部分:
    * 弹幕注释: 
      1. <-没实现纯虚函数就还是用Event的纯虚函数，这个KeyEvent还是被看作一个抽象类.
      2. 包含至少一个没实现的纯虚函数的派生类即为抽象类，不能被实例化，只能继承 
  * 16:23->关于KeyEvent.h: 中 int `repeatCount`的用处
  * 18:15-> 在 KeyEvent.h 中重写的: `std::string ToString() const override`之一 :
```C++
class HAZEL_API KeyPressedEvent : public KeyEvent
{
public:
	KeyPressedEvent(int keycode, int repeatCount)
		:KeyEvent(keycode), m_RepeatCount(repeatCount) {
	}
	inline int GetRepeatCount() const { return m_RepeatCount; } //获取重复次数
	std::string ToString() const override
	{
		std::stringstream ss;
		ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
		return ss.str();
	}
	//static EventType GetStaticType() { return EventType::KeyPressed; }\
	//	virtual EventType GetEventType() const override { return GetStaticType(); }\
	//	virtual const char* GetName() const override { return "KeyPressed"; }

	EVENT_CLASS_TYPE(KeyPressed)
private:
	int m_RepeatCount;//重复次数
};
```
  * 18:35->两个宏`EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)`与`EVENT_CLASS_TYPE(KeyPressed)`和三个虚函数: 
  ```C++
  virtual EventType GetEventType() const = 0;
  virtual const char* GetName() const = 0;
  virtual int GetCategoryFlags() const = 0;
  ```
  * 21:13-> `Dispatch`检查当前尝试调用的事件类型是否与此模板参数类型匹配:
```C++
bool Dispatch(EventFn<T> func)
{
	if (m_Event.GetEventType() == T::GetStaticType())
	{
		m_Event.m_Handled = func(*(T*)&m_Event);
		return true;
	}
	return false;
}
```
  * 23:17->关于MouseEvent.h两个宏`EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput) //事件类别` And `EVENT_CLASS_TYPE(MouseButtonPressed) //事件类型`
  * 29:24->通过 `git difftool --dir-diff`来查看tutorial_9 与 tutorial_10 的代码对比 
  * 31:55->代码运行_1结果
  * 32:08->测试`IsInCategory()`
  * 32:41->代码运行_2结果
...: 由于本项目没有注释掉: `HZ_TRACE("{}", e.ToString());`  
--成功运行,成功应输出:(比theCherno演示的要多一次输出) 

```
[11:42:06] HAZEL:Initialized log !
[11:42:06] APP:Hello App !
[11:42:06] APP:Hello! Var=5
Hello Learn Hazel !
Hazel Engine was started !
[11:42:06] APP:WindowResizeEvent: 1280, 720
[11:42:06] APP:WindowResizeEvent: 1280, 720

```
10.预编译头:    
  * 00:48-> About Precompiled Headers:
    * 关于precompiledHeaders更详细的视频介绍: https://www.youtube.com/watch?v=eSI4wctZUto
      * Yuotube->8:37->预编译头应只包含:比如说，标准模板库，windows API调用之类的,你不会更改的外部文件.
      * Yuotube->12:20->正式开始演示
  * 01:07->正式开始代码:
  * 01:56->make a C++ file called hzpch.cpp
  * 02:47->We could make a precompiled header be separate for each platform
```C++
#ifdef HZ_PLATFORM_WINDOWS
#include <Windows.h>
#endif
```
  * 04:33->write pchheader...in `premake5.lua`
```Lua
project "Learn_Hazel"
    location "Learn_Hazel"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin/int/" .. outputdir .. "/%{prj.name}")

    pchheader "hzpch.h"
    pchsource "Learn_Hazel/src/hzpch.cpp"
```

  * 05:16->相当于在VS里操作  
`right_Click: hzpch.cpp -> Properties ->从C\C++ -> Precompiled Headers ->Precompiled Header :Create(/Yc) ;`  
`right_Click: Learn_Hazel -> Properties ->从C\C++ -> Precompiled Headers ->Precompiled Header :Use(/Yu) ;`  
`right_Click: Learn_Hazel -> Properties ->从C\C++ -> Precompiled Headers ->Precompiled Header File :hzpch.h ;`
 * 07:37->在每一个文件第一个包含`hzpch.h'
```C++
//hzpch.h:
#pragma once

#include <iostream>
#include <memory>// For std::shared_ptr
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "Hazel/Log.h"

#ifdef HZ_PLATFORM_WINDOWS
#include <Windows.h>
#endif
```
11.窗口抽象 和 GLFW :    
  * 00:00->




