#! /usr/bin/env perl6
#Note `zef build .` will run this script
use v6.c;

class Build {
    need LibraryMake;
    # adapted from deprecated Native::Resources

    #| Sets up a C<Makefile> and runs C<make>.  C<$folder> should be
    #| C<"$folder/resources/lib"> and C<$libname> should be the name of the library
    #| without any prefixes or extensions.
    sub make(Str $folder, Str $destfolder) {
        my %vars = LibraryMake::get-vars($destfolder);

        mkdir($destfolder);
        LibraryMake::process-makefile($folder, %vars);
        shell(%vars<MAKE>);
    }

    method build($workdir) {
        my $destdir = 'resources/bin';
        my $pmdir = 'lib';
        mkdir $destdir;
        mkdir $pmdir;
        make($workdir, "$destdir");
        copy("Fcntl.prefix.pm", "Fcntl.pm");
        shell("$destdir/P6-Fcntl");
        move("Fcntl.pm", "$pmdir/Fcntl.pm");
    }
}

# Build.pm can also be run standalone
sub MAIN(Str $working-directory = '.' ) {
    Build.new.build($working-directory);
}
