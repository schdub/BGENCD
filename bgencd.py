#!/usr/bin/python
__author__ = 'jsbot@ya.ru'

import ctypes
import sys
fn = sys.argv[1]
encrypt = (sys.argv[2] == '-e') if len(sys.argv) > 2 else False

def BGENCD(d):
    s  = 'iVBORw0KGgoAAAANSUhEUgAAACAAAAAgCAMAAABEpIrGAAAAGXRFWHRTb2Z0d2FyZQBBZG9iZSBJbWFnZVJlYWR5ccllPAAAAyRpVFh0WE1MOmNvbS5hZG9iZS54bXAAAAAAADw/eHBhY2tldCBiZWdpbj0i77u/IiBpZD0iVzVNME1wQ2VoaUh6cmVTek5UY3prYzlkIj8+IDx4OnhtcG1ldGEgeG1sbnM6eD0iYWRvYmU6bnM6bWV0YS8iIHg6eG1wdGs9IkFkb2JlIFhNUCBDb3JlIDUuMC1jMDYxIDY0LjE0MDk0OSwgMjAxMC8xMi8wNy0xMDo1NzowMSAgICAgICAgIj4gPHJkZjpSREYgeG1sbnM6cmRmPSJodHRwOi8vd3d3LnczLm9yZy8xOTk5LzAyLzIyLXJkZi1zeW50YXgtbnMjIj4gPHJkZjpEZXNjcmlwdGlvbiByZGY6YWJvdXQ9IiIgeG1sbnM6eG1wPSJodHRwOi8vbnMuYWRvYmUuY29tL3hhcC8xLjAvIiB4bWxuczp4bXBNTT0iaHR0cDovL25zLmFkb2JlLmNvbS94YXAvMS4wL21tLyIgeG1sbnM6c3RSZWY9Imh0dHA6Ly9ucy5hZG9iZS5jb20veGFwLzEuMC9zVHlwZS9SZXNvdXJjZVJlZiMiIHhtcDpDcmVhdG9yVG9vbD0iQWRvYmUgUGhvdG9zaG9wIENTNS4xIE1hY2ludG9zaCIgeG1wTU06SW5zdGFuY2VJRD0ieG1wLmlpZDoxQjI3QjdCRDA2MzUxMUU2Qjg2RkI2RUM4Mjk1QkY1QyIgeG1wTU06RG9jdW1lbnRJRD0ieG1wLmRpZDoxQjI3QjdCRTA2MzUxMUU2Qjg2RkI2RUM4Mjk1QkY1QyI+IDx4bXBNTTpEZXJpdmVkRnJvbSBzdFJlZjppbnN0YW5jZUlEPSJ4bXAuaWlkOjFCMjdCN0JCMDYzNTExRTZCODZGQjZFQzgyOTVCRjVDIiBzdFJlZjpkb2N1bWVudElEPSJ4bXAuZGlkOjFCMjdCN0JDMDYzNTExRTZCODZGQjZFQzgyOTVCRjVDIi8+IDwvcmRmOkRlc2NyaXB0aW9uPiA8L3JkZjpSREY+IDwveDp4bXBtZXRhPiA8P3hwYWNrZXQgZW5kPSJyIj8+AfqKmAAAAYBQTFRFdHJq7O32qaqq8+ZNxcXJ4+PjpKSjvLzFpJ1JsaNx+fn5xLpHenp6urmt8uZQ8/P6tbWyzrp3lpeh2MN8mpZdh4eD3d7klotmsqpM28Z/0shL+u1P1dXV0753uru82tvc1NXeysvU1cB7kpKRn5hN9ulSe3RW8uZUq6VX/vJV8fHxn5BlsLCyi4Nj6ert/vFP+exRm5ub5dpNj4xt0dHRrKRKkoxT5OTro59m7uFKoaGgopxYa2pomJiU9+lMg31gqpttioVJzMJJs6tRi4RT8+VG7uJR9vb3jINeVlZU4tdN9+pU+OpPmJJgx75S2s9L+fn+38qB7+/w8+hWnJho++5OlZN2sK+mqqmWmZE8/Pz729FPYF5MubFWs7CUt7e8vLu0zLZsk5Sa9OdXoZ576txD0NHX09TWe3dIj4xj1MlH2c1GjYVsv7+/+epIkJCV/vBMlZJvhIF0mpdonpliZGJLsZ9k19fX5dlG8vP0qKeW5+fnq6qbqJhj/////v7+ktLKzwAAAhdJREFUeNps0+lz0kAUAHBMQoBEQ7nvAmkggBASQqENtlwtUI4WqIjFA+8Dra2KYkVf/vUGZ6xjlped5MP7bd7uzluD+jcAhOlmE0D9Pww3+aVRsduj0aKO3ID8VJK3EwnzV6wPawAspc16LjkKXO7SD5vrgHDvSTfGMDiOj2gM1oBi4dNLRgucZ5i5G1BA1mKrtPbwsdeyFXQA3Ds8jvO8NrRv12tCALGd5VezO6LIdMQfr4agK5F6kItp+e6Mpk/bdfnbQg9g78M+w4u0gmE92dQnMAS4uVE3drwBAAShvZQl6M/hYFbvvrdSxglcTYTb2IYeDI+4x+1eP3+UAjIsXGBpPVhuGarmhJsygts5lz+7hnpgxKact2aJ3BKeniRHhzIgJTA7F2jslpzxqtdbN/9SdUCF9Fmjcyo+MvcslUrlrqTfpgphJ5cTj1sWh8+hDc9bQDrKVA2ctHwONhRiWd/vNAoi5qy/5WNDrCPE+r6PJyjgkitgW0Xo+UcBdGuAc2/WnxnYMvFyJm748myi3+ZFeT/WKFgGIXZgKecBOQeFLPgPL2sFj83mGV8B0jBBUo38zHhnDfqg8O4FhfQknKcBKOsmOU+0R6UpRiF/WOzlVZgAFNP3mVJ0Kw9IVwcVaaGRiRTd8buWZBg9ajWsKMGmVmp8docwBAG9vAALyeVKAfUGXASFXt4/htJmrqT6bw3XAgwAPTBz7cfixY8AAAAASUVORK5CYII='
    sb = int((ctypes.c_uint32(~(len(d))).value & 0x1039498) % len(s))
    l  = []
    for i in range(len(d)):
        l.append(chr(ord(d[i])^ord(s[sb])))
        i += 1
        sb = (sb+1) % len(s)
    return ''.join(l)

with open(fn, 'rb') as fi:
    if (encrypt == False):
        fi.seek(8, 0) # skiping BGENCD>> part
    d = BGENCD(fi.read())
    if (encrypt == True):
        sys.stdout.write('BGENCD>>')
    sys.stdout.write(d)
