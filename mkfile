</$objtype/mkfile

LIB=libutf8.a

OFILES= locale_is.$O mb_cur_max.$O setlocale.$O mbsinit.$O \
  wcpcpy.$O wcpncpy.$O wcscat.$O wcschr.$O wcscmp.$O wcscpy.$O wcscspn.$O \
  wcsdup.$O wcslen.$O wcsncat.$O wcsncmp.$O wcsncpy.$O wcsnlen.$O wcspbrk.$O \
  wcsrchr.$O wcsspn.$O wcsstr.$O wcstok.$O \
  wmemchr.$O wmemcmp.$O wmemcpy.$O wmemmove.$O wmemset.$O \
  wcrtomb.$O wcsnrtombs.$O wcsrtombs.$O wcstombs.$O wctob.$O wctomb.$O \
  btowc.$O mblen.$O mbrlen.$O mbrtowc.$O mbsnrtowcs.$O mbsrtowcs.$O \
  mbstowcs.$O mbtowc.$O \
  noppage.$O towctrans.$O towlower.$O towupper.$O wctrans.$O \
  wcscasecmp.$O wcsncasecmp.$O \
  attribute.$O iswalnum.$O iswalpha.$O iswblank.$O iswcntrl.$O iswctype.$O \
  iswdigit.$O iswgraph.$O iswlower.$O iswprint.$O iswpunct.$O iswspace.$O \
  iswupper.$O iswxdigit.$O wctype.$O wcwidth.$O wcswidth.$O \
  integer-parse.$O wcstol.$O wcstoul.$O wcstoll.$O wcstoull.$O \
  number-parse.$O wcstof.$O wcstod.$O wcstold.$O \
  fgetwc.$O fgetws.$O getwchar.$O ungetwc.$O \
  fputwc.$O fputws.$O putwchar.$O fwide.$O \
  printf-args.$O printf-parse.$O wprintf-parse.$O \
  vfprintf.$O vprintf.$O vsprintf.$O vsnprintf.$O \
  fprintf.$O printf.$O sprintf.$O snprintf.$O \
  vfwprintf.$O vwprintf.$O vswprintf.$O \
  fwprintf.$O wprintf.$O swprintf.$O


HFILES= \
/sys/include/ape/libutf8.h \
/sys/include/ape/wchar.h \
/sys/include/ape/wctype.h


MANFILES= MB_CUR_MAX MB_LEN_MAX btowc fgetwc fgetws fputwc \
    fputws fwide fwprintf getwchar iswalnum iswalpha iswblank \
    iswcntrl iswctype iswdigit iswgraph iswlower iswprint iswpunct \
    iswspace iswupper iswxdigit mblen mbrlen mbrtowc mbsinit mbsnrtowcs \
    mbsrtowcs mbstowcs mbtowc printf putwchar setlocale swprintf \
    towctrans towlower towupper ungetwc fwprintf vswprintf vwprintf \
    wcpcpy wcpncpy wcrtomb wcscasecmp wcscat wcschr wcscmp wcscpy \
    wcscspn wcsdup wcslen wcsncasecmp wcsncat wcsncmp wcsncpy \
    wcsnlen wcsnrtombs wcspbrk wcsrchr wcsrtombs wcsspn \
    wcsstr wcstok wcstombs wcswidth wctob wctomb wctrans \
    wctype wcwidth wmemchr wmemcmp wmemcpy wmemmove wmemset \
    wprintf

</sys/src/cmd/mksyslib

CC=pcc
LD=pcc
CFLAGS= -c -I. -I./src -D_POSIX_SOURCE -D_SUSV2_SOURCE -D_BSD_EXTENSION \
-D_LIMITS_EXTENSION -D_RESEARCH_SOURCE -D_C99_SNPRINTF_EXTENSION

%.$O: src/%.c
	$CC $CFLAGS src/$stem.c

%.$O: src/wstring/%.c
	$CC $CFLAGS src/wstring/$stem.c
	
%.$O: src/wcstombs/%.c
	$CC $CFLAGS src/wcstombs/$stem.c
	
%.$O: src/mbstowcs/%.c
	$CC $CFLAGS src/mbstowcs/$stem.c
	
%.$O: src/caseconv/%.c
	$CC $CFLAGS src/caseconv/$stem.c
	
%.$O: src/attribute/%.c
	$CC $CFLAGS src/attribute/$stem.c
	
%.$O: src/number/%.c
	$CC $CFLAGS src/number/$stem.c
	
%.$O: src/stdio/%.c
	$CC $CFLAGS src/stdio/$stem.c
	
%.$O: extras/%.c
	$CC $CFLAGS extras/$stem.c

install:V:
    mkdir /sys/include/ape/utf8
    cp include/utf8/*.h /sys/include/ape/utf8/
    mkdir -p /sys/man/3ape
    for (i in $MANFILES) @{
    cp man/$i.3 /sys/man/3ape/$i
    }
    
clean:V:
	rm -f *.[$OS]

nuke:V:
	rm -f $LIB
	rm -f /$objtype/lib/ape/libutf8.a
	rm -rf /sys/include/ape/utf8
	rm -f $HFILES
    for (i in $MANFILES) @{
    rm -f /sys/man/3ape/$i
    }
