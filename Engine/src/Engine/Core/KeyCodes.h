#pragma once


namespace Engine
{

	enum class KeyCode : uint16_t
	{
		// From glfw3.h
		Space              = 32,
		Apostrophe         = 39,  /* ' */
		Comma              = 44,  /* , */
		Minus              = 45,  /* - */
		Period             = 46,  /* . */
		Slash              = 47,  /* / */
		D0                 = 48,
		D1                 = 49,
		D2                 = 50,
		D3                 = 51,
		D4                 = 52,
		D5                 = 53,
		D6                 = 54,
		D7                 = 55,
		D8                 = 56,
		D9                 = 57,
		SEMICOLON          = 59,  /* ; */
		EQUAL              = 61,  /* = */
		A                  = 65,
		B                  = 66,
		C                  = 67,
		D                  = 68,
		E                  = 69,
		F                  = 70,
		G                  = 71,
		H                  = 72,
		I                  = 73,
		J                  = 74,
		K                  = 75,
		L                  = 76,
		M                  = 77,
		N                  = 78,
		O                  = 79,
		P                  = 80,
		Q                  = 81,
		R                  = 82,
		S                  = 83,
		T                  = 84,
		U                  = 85,
		V                  = 86,
		W                  = 87,
		X                  = 88,
		Y                  = 89,
		Z                  = 90,
		LeftBracket       = 91,  /* [ */
		Backslash          = 92,  /* \ */
		RightBracket      = 93,  /* ] */
		GraceAccent       = 96,  /* ` */
		World1            = 161, /* non-US #1 */
		World2            = 162, /* non-US #2 */

/* Function keys */
		Escape             = 256,
		Enter              = 257,
		Tab                = 258,
		Backspace          = 259,
		Insert             = 260,
		Delete             = 261,
		Right              = 262,
		Left               = 263,
		Down               = 264,
		Up                 = 265,
		PageUp            = 266,
		PageDown          = 267,
		Home               = 268,
		End                = 269,
		CapsLock          = 280,
		ScrollLock        = 281,
		NumLock           = 282,
		PrintScreen       = 283,
		Pause              = 284,
		F1                 = 290,
		F2                 = 291,
		F3                 = 292,
		F4                 = 293,
		F5                 = 294,
		F6                 = 295,
		F7                 = 296,
		F8                 = 297,
		F9                 = 298,
		F10                = 299,
		F11                = 300,
		F12                = 301,
		F13                = 302,
		F14                = 303,
		F15                = 304,
		F16                = 305,
		F17                = 306,
		F18                = 307,
		F19                = 308,
		F20                = 309,
		F21                = 310,
		F22                = 311,
		F23                = 312,
		F24                = 313,
		F25                = 314,
		KP_0               = 320,
		KP_1               = 321,
		KP_2               = 322,
		KP_3               = 323,
		KP_4               = 324,
		KP_5               = 325,
		KP_6               = 326,
		KP_7               = 327,
		KP_8               = 328,
		KP_9               = 329,
		KPDecimal          = 330,
		KPDivide           = 331,
		KPMultiply         = 332,
		KPSubtract         = 333,
		KPAdd              = 334,
		KPEnter            = 335,
		KPEqual            = 336,
		LeftShift         = 340,
		LeftControl        = 341,
		LeftAlt            = 342,
		LeftSuper          = 343,
		RightShift        = 344,
		RightControl      = 345,
		RightAlt          = 346,
		RightSuper        = 347,
		Menu               = 348,

		ModShift           = 0x0001,
		ModControl         = 0x0002,
		ModAlt             = 0x0004,
		ModSuper           = 0x0008,
		ModCapsLock       = 0x0010,
		ModNumLock        = 0x0020,

	};

	inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
	{
		os << static_cast<uint32_t>(keyCode);
		return os;
	}
}
// From glfw3.h
#define E_SPACE           ::Engine::Key::Space
#define E_APOSTROPHE      ::Engine::Key::Apostrophe    /* ' */
#define E_COMMA           ::Engine::Key::Comma         /* , */
#define E_MINUS           ::Engine::Key::Minus         /* - */
#define E_PERIOD          ::Engine::Key::Period        /* . */
#define E_SLASH           ::Engine::Key::Slash         /* / */
#define E_0               ::Engine::Key::D0
#define E_1               ::Engine::Key::D1
#define E_2               ::Engine::Key::D2
#define E_3               ::Engine::Key::D3
#define E_4               ::Engine::Key::D4
#define E_5               ::Engine::Key::D5
#define E_6               ::Engine::Key::D6
#define E_7               ::Engine::Key::D7
#define E_8               ::Engine::Key::D8
#define E_9               ::Engine::Key::D9
#define E_SEMICOLON       ::Engine::Key::Semicolon     /* ; */
#define E_EQUAL           ::Engine::Key::Equal         /* = */
#define E_A               ::Engine::Key::A
#define E_B               ::Engine::Key::B
#define E_C               ::Engine::Key::C
#define E_D               ::Engine::Key::D
#define E_E               ::Engine::Key::E
#define E_F               ::Engine::Key::F
#define E_G               ::Engine::Key::G
#define E_H               ::Engine::Key::H
#define E_I               ::Engine::Key::I
#define E_J               ::Engine::Key::J
#define E_K               ::Engine::Key::K
#define E_L               ::Engine::Key::L
#define E_M               ::Engine::Key::M
#define E_N               ::Engine::Key::N
#define E_O               ::Engine::Key::O
#define E_P               ::Engine::Key::P
#define E_Q               ::Engine::Key::Q
#define E_R               ::Engine::Key::R
#define E_S               ::Engine::Key::S
#define E_T               ::Engine::Key::T
#define E_U               ::Engine::Key::U
#define E_V               ::Engine::Key::V
#define E_W               ::Engine::Key::W
#define E_X               ::Engine::Key::X
#define E_Y               ::Engine::Key::Y
#define E_Z               ::Engine::Key::Z
#define E_LEFT_BRACKET    ::Engine::Key::LeftBracket   /* [ */
#define E_BACKSLASH       ::Engine::Key::Backslash     /* \ */
#define E_RIGHT_BRACKET   ::Engine::Key::RightBracket  /* ] */
#define E_GRAVE_ACCENT    ::Engine::Key::GraveAccent   /* ` */
#define E_WORLD_1         ::Engine::Key::World1        /* non-US #1 */
#define E_WORLD_2         ::Engine::Key::World2        /* non-US #2 */

/* Function keys */
#define E_ESCAPE          ::Engine::Key::Escape
#define E_ENTER           ::Engine::Key::Enter
#define E_TAB             ::Engine::Key::Tab
#define E_BACKSPACE       ::Engine::Key::Backspace
#define E_INSERT          ::Engine::Key::Insert
#define E_DELETE          ::Engine::Key::Delete
#define E_RIGHT           ::Engine::Key::Right
#define E_LEFT            ::Engine::Key::Left
#define E_DOWN            ::Engine::Key::Down
#define E_UP              ::Engine::Key::Up
#define E_PAGE_UP         ::Engine::Key::PageUp
#define E_PAGE_DOWN       ::Engine::Key::PageDown
#define E_HOME            ::Engine::Key::Home
#define E_END             ::Engine::Key::End
#define E_CAPS_LOCK       ::Engine::Key::CapsLock
#define E_SCROLL_LOCK     ::Engine::Key::ScrollLock
#define E_NUM_LOCK        ::Engine::Key::NumLock
#define E_PRINT_SCREEN    ::Engine::Key::PrintScreen
#define E_PAUSE           ::Engine::Key::Pause
#define E_F1              ::Engine::Key::F1
#define E_F2              ::Engine::Key::F2
#define E_F3              ::Engine::Key::F3
#define E_F4              ::Engine::Key::F4
#define E_F5              ::Engine::Key::F5
#define E_F6              ::Engine::Key::F6
#define E_F7              ::Engine::Key::F7
#define E_F8              ::Engine::Key::F8
#define E_F9              ::Engine::Key::F9
#define E_F10             ::Engine::Key::F10
#define E_F11             ::Engine::Key::F11
#define E_F12             ::Engine::Key::F12
#define E_F13             ::Engine::Key::F13
#define E_F14             ::Engine::Key::F14
#define E_F15             ::Engine::Key::F15
#define E_F16             ::Engine::Key::F16
#define E_F17             ::Engine::Key::F17
#define E_F18             ::Engine::Key::F18
#define E_F19             ::Engine::Key::F19
#define E_F20             ::Engine::Key::F20
#define E_F21             ::Engine::Key::F21
#define E_F22             ::Engine::Key::F22
#define E_F23             ::Engine::Key::F23
#define E_F24             ::Engine::Key::F24
#define E_F25             ::Engine::Key::F25

/* Keypad */
#define E_KP_0            ::Engine::Key::KP0
#define E_KP_1            ::Engine::Key::KP1
#define E_KP_2            ::Engine::Key::KP2
#define E_KP_3            ::Engine::Key::KP3
#define E_KP_4            ::Engine::Key::KP4
#define E_KP_5            ::Engine::Key::KP5
#define E_KP_6            ::Engine::Key::KP6
#define E_KP_7            ::Engine::Key::KP7
#define E_KP_8            ::Engine::Key::KP8
#define E_KP_9            ::Engine::Key::KP9
#define E_KP_DECIMAL      ::Engine::Key::KPDecimal
#define E_KP_DIVIDE       ::Engine::Key::KPDivide
#define E_KP_MULTIPLY     ::Engine::Key::KPMultiply
#define E_KP_SUBTRACT     ::Engine::Key::KPSubtract
#define E_KP_ADD          ::Engine::Key::KPAdd
#define E_KP_ENTER        ::Engine::Key::KPEnter
#define E_KP_EQUAL        ::Engine::Key::KPEqual

#define E_LEFT_SHIFT      ::Engine::Key::LeftShift
#define E_LEFT_CONTROL    ::Engine::Key::LeftControl
#define E_LEFT_ALT        ::Engine::Key::LeftAlt
#define E_LEFT_SUPER      ::Engine::Key::LeftSuper
#define E_RIGHT_SHIFT     ::Engine::Key::RightShift
#define E_RIGHT_CONTROL   ::Engine::Key::RightControl
#define E_RIGHT_ALT       ::Engine::Key::RightAlt
#define E_RIGHT_SUPER     ::Engine::Key::RightSuper
#define E_MENU            ::Engine::Key::Menu
