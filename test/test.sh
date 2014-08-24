#!/bin/bash

gcc test.c
./a.out
/usr/bin/env php pack64_test.php
rm -f a.out test.db
