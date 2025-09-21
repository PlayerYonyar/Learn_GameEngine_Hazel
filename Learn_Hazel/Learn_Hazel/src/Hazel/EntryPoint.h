#pragma once
#ifdef HZ_PLATFORM_WINDOWS
extern Hazel::Application* Hazel::CreateApplication();
int main(int argc, char** argv)
{
	printf("Hello Learn Hazel !\nHazel Engine was started !\n");
	auto app = Hazel::CreateApplication();
	app->Run();
	delete app;
}
#endif