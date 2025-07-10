#    SPDX-FileCopyrightText: 2021 Monaco F. J. <monaco@usp.br>
#    SPDX-FileCopyrightText: 2025 João Pedro Gomes <joaop.gomes@usp.br>
#   
#    SPDX-License-Identifier: GPL-3.0-or-later
#
#  This file is a derivative of SYSeg (https://gitlab.com/monaco/syseg)
#  and includes modifications made by the following author(s):
#  João Pedro Gomes <joaop.gomes@usp.br>

CC=gcc
MAKE=make

bin = tyfsedit
bin = tyfsedit

%.o : %.c
	gcc -c $(CPPFLAGS) $(CFLAGS) -Wno-unused-result $< -o $@

tyfsedit : tyfsedit.o
	gcc $< -lm -o $@

# Create a 1.44 MB floppy image (2880 * 512 bytes)

disk.img:
	rm -f $@
	dd if=/dev/zero of=$@ count=2880

.PHONY: clean img

clean:
	rm -f $(bin) *.o tyfsedit *.img

# SYSeg's  convenience rules (not related to the example itself)
include bintools.mk
