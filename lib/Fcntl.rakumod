use v6.c;

=begin pod

=head1 NAME

Fcntl - load the C Fcntl.h defines

=head1 SYNOPSIS

    use Fcntl;
    use Fcntl qw(:DEFAULT :flock);

=head1 DESCRIPTION

This module is just a translation of the C F<fcntl.h> file.
Unlike the old mechanism of requiring a translated F<fcntl.ph>
file, this uses the B<h2xs> program (see the Perl source distribution)
and your native C compiler.  This means that it has a
far more likely chance of getting the numbers right.

=head1 NOTE

Only C<#define> symbols get translated; you must still correctly
pack up your own arguments to pass as args for locking functions, etc.

=head1 EXPORTED SYMBOLS

By default your system's F_* and O_* constants (eg, F_DUPFD and
O_CREAT) and the FD_CLOEXEC constant are exported into your namespace.

You can request that the flock() constants (LOCK_SH, LOCK_EX, LOCK_NB
and LOCK_UN) be provided by using the tag C<:flock>.  See L<Exporter>.

You can request that the old constants (FAPPEND, FASYNC, FCREAT,
FDEFER, FEXCL, FNDELAY, FNONBLOCK, FSYNC, FTRUNC) be provided for
compatibility reasons by using the tag C<:Fcompat>.  For new
applications the newer versions of these constants are suggested
(O_APPEND, O_ASYNC, O_CREAT, O_DEFER, O_EXCL, O_NDELAY, O_NONBLOCK,
O_SYNC, O_TRUNC).

For ease of use also the SEEK_* constants (for seek() and sysseek(),
e.g. SEEK_END) and the S_I* constants (for chmod() and stat()) are
available for import.  They can be imported either separately or using
the tags C<:seek> and C<:mode>.

Please refer to your native fcntl(2), open(2), fseek(3), lseek(2)
(equal to Perl's seek() and sysseek(), respectively), and chmod(2)
documentation to see what constants are implemented in your system.

See L<perlopentut> to learn about the uses of the O_* constants
with sysopen().

See L<perlfunc/seek> and L<perlfunc/sysseek> about the SEEK_* constants.

See L<perlfunc/stat> about the S_I* constants.

=cut

=end pod

unit module Fcntl:ver<0.0.1>:auth<github:manchicken>;
use NativeCall;

sub impl_S_ISREG(int32 --> int8) is native('fcntl') {*}
sub S_ISREG(Int :$mode) is export(:S_ISREG) {
  return impl_S_ISREG($mode);
}

constant DN_ACCESS is export(:DN_ACCESS, :ALL) = 0;
constant DN_MODIFY is export(:DN_MODIFY, :ALL) = 0;
constant DN_CREATE is export(:DN_CREATE, :ALL) = 0;
constant DN_DELETE is export(:DN_DELETE, :ALL) = 0;
constant DN_RENAME is export(:DN_RENAME, :ALL) = 0;
constant DN_ATTRIB is export(:DN_ATTRIB, :ALL) = 0;
constant DN_MULTISHOT is export(:DN_MULTISHOT, :ALL) = 0;
constant FAPPEND is export(:FAPPEND, :ALL, :Fcompat) = 8;
constant FASYNC is export(:FASYNC, :ALL, :Fcompat) = 64;
constant FCREAT is export(:FCREAT, :ALL, :Fcompat) = 0;
constant FDEFER is export(:FDEFER, :ALL, :Fcompat) = 0;
constant FDSYNC is export(:FDSYNC, :ALL) = 0;
constant FD_CLOEXEC is export(:FD_CLOEXEC, :ALL) = 1;
constant FEXCL is export(:FEXCL, :ALL, :Fcompat) = 0;
constant FLARGEFILE is export(:FLARGEFILE, :ALL) = 0;
constant FNDELAY is export(:FNDELAY, :ALL, :Fcompat) = 4;
constant FRSYNC is export(:FRSYNC, :ALL) = 0;
constant FNONBLOCK is export(:FNONBLOCK, :ALL, :Fcompat) = 4;
constant FSYNC is export(:FSYNC, :ALL, :Fcompat) = 0;
constant FTRUNC is export(:FTRUNC, :ALL, :Fcompat) = 0;
constant F_ALLOCSP is export(:F_ALLOCSP, :ALL) = 0;
constant F_ALLOCSP64 is export(:F_ALLOCSP64, :ALL) = 0;
constant F_COMPAT is export(:F_COMPAT, :ALL) = 0;
constant F_DUP2FD is export(:F_DUP2FD, :ALL) = 0;
constant F_DUPFD is export(:F_DUPFD, :ALL) = 0;
constant F_EXLCK is export(:F_EXLCK, :ALL) = 0;
constant F_FREESP is export(:F_FREESP, :ALL) = 0;
constant F_FREESP64 is export(:F_FREESP64, :ALL) = 0;
constant F_FSYNC is export(:F_FSYNC, :ALL) = 0;
constant F_FSYNC64 is export(:F_FSYNC64, :ALL) = 0;
constant F_GETFD is export(:F_GETFD, :ALL) = 1;
constant F_GETFL is export(:F_GETFL, :ALL) = 3;
constant F_GETLEASE is export(:F_GETLEASE, :ALL) = 0;
constant F_GETLK is export(:F_GETLK, :ALL) = 7;
constant F_GETLK64 is export(:F_GETLK64, :ALL) = 0;
constant F_GETOWN is export(:F_GETOWN, :ALL) = 5;
constant F_GETPIPE_SZ is export(:F_GETPIPE_SZ, :ALL) = 0;
constant F_GETSIG is export(:F_GETSIG, :ALL) = 0;
constant F_NODNY is export(:F_NODNY, :ALL) = 0;
constant F_NOTIFY is export(:F_NOTIFY, :ALL) = 0;
constant F_POSIX is export(:F_POSIX, :ALL) = 0;
constant F_RDACC is export(:F_RDACC, :ALL) = 0;
constant F_RDDNY is export(:F_RDDNY, :ALL) = 0;
constant F_RDLCK is export(:F_RDLCK, :ALL) = 1;
constant F_RWACC is export(:F_RWACC, :ALL) = 0;
constant F_RWDNY is export(:F_RWDNY, :ALL) = 0;
constant F_SETFD is export(:F_SETFD, :ALL) = 2;
constant F_SETFL is export(:F_SETFL, :ALL) = 4;
constant F_SETLEASE is export(:F_SETLEASE, :ALL) = 0;
constant F_SETLK is export(:F_SETLK, :ALL) = 8;
constant F_SETLK64 is export(:F_SETLK64, :ALL) = 0;
constant F_SETLKW is export(:F_SETLKW, :ALL) = 9;
constant F_SETLKW64 is export(:F_SETLKW64, :ALL) = 0;
constant F_SETOWN is export(:F_SETOWN, :ALL) = 6;
constant F_SETPIPE_SZ is export(:F_SETPIPE_SZ, :ALL) = 0;
constant F_SETSIG is export(:F_SETSIG, :ALL) = 0;
constant F_SHARE is export(:F_SHARE, :ALL) = 0;
constant F_SHLCK is export(:F_SHLCK, :ALL) = 0;
constant F_UNLCK is export(:F_UNLCK, :ALL) = 2;
constant F_UNSHARE is export(:F_UNSHARE, :ALL) = 0;
constant F_WRACC is export(:F_WRACC, :ALL) = 0;
constant F_WRDNY is export(:F_WRDNY, :ALL) = 0;
constant F_WRLCK is export(:F_WRLCK, :ALL) = 3;
constant LOCK_MAND is export(:LOCK_MAND, :ALL) = 0;
constant LOCK_READ is export(:LOCK_READ, :ALL) = 0;
constant LOCK_WRITE is export(:LOCK_WRITE, :ALL) = 0;
constant LOCK_RW is export(:LOCK_RW, :ALL) = 0;
constant O_ACCMODE is export(:O_ACCMODE, :ALL) = 3;
constant O_ALIAS is export(:O_ALIAS, :ALL) = 0;
constant O_ALT_IO is export(:O_ALT_IO, :ALL) = 0;
constant O_APPEND is export(:O_APPEND, :ALL) = 8;
constant O_ASYNC is export(:O_ASYNC, :ALL) = 64;
constant O_BINARY is export(:O_BINARY, :ALL) = 0;
constant O_CREAT is export(:O_CREAT, :ALL) = 512;
constant O_DEFER is export(:O_DEFER, :ALL) = 0;
constant O_DIRECT is export(:O_DIRECT, :ALL) = 0;
constant O_DIRECTORY is export(:O_DIRECTORY, :ALL) = 1048576;
constant O_DSYNC is export(:O_DSYNC, :ALL) = 4194304;
constant O_EVTONLY is export(:O_EVTONLY, :ALL) = 32768;
constant O_EXCL is export(:O_EXCL, :ALL) = 2048;
constant O_EXLOCK is export(:O_EXLOCK, :ALL) = 32;
constant O_IGNORE_CTTY is export(:O_IGNORE_CTTY, :ALL) = 0;
constant O_LARGEFILE is export(:O_LARGEFILE, :ALL) = 0;
constant O_NDELAY is export(:O_NDELAY, :ALL) = 4;
constant O_NOATIME is export(:O_NOATIME, :ALL) = 0;
constant O_NOCTTY is export(:O_NOCTTY, :ALL) = 131072;
constant O_NOFOLLOW is export(:O_NOFOLLOW, :ALL) = 256;
constant O_NOINHERIT is export(:O_NOINHERIT, :ALL) = 0;
constant O_NOLINK is export(:O_NOLINK, :ALL) = 0;
constant O_NONBLOCK is export(:O_NONBLOCK, :ALL) = 4;
constant O_NOSIGPIPE is export(:O_NOSIGPIPE, :ALL) = 0;
constant O_NOTRANS is export(:O_NOTRANS, :ALL) = 0;
constant O_RANDOM is export(:O_RANDOM, :ALL) = 0;
constant O_RAW is export(:O_RAW, :ALL) = 0;
constant O_RDONLY is export(:O_RDONLY, :ALL) = 0;
constant O_RDWR is export(:O_RDWR, :ALL) = 2;
constant O_RSRC is export(:O_RSRC, :ALL) = 0;
constant O_RSYNC is export(:O_RSYNC, :ALL) = 0;
constant O_SEQUENTIAL is export(:O_SEQUENTIAL, :ALL) = 0;
constant O_SHLOCK is export(:O_SHLOCK, :ALL) = 16;
constant O_SYMLINK is export(:O_SYMLINK, :ALL) = 2097152;
constant O_SYNC is export(:O_SYNC, :ALL) = 128;
constant O_TEMPORARY is export(:O_TEMPORARY, :ALL) = 0;
constant O_TEXT is export(:O_TEXT, :ALL) = 0;
constant O_TRUNC is export(:O_TRUNC, :ALL) = 1024;
constant O_TTY_INIT is export(:O_TTY_INIT, :ALL) = 0;
constant O_WRONLY is export(:O_WRONLY, :ALL) = 1;
constant S_ENFMT is export(:S_ENFMT, :ALL) = 0;
constant S_IEXEC is export(:S_IEXEC, :ALL) = 64;
constant S_IFBLK is export(:S_IFBLK, :ALL) = 24576;
constant S_IFCHR is export(:S_IFCHR, :ALL) = 8192;
constant S_IFDIR is export(:S_IFDIR, :ALL) = 16384;
constant S_IFIFO is export(:S_IFIFO, :ALL) = 4096;
constant S_IFLNK is export(:S_IFLNK, :ALL) = 40960;
constant S_IFREG is export(:S_IFREG, :ALL) = 32768;
constant S_IFSOCK is export(:S_IFSOCK, :ALL) = 49152;
constant S_IFWHT is export(:S_IFWHT, :ALL) = 57344;
constant S_IREAD is export(:S_IREAD, :ALL) = 256;
constant S_IRGRP is export(:S_IRGRP, :ALL) = 32;
constant S_IROTH is export(:S_IROTH, :ALL) = 4;
constant S_IRUSR is export(:S_IRUSR, :ALL) = 256;
constant S_IRWXG is export(:S_IRWXG, :ALL) = 56;
constant S_IRWXO is export(:S_IRWXO, :ALL) = 7;
constant S_IRWXU is export(:S_IRWXU, :ALL) = 448;
constant S_ISGID is export(:S_ISGID, :ALL) = 1024;
constant S_ISTXT is export(:S_ISTXT, :ALL) = 512;
constant S_ISUID is export(:S_ISUID, :ALL) = 2048;
constant S_ISVTX is export(:S_ISVTX, :ALL) = 512;
constant S_IWGRP is export(:S_IWGRP, :ALL) = 16;
constant S_IWOTH is export(:S_IWOTH, :ALL) = 2;
constant S_IWRITE is export(:S_IWRITE, :ALL) = 128;
constant S_IWUSR is export(:S_IWUSR, :ALL) = 128;
constant S_IXGRP is export(:S_IXGRP, :ALL) = 8;
constant S_IXOTH is export(:S_IXOTH, :ALL) = 1;
constant S_IXUSR is export(:S_IXUSR, :ALL) = 64;
constant LOCK_SH is export(:LOCK_SH, :ALL, :flock) = 1;
constant LOCK_EX is export(:LOCK_EX, :ALL, :flock) = 2;
constant LOCK_NB is export(:LOCK_NB, :ALL, :flock) = 4;
constant LOCK_UN is export(:LOCK_UN, :ALL, :flock) = 8;
constant SEEK_SET is export(:SEEK_SET, :ALL, :seek, :mode) = 0;
constant SEEK_CUR is export(:SEEK_CUR, :ALL, :seek, :mode) = 1;
constant SEEK_END is export(:SEEK_END, :ALL, :seek, :mode) = 2;
constant S_IFMT is export(:S_IFMT, :ALL) = 61440;
