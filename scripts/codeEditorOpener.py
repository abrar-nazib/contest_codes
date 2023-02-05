#!/usr/bin/env python
import time
import signal
import os


def open_editor(filename="."):
    time.sleep(1)
    print("[*] Opening Code Editor....")
    time.sleep(2)
    os.system(f"code {filename}")
    time.sleep(1)
    os.system("code output.txt -n; code input.txt -n")
    os.kill(os.getppid(), signal.SIGHUP)    # destroy the terminal


if __name__ == "__main__":
    open_editor()
