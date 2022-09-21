#!/usr/bin/bash
# ssh -NL 19080:127.0.0.1:19080 root@192.168.1.200
ssh -L 19021:127.0.0.1:19021 root@192.168.1.200 "/opt/SEGGER/JLinkGDBServerCLExe -device AT32F403ACGT7 -if swd -speed 4000 -singlerun -halt -rtos GDBServer/RTOSPlugin_FreeRTOS"
