set -x
mkdir build
cd build
foldertab "cmake .."
cmake --log-level=VERBOSE ..
foldertab "cmake --build ."
#cmake --log-level=ERROR|WARNING|NOTICE|STATUS|VERBOSE|DEBUG|TRACE --build ..
cmake --log-level=VERBOSE --build ..
# ./EKGViewer
