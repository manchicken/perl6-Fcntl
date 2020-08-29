#ifdef VMS
#  include <file.h>
#else
#  if defined(__GNUC__) && defined(__cplusplus) && defined(WIN32)
#    define _NO_OLDNAMES
#  endif
#  include <fcntl.h>
#  if defined(__GNUC__) && defined(__cplusplus) && defined(WIN32)
#    undef _NO_OLDNAMES
#  endif
#endif

#ifdef I_UNISTD
#  include <unistd.h>
#endif
