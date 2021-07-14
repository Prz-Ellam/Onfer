#include "Timer.h"
#include "Log.h"

namespace Onfer {

	Timer::Timer(const std::string& name) {

		m_Name = name;
		begin();

	}

	Timer::~Timer() {

		end();

	}

	void Timer::begin() {

		QueryPerformanceCounter(&m_BeginTime);
		m_PerformanceCounter = getPerformanceCounter();

	}

	void Timer::end() {

		QueryPerformanceCounter(&m_EndTime);
		double duration = (float)((m_EndTime.QuadPart - m_BeginTime.QuadPart)) / m_PerformanceCounter;
		Log::info("%s Duration: %.5f", m_Name.c_str(), duration);

	}

	double Timer::getPerformanceCounter() {

		LARGE_INTEGER frequency;
		QueryPerformanceFrequency(&frequency);

		return (double)frequency.QuadPart;
	
	}

}