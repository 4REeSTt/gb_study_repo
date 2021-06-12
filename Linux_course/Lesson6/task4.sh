#!/bin/bash

sudo cat /var/log/syslog | grep -iE "threads" | grep -iE "1 pro"
