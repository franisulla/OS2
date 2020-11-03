#!/bin/bash

#for some reason random works very slowly and I decided to change it to urandom

head /dev/urandom | tr -dc [:graph:] | head --bytes=20 > ex1.txt
