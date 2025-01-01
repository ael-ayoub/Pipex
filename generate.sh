#!/bin/bash
filename=$(basename "$1" .h | tr '[:lower:]' '[:upper:]')
echo "#ifndef ${filename}_H"
echo "#define ${filename}_H"
echo ""
echo "#endif // ${filename}_H"
