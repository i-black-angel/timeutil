#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <locale>
#include "timeutil.h"

using namespace std;

#ifdef _WIN32
# include <tchar.h>
#else
# define TCHAR      char
# define _tprintf   printf
# define _tmain     main
#endif /* _WIN32 */

int _tmain(int argc, TCHAR *argv[])
{
    CTimeUtil tu_obj;
#ifdef _WIN32
	_tprintf(_T("In _WIN32 environment:\n"));
#else
	_tprintf(_T("In non-_WIN32 environment:\n"));
#endif /* _WIN32 */
	_tprintf(_T("\nDay: %d\n"), tu_obj.Day());
	_tprintf(_T("Time: %s\n"), tu_obj.Now().c_str());
    return 0;
}
