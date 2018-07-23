#!/bin/sh

usage () {
	echo "usage: ./`basename ${0}` <Repository Name>"
}

if test ! ${#} -eq 1 ; then
	usage
else
	git clone https://github.com/HippopoStar/${1}.git
fi
