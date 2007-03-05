#ifndef __MYSTRING_H__
#define __MYSTRING_H__

#include <TCFoundation/TCDefines.h>
#include <TCFoundation/TCStlIncludes.h>

#include <string.h>
#ifdef _AIX
#include <strings.h>
#endif

#ifdef _QT
#include <qstring.h>
#endif // _QT

TCExport char *copyString(const char *string, int pad = 0);
TCExport wchar_t *copyString(const wchar_t *string, int pad = 0);

#ifndef __APPLE__
TCExport char *strnstr(const char *s1, const char *s2, size_t n);
TCExport char *strcasestr(const char *s1, const char *s2) __THROW;
#endif // !__APPLE__
TCExport char *strnstr2(const char *s1, const char *s2, size_t n,
						int skipZero);
TCExport char *strncasestr(const char *s1, const char *s2, size_t n, int 
skipZero = 0);

//int stringHasPrefix(const char *s1, const char *s2);

TCExport void printStringArray(char** array, int count);
TCExport char **copyStringArray(char** array, int count);
template<class T> inline TCExport void deleteStringArray(T** array, int count)
{
	int i;

	for (i = 0; i < count; i++)
	{
		delete array[i];
	}
	delete array;
}

TCExport bool arrayContainsString(char** array, int count, const char* string);
TCExport bool arrayContainsPrefix(char** array, int count, const char* prefix);
TCExport char **componentsSeparatedByString(const char* string,
											const char* separator, int& count);
TCExport wchar_t **componentsSeparatedByString(const wchar_t* string,
											   const wchar_t* separator,
											   int& count);
TCExport char *componentsJoinedByString(char** array, int count,
	const char* separator);
TCExport bool stringHasPrefix(const char* string, const char* prefix);
TCExport bool stringHasCaseInsensitivePrefix(const char* string,
	const char* prefix);
TCExport bool stringHasCaseInsensitivePrefix(const wchar_t* string,
	const wchar_t* prefix);
TCExport bool stringHasSuffix(const char* string, const char* suffix);
TCExport bool stringHasSuffix(const wchar_t* string, const wchar_t* suffix);
TCExport bool stringHasCaseInsensitiveSuffix(const char* string,
	const char* suffix);
TCExport char* convertStringToUpper(char*);
TCExport char* convertStringToLower(char*);

TCExport char* filenameFromPath(const char*);
TCExport char* directoryFromPath(const char*);

TCExport char* findExecutable(const char* executable);

TCExport void stripCRLF(char*);
TCExport void stripCRLF(wchar_t*);
TCExport void stripTrailingWhitespace(char*);
TCExport void stripTrailingWhitespace(wchar_t*);
TCExport void stripLeadingWhitespace(char*);
TCExport void stripLeadingWhitespace(wchar_t*);
TCExport void stripTrailingPathSeparators(char*);
TCExport void replaceStringCharacter(char*, char, char, int = 1);
TCExport char *stringByReplacingSubstring(const char* string,
										  const char* oldSubstring,
										  const char* newSubstring,
										  bool repeat = true);
TCExport int countStringLines(const char*);

TCExport void setDebugLevel(int value);
TCExport int getDebugLevel(void);
TCExport void debugPrintf(const char *format, ...);
TCExport void debugPrintf(int level, const char *format, ...);
TCExport void indentPrintf(int indent, const char *format, ...);

TCExport void processEscapedString(char *string);
TCExport void processEscapedString(wchar_t *string);

void stringtowstring(std::wstring &dst, const std::string &src);
void mbstowstring(std::wstring &dst, const char *src, int length = -1);
void wstringtostring(std::string &dst, const std::wstring &src);
void wcstostring(std::string &dst, const wchar_t *src, int length = -1);
UCSTR mbstoucstring(const char *src, int length = -1);
char *ucstringtombs(CUCSTR src, int length = -1);

#ifdef _QT
void wcstoqstring(QString &dst, const wchar_t *src, int length = -1);
void wstringtoqstring(QString &dst, const std::wstring &src);
#endif // _QT

#ifdef WIN32

#define strcasecmp stricmp
#define strncasecmp strnicmp
#define wcscasecmp wcsicmp
#define wcsncasecmp wcsnicmp

#else // WIN32

char *prettyLongLongString(long long);
long long longLongFromString(char*);

#endif // WIN32

#ifdef TC_NO_UNICODE
#define ucsprintf sprintf
#define ucstrcmp strcmp
#define ucstrstr strstr
#define ucstrcpy strcpy
#define ucstrcat strcat
#define ucstrncpy strncpy
#define sucscanf sscanf
typedef std::string ucstring;
#else // TC_NO_UNICODE
#define ucstrcmp wcscmp
#define ucstrstr wcsstr
#define ucstrcpy wcscpy
#define ucstrcat wcscat
#define ucstrncpy wcsncpy
#define sucscanf swscanf
typedef std::wstring ucstring;
#endif // TC_NO_UNICODE

typedef std::vector<ucstring> ucstringVector;

int sucprintf(UCSTR buffer, size_t maxLen, CUCSTR format, ...);
int vsucprintf(UCSTR buffer, size_t maxLen, CUCSTR format, va_list argPtr);
#define COUNT_OF(ar) (sizeof(ar) / sizeof(ar[0]))


#endif
