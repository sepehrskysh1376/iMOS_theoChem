#! /usr/bin/perl -w

use strict;

my @hatoms = ();
my @oatoms = ();

while (<>) {
    if (/^\s*H\s+(-?\d+\.?\d*)\s+(-?\d+\.?\d*)\s+(-?\d+\.?\d*).*$/) {
        push @hatoms, $1, $2, $3;
    }

    if (/^\s*O\s+(-?\d+\.?\d*)\s+(-?\d+\.?\d*)\s+(-?\d+\.?\d*).*$/) {
        push @oatoms, $1, $2, $3;
    }
}

print  "\n&SYSTEM\n  ANGSTROM\n  SYMMETRY\n    1\n";
printf "  CHARGE\n   %4.1f\n", ($#hatoms+1)/3.0 - (2.0 * ($#oatoms + 1)/3.0); 
print  "  CELL\n   ##FIXME## 1.0 1.0 0.0 0.0 0.0\n  CUTOFF\n    25.0\n&END\n";


print "\n&ATOMS\n\n  ATOMIC CHARGES\n    -0.6\n     0.3\n";
 
if ($#oatoms > 0) {
    print "\n";
    print "*O_VDB_BLYP.psp FORMATTED\n";
    print "   LMAX=P\n";
    print "   ", ($#oatoms + 1) / 3, "\n";
    for (my $i=0; $i < $#oatoms; $i +=3) {
        printf "   %10.4f %10.4f %10.4f\n",
          $oatoms[$i+0], $oatoms[$i+1], $oatoms[$i+2];
    }
}

if ($#hatoms > 0) {
    print "\n";
    print "*H_VDB_BLYP.psp FORMATTED\n";
    print "   LMAX=S\n";
    print "   ", ($#hatoms + 1) / 3, "\n";
    for (my $i=0; $i < $#hatoms; $i +=3) {
        printf "   %10.4f %10.4f %10.4f\n",
          $hatoms[$i+0], $hatoms[$i+1], $hatoms[$i+2];
    }
}

print "\n&END\n\n";
