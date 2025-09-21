#include "Hazel.h"
class Sandbox : public Hazel::Application
{
public:
	Sandbox() {}
	~Sandbox(){}
};

//int main()
//{
//	Sandbox* sandbox = new Sandbox();
//	sandbox->Run();
//	delete sandbox;
//}
Hazel::Application* Hazel::CreateApplication() 
{
	return new Sandbox();
}