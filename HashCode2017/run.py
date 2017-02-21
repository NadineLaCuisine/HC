#! /usr/bin/python

import sys, os
import subprocess

inputs=["empty"]

print "We build the sources once more to be sure..."
subprocess.check_call(["make", "rebuild", "-s"])

for oneInput in inputs: 
	subprocess.check_call(["./bin", "./inputs/" + oneInput + ".in" , "./outputs/" + oneInput + ".out"])
