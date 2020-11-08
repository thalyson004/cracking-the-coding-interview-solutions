import os
import glob

print('Clearing files...')
for files in os.listdir():
	if os.path.isdir(files):
		os.chdir(files)
		for files in os.listdir():
			if files.endswith( '.exe' ) or files.endswith( '.o' ):
				print(files, "deleted")
				os.remove( files )		
		os.chdir( os.path.dirname(os.getcwd()) )
		
	if files.endswith( '.exe' ) or files.endswith( '.o' ):
		print(files, "deleted")
		os.remove( files )