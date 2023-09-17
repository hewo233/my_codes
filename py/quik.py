# -*- coding: utf-8 -*-

import pyautogui
import time

need_time = float(input())

delay = 0.1

num_clicks = int(need_time / delay) 

print(num_clicks)

time.sleep(2)

for _ in range(num_clicks):
    click = pyautogui.position()
    pyautogui.click(click.x, click.y)
    time.sleep(delay)