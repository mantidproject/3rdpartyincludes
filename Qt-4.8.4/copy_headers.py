"""This script scans the headers in the ./include/ directory and
copies over the corresponding header from the Qt src directory. The location
of the installed Qt directory needs to be given as the first argument to the
script. The src is assumed to be a sub-directory called "src".
"""
import sys
import os
import re
import shutil

def usage():
    print """python copy_qt_headers.py QT_INSTALL_DIR
    """
    sys.exit(1)

def copy_headers(dest_include_dir, qt_install_dir, dest_src_dir):
    """
    Copy the headers that are linked from the files in dest_include_dir
    to dest_src_dir from qt_src_dir
    """
    for root, dirs, files in os.walk(dest_include_dir):
        for dir in dirs:
            for sub_root, sub_dirs, sub_files in os.walk(os.path.join(root, dir)):
                copy_headers(sub_root, qt_install_dir, dest_src_dir)
        for header in files:
            copy_header_file(os.path.join(root,header), qt_install_dir)
                    
def copy_header_file(header, qt_install_dir):
    header_ref = get_header_ref(header)
    if header_ref is not None:
        try:
            os.makedirs(os.path.dirname(header_ref))
        except WindowsError, exc:
            if 'already exists' not in str(exc):
                raise
        src_file = os.path.join(qt_install_dir, header_ref)
        if not os.path.exists(header_ref) or \
        os.path.getmtime(src_file) > os.path.getmtime(header_ref):
            try:
                shutil.copy(src_file, header_ref)
            except IOError, exc:
                print exc
                print "Error copying %s to %s from reference %s" % (src_file, header_ref, header)

def get_header_ref(header):
    file = open(header)
    ref = None
    for line in file:
        if line.startswith('#include'):
            ref = line[10:-2] # -2 takes care of newline & final "
            break
    file.close()
    if ref is not None and ".." in ref:
        ref = re.sub("\.\./", "", ref)
    else:
        ref = None
    return ref
   
if __name__ == '__main__':
    if len(sys.argv) != 2 :
        usage()
    dest_include_dir = os.path.join(os.path.dirname(__file__), 'include')
    if not os.path.exists(dest_include_dir):
        sys.exit("Missing include directory, cannot determine files to copy.")
    qt_src_dir = os.path.join(sys.argv[1], 'src')
    if not os.path.exists(os.path.join(qt_src_dir)):
        raise ArgumentError("Source directory '%s' does not exist." % qt_src_dir)
    dest_src_dir = os.path.join(os.path.dirname(__file__), 'src')
    #if not os.path.exists(dest_src_dir):
    #    os.mkdir(dest_src_dir)
    copy_headers(dest_include_dir, sys.argv[1], dest_src_dir)
