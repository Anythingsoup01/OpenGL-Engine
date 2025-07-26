#pragma once

#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#pragma warning(pop)

namespace Engine {
	class Log
	{
	public:
		static void Init();

		inline static Ref<spdlog::logger>& GetAPILogger() { return s_APILogger; }
		inline static Ref<spdlog::logger>& GetCLILogger() { return s_CLILogger; }
	private:
		static Ref<spdlog::logger> s_APILogger;
		static Ref<spdlog::logger> s_CLILogger;
	};
}

#ifdef E_DEBUG

// Core Log Macros
#define E_API_CRITICAL(...)             ::Engine::Log::GetAPILogger()->critical(__VA_ARGS__)
#define E_API_ERROR(...)                ::Engine::Log::GetAPILogger()->error(__VA_ARGS__)
#define E_API_WARN(...)                 ::Engine::Log::GetAPILogger()->warn(__VA_ARGS__)
#define E_API_INFO(...)                 ::Engine::Log::GetAPILogger()->info(__VA_ARGS__)
#define E_API_TRACE(...)                ::Engine::Log::GetAPILogger()->trace(__VA_ARGS__)

// Client Log Macros
#define E_CLI_CRITICAL(...)             ::Engine::Log::GetCLILogger()->critical(__VA_ARGS__)
#define E_CLI_ERROR(...)                ::Engine::Log::GetCLILogger()->error(__VA_ARGS__)
#define E_CLI_WARN(...)                 ::Engine::Log::GetCLILogger()->warn(__VA_ARGS__)
#define E_CLI_INFO(...)                 ::Engine::Log::GetCLILogger()->info(__VA_ARGS__)
#define E_CLI_TRACE(...)                ::Engine::Log::GetCLILogger()->trace(__VA_ARGS__)
#elif E_RELEASE
// Core Log Macros
#define E_API_CRITICAL(...)
#define E_API_ERROR(...)
#define E_API_WARN(...)
#define E_API_INFO(...)
#define E_API_TRACE(...)

// Client Log Macros
#define E_CLI_CRITICAL(...)             ::Engine::Log::GetCLILogger()->critical(__VA_ARGS__)
#define E_CLI_ERROR(...)                ::Engine::Log::GetCLILogger()->error(__VA_ARGS__)
#define E_CLI_WARN(...)                 ::Engine::Log::GetCLILogger()->warn(__VA_ARGS__)
#define E_CLI_INFO(...)                 ::Engine::Log::GetCLILogger()->info(__VA_ARGS__)
#define E_CLI_TRACE(...)                ::Engine::Log::GetCLILogger()->trace(__VA_ARGS__)

#endif // E_DEBUG
