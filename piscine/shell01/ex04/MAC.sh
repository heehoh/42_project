#!/bin/bash
ifconfig -a | grep -w ether | cut -f2 -d ' '
