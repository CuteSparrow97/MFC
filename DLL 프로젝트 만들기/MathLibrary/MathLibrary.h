// MathLibrary.h - Contains declarations of math functions
#pragma once

//https://learn.microsoft.com/ko-kr/cpp/build/walkthrough-creating-and-using-a-dynamic-link-library-cpp?view=msvc-170

/* 
파일 맨 위의 전처리기 문을 확인합니다. 
DLL 프로젝트에 대한 새 프로젝트 템플릿은 정의된 전처리기 매크로에 추가 <PROJECTNAME>_EXPORTS 됩니다.
이 예제에서 Visual Studio는 MATHLIBRARY_EXPORTS MathLibrary DLL 프로젝트가 빌드되는 시기를 정의합니다.

매크로가 MATHLIBRARY_EXPORTS 정의되면 매크로는 MATHLIBRARY_API 함수 선언에서 한정자를 설정합니다
__declspec(dllexport) . 
이 한정자는 DLL에서 함수 또는 변수를 내보내도록 컴파일러 및 링커에 알려 다른 애플리케이션에서 사용할 수 있도록 합니다.
가 정의되지 않은 경우 MATHLIBRARY_EXPORTS (예: 헤더 파일이 클라이언트 애플리케이션에 포함되는 경우)는 
MATHLIBRARY_API 선언에 한정자를 적용 __declspec(dllimport) 합니다. 
이 한정자는 애플리케이션에서 함수 또는 변수의 가져오기를 최적화합니다. 
자세한 내용은 dllexport, dllimport를 참조하세요.
*/
#ifdef MATHLIBRARY_EXPORTS
#define MATHLIBRARY_API __declspec(dllexport)
#else
#define MATHLIBRARY_API __declspec(dllimport)
#endif

// The Fibonacci recurrence relation describes a sequence F
// where F(n) is { n = 0, a
//               { n = 1, b
//               { n > 1, F(n-2) + F(n-1)
// for some initial integral values a and b.
// If the sequence is initialized F(0) = 1, F(1) = 1,
// then this relation produces the well-known Fibonacci
// sequence: 1, 1, 2, 3, 5, 8, 13, 21, 34, ...

// Initialize a Fibonacci relation sequence
// such that F(0) = a, F(1) = b.
// This function must be called before any other function.
extern "C" MATHLIBRARY_API void fibonacci_init(
    const unsigned long long a, const unsigned long long b);

// Produce the next value in the sequence.
// Returns true on success and updates current value and index;
// false on overflow, leaves current value and index unchanged.
extern "C" MATHLIBRARY_API bool fibonacci_next();

// Get the current value in the sequence.
extern "C" MATHLIBRARY_API unsigned long long fibonacci_current();

// Get the position of the current value in the sequence.
extern "C" MATHLIBRARY_API unsigned fibonacci_index();