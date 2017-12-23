#include <stdlib.h>
#include <strings.h>
#include <stdio.h>

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

struct definition_pair {
  char *const_name;
  long long const_value;
};

/**
 * This set of definitions lets us construct Perl 6 code later...
 */
struct definition_pair definitions[] = {
  {
    "constant DN_ACCESS is export(:ALL) = %lld",
    #ifdef DN_ACCESS
      DN_ACCESS
    #else
      0
    #endif
  },
  {
    "constant DN_MODIFY is export(:ALL) = %lld",
    #ifdef DN_MODIFY
      DN_MODIFY
    #else
      0
    #endif
  },
  {
    "constant DN_CREATE is export(:ALL) = %lld",
    #ifdef DN_CREATE
      DN_CREATE
    #else
      0
    #endif
  },
  {
    "constant DN_DELETE is export(:ALL) = %lld",
    #ifdef DN_DELETE
      DN_DELETE
    #else
      0
    #endif
  },
  {
    "constant DN_RENAME is export(:ALL) = %lld",
    #ifdef DN_RENAME
      DN_RENAME
    #else
      0
    #endif
  },
  {
    "constant DN_ATTRIB is export(:ALL) = %lld",
    #ifdef DN_ATTRIB
      DN_ATTRIB
    #else
      0
    #endif
  },
  {
    "constant DN_MULTISHOT is export(:ALL) = %lld",
    #ifdef DN_MULTISHOT
      DN_MULTISHOT
    #else
      0
    #endif
  },
  {
    "constant FAPPEND is export(:ALL, :Fcompat) = %lld",
    #ifdef FAPPEND
      FAPPEND
    #else
      0
    #endif
  },
  {
    "constant FASYNC is export(:ALL, :Fcompat) = %lld",
    #ifdef FASYNC
      FASYNC
    #else
      0
    #endif
  },
  {
    "constant FCREAT is export(:ALL, :Fcompat) = %lld",
    #ifdef FCREAT
      FCREAT
    #else
      0
    #endif
  },
  {
    "constant FDEFER is export(:ALL, :Fcompat) = %lld",
    #ifdef FDEFER
      FDEFER
    #else
      0
    #endif
  },
  {
    "constant FDSYNC is export(:ALL) = %lld",
    #ifdef FDSYNC
      FDSYNC
    #else
      0
    #endif
  },
  {
    "constant FD_CLOEXEC is export(:ALL) = %lld",
    #ifdef FD_CLOEXEC
      FD_CLOEXEC
    #else
      0
    #endif
  },
  {
    "constant FEXCL is export(:ALL, :Fcompat) = %lld",
    #ifdef FEXCL
      FEXCL
    #else
      0
    #endif
  },
  {
    "constant FLARGEFILE is export(:ALL) = %lld",
    #ifdef FLARGEFILE
      FLARGEFILE
    #else
      0
    #endif
  },
  {
    "constant FNDELAY is export(:ALL, :Fcompat) = %lld",
    #ifdef FNDELAY
      FNDELAY
    #else
      0
    #endif
  },
  {
    "constant FRSYNC is export(:ALL) = %lld",
    #ifdef FRSYNC
      FRSYNC
    #else
      0
    #endif
  },
  {
    "constant FNONBLOCK is export(:ALL, :Fcompat) = %lld",
    #ifdef FNONBLOCK
      FNONBLOCK
    #else
      0
    #endif
  },
  {
    "constant FSYNC is export(:ALL, :Fcompat) = %lld",
    #ifdef FSYNC
      FSYNC
    #else
      0
    #endif
  },
  {
    "constant FTRUNC is export(:ALL, :Fcompat) = %lld",
    #ifdef FTRUNC
      FTRUNC
    #else
      0
    #endif
  },
  {
    "constant F_ALLOCSP is export(:ALL) = %lld",
    #ifdef F_ALLOCSP
      F_ALLOCSP
    #else
      0
    #endif
  },
  {
    "constant F_ALLOCSP64 is export(:ALL) = %lld",
    #ifdef F_ALLOCSP64
      F_ALLOCSP64
    #else
      0
    #endif
  },
  {
    "constant F_COMPAT is export(:ALL) = %lld",
    #ifdef F_COMPAT
      F_COMPAT
    #else
      0
    #endif
  },
  {
    "constant F_DUP2FD is export(:ALL) = %lld",
    #ifdef F_DUP2FD
      F_DUP2FD
    #else
      0
    #endif
  },
  {
    "constant F_DUPFD is export(:ALL) = %lld",
    #ifdef F_DUPFD
      F_DUPFD
    #else
      0
    #endif
  },
  {
    "constant F_EXLCK is export(:ALL) = %lld",
    #ifdef F_EXLCK
      F_EXLCK
    #else
      0
    #endif
  },
  {
    "constant F_FREESP is export(:ALL) = %lld",
    #ifdef F_FREESP
      F_FREESP
    #else
      0
    #endif
  },
  {
    "constant F_FREESP64 is export(:ALL) = %lld",
    #ifdef F_FREESP64
      F_FREESP64
    #else
      0
    #endif
  },
  {
    "constant F_FSYNC is export(:ALL) = %lld",
    #ifdef F_FSYNC
      F_FSYNC
    #else
      0
    #endif
  },
  {
    "constant F_FSYNC64 is export(:ALL) = %lld",
    #ifdef F_FSYNC64
      F_FSYNC64
    #else
      0
    #endif
  },
  {
    "constant F_GETFD is export(:ALL) = %lld",
    #ifdef F_GETFD
      F_GETFD
    #else
      0
    #endif
  },
  {
    "constant F_GETFL is export(:ALL) = %lld",
    #ifdef F_GETFL
      F_GETFL
    #else
      0
    #endif
  },
  {
    "constant F_GETLEASE is export(:ALL) = %lld",
    #ifdef F_GETLEASE
      F_GETLEASE
    #else
      0
    #endif
  },
  {
    "constant F_GETLK is export(:ALL) = %lld",
    #ifdef F_GETLK
      F_GETLK
    #else
      0
    #endif
  },
  {
    "constant F_GETLK64 is export(:ALL) = %lld",
    #ifdef F_GETLK64
      F_GETLK64
    #else
      0
    #endif
  },
  {
    "constant F_GETOWN is export(:ALL) = %lld",
    #ifdef F_GETOWN
      F_GETOWN
    #else
      0
    #endif
  },
  {
    "constant F_GETPIPE_SZ is export(:ALL) = %lld",
    #ifdef F_GETPIPE_SZ
      F_GETPIPE_SZ
    #else
      0
    #endif
  },
  {
    "constant F_GETSIG is export(:ALL) = %lld",
    #ifdef F_GETSIG
      F_GETSIG
    #else
      0
    #endif
  },
  {
    "constant F_NODNY is export(:ALL) = %lld",
    #ifdef F_NODNY
      F_NODNY
    #else
      0
    #endif
  },
  {
    "constant F_NOTIFY is export(:ALL) = %lld",
    #ifdef F_NOTIFY
      F_NOTIFY
    #else
      0
    #endif
  },
  {
    "constant F_POSIX is export(:ALL) = %lld",
    #ifdef F_POSIX
      F_POSIX
    #else
      0
    #endif
  },
  {
    "constant F_RDACC is export(:ALL) = %lld",
    #ifdef F_RDACC
      F_RDACC
    #else
      0
    #endif
  },
  {
    "constant F_RDDNY is export(:ALL) = %lld",
    #ifdef F_RDDNY
      F_RDDNY
    #else
      0
    #endif
  },
  {
    "constant F_RDLCK is export(:ALL) = %lld",
    #ifdef F_RDLCK
      F_RDLCK
    #else
      0
    #endif
  },
  {
    "constant F_RWACC is export(:ALL) = %lld",
    #ifdef F_RWACC
      F_RWACC
    #else
      0
    #endif
  },
  {
    "constant F_RWDNY is export(:ALL) = %lld",
    #ifdef F_RWDNY
      F_RWDNY
    #else
      0
    #endif
  },
  {
    "constant F_SETFD is export(:ALL) = %lld",
    #ifdef F_SETFD
      F_SETFD
    #else
      0
    #endif
  },
  {
    "constant F_SETFL is export(:ALL) = %lld",
    #ifdef F_SETFL
      F_SETFL
    #else
      0
    #endif
  },
  {
    "constant F_SETLEASE is export(:ALL) = %lld",
    #ifdef F_SETLEASE
      F_SETLEASE
    #else
      0
    #endif
  },
  {
    "constant F_SETLK is export(:ALL) = %lld",
    #ifdef F_SETLK
      F_SETLK
    #else
      0
    #endif
  },
  {
    "constant F_SETLK64 is export(:ALL) = %lld",
    #ifdef F_SETLK64
      F_SETLK64
    #else
      0
    #endif
  },
  {
    "constant F_SETLKW is export(:ALL) = %lld",
    #ifdef F_SETLKW
      F_SETLKW
    #else
      0
    #endif
  },
  {
    "constant F_SETLKW64 is export(:ALL) = %lld",
    #ifdef F_SETLKW64
      F_SETLKW64
    #else
      0
    #endif
  },
  {
    "constant F_SETOWN is export(:ALL) = %lld",
    #ifdef F_SETOWN
      F_SETOWN
    #else
      0
    #endif
  },
  {
    "constant F_SETPIPE_SZ is export(:ALL) = %lld",
    #ifdef F_SETPIPE_SZ
      F_SETPIPE_SZ
    #else
      0
    #endif
  },
  {
    "constant F_SETSIG is export(:ALL) = %lld",
    #ifdef F_SETSIG
      F_SETSIG
    #else
      0
    #endif
  },
  {
    "constant F_SHARE is export(:ALL) = %lld",
    #ifdef F_SHARE
      F_SHARE
    #else
      0
    #endif
  },
  {
    "constant F_SHLCK is export(:ALL) = %lld",
    #ifdef F_SHLCK
      F_SHLCK
    #else
      0
    #endif
  },
  {
    "constant F_UNLCK is export(:ALL) = %lld",
    #ifdef F_UNLCK
      F_UNLCK
    #else
      0
    #endif
  },
  {
    "constant F_UNSHARE is export(:ALL) = %lld",
    #ifdef F_UNSHARE
      F_UNSHARE
    #else
      0
    #endif
  },
  {
    "constant F_WRACC is export(:ALL) = %lld",
    #ifdef F_WRACC
      F_WRACC
    #else
      0
    #endif
  },
  {
    "constant F_WRDNY is export(:ALL) = %lld",
    #ifdef F_WRDNY
      F_WRDNY
    #else
      0
    #endif
  },
  {
    "constant F_WRLCK is export(:ALL) = %lld",
    #ifdef F_WRLCK
      F_WRLCK
    #else
      0
    #endif
  },
  {
    "constant LOCK_MAND is export(:ALL) = %lld",
    #ifdef LOCK_MAND
      LOCK_MAND
    #else
      0
    #endif
  },
  {
    "constant LOCK_READ is export(:ALL) = %lld",
    #ifdef LOCK_READ
      LOCK_READ
    #else
      0
    #endif
  },
  {
    "constant LOCK_WRITE is export(:ALL) = %lld",
    #ifdef LOCK_WRITE
      LOCK_WRITE
    #else
      0
    #endif
  },
  {
    "constant LOCK_RW is export(:ALL) = %lld",
    #ifdef LOCK_RW
      LOCK_RW
    #else
      0
    #endif
  },
  {
    "constant O_ACCMODE is export(:ALL) = %lld",
    #ifdef O_ACCMODE
      O_ACCMODE
    #else
      0
    #endif
  },
  {
    "constant O_ALIAS is export(:ALL) = %lld",
    #ifdef O_ALIAS
      O_ALIAS
    #else
      0
    #endif
  },
  {
    "constant O_ALT_IO is export(:ALL) = %lld",
    #ifdef O_ALT_IO
      O_ALT_IO
    #else
      0
    #endif
  },
  {
    "constant O_APPEND is export(:ALL) = %lld",
    #ifdef O_APPEND
      O_APPEND
    #else
      0
    #endif
  },
  {
    "constant O_ASYNC is export(:ALL) = %lld",
    #ifdef O_ASYNC
      O_ASYNC
    #else
      0
    #endif
  },
  {
    "constant O_BINARY is export(:ALL) = %lld",
    #ifdef O_BINARY
      O_BINARY
    #else
      0
    #endif
  },
  {
    "constant O_CREAT is export(:ALL) = %lld",
    #ifdef O_CREAT
      O_CREAT
    #else
      0
    #endif
  },
  {
    "constant O_DEFER is export(:ALL) = %lld",
    #ifdef O_DEFER
      O_DEFER
    #else
      0
    #endif
  },
  {
    "constant O_DIRECT is export(:ALL) = %lld",
    #ifdef O_DIRECT
      O_DIRECT
    #else
      0
    #endif
  },
  {
    "constant O_DIRECTORY is export(:ALL) = %lld",
    #ifdef O_DIRECTORY
      O_DIRECTORY
    #else
      0
    #endif
  },
  {
    "constant O_DSYNC is export(:ALL) = %lld",
    #ifdef O_DSYNC
      O_DSYNC
    #else
      0
    #endif
  },
  {
    "constant O_EVTONLY is export(:ALL) = %lld",
    #ifdef O_EVTONLY
      O_EVTONLY
    #else
      0
    #endif
  },
  {
    "constant O_EXCL is export(:ALL) = %lld",
    #ifdef O_EXCL
      O_EXCL
    #else
      0
    #endif
  },
  {
    "constant O_EXLOCK is export(:ALL) = %lld",
    #ifdef O_EXLOCK
      O_EXLOCK
    #else
      0
    #endif
  },
  {
    "constant O_IGNORE_CTTY is export(:ALL) = %lld",
    #ifdef O_IGNORE_CTTY
      O_IGNORE_CTTY
    #else
      0
    #endif
  },
  {
    "constant O_LARGEFILE is export(:ALL) = %lld",
    #ifdef O_LARGEFILE
      O_LARGEFILE
    #else
      0
    #endif
  },
  {
    "constant O_NDELAY is export(:ALL) = %lld",
    #ifdef O_NDELAY
      O_NDELAY
    #else
      0
    #endif
  },
  {
    "constant O_NOATIME is export(:ALL) = %lld",
    #ifdef O_NOATIME
      O_NOATIME
    #else
      0
    #endif
  },
  {
    "constant O_NOCTTY is export(:ALL) = %lld",
    #ifdef O_NOCTTY
      O_NOCTTY
    #else
      0
    #endif
  },
  {
    "constant O_NOFOLLOW is export(:ALL) = %lld",
    #ifdef O_NOFOLLOW
      O_NOFOLLOW
    #else
      0
    #endif
  },
  {
    "constant O_NOINHERIT is export(:ALL) = %lld",
    #ifdef O_NOINHERIT
      O_NOINHERIT
    #else
      0
    #endif
  },
  {
    "constant O_NOLINK is export(:ALL) = %lld",
    #ifdef O_NOLINK
      O_NOLINK
    #else
      0
    #endif
  },
  {
    "constant O_NONBLOCK is export(:ALL) = %lld",
    #ifdef O_NONBLOCK
      O_NONBLOCK
    #else
      0
    #endif
  },
  {
    "constant O_NOSIGPIPE is export(:ALL) = %lld",
    #ifdef O_NOSIGPIPE
      O_NOSIGPIPE
    #else
      0
    #endif
  },
  {
    "constant O_NOTRANS is export(:ALL) = %lld",
    #ifdef O_NOTRANS
      O_NOTRANS
    #else
      0
    #endif
  },
  {
    "constant O_RANDOM is export(:ALL) = %lld",
    #ifdef O_RANDOM
      O_RANDOM
    #else
      0
    #endif
  },
  {
    "constant O_RAW is export(:ALL) = %lld",
    #ifdef O_RAW
      O_RAW
    #else
      0
    #endif
  },
  {
    "constant O_RDONLY is export(:ALL) = %lld",
    #ifdef O_RDONLY
      O_RDONLY
    #else
      0
    #endif
  },
  {
    "constant O_RDWR is export(:ALL) = %lld",
    #ifdef O_RDWR
      O_RDWR
    #else
      0
    #endif
  },
  {
    "constant O_RSRC is export(:ALL) = %lld",
    #ifdef O_RSRC
      O_RSRC
    #else
      0
    #endif
  },
  {
    "constant O_RSYNC is export(:ALL) = %lld",
    #ifdef O_RSYNC
      O_RSYNC
    #else
      0
    #endif
  },
  {
    "constant O_SEQUENTIAL is export(:ALL) = %lld",
    #ifdef O_SEQUENTIAL
      O_SEQUENTIAL
    #else
      0
    #endif
  },
  {
    "constant O_SHLOCK is export(:ALL) = %lld",
    #ifdef O_SHLOCK
      O_SHLOCK
    #else
      0
    #endif
  },
  {
    "constant O_SYMLINK is export(:ALL) = %lld",
    #ifdef O_SYMLINK
      O_SYMLINK
    #else
      0
    #endif
  },
  {
    "constant O_SYNC is export(:ALL) = %lld",
    #ifdef O_SYNC
      O_SYNC
    #else
      0
    #endif
  },
  {
    "constant O_TEMPORARY is export(:ALL) = %lld",
    #ifdef O_TEMPORARY
      O_TEMPORARY
    #else
      0
    #endif
  },
  {
    "constant O_TEXT is export(:ALL) = %lld",
    #ifdef O_TEXT
      O_TEXT
    #else
      0
    #endif
  },
  {
    "constant O_TRUNC is export(:ALL) = %lld",
    #ifdef O_TRUNC
      O_TRUNC
    #else
      0
    #endif
  },
  {
    "constant O_TTY_INIT is export(:ALL) = %lld",
    #ifdef O_TTY_INIT
      O_TTY_INIT
    #else
      0
    #endif
  },
  {
    "constant O_WRONLY is export(:ALL) = %lld",
    #ifdef O_WRONLY
      O_WRONLY
    #else
      0
    #endif
  },
  {
    "constant S_ENFMT is export(:ALL) = %lld",
    #ifdef S_ENFMT
      S_ENFMT
    #else
      0
    #endif
  },
  {
    "constant S_IEXEC is export(:ALL) = %lld",
    #ifdef S_IEXEC
      S_IEXEC
    #else
      0
    #endif
  },
  {
    "constant S_IFBLK is export(:ALL) = %lld",
    #ifdef S_IFBLK
      S_IFBLK
    #else
      0
    #endif
  },
  {
    "constant S_IFCHR is export(:ALL) = %lld",
    #ifdef S_IFCHR
      S_IFCHR
    #else
      0
    #endif
  },
  {
    "constant S_IFDIR is export(:ALL) = %lld",
    #ifdef S_IFDIR
      S_IFDIR
    #else
      0
    #endif
  },
  {
    "constant S_IFIFO is export(:ALL) = %lld",
    #ifdef S_IFIFO
      S_IFIFO
    #else
      0
    #endif
  },
  {
    "constant S_IFLNK is export(:ALL) = %lld",
    #ifdef S_IFLNK
      S_IFLNK
    #else
      0
    #endif
  },
  {
    "constant S_IFREG is export(:ALL) = %lld",
    #ifdef S_IFREG
      S_IFREG
    #else
      0
    #endif
  },
  {
    "constant S_IFSOCK is export(:ALL) = %lld",
    #ifdef S_IFSOCK
      S_IFSOCK
    #else
      0
    #endif
  },
  {
    "constant S_IFWHT is export(:ALL) = %lld",
    #ifdef S_IFWHT
      S_IFWHT
    #else
      0
    #endif
  },
  {
    "constant S_IREAD is export(:ALL) = %lld",
    #ifdef S_IREAD
      S_IREAD
    #else
      0
    #endif
  },
  {
    "constant S_IRGRP is export(:ALL) = %lld",
    #ifdef S_IRGRP
      S_IRGRP
    #else
      0
    #endif
  },
  {
    "constant S_IROTH is export(:ALL) = %lld",
    #ifdef S_IROTH
      S_IROTH
    #else
      0
    #endif
  },
  {
    "constant S_IRUSR is export(:ALL) = %lld",
    #ifdef S_IRUSR
      S_IRUSR
    #else
      0
    #endif
  },
  {
    "constant S_IRWXG is export(:ALL) = %lld",
    #ifdef S_IRWXG
      S_IRWXG
    #else
      0
    #endif
  },
  {
    "constant S_IRWXO is export(:ALL) = %lld",
    #ifdef S_IRWXO
      S_IRWXO
    #else
      0
    #endif
  },
  {
    "constant S_IRWXU is export(:ALL) = %lld",
    #ifdef S_IRWXU
      S_IRWXU
    #else
      0
    #endif
  },
  {
    "constant S_ISGID is export(:ALL) = %lld",
    #ifdef S_ISGID
      S_ISGID
    #else
      0
    #endif
  },
  {
    "constant S_ISTXT is export(:ALL) = %lld",
    #ifdef S_ISTXT
      S_ISTXT
    #else
      0
    #endif
  },
  {
    "constant S_ISUID is export(:ALL) = %lld",
    #ifdef S_ISUID
      S_ISUID
    #else
      0
    #endif
  },
  {
    "constant S_ISVTX is export(:ALL) = %lld",
    #ifdef S_ISVTX
      S_ISVTX
    #else
      0
    #endif
  },
  {
    "constant S_IWGRP is export(:ALL) = %lld",
    #ifdef S_IWGRP
      S_IWGRP
    #else
      0
    #endif
  },
  {
    "constant S_IWOTH is export(:ALL) = %lld",
    #ifdef S_IWOTH
      S_IWOTH
    #else
      0
    #endif
  },
  {
    "constant S_IWRITE is export(:ALL) = %lld",
    #ifdef S_IWRITE
      S_IWRITE
    #else
      0
    #endif
  },
  {
    "constant S_IWUSR is export(:ALL) = %lld",
    #ifdef S_IWUSR
      S_IWUSR
    #else
      0
    #endif
  },
  {
    "constant S_IXGRP is export(:ALL) = %lld",
    #ifdef S_IXGRP
      S_IXGRP
    #else
      0
    #endif
  },
  {
    "constant S_IXOTH is export(:ALL) = %lld",
    #ifdef S_IXOTH
      S_IXOTH
    #else
      0
    #endif
  },
  {
    "constant S_IXUSR is export(:ALL) = %lld",
    #ifdef S_IXUSR
      S_IXUSR
    #else
      0
    #endif
  },
  {
    "constant LOCK_SH is export(:ALL, :flock) = %lld",
    #ifdef LOCK_SH
      LOCK_SH
    #else
      0
    #endif
  },
  {
    "constant LOCK_EX is export(:ALL, :flock) = %lld",
    #ifdef LOCK_EX
      LOCK_EX
    #else
      0
    #endif
  },
  {
    "constant LOCK_NB is export(:ALL, :flock) = %lld",
    #ifdef LOCK_NB
      LOCK_NB
    #else
      0
    #endif
  },
  {
    "constant LOCK_UN is export(:ALL, :flock) = %lld",
    #ifdef LOCK_UN
      LOCK_UN
    #else
      0
    #endif
  },
  {
    "constant SEEK_SET is export(:ALL, :seek, :mode) = %lld",
    #ifdef SEEK_SET
      SEEK_SET
    #else
      0
    #endif
  },
  {
    "constant SEEK_CUR is export(:ALL, :seek, :mode) = %lld",
    #ifdef SEEK_CUR
      SEEK_CUR
    #else
      0
    #endif
  },
  {
    "constant SEEK_END is export(:ALL, :seek, :mode) = %lld",
    #ifdef SEEK_END
      SEEK_END
    #else
      0
    #endif
  },
  {
    "constant S_IFMT is export(:ALL) = %lld",
    #ifdef S_IFMT
      S_IFMT
    #else
      0
    #endif
  },
  { (char*)NULL, 0 }
};

int main() {
  char buff[1024];
  struct definition_pair *one = definitions;
  FILE *outfile = fopen("Fcntl.pm", "a");
  fprintf(outfile, "\n");

  while ( one->const_name != NULL ) {
    fprintf(outfile, one->const_name, one->const_value);
    fprintf(outfile, ";\n");
    one++;
  }

  fclose(outfile);

  return 0;
}
