#!/bin/bash

BLUE="\e[0;94m"
RED="\e[31m"
GREEN="\e[0;92m"
YELLOW="\e[0;33m"
CYAN="\e[0;96m"
COLOR="\e[0m"

ARG="$(( (RANDOM % 6) + 1))"

if [ "$ARG" == "1" ]
then
	echo -e "${CYAN}⠀⠀⠀⠀⠀⠀⠀⠄⣀⠢⢀⣤⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣄⠀⡔⢀⠂⡜⢭⢻⣍⢯⡻⣝⣿⣿⡿⣟⠂
⠀⠀⠀⠀⠀⠀⠀⠄⠀⣦⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⡔⡀⢂⠜⣪⢗⡾⣶⡽⣾⣟⣯⠛⠀⠀
⠀⠀⠀⠀⠀⠄⠀⠠⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣔⠨⡸⡝⣯⣳⢏⣿⠳⠉⠀⢠⣬⡶
⠠⣓⢤⣂⣄⣀⢀⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡆⠁⣞⡱⣝⠎⠀⢀⠠⣥⠳⡞⡹
⠀⡄⢉⠲⢿⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡔⣧⡽⠋⠀⣰⣶⣻⣶⣿⢾⣷
⢤⡈⠉⠲⢤⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠁⢀⡴⢏⡳⢮⡿⣽⣞⠻⡜
⠒⣭⠳⢶⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢿⡙⠮⣜⣯⡽⣳⢌⡓⠈
⡸⣰⢋⣷⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣻⢿⣻⣿⡽⣗⠋⠄⠀
⠣⢇⢟⣸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⢟⡿⢣⣟⡻⠘⠀⠀⠀
⠱⡊⠤⣸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠨⠗⠋⣁⣤⠖⠊⢁⣀
⠀⠁⠂⢹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡏⠀⠀⠀⠀⣿⡂⠹⣿⣿⣿⣿⣿⠙⣿⣿⣿⣿⣿⣿⣿⣿⡿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠄⠒⢋⣉⡤⣔⣮⣽⣾
⢢⠣⣌⢼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⢰⣿⡅⠀⣿⣿⣿⣿⣿⠀⠸⢿⣹⣿⣿⣿⣿⣿⡇⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣻⣿⣿⣿⣿⣿⣿⣿
⢃⡉⠠⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⣼⢹⠀⠀⠀⠀⣾⠿⡇⠀⣿⣿⣿⣿⡏⠀⠀⣞⣧⣻⠟⢿⣿⣿⢠⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⣧⠱⣌⣳⣽⣻⣿⣿⣻
⠀⢒⡕⣺⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠁⡇⠈⣇⠀⠀⠀⠈⡆⢳⠀⠇⡟⠋⠉⠀⠀⠀⠃⢙⣠⣤⣤⣼⣯⣚⣟⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠌⠑⠌⢳⠛⡛⠏⠛⠉
⡘⢷⣌⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠉⢻⣀⣧⣤⣽⣦⣤⣄⠀⠰⡀⠃⠀⠀⠀⠀⠀⠀⡴⠟⠛⣉⣉⡉⠉⠈⠉⠉⠉⠋⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⢈⠈⠈⠁⠛⠀⠀⠀⣒
⠉⢣⡛⣿⣿⣿⣿⣿⣿⣿⣿⣿⡧⠖⠛⠉⠉⠉⠀⠀⠐⠒⢢⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡾⣠⣲⣾⣿⢿⣷⢶⡄⠀⠀⣽⣿⣿⣿⣿⡿⠟⣿⣿⣿⣿⣿⠛⢁⣤⡶⠿⠛⠋
⠀⠀⠌⢽⣿⣿⣿⣿⣿⣿⣿⣿⡷⠀⠀⠀⣠⣶⣶⣿⣟⣿⣶⡅⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠃⢿⣿⣿⣿⣿⠀⣿⡀⠀⢻⣬⣙⡻⡿⣡⣾⣿⣿⡍⠈⣀⣤⣬⣤⣶⣲⣶⣿
⠀⢈⠐⡀⢻⣫⢿⣿⣿⣿⣿⠘⢧⠁⠀⣻⡏⠸⣿⣿⣿⣿⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠑⢄⣉⣛⣋⣡⡴⠃⠀⠀⣿⣿⣿⠟⣠⡛⢿⣿⣿⣷⣲⣽⣿⣿⣷⣾⣷⣿⣿
⠀⠀⢀⠐⡀⢃⡈⣿⢿⣿⣿⣟⡆⠀⠀⠉⠿⣦⣈⣉⣉⠤⠚⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡟⣡⣶⣿⣿⣾⣿⣿⣿⢿⡿⣿⣿⡿⠿⠛⣋⣡
⠠⠐⡀⢢⣶⣿⢧⠻⣯⣿⣯⡛⢿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⠘⠐⠂⡁⠤⠔⢂⣉⣤⡴
⣀⠥⠌⣳⢯⣟⣮⣗⣾⣟⣿⣿⣦⣭⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⠂⣈⠥⡔⡤⣍⠣⣝⢾⡹
⠀⠀⠀⠠⠈⠉⠈⠉⠉⠉⣨⣿⣿⣿⣯⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣿⣿⣿⣿⣿⣿⣿⣿⡟⠻⢞⣿⣝⣳⢎⢳⢻⡮⣕
⠀⠀⢀⠀⡀⠀⠀⣀⣴⣾⣿⣿⣿⣿⣿⣧⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⣿⣿⣿⣿⣿⣿⣿⣿⣿⡗⢠⠘⡼⣽⣛⡞⠦⣧⢻⣽
⠀⢈⠀⡀⡀⢤⠞⡉⢭⣹⣿⣿⣿⣿⣿⣿⣿⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⣿⣿⣿⣿⣿⣿⣟⣿⣍⣣⢾⣵⣯⣷⣽⣦⣑⣯⢿
⠀⠂⣴⣾⡟⣧⠊⡔⢢⠛⣿⣿⣿⣿⣿⣿⣿⣿⣷⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⠒⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣾⣿⣿⣿⣿⣿⣿⣿⣿⡟⠉⣯⢹⣽⢻⣿⣿⣿⣿⣿⣿⣿⣿
⣶⣟⠳⣏⡿⣎⠳⣈⡜⣺⣿⠿⢿⣝⡿⣫⢟⣽⣿⣿⠻⣦⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠔⠛⣿⠿⣟⢩⢾⣿⣿⣿⣿⣇⠾⣜⡧⣯⣟⣿⣿⣿⣿⣿⣿⣿⣿
⠋⢀⢱⣫⣟⢾⡹⢴⡸⣵⡏⣂⢾⡿⣽⣹⣟⣾⣿⡟⢠⡇⠀⣹⠂⠄⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣷⣣⢟⡿⣾⣿⣿⣿⣿⢌⠫⢝⡻⣵⢻⡟⣿⢿⣿⢿⡿⣿⠿
⠀⢢⠞⣴⢯⢯⣝⣦⢳⡝⡶⣭⣿⣽⣳⣟⡾⣽⡟⢀⡟⠀⢀⡿⠀⠀⠀⠁⠠⠤⠀⠀⠀⠤⠐⠀⠀⠀⠀⠀⠀⠀⢸⡗⠈⠭⣿⣿⣿⣿⡿⢌⠣⡀⡐⢈⠃⠚⠦⣉⠂⠣⠜⡄⢋
⣜⣷⢻⡜⣯⣾⡞⣥⣓⢾⡽⢎⡷⢯⡷⣯⢟⣽⠃⣸⠁⠀⡼⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⡄⢹⣿⣿⣿⣿⢃⡮⡑⢰⢠⣂⡜⣦⡴⣱⣎⣴⣩⡜⣦
⣿⣯⢷⡻⣏⣷⣟⠶⣙⠮⡙⢪⠜⣯⢽⣯⣿⠃⠄⢃⣠⠞⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⣾⣿⣿⣿⡇⠢⢡⡙⢦⡓⡼⣽⣾⣿⣿⣿⣿⣷⣿⣿
⣿⡹⢇⡳⡹⣞⠘⡈⢅⠢⢁⠂⡘⠤⣋⣶⣡⠴⠚⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⠰⡁⢆⠘⣡⠻⣽⣳⣿⣿⣿⣿⢿⣿⣿⣿
⢣⠝⡢⢍⠱⢈⣂⣌⡤⠦⠶⠶⠞⠛⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⣿⣿⣿⠛⠷⣭⣂⠌⢠⠓⡴⣻⣿⣿⣿⣿⣿⣿⣯⣿
⣇⢾⡱⠞⠈⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⣿⣿⡇⠀⠀⠀⠉⠛⠳⠿⣶⣽⣿⣿⣿⣿⣿⣿⣿⣿${COLOR}"
fi

if [ "$ARG" == "2" ]
then
	echo -e "${RED}⠀⠀⢮⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⠀
⠀⢘⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠠
⠀⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇
⠀⢸⣿⣿⣿⣿⣿⡿⣽⠇⢸⣿⣿⣿⣿⣿⣿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠆
⠀⠈⠘⢿⣿⡿⢿⣇⣹⠇⠨⢎⣿⢿⣿⣿⡿⠘⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃
⠀⠀⠀⢸⣿⡇⣷⣤⣩⡃⠘⠈⢸⠉⡤⣿⣅⡐⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣟⠆
⠀⠀⠀⠈⠃⢿⠘⠛⠛⠃⠀⠀⠀⠀⠀⢿⣤⣉⡓⠻⣿⣿⣿⣿⣿⡳⣿⣿⡿⠀
⠀⠀⠀⠀⠀⠈⣆⠀⠐⠀⢀⠀⠀⠀⠀⠈⠛⠿⠛⠁⠁⣿⣿⣿⣏⣽⣿⡟⠇⠀
⠀⠀⠀⠀⠀⠀⠈⢦⡀⢀⠯⣤⠀⠀⠀⠀⠀⠀⠀⠀⢨⣿⣿⡿⠿⠿⠻⠁⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⢹⣄⡀⠀⠄⠀⡀⠀⠀⠀⢀⣠⢷⣿⣿⣿⡆⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⢀⣠⣶⣿⣿⠑⢤⣈⣄⣤⣤⢶⣟⠯⠃⢹⣿⣿⣿⣷⣄⠀⠀⠀⠀
⠀⢀⣠⣴⣾⣿⣿⣿⣿⡏⢀⣦⣿⡞⠓⠋⠉⠀⠀⠀⢸⣿⣿⣿⣿⣿⣷⣄⠀⠀
⣶⣿⣿⣿⣿⣿⣿⣿⣿⣷⣿⣿⣿⣷⡀⠂⠄⠀⠀⢀⣾⣿⣿⣿⣿⣿⣿⣯⣧⡀
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⢀⠀⣀⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣄⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿${COLOR}"
fi

if [ "$ARG" == "3" ]
then
	echo -e "${GREEN}⠀⠀⠀⠀⠀⠀⠀⢠⣤⣄⣀⣠⣤⣶⣿⣯⣿⣽⣾⣷⣶⣶⡦⣄⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⢀⣿⣟⣯⣽⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣾⣟⣦⣄⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⣠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣾⣿⣿⣿⣿⣿⣿⣾⡷⣄⠀⠀⠀⠀⠀
⠀⠀⠀⢀⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣾⣿⣿⣾⣿⣿⣿⣷⣿⣿⣿⣿⣿⣿⣳⡀⠀⠀⠀
⠀⠀⢠⣿⣿⣽⣿⢿⣿⣿⣿⣿⡿⣿⣿⣿⣿⢿⡿⣽⣿⣿⡿⣿⣿⣏⣿⣿⣿⣟⣿⣳⡄⠀⠀
⠀⠀⣾⣿⣿⣽⣾⣿⣿⣿⣿⢿⣿⣿⣿⣿⣿⣿⢿⣿⣾⢿⣷⡿⣿⣿⣷⢿⣿⣿⣷⡿⣷⠀⠀
⠀⢸⣿⣿⣿⣿⣟⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣳⣿⣟⣿⣿⣿⣻⣽⣿⣿⡽⡇⠀
⠀⡿⣿⣿⣿⣿⣾⣿⣿⣿⣿⢿⣿⣿⣿⣽⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣽⡀
⢸⣿⣿⣿⣿⣿⣿⣿⣏⠀⠈⠀⣿⣿⣿⣿⣿⣿⣟⣿⣿⣿⣿⣿⣿⣿⡿⣿⣿⣿⣿⣿⣿⢿⡇
⢨⣿⣿⣿⣿⣽⣿⣿⣇⣀⡤⠤⣟⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣟⣿⣿⣿⣿⠎⠀
⢰⣿⡿⣿⣿⣿⣿⣿⠃⠀⠀⠐⠃⠘⠙⢹⠿⡘⣿⠟⠉⢹⡂⠿⡞⣿⣿⣿⣿⣿⣿⣿⣿⠂⠀
⠀⣿⣿⣿⣿⣿⣿⡞⠅⣀⣀⣀⣀⠉⠓⠚⠀⠁⡏⠀⢛⠋⢀⣀⣀⣋⠸⣿⣿⣿⣿⣿⣿⠃⠀
⠀⣷⣟⣿⣿⣿⣿⣆⠠⡟⣿⣿⣿⡿⠦⠀⠀⠀⠀⠀⠠⢿⣿⣿⣿⠻⢇⣿⣿⣿⣿⣿⣿⠀⠀
⠀⠈⢸⣻⣿⣿⣿⢯⡃⢀⠹⣿⡿⠗⠀⠀⠀⠀⠀⠀⠀⠘⢿⣿⠏⣈⠈⣿⣿⣿⣿⣿⣿⠀⠀
⠀⠀⠈⣿⣿⣿⣿⣇⡗⠈⠉⠉⠉⠉⠀⠀⢐⡀⠀⠀⠀⠈⠉⠉⠉⠑⢸⣸⣿⡟⣿⣿⡟⠀⠀
⠀⠀⠀⢻⣿⣽⣿⡏⢿⡆⠀⠀⠀⠀⠀⠀⠸⢆⡄⠀⠀⠀⠀⠀⠀⢠⣿⣿⣿⣿⣿⡿⠇⠀⠀
⠀⠀⠀⠈⠿⣿⢿⡇⠀⠙⢦⡀⠀⠀⠀⠐⠲⠤⠔⠂⠀⠀⠀⢀⣴⣾⣿⣿⣿⣿⣿⡟⠀⠀⠀
⠀⠀⠀⠀⠀⠘⣿⣇⠀⠀⠀⠙⠢⣄⡀⠀⠀⠀⠀⣀⣐⣺⣵⣿⣿⣿⣿⣿⣿⣿⣿⠇⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠙⠋⠀⠀⠀⠀⠀⢹⢨⠑⠲⠤⠞⠋⠉⣿⣿⣿⣿⣿⣿⣿⣿⡿⠁⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡼⠈⠀⠀⠀⠀⠀⠀⢿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⢀⣀⣠⢤⡠⠒⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠛⠿⣿⣿⣿⣿⣇⠀⠀⠀⠀⠀
⠀⠀⣠⠔⠒⠉⠁⠀⠀⠘⠶⣲⠄⠀⠀⠈⠀⠀⠀⢠⢀⠀⠀⣀⠤⢻⣿⣿⣿⡏⠐⠲⣄⠀⠀
⠀⢰⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠓⠒⠚⢕⡀⠀⠀⣠⠖⠒⠚⠁⠀⢾⣿⣿⣿⡁⠀⠀⠨⡆⠀
⠀⢸⠀⠀⠀⠒⠒⠒⠒⠒⠂⠀⠐⠚⠑⠆⠀⠀⠒⠓⠀⠀⠀⠀⠀⣿⣿⣿⣿⡆⠀⠀⠀⣇⠀
⠀⠈⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠁⠀${COLOR}"
fi

if [ "$ARG" == "4" ]
then
	echo -e "${CYAN}⣬⡙⡻⣿⣿⣿⣷⣞⡻⡶⢀⣀⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡠⠃⠀⠀⢀⡼⣹⣟⣿⡿⣟⡟⢁⣴⣿⣿⢣⡃
⠿⣿⣷⣮⡹⢿⣿⣿⠇⣤⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⡄⠀⠀⠀⠀⠀⠀⠀⡀⢴⠅⠀⠠⣢⣑⡱⢷⣹⡷⠋⣡⣴⣿⣿⣿⣞⢣⠂
⠐⠨⣛⢿⣿⣷⣤⠛⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣆⠀⠀⠀⠀⠀⡠⠴⠂⢀⣴⢏⠖⡺⢭⠟⠋⣠⣾⢿⣿⣿⣿⡿⣟⡡⠀
⠿⣶⣬⡑⢍⡻⢣⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⠀⢀⣴⢆⠇⠀⣰⣿⡓⢮⢩⡴⠋⣠⢾⣹⢫⣋⠷⣫⣿⣿⢷⣜⣦
⠶⣬⣛⠿⣶⡄⣸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⠺⡟⠁⣠⡾⢛⢯⡳⡬⠋⢠⣶⢻⢎⡵⡲⠭⣵⣻⣾⣿⣿⣿⣾
⠀⠀⠙⠻⠯⠅⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣇⢀⡼⢣⡝⢞⠸⢊⣔⢣⣏⣞⢯⡞⣱⢇⡿⣴⠿⣵⣯⣏⣿⣻
⢀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡆⠱⢑⡞⢀⡴⢏⠪⠖⡙⢎⠍⡼⢠⠟⠼⢏⠿⣋⠾⢹⠲⢯
⢀⢉⡖⡤⡄⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠈⣡⣞⣣⣎⣶⣙⣬⣑⡳⣘⡔⣣⢊⡵⠌⠱⢄⠩⠢⠙⠐
⣔⠣⡝⡴⠁⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠾⠯⣍⠶⣙⠎⠈⠀⠀⠀⠐
⠍⠈⠁⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣮⣿⣿⡿⣻⢿⣏⡏⢅⡣⢬⡝⢗⣪⣤⡶⠐⠀⠀⠀⠀⠀
⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⣿⣷⣿⣞⢮⣱⢬⠷⠟⠛⠉⡀⠠⡀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠈⠉⠉⣿⣿⣿⣿⣿⣿⣿⣿⠇⠘⢿⣿⣿⡇⣿⣿⣿⢿⣎⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢹⣶⠧⢛⡭⠓⠋⠉⠁⠀⠐⠊⢉⠀⡍⣤⠒⠀⠁⠀⠀⠀
⠀⠀⠂⠉⠸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⡀⠀⠀⠀⣿⠸⢿⣿⣿⣿⣿⡿⡆⠀⠀⢙⣻⣧⣯⡭⠶⠞⠓⠒⠹⣿⣿⣿⣿⣿⣿⣿⣿⢟⣿⣿⢰⠊⠉⠅⠀⠀⠀⠀⠀⠀⠀⠠⠤⡤⠤⠄⣀⡀⠀⠀⠀⠀
⠀⠀⠀⢠⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⢿⣇⠘⢄⠀⠀⣿⠀⠈⣿⣿⡿⠿⠏⠃⢀⡼⠟⠋⠉⠀⠀⢀⣀⣀⣀⠀⢻⣿⡛⠛⠿⢿⣿⢋⣾⣿⣿⢸⣖⣲⡡⠀⠀⠀⠀⠀⠀⠀⠐⣢⣒⣧⣂⡄⠀⠀⠀⠀⠀
⠀⠀⠀⠁⢺⣹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠸⣿⠀⠘⠄⠀⢿⠀⠀⠘⠀⠀⠀⠀⠀⠁⠀⡶⠀⣀⣤⠶⣶⣶⣶⣒⣹⠛⠉⣿⣿⣷⡶⣤⣍⣛⣿⣿⢸⣏⡧⢟⡷⣭⣤⡄⠀⠀⡀⣰⣽⣯⣷⣯⣦⢥⣤⣤⣶⣿
⡽⣗⠷⠽⠌⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠹⡄⠀⢠⣴⣾⡶⠒⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⠉⠤⠤⠿⠛⠛⠋⠉⠀⠀⠻⡿⣫⣾⣿⣿⣿⣿⣿⢸⣿⡛⣫⣿⣿⠿⠓⠉⠸⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿
⠀⠀⢀⡠⡄⠈⡿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⢀⣹⣾⠟⠛⣉⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣷⣿⣿⣿⣿⣿⣿⣿⢸⣿⣇⡉⢻⡉⣀⣀⣠⣤⣿⣿⣿⣿⣿⣿⣿⡿⠟⠛⠉⠀
⢠⡾⠯⢿⣧⠀⡇⠹⣿⣿⣿⣿⣿⣿⣿⣿⠟⣠⡶⠛⠉⠀⢀⠀⢙⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⣿⣿⣿⣿⣿⣿⣿⢸⣿⣿⣿⣦⣙⢶⡻⣿⡟⠿⠿⠛⠋⢉⣀⣀⣤⣴⣶⣾⣿
⠉⠀⠀⠀⠞⠄⠀⠀⢸⡿⢻⣿⣿⣿⣿⣷⡘⠉⠀⠀⢀⣐⣥⣾⣭⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣻⣿⣿⣿⣿⣿⣿⣿⢸⣿⣿⡾⠛⠛⣆⡩⣥⡠⣴⡦⠦⣍⡛⠿⡿⢿⣿⣿⢿⣾
⠀⠀⠀⠀⠀⡀⣀⠤⢋⣀⠸⣿⣿⣿⣿⣿⣿⠦⠀⣴⣟⣁⣫⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢼⣿⣿⣿⣿⣿⣿⣿⡀⠿⣿⣷⣾⢿⣿⣿⣎⠻⣮⡿⣾⣢⡕⠢⢅⠩⠟⠽⠛⠞
⠀⠀⠀⠠⡈⢜⡯⣲⡼⣣⠵⡿⣿⣿⣿⣿⣿⣵⡀⠀⠀⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⡛⠿⢄⣟⢏⡓⠉⡭⢍⣭⣥⣌⢲⣄⢶⣶⡲⣤⡒⣠⡐⠲⣲
⠀⠀⣠⢣⣝⣾⢺⣙⡞⡳⢊⢵⣌⡙⠿⣿⣿⣦⠐⢄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢘⣿⣿⣿⣿⣿⣿⣷⣤⠘⢬⡮⣝⣆⢞⣷⣾⣿⣯⣦⡙⢷⡝⣿⣮⣛⠧⣝⡖⣆
⣰⡿⣽⣯⡳⣮⣥⣶⣫⣕⣏⠦⢱⠹⡳⣼⡙⣿⣷⣄⠣⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⠀⠀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⠿⣈⡠⠢⡑⠦⢭⡜⢯⣿⣝⢿⣿⣿⣦⠐⣶⣄⢤⣄⣀⢀⣀
⠁⠳⣽⣺⣿⣿⣿⢯⣿⣵⢾⣼⡓⣛⡣⣿⡇⣿⡻⢿⣿⣶⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢎⣀⠤⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣻⣿⣿⣿⣿⣿⣷⢼⢹⠢⠙⡲⢧⡞⣌⢿⣿⣆⡹⣟⠻⢷⢼⣿⡧⣟⣿⣧⣟
⣤⢿⡽⣿⣿⣿⣿⣿⣿⣿⣿⣿⣽⣿⣿⣟⣇⡏⣀⡖⡄⣿⣿⣿⣶⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⠀⠀⠀⠸⣿⣿⣿⣿⣿⣿⣿⣀⢳⡍⠀⠒⠭⣹⣂⢻⠿⣷⣬⣷⣄⠀⠛⢿⣿⣦⡲⣭
⣚⣯⡿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣞⣿⡻⢼⣝⣧⠂⣿⣿⣿⣿⣿⣿⣷⣶⣤⣤⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⠔⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣯⡜⢿⡳⣆⣒⠠⣬⣁⡉⠻⢷⣯⣿⣟⣳⠶⣿⣿⣿⣮
⣽⣮⢷⣿⡿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢿⣾⣿⣾⣽⢗⠢⣟⢙⣥⡬⠛⣿⠿⣿⢿⡿⢟⢻⠉⠉⠑⠒⠒⠂⠐⠒⠉⠀⠀⠀⠀⠀⠀⠀⠀⢹⣿⠸⣿⣿⣿⣿⣿⣷⡌⢛⣟⣿⣻⡷⣏⢤⡁⠲⣦⣎⣉⠛⠻⠿⢶⡋⢭
⣳⣞⣯⢷⣻⣟⡿⣽⢿⣻⢯⡿⣟⣾⡿⣿⢿⣿⣻⣿⣷⡺⣝⣶⢾⣤⣬⣤⣁⣴⣚⣷⣾⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠩⡄⠘⢿⣿⣿⣿⣿⣿⣆⠹⣾⣵⣟⣿⣶⣌⢱⠐⣭⣟⠿⣾⣶⣤⣬⡀
⣟⡾⣞⣯⢷⣺⣽⢞⣯⡽⣫⢷⣛⡮⡽⠋⠉⠁⠉⠁⠉⠑⠶⠶⠲⠯⠿⠿⠿⠿⠿⠟⠛⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠐⠂⠝⢿⣿⣿⣿⣿⣦⢋⣾⣫⢯⡷⣯⡗⣤⠘⢿⣿⣦⣛⠛⡿⣷
⣿⣟⣿⡾⣯⣷⣻⡾⣝⣯⣽⣳⡟⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢿⣿⣿⣿⣆⠉⠉⠉⠉⠉⠛⠾⣗⠨⢳⣯⢿⣳⢌⠳
⢏⡿⣾⣻⢿⣟⣿⣿⣿⣷⣻⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠻⣿⣿⣿⡆⠀⠀⠀⠀⠀⠀⠀⠱⢄⢨⣕⠿⣞⣔
⠫⣔⢋⠞⡳⢏⡷⣿⢯⡿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠑⣿⣿⣶⣬${COLOR}"
fi

if [ "$ARG" == "5" ]
then
	echo -e "${BLUE}⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⣀⣀⢀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⡀⣀⣀⣀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⡀
⠠⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⣦⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣅⠩⠖⠤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⠄⠆
⠠⠈⠀⠌⠀⠄⠠⠈⠠⠀⠄⠠⠁⠠⠀⠄⠠⠀⢄⣽⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣎⠠⠄⠠⠈⠀⠄⠠⠁⠠⠀⠄⠁⠄⠠⠀⠄⠨⠅
⠠⠁⠈⠀⠈⠀⠁⠀⠁⠠⠈⠀⠈⠀⠄⠀⠡⣪⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣍⢅⠈⠀⠈⠀⠈⠀⠁⠠⠈⠀⠄⠁⠠⠠⠅
⢀⡀⣀⢀⡀⣀⢀⡀⣀⠀⣀⠀⡀⢀⡀⢄⣵⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣆⢢⡀⡀⢀⡀⣀⠀⣀⠀⣀⠀⡀⢀⢀⡆
⢀⠀⠀⠀⠀⠀⠀⠀⠀⡀⠀⠀⢀⠀⢔⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⠑⡀⠀⠀⠀⡀⠀⢀⠀⢀⠀⠀⢂⡂
⠀⠂⠐⠐⠀⠒⠀⠒⠀⠐⠀⠂⢀⢎⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⠐⡀⠂⠐⠀⠂⠀⠂⠀⠂⠐⠀⡆
⠰⠠⠠⠄⠤⠀⠤⠀⠤⠀⠄⠄⢂⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣇⢢⠀⠄⠤⠠⠄⠤⠠⠀⠄⠢⠅
⠠⠀⠄⠠⠀⠄⠀⠄⠀⠠⠀⠰⣹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⣿⡛⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡄⠆⠀⠀⠄⠠⠀⠠⠀⠠⠠⠅
⠈⠀⠈⠀⠀⠈⠀⠈⠀⠁⢨⢡⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠁⠀⠀⠈⣿⡟⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⠈⠀⠁⠀⠀⠁⠀⠁⠀⠁⠇
⠐⡀⢀⠀⡀⢀⠀⡀⠀⢀⠂⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡏⠀⠀⠀⠀⢹⡇⢿⣿⣿⣿⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡆⠁⠀⠀⡀⢀⠀⡀⠀⡀⡆
⠐⠀⠂⠀⠐⠀⡀⠐⠀⠒⢰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⢸⠀⢸⣿⣿⣿⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠃⠐⠀⠐⠀⡀⠐⠀⠒⡂
⠀⠐⠀⠐⠀⠀⠀⠀⠀⢲⣸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇⠀⠀⠀⠀⢈⠀⢸⣿⣿⡟⠀⡿⠋⡿⢹⠿⣿⣿⣿⣿⠃⢿⠟⣿⡟⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣏⢰⠀⠀⠀⠀⠀⠀⠀⠐⠂
⠰⠠⠄⠤⠠⠄⠤⠠⠄⠃⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠙⡄⠀⣀⠀⠀⠠⠀⠘⠁⠙⠃⠀⠁⠀⠀⠀⣠⣤⣶⠶⠿⠶⠼⢤⣼⣁⣹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠈⠀⠄⠄⠢⠄⠤⠀⠌⠇
⢀⠀⠀⠀⠀⠀⠀⠀⠀⠃⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠸⣿⣿⣿⣻⣇⡼⠼⠿⠿⠛⠛⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⠀⠀⠀⠀⠀⠀⠀⠸⠃⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠘⡃
⠀⠂⠐⠀⠂⠐⠀⠂⠐⠀⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡠⢽⡿⠻⠃⠀⠀⢀⠀⠀⢀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠊⠀⢀⣠⣤⣤⣀⣀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠐⠀⠂⠐⠀⠂⠐⠆
⠠⠄⠄⠠⠀⠄⠠⠀⠄⠹⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡆⠀⠀⠀⢀⣠⣤⣦⡤⠤⢄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠟⠉⣾⣿⣿⣿⣛⡙⠲⣀⠀⠘⠛⣿⣿⣿⣿⣿⣿⣿⣿⡧⢠⠀⠄⠠⠀⠄⠠⠀⠌⠇
⠠⠈⠀⠄⠁⠠⠀⠄⠠⠁⠈⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⣠⠴⣻⣿⣿⣿⣽⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠛⠿⠿⠿⠿⠧⠄⠁⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⡇⠘⠀⠀⠄⠁⠀⠁⠀⠌⠅
⠀⠀⠁⠀⠈⠀⠀⠀⠀⠈⠀⢿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠇⠘⠡⠀⢿⡿⠿⠛⠋⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣧⡙⢿⣿⣿⣿⣿⣿⠁⠆⠀⠁⠈⠀⠁⠈⠀⠈⡅
⢐⠀⡀⢀⠀⡀⢀⠀⡀⢀⠃⠸⣿⣿⣿⣿⣿⣿⣿⣿⠃⠀⠀⠈⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣤⠙⣋⣴⣿⡿⠐⡂⢀⠀⡀⢀⠀⡀⢀⠀⡆
⢀⠂⠐⠀⠂⠐⠀⠂⠀⠒⠘⡀⢿⣿⣿⣿⢿⣿⣿⣿⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⣿⡿⢋⣴⡙⣿⣿⠇⠠⠐⠀⠂⠐⠀⠂⠐⠀⠒⡂
⠠⠀⠄⠠⠀⠄⠠⠀⠄⠠⠀⢣⠸⣿⣿⣿⣧⣿⣿⣿⣷⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣫⣶⣿⣿⣿⣾⡏⢀⠆⠀⠠⠀⠄⠠⠀⠄⠀⠄⠆
⠠⠄⠤⠀⠤⠀⠄⠄⠠⠀⠌⠤⠆⢻⣿⣿⣿⡿⣿⣯⣷⣷⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⠀⠌⠠⠄⠤⠀⠤⠀⠤⠀⠄⠌⠇
⠈⠀⠀⠀⠀⠀⠈⠀⠀⠀⠈⠀⠄⠘⣿⣿⣿⣿⣿⣧⡿⣿⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⣿⣿⣿⣿⣿⣿⠀⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠅
⠘⠀⠁⠈⠀⠁⠈⠀⠁⠈⠀⢈⠘⡀⢻⣿⣿⣿⣿⣿⣯⣼⣿⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⠒⠒⠀⠀⠈⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣼⣿⣿⣿⣿⣿⣿⣿⢰⠀⠈⠀⠁⠈⠀⠁⠈⠀⠁⡈⡃
⠐⢂⠂⠂⠒⠀⢂⠂⠐⠂⡐⠀⠂⣃⠸⡇⠹⣿⣿⣿⣿⣿⣿⣿⣿⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣾⣿⣿⣿⣿⣿⣿⡿⠃⢀⠀⢂⠐⡀⠒⠀⠒⢀⠂⠐⠐⡂
⠐⠀⠀⠐⠀⠀⠀⠀⠂⠀⠀⠀⠒⠘⢠⠒⢆⠸⣿⣿⣿⣿⣿⣿⣿⣿⣝⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⣿⣿⣿⣿⣿⣿⠀⠔⢂⠒⠀⠀⠀⠀⠂⠀⠀⠀⠐⠐⡂
⠠⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠈⡀⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⡧⢰⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⠅
⠠⠌⠠⠁⠌⠠⠁⠌⠠⠁⠌⠠⠁⠄⠈⠠⠁⠅⢺⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣤⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠄⠠⠀⠌⠠⠁⠌⠠⠁⠌⠠⠁⠄⠁⠇
⠀⠈⠀⠈⠀⠀⠁⠀⠁⠀⠈⠀⠈⠀⠁⠀⠁⠀⠸⠈⣿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣦⣄⡀⠀⠀⠀⢀⣠⣤⣾⣿⡗⠈⢻⣿⣿⣿⣿⣿⡿⣿⣿⣿⣿⣿⣿⠀⠉⠀⠁⠈⠀⠈⠀⠁⠈⠀⠀⠁⠈⠈⠅
⠘⠐⠀⠂⠐⠀⠂⠐⠀⠂⠐⠀⠂⠐⠀⠂⠐⢒⡓⡆⢛⠈⠻⠈⢿⠟⢿⣿⣿⢿⣿⣿⡿⣿⣿⠿⣹⢿⣿⣿⣿⣿⣿⣿⣿⠟⠟⠀⠀⡾⠋⠈⠻⠋⠈⠀⣈⢹⣿⣿⣿⡇⢀⠃⠐⠀⠂⠐⠀⠂⠐⠀⠂⠐⠀⠂⡐⡃
⠐⢂⠐⢀⠂⡐⢀⠂⡐⢀⠂⡐⢀⠂⡐⠀⢂⠀⠐⠒⣐⣒⣀⣣⣀⣂⡀⠉⠛⡈⠉⢿⠇⠀⠀⠀⠉⠙⠻⠿⠿⠟⠛⠉⠀⠀⠀⠀⠀⠂⣔⣚⣂⢄⣛⠚⠐⣿⣿⣿⣿⠀⡈⠐⢀⠂⡐⠀⢂⠐⡀⠂⡐⠀⢂⠐⢀⡃
⢀⠀⡀⢀⠀⡀⢀⠀⡀⢀⠀⡀⢀⠀⡀⢀⠀⡀⢀⠀⠀⠀⠀⢀⠐⠐⣊⣂⣖⣳⠴⣸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⢒⡀⠀⡀⠀⠀⣐⣿⣿⣿⡇⢠⠁⠀⡀⢀⠀⡀⢀⠀⡀⢀⠀⡀⢀⠀⡀⡆
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠀⠁⠈⠀⠀⠀⠀⠀⠈⠀⢠⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢫⠄⠀⠀⠀⠁⢨⣿⣿⣿⠀⡌⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⠅
⠈⠁⠌⠠⠁⠌⠠⠁⠌⠠⠁⠈⠀⠁⠈⠄⠡⢈⣤⠥⠬⢤⠡⠄⠥⠬⠄⠡⠘⠋⠙⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠫⢍⠤⠅⠨⣽⣿⣿⡏⠰⠀⠠⠁⠌⠠⠁⠌⠠⠁⠌⠠⠁⠌⠀⠡⠠⠅
⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣤⠌⠒⠉⠁⠀⠀⠀⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠑⠪⢁⣽⣿⣿⠁⠂⠀⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⡅
⠐⢀⠂⠐⠀⠂⠐⠀⡀⢂⣐⢾⣿⣿⡆⠀⠀⠀⠀⠀⠀⠀⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⠗⠠⢍⡒⣀⢂⠀⠐⠀⠂⠐⠀⠂⠐⠀⠂⠐⠀⡐⡂
⢐⠀⡐⠀⢂⠐⠀⠂⣐⠖⠀⠀⠙⣏⡇⠀⠀⠀⠀⠀⠀⠀⠁⠀⢀⡀⠀⠠⠤⠄⠀⠐⠀⠀⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠤⠀⣀⡀⠀⠀⠀⠀⢠⣿⡟⠀⠀⠀⠀⠁⣶⣒⡒⠒⡀⠂⠐⡀⢂⠐⡀⠂⠐⣀⡃
⢀⠀⠀⠀⠀⠀⠀⡴⠁⠀⠀⠀⠀⣽⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠀⠀⠀⢸⣿⠃⠀⠀⠀⠀⠀⣳⠿⠿⣷⣤⡂⣀⠀⠀⠀⠀⠀⠀⠀⡆
⠈⠁⠁⠈⠀⠡⡹⠁⠀⠀⠀⠀⠀⣯⡇⠀⠀⠀⠀⠀⠀⠀⠘⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⠃⠀⠀⠀⠀⠀⠀⢸⢰⠀⠈⠙⠻⠮⡭⠅⠈⠁⠈⠀⠉⠅
⠨⠀⠄⠁⠄⡰⠁⠀⠀⠀⠀⠀⠀⣎⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠑⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⠏⠀⠀⠀⠀⠀⠀⠀⢸⣼⡀⠀⠀⠀⠀⠈⢯⠡⠄⠠⠁⠈⡅
⣸⠤⠀⡀⣀⠃⠀⠀⠀⠀⠀⠀⢀⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠑⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡠⠀⠀⠎⠀⠀⠀⠀⠀⠀⠀⠀⢸⡷⡄⠀⠀⠀⠀⠀⠀⠱⡀⠀⡀⢈⡆
⣼⣿⣷⣶⣿⣷⣶⣶⣶⣶⣶⣶⣾⣿⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣿⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣿⣶⣶⣾⣶⣶⣶⣶⣶⣶⣶⣶⣶⣾⣿⣷⣶⣶⣶⣶⣶⣶⣾⣷⣾⣶⣷⡖
⢼⣿⡟⠛⢻⣿⣿⣿⣿⣿⣿⡟⠛⠛⠛⠛⠛⠛⠛⢻⡟⠛⠛⠛⠛⠛⠛⠛⠛⣿⡿⠛⠛⠛⠛⠛⠛⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠛⠛⠛⠛⠛⠛⣿⡟⠛⢻⣿⣿⣿⣿⣿⣿⣿⡿⠛⠛⣿⣿⣿⣿⣿⣿⣿⣿⡗
⢺⣿⡇⠀⢸⣿⣿⣿⣿⣿⣿⡇⠀⢀⣠⣀⣀⣀⣀⣸⣇⣀⣀⡀⠀⢀⣀⣀⣀⣿⠀⠀⣄⣀⣀⣀⡀⠀⢸⣿⣿⣿⣿⣿⣿⣿⠟⠁⠀⢀⣀⣀⡀⠀⠀⣿⡇⠀⢸⣿⣿⣿⣿⣿⣿⣿⡟⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣏
⣹⣿⡇⠀⢸⣿⣿⣿⣿⣿⣿⡇⠀⠘⠿⠿⠻⠿⠿⣿⣿⣿⣿⡇⠀⢸⣿⣿⣿⣿⠀⠀⠿⠻⠿⠻⠿⠾⣿⣿⣿⣿⣿⣿⣿⠅⠀⢀⣾⣿⣿⣿⡇⠀⠀⣿⡇⠀⢸⣿⣿⣿⣿⣿⣿⣿⣏⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⡧
⢼⣿⡇⠀⢸⣿⣿⣿⣿⣿⣿⡇⠀⢀⣀⣀⣀⣀⣀⣿⣿⣿⣿⡇⠀⢸⣿⣿⣿⣿⣄⣀⣀⣀⣀⣀⡀⠀⢸⣿⣿⣿⣿⣿⣿⠂⠀⠈⠉⠉⠉⠉⠁⠀⠀⣿⡇⠀⢸⣿⣿⣿⣿⣿⣿⣿⣏⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⡗
⢺⣿⡇⠀⠸⠿⠿⠿⠿⠿⣿⡇⠀⠸⠿⠿⠿⠿⠿⢿⣿⣿⣿⡇⠀⢸⣿⣿⣿⣿⠉⠉⠿⠿⠿⠿⠇⠀⢸⣿⣿⣿⣿⣿⣿⡁⠀⢰⣶⣶⣶⣶⡆⠀⠀⣿⡇⠀⠸⠿⠿⠿⠿⠿⠿⢿⣧⠀⠀⠿⠿⠿⠿⠿⠿⢿⣿⣏
⣹⣿⡇⡀⢀⢀⡀⢀⡀⢀⣼⡇⣀⠀⣀⠀⣀⠀⡀⣸⣿⣿⣿⣇⠀⣸⣿⣿⣿⣿⣄⡀⢀⡀⢀⡀⢀⣀⣼⣿⣿⣿⣿⣿⣿⡄⣀⣸⣿⣿⣿⣿⣇⢀⢀⣿⡇⣀⠀⣀⠀⣀⢀⡀⢀⣸⣷⢀⢀⠀⣀⢀⡀⡀⢀⢸⣿⡧
⢼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡗
⢺⣿⡇⢄⢻⣿⣿⣿⣿⣿⣿⡟⢠⠐⡄⢢⠐⡄⣈⢻⣿⡐⢸⣿⣿⣿⣿⡇⠄⣿⣟⠠⡐⢄⠢⡐⢄⡂⣽⣿⣿⣿⣿⣿⣿⡇⠀⢸⣿⣿⣿⣿⣿⣿⣿⡟⠁⠀⠀⠀⠀⠀⢸⣿⠀⠀⣿⡇⠀⠈⢻⣿⣿⣟⠀⢸⣿⣏
⣹⣿⡇⠌⣾⣿⣿⣿⣿⣿⣿⣇⠂⣿⣿⣿⣿⣿⢀⢻⣿⠌⢲⣿⣿⣿⣿⡇⢊⣿⣯⠐⣽⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡆⠀⢸⣿⣿⣿⣿⣿⣿⠏⠀⢀⣼⣿⣿⡇⠀⢸⣿⠀⠀⣿⡇⠀⠀⠀⠻⣿⣯⠀⢸⣿⡧
⢼⣿⡇⢊⣼⣿⣿⣿⣿⣿⣿⡇⠌⣿⣿⣿⣿⣿⢀⢻⣿⡘⢰⣿⣿⣿⣿⡇⢂⣿⡷⢈⠄⢂⠔⡠⠌⢸⣿⣿⣿⣿⣿⣿⣿⡆⠀⢸⣿⣿⣿⣿⣿⣿⠂⠀⠛⠛⠻⠛⠃⠀⢸⣿⠀⠀⣿⡇⠀⢸⡄⠀⠙⡷⠀⢸⣿⡗
⢺⣿⡇⠡⣾⣿⣿⣿⣿⣿⣿⡏⡐⣿⣿⣿⣿⣿⢀⢻⣿⡡⠌⠻⣿⣿⠟⡉⢄⣿⡿⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡆⠀⢸⣿⣿⣿⣿⣿⣿⡁⠀⣀⣀⣀⣀⡀⠀⢸⣿⠀⠀⣿⡇⠀⢸⣿⣆⠀⠈⠀⢸⣿⣏
⣹⣿⡇⠱⡈⢉⡉⡉⣉⠉⣿⣇⠰⢉⢉⡉⢉⠔⠂⣽⣿⣿⣦⡡⠌⡑⣈⣴⣿⣿⣟⠡⣈⠡⡉⢌⢉⡉⣽⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⣿⡁⠀⣿⣿⣿⣿⡇⠀⢸⣿⠀⠀⣿⡇⠀⢸⣿⣿⣧⡀⠀⢸⣿⡧
⢼⣿⣿⣶⣷⣷⣶⣷⣶⣾⣿⣿⣷⣾⣶⣾⣶⣾⣿⣿⣿⣿⣿⣷⣾⣶⣾⣿⣿⣿⣿⣶⣶⣷⣾⣶⣶⣶⣿⣿⣿⣿⣿⣿⣿⣷⣶⣶⣶⣶⣶⣶⣶⣿⣷⣶⣿⣿⣿⣿⣷⣶⣾⣿⣶⣶⣿⣷⣶⣾⣿⣿⣿⣷⣶⣾⣿⡗
⠘⠋⠙⠉⠋⠙⠉⠋⠙⠉⠋⠙⠉⠋⠙⠉⠋⠙⠉⠋⠙⠉⠋⠙⠉⠋⠙⠉⠋⠙⠉⠋⠙⠉⠋⠙⠋⠙⠉⠋⠙⠉⠋⠙⠉⠋⠙⠉⠋⠙⠉⠋⠙⠉⠋⠙⠉⠋⠙⠉⠋⠙⠉⠋⠙⠉⠋⠙⠉⠋⠙⠉⠋⠙⠉⠋⠙⠉${COLOR}"
fi

if [ "$ARG" == "6" ]
then
	echo -e "${YELLOW}⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⣶⣶⣖⣦⡶⣴⣤⡤⣄⣄⣀⣀⡀⣀⣀⣤⣶⣶⣿⣿⣿⣿⣿⣿⣿⣶⣮⣄⣀⣠⣠⣤⣤⡄⢿⡆
⡿⠿⢿⠿⠿⠿⠿⠿⠿⠾⠿⠿⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡉⠉⠉⢹⡃⢼⡇
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⠀⢸⡇⢸⡇
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⣿⣿⣿⣿⣿⣿⡿⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⠰⡃⢸⡇
⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⣿⣿⣿⣿⣿⣿⣿⡇⠀⡿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠄⡇⢸⡇
⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⠀⠇⠀⠀⡇⡿⢿⠟⡇⡟⡿⡿⢸⣿⣿⣿⣿⡇⡧⢸⡇
⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⢻⠝⠒⠛⠍⢁⠀⠀⠀⠀⠀⡉⠉⠑⠂⠈⣿⣿⣿⣗⠇⣸⡇
⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⠄⣠⢺⣿⣮⠁⠀⠀⠀⠠⠈⠋⣿⣿⢱⠀⣿⣿⣿⣾⡇⢸⡇
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⣿⡇⣿⠀⠀⠢⠉⠁⠀⠀⠀⠀⠀⠀⠀⠈⠁⠀⢠⣯⢿⣿⢸⡇⢸⡇
⠀⣀⢤⡠⢄⡀⠀⠀⢀⡐⢿⣷⣈⠇⠀⠀⠀⠀⠀⠀⢀⣀⠀⠀⠀⠀⠀⠀⢸⣿⣯⡏⢸⣧⢹⡇
⠀⢭⢂⠑⠂⠈⠀⢾⣋⡂⠈⣿⣿⣿⣆⠀⠀⠀⠀⠀⠚⣈⠀⠀⠀⠀⠀⢀⣾⣿⣿⠀⢸⣧⢻⣷
⠀⠀⠀⠀⠀⠀⠀⠜⠃⠋⠑⢸⣿⣿⣿⣧⣀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣾⣿⣿⣿⠀⢸⣧⢻⣿
⠀⠀⠀⠀⠀⠊⠀⠀⠀⠀⠀⠀⠋⠛⠻⡿⢿⡇⠂⠠⢀⣀⠠⠔⠊⣝⠟⠛⢻⣿⡇⠀⢸⣿⢸⣿
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⠀⠸⣿⠃⠀⢸⣿⡽⣿
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡆⠀⣿⠀⠀⢸⣿⣽⣿
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣿⡀⠀⢸⣿⣯⣿
⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣴⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⣼⣿⣻⣿
⣤⣤⣤⣤⣤⣤⣤⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿
⢯⡙⡭⢡⢣⠘⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷${COLOR}"

fi