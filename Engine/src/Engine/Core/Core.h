#pragma once

#include <memory>

#include "Engine/Core/PlatformDetection.h"

#ifdef E_DEBUG
#if defined(E_PLATFORM_WINDOWS)
#define E_DEBUGBREAK() __debugbreak()
#define E_PROFILE
#elif defined(E_PLATFORM_LINUX)
#include <signal.h>
#define E_DEBUGBREAK() raise(SIGTRAP)
#else
#error "Platform doesn't support debugbreak yet!"
#endif
#define E_ENABLE_ASSERTS
#else
#define E_DEBUGBREAK()
#endif
#define BIT(x) 1<<x

#define BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

#ifdef E_DEBUG
// Currently accepts at least the condition and one additional parameter (the message) being optional
#define E_ASSERT(x) if (!(x)) { raise(SIGTRAP); }
#define E_API_ASSERT(x, ...) if (!(x)) { printf("%s", __VA_ARGS__); raise(SIGTRAP); } 
#else
#define E_ASSERT(...)
#define E_API_ASSERT(...)
#endif


namespace Engine
{
	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;

	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}
}
