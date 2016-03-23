#!/bin/bash
DATE=$(date +"%Y-%m-%d_%H-%M-%S")
mkdir out/$DATE
echo $DATE > out/current_dir
