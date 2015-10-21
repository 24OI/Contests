#coding=utf-8
import os
import shutil

pathList = os.listdir(os.getcwd())
for i in pathList:
	if not(os.path.isfile(os.path.join(os.getcwd(), i))):
		Dir = os.listdir(os.path.join(os.getcwd(), i))
		for j in Dir:
			try:
				shutil.copy(os.path.join(os.getcwd(), i, j, j + '.cpp'), os.path.join(os.getcwd(), i, j + '.cpp'))
				shutil.rmtree(os.path.join(os.getcwd(), i, j), ignore_errors = False)
			except BaseException:
				try:
					shutil.copy(os.path.join(os.getcwd(), i, j, j + '.pas'), os.path.join(os.getcwd(), i, j + '.pas'))
					shutil.rmtree(os.path.join(os.getcwd(), i, j),ignore_errors = False)
				except BaseException:
					print '%s %s err' % (i, j)