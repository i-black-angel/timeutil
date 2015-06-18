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

#ifdef _WIN32
# include <tchar.h>
#else
# ifdef _UNICODE
#  define _tcsftime   wcsftime
#  define _T(x)       L ## x
# else
#  define _tcsftime   strftime
#  define _T(x)       x
# endif
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
	int Day() const;
	int DayOfYear() const;
	int DayOfWeek() const;
	int Year() const;
	int Month() const;
	int Hour() const;
	int Minute() const;
	int Second() const;
	struct tm *CurrentTime() const;
	std::basic_string<CharT> Now() const;
	std::basic_string<CharT> Yesterday(int year, int month, int day,
					 int hour = 0, int min = 0, int sec = 0) const;
	std::basic_string<CharT> Tomorrow(int year, int month, int day,
					int hour = 0, int min = 0, int sec = 0) const;
	std::basic_string<CharT> LocalTime(time_t t) const;
	void Range(time_t t, time_t &begin_of_day, time_t &end_of_day) const;
private:
	clock_t m_clock_start;
};

template <typename CharT>
CTimeUtilTempl<CharT>::CTimeUtilTempl()
	: m_clock_start(clock())
{
}

template <typename CharT>
CTimeUtilTempl<CharT>::~CTimeUtilTempl() {
}

template <typename CharT>
clock_t CTimeUtilTempl<CharT>::Clock() {
	m_clock_start = clock();
	return m_clock_start;
}

template <typename CharT>
double CTimeUtilTempl<CharT>::TimeElapsed() const {
	return ((double)(clock() - m_clock_start) / CLOCKS_PER_SEC);
}

template <typename CharT>
int CTimeUtilTempl<CharT>::Day() const {
	return CurrentTime()->tm_mday;
}

template <typename CharT>
int CTimeUtilTempl<CharT>::DayOfYear() const {
	return CurrentTime()->tm_yday + 1;
}

template <typename CharT>
int CTimeUtilTempl<CharT>::DayOfWeek() const {
	return CurrentTime()->tm_wday;
}

template <typename CharT>
int CTimeUtilTempl<CharT>::Year() const {
	return CurrentTime()->tm_year + 1900;
}

template <typename CharT>
int CTimeUtilTempl<CharT>::Month() const {
	return CurrentTime()->tm_mon + 1;
}

template <typename CharT>
int CTimeUtilTempl<CharT>::Hour() const {
	return CurrentTime()->tm_hour;
}

template <typename CharT>
int CTimeUtilTempl<CharT>::Minute() const {
	return CurrentTime()->tm_min;
}

template <typename CharT>
int CTimeUtilTempl<CharT>::Second() const {
	return CurrentTime()->tm_sec;
}

template <typename CharT>
struct tm * CTimeUtilTempl<CharT>::CurrentTime() const {
	time_t _cur_time = time(NULL);
	return localtime(&_cur_time);
}

template <typename CharT>
std::basic_string<CharT> CTimeUtilTempl<CharT>::Now() const {
	CharT buffer[64] = {0};
    _tcsftime(buffer, 64, _T("%Y-%m-%d %H:%M:%S"), CurrentTime());
    return std::basic_string<CharT>(buffer);
}

template <typename CharT>
std::basic_string<CharT> CTimeUtilTempl<CharT>::LocalTime(time_t t) const {
	CharT buffer[64] = {0};
	time_t __time = t;
    _tcsftime(buffer, 64, _T("%Y-%m-%d %H:%M:%S"), localtime(&__time));
    return std::basic_string<CharT>(buffer);
}

template <typename CharT>
void CTimeUtilTempl<CharT>::Range(time_t t, time_t &begin_of_day,
					 time_t &end_of_day) const {
	time_t daytime = t;
	struct tm *st = localtime(&daytime);
	st->tm_hour = 0;
	st->tm_min  = 0;
	st->tm_sec  = 0;
	begin_of_day = mktime(st);

	st->tm_hour = 23;
	st->tm_min  = 59;
	st->tm_sec  = 59;
	end_of_day = mktime(st);
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
