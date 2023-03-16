#/usr/bin/env bash
#
if [ -z $(which bcpp) ]; then
  echo "* BCPP is not installed!"
  exit 1
fi
#
if [[ -n "$1" ]]; then
  bcpp -bcl -i 2 -s -tbcl -ybbi $1 $1.new
  mv -vf $1.new $1
  exit
else
#
  cd $(dirname ${0})
#
  for _file in $(find . -type f -iname '*.cpp' -o -iname '*.hpp' -o -iname '*.c' -o -iname '*.h'); do
    if [[ $_file =~ percentage.cpp ]]; then
      echo Skipping $_file
      continue
    fi

    echo "- formatting ${_file}"
    bcpp -bcl -i 2 -s -tbcl -ybbi ${_file} ${_file}.new
    mv -f ${_file}.new ${_file}
    git add ${_file}
  done
fi
#
