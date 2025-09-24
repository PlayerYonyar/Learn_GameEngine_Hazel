#pragma once
#ifdef HZ_PLATFORM_WINDOWS
extern Hazel::Application* Hazel::CreateApplication();
int main(int argc, char** argv)
{
	Hazel::Log::Init();
	HZ_CORE_WARN("Initialized log !");
	HZ_CLIENT_INFO("Hello App !");
	int a =5;
	HZ_INFO("Hello! Var={0}",a);
	printf("Hello Learn Hazel !\nHazel Engine was started !\n");
	
	auto app = Hazel::CreateApplication();
	app->Run();
	delete app;
}
#endif