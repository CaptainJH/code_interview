#pragma once
#include <chrono>
#include <iostream>

class time_profiler
{
	static std::chrono::system_clock oneClock;

	std::chrono::time_point<std::chrono::system_clock> t;
	const char* tag;

public:
	time_profiler(const char* text = nullptr)
		: tag(text)
	{
		t = oneClock.now();
	}

	~time_profiler()
	{
		auto temp = oneClock.now();
		auto delta = std::chrono::duration_cast<std::chrono::microseconds>(temp - t);
		std::cout << (tag ? tag : "") << "|time duration is " << delta.count() << " us" << std::endl;
	}
};