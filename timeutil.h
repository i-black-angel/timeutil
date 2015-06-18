/**
 * @file   timeutil.h
 * @author Shusheng Shao <iblackangel@163.com>
 * @date   Thu Jun 18 16:23:43 2015
 * 
 * @brief  A cross-platform library that provides a simple API to get and calculate system time
 * 
 * 
 */
#ifndef _TIMEUTIL_H_
#define _TIMEUTIL_H_

#include <ctime>
#include <string>

using namespace std;

#ifdef _DEBUG
# ifndef assert
#  include <cassert>
# endif
# define TU_ASSERT(x)  assert(x)
#else
# define TU_ASSERT(x)
#endif

/**
 * One minute has 60 seconds
 */
#ifndef SECONDS_PER_MIN
#define SECONDS_PER_MIN 60
#endif

/**
 * One hour has 60*60 seconds
 */
#ifndef SECONDS_PER_HOUR
#define SECONDS_PER_HOUR 3600
#endif

/**
 * One day has 24*hours equals to (24*60*60)
 */
#ifndef SECONDS_PER_DAY
#define SECONDS_PER_DAY 86400
#endif


template <typename CharT>
class CTimeUtilTempl
{
public:
    CTimeUtilTempl();
    virtual ~CTimeUtilTempl();

	clock_t Clock();
	double TimeElapsed() const;
	clock_t Clock();
	double TimeElapsed() const;
	int Day() const;
	int DayOfYear() const;
	int DayOfWeek() const;
	int Year() const;
	int Month() const;
	int Hour() const;
	int Minute() const;
	int Second() const;
	std::basic_string<CharT> Now() const;
	std::basic_string<CharT> Yesterday(int year, int month, int day,
					 int hour = 0, int min = 0, int sec = 0) const;
	std::basic_string<CharT> Tomorrow(int year, int month, int day,
					int hour = 0, int min = 0, int sec = 0) const;
	std::basic_string<CharT> LocalTime(time_t t) const;
	void Range(time_t t, time_t &begin_of_day, time_t &end_of_day) const;
private:
	enum {YESTERDAY = 0, TOMORROW = 1};
	struct tm *CurrentTime() const;
	string YTCalBase(int year, int month, int day,
					 int hour, int min, int sec,
					 int flag) const;
private:
	clock_t m_clock_start;
};

template <typename CharT>
CTimeUtilTempl::CTimeUtilTempl()
	: m_clock_start(clock())
{
}

template <typename CharT>
CTimeUtilTempl::~CTimeUtilTempl() {
}

template <typename CharT>
clock_t CTimeUtilTempl::Clock() {
	m_clock_start = clock();
	return m_clock_start;
}

template <typename CharT>
double CTimeUtilTempl::TimeElapsed() const {
	return ((double)(clock() - m_clock_start) / CLOCKS_PER_SEC);
}

template <typename CharT>
int CTimeUtilTempl::Day() const {
	return CurrentTime()->tm_mday;
}

template <typename CharT>
int CTimeUtilTempl::DayOfYear() const {
	return CurrentTime()->tm_yday;
}

// ------------------------------------------------------
//                 TYPE DEFINITIONS
// ------------------------------------------------------
typedef CTimeUtilTempl<char>        CTimeUtilA;
typedef CTimeUtilTempl<wchar_t>     CTimeUtilW;

#ifdef _UNICODE
# define CTimeUtil  CTimeUtilW
#else
# define CTimeUtil CTimeUtilA
#endif

#endif /* _TIMEUTIL_H_ */
