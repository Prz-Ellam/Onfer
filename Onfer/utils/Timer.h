#ifndef ONFER_TIMER_H
#define ONFER_TIMER_H

#include <Windows.h>
#include <string>

namespace Onfer {

	class Timer {
	public:
		Timer(const std::string& name);
		virtual ~Timer();
		void begin();
		void end();
	private:
		double getPerformanceCounter();
		std::string m_Name;
		double m_PerformanceCounter;
		LARGE_INTEGER m_BeginTime, m_EndTime;
	};

}

#endif