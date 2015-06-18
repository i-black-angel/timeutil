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

int main(int argc, char *argv[])
{
    CTimeUtil tu_obj;
	_tprintf(_T("%d\n"), tu_obj.Day());
	_tprintf(_T("%s\n"), tu_obj.Now().c_str());
    return 0;
}
