//LayerStack.cpp:
//PopLayer函数中对m_LayerInsert--的操作看上去是不安全的
#include "hzpch.h"//prcompiled header(预编译头文件)
#include "LayerStack.h"

namespace Hazel
{
	Hazel::LayerStack::LayerStack()
	{
		m_LayerInsert = m_Layers.begin();
	}

	Hazel::LayerStack::~LayerStack()
	{
		//遍历删除
		for (Layer* layer : m_Layers)
		{
			delete layer;
		}
	}

	void Hazel::LayerStack::PushLayer(Layer* layer)
	{
		m_LayerInsert = m_Layers.emplace(m_LayerInsert, layer);
	}

	void Hazel::LayerStack::PushOverlay(Layer* overlay)
	{
		m_Layers.emplace_back(overlay);
	}

	void Hazel::LayerStack::PopLayer(Layer* layer)
	{
		auto it = std::find(m_Layers.begin(), m_Layers.end(), layer);
		if (it != m_Layers.end())
		{
			m_Layers.erase(it);
			m_LayerInsert--;
		}

	}

	void Hazel::LayerStack::PopOverlay(Layer* overlay)
	{
		auto it = std::find(m_Layers.begin(), m_Layers.end(), overlay);
		if (it != m_Layers.end())
		{
			m_Layers.erase(it);
		}
	}
}

