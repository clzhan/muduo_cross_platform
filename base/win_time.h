/*
* https://gist.github.com/ugovaretto/5875385#file-win-gettimeofday-c
*/
#ifndef  MUDUO_BASE_WINTIME_H_
#define  MUDUO_BASE_WINTIME_H_


# if defined(_WIN32)

#include <time.h>
#include <windows.h>

#if defined(_MSC_VER) || defined(_MSC_EXTENSIONS)
#define DELTA_EPOCH_IN_MICROSECS  11644473600000000Ui64
#else
#define DELTA_EPOCH_IN_MICROSECS  11644473600000000ULL
#endif

namespace muduo
{
	struct timezone
	{
		int  tz_minuteswest; /* minutes W of Greenwich */
		int  tz_dsttime;     /* type of dst correction */
	};
	int wgettimeofday(struct timeval *tv, struct timezone *tz);
	int wgmtime(struct timeval *tv, SYSTEMTIME *st);
}// end namespace muduo

#endif
#endif //MUDUO_BASE_WINTIME_H_