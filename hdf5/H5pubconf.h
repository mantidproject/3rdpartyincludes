
#ifdef _WIN32

/*
	#ifdef __GNUC__
		#include "H5pubconf-mingw.h"
	#endif
*/

	#ifdef _WIN64
		#include "H5pubconf-win64.h"
	#else
		#include "H5pubconf-win32.h"
	#endif

#endif

#if defined(__APPLE__)
	#include "H5pubconf-darwin.h"
#endif