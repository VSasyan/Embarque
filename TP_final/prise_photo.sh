#!/bin/bash
DATE=$(date +"%Y-%m-%d_%H-%M-%S")
current=$(cat out/current_dir)
raspistill -vf -hf -t 1 -o out/$current/$DATE.jpg
scp out/$current/$DATE.jpg prof@rks1306w316:~/out_camera/
