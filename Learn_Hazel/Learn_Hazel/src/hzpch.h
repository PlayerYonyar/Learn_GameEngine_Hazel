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

//因为`日志`不会改变,所以把它添加到了`hzpch.h`
#include "Hazel/Log.h"

#ifdef HZ_PLATFORM_WINDOWS
#include <Windows.h>
#endif

