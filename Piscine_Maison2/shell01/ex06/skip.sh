#!/bin/sh
ls -l | awk 'NR % 2 == 1 {print $0}'
