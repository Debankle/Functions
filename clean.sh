rm -rf build
find tests -type f | perl -lne 'print if -B' | xargs rm -rf