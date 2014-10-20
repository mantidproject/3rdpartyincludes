"""This script scans the headers in the ./include/ directory and
copies over the corresponding header from the Qt src directory. The location
of the installed Qt directory needs to be given as the first argument to the
script. The src is assumed to be a sub-directory called "src".
"""
import sys
import os
import posixpath #  Always use unix-style paths, since the Qt headers do
import re
import shutil

HEADER_REF_RE = re.compile(r'^#include "(.*)"$')
STRIPPED_HEADER_RE = re.compile(r'^((?:\.\./)+)(.*)$')

def usage():
    print """python copy_qt_headers.py QT_SRC_ROOT
    """
    sys.exit(1)

def copy_headers(dest_include_dir, qt_root, dest_dir):
    """
    Copy the headers that are linked from the files in dest_include_dir
    to dest_src_dir from qt_src_dir
    """
    for root, dirs, files in os.walk(dest_include_dir):
        for dir in dirs:
            for sub_root, sub_dirs, sub_files in os.walk(posixpath.join(root, dir)):
                copy_headers(sub_root, qt_root, dest_dir)
        for header in files:
            copy_referenced_headers(posixpath.join(root,header), qt_root, dest_dir)
                    
def copy_referenced_headers(header, qt_root, dest_root):
    header_ref = get_header_ref(header)
    if header_ref is None or not header_ref.startswith(".."):
        return
    # If the bare reference exists and is up to date
    # then do nothing
    header_dir = posixpath.dirname(header)
    dest_file = posixpath.join(dest_root, header_dir, header_ref)
    if os.path.exists(dest_file):
        return # nothing to do
    # Strip the parent directory separators
    re_match = STRIPPED_HEADER_RE.match(header_ref)
    dest_file_rel = re_match.group(2)
    dest_file_abs = posixpath.join(dest_root, dest_file_rel)
    try:
        os.makedirs(os.path.dirname(dest_file))
    except WindowsError, exc:
        if 'already exists' not in str(exc):
            raise
    src_file = posixpath.join(qt_root, dest_file_rel)
    try:
        shutil.copy(src_file, dest_file_abs)
    except IOError, exc:
        print exc
        print "Error copying %s to %s referenced from %s" % (src_file, dest_file_abs, header)

def get_header_ref(header):
    file = open(header)
    ref = None
    for line in file:
        if line.startswith('#include'):
            line = line.strip()
            re_match = HEADER_REF_RE.match(line)
            if re_match is not None:
                ref = re_match.group(1)
            break
    file.close()
    return ref

if __name__ == '__main__':
    if len(sys.argv) != 2 :
        usage()
    # Needs the include directory to begin with
    mod_dir = os.path.dirname(__file__).replace("\\", "/")
    dest_include_dir = posixpath.join(mod_dir, 'include')
    if not os.path.exists(dest_include_dir):
        sys.exit("Missing include directory, cannot determine files to copy.")
    qt_root = sys.argv[1].replace("\\", "/")

    # Make sure we get a fresh copy each time
    dest_dir = os.path.abspath(os.path.dirname(__file__)).replace("\\", "/")
    shutil.rmtree(posixpath.join(dest_dir, "src"))
    shutil.rmtree(posixpath.join(dest_dir, "tools"))

    # Do the copy
    copy_headers(dest_include_dir, qt_root, dest_dir)
