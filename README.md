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

Add a new line commit in VsCode.  
Test Markdown syntax for line breaks//"空格空格回车"  Set as a heading level//"井号空格"
### Learning objectives(学习目标):  
# The Cherno's Game Engine Tutorial (The Cherno的游戏引擎教程):  
YouTube platform link: <https://www.youtube.com/watch?v=JxIZbV_XjAs&list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT>  
哔哩哔哩 平台翻译后的链接: <https://www.bilibili.com/video/BV1mw41187Ac?vd_source=19057ea4478296c5eac97eb7dcf4e71e> 译者:SPEAUTY  
### Current progress and key points of the personal study tutorial(个人学习教程的当前进度和重点记录):  
[ ] 1-3:  No code, skip(无代码,跳过),Among them are the 3 design levels: timestamp 20:50(其中3设计层级:时间戳 20:50).  
[ ] 4:    03:22->创建仓库和声明(Apache License 2.0)  
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
                  13:06->设置 输出,中间目录(Output Directory: $(SolutionDir)$(Platform)\$(Configuration)\ -> $(SolutionDir)bin\$(Configuration)-$(Platform)\$(ProjectName)\ , Intermediate Directory: $(Platform)\$(Configuration)\ -> $(SolutionDir)bin-int\$(Configuration)-$(Platform)\$(ProjectName)\ )  
                  15:41->添加项目Sandbox(right_Click: Solution 'Learn_Hazel' -> Add->New Projects... ->Empty Project) -> 同上项目设置  
                  16:36->设置Sandbox为启动项(right_Click: Sandbox -> Set as Startup Project)  
                  17:17->通过VS Code 打开 Learn_Hazel.sln ->将Sandbox从列表的第二项移到第一项  
                  18:05->设置Sandbox的引用(right_Click: Sandbox -> Add->Reference->勾选Lean_Hazel)  
                  18:27->设置连接器(right_Click: Learn_Hazel -> Properties -> Linker -> Command Line ?应该有Learn_Hazle.dll但是没有?)  
                  19:24->设置项目筛选器
                  20:07->创建命名空间: namespace Learn_Hazel  
                  21:12->构建  
      !!!: 出现了2个问题:项目设置dll时未采用All Configurations, 2. 命名空间的使用你在调用   Print   函数时，使用了   Learn_Hazel:Print()  ，这是错误的。在 C++ 中，命名空间的正确使用方式是   Learn_Hazel::Print()  ，其中   ::   是作用域解析运算符。




