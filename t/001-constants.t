use v6.c;
use Test;
plan 2;

use lib 'lib';

use-ok 'Fcntl', 'Verify that we can use the module.';
use Fcntl ('SEEK_SET', 'SEEK_CUR', 'SEEK_END');

subtest {
  plan 3;
  is SEEK_SET, 0, 'Verify SEEK_SET...';
  is SEEK_CUR, 1, 'Verify SEEK_CUR...';
  is SEEK_END, 2, 'Verify SEEK_END...';
}

done-testing;
