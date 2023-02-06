import re

strvar = "hello(itsme) Mr.Holmes -a great-detective"
strvar = re.sub("[().]", "", strvar)
strvar = re.sub("[- ]", "_", strvar)
print(strvar)
