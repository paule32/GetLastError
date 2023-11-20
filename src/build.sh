#!/bin/bash
# --------------------------------------------------------------------------------
# File:   build.sh
# Author: (c) 2023 Jens Kallup - paule32
# All rights reserved.
# only for education, and non-profit usage !
#
# This bash script convert the "de_DE" text file into gnu getext .mo format.
# the final output file "de_DE_utf8.mo" will be use for localization the app
# in the parent folder.
#
# Please be fair, and hold the Copyright notice, and use CODEOFCONDUCT rules.
# This script will be hosted on <https://github.com/paule32> for Free.
# --------------------------------------------------------------------------------
echo "[= build de_DE localization file =]"
mkdir -p ./locale/de_DE.utf8/LC_MESSAGES/
mkdir -p ./temp

# --------------------------------------------------------------------------------
# get encoding from original "de_DE.text" file, and store result into FROM_ENC ...
# --------------------------------------------------------------------------------
FROM_ENC=$(file -i ./po/de_DE.text | awk '{print $3}' | cut -d "=" -f 2-)
LAST_MOD=$(echo "Jens Kallup \\<paule32\\.jk\\@gmail\\.com\\>")
# --------------------------------------------------------------------------------
# convert ANSI German Umlauts to UTF-8 Encoding characters, pipe result ...
# --------------------------------------------------------------------------------
echo "[= convert input Encoding to UTF-8 =]"
iconv --from-code=${FROM_ENC} --to-code=UTF-8 ./po/de_DE.text > ./temp/windows.pot
if [[ $? -gt 0 ]]; then
  echo "error: iconv file could not be converted to utf-8 encoding format."
  exit 1
fi

# --------------------------------------------------------------------------------
# create german locale "de_DE_utf8.po" file for getext localization ...
# --------------------------------------------------------------------------------
echo "[= create windows.po =]"
msginit --locale de_DE --output-file ./temp/windows.po --input ./temp/windows.pot
if [[ $? -gt 0 ]]; then
  echo "error: msginit could not create windows.po file."
  exit 1
fi

# --------------------------------------------------------------------------------
# replace Translator in "de_DE_utf8.po" with sed ...
# --------------------------------------------------------------------------------
echo "[= replace translator =]"
sed -i 's/\"Last-Translator\: .*\\n\"/\"Last-Translator\: Jens Kallup \<paule32\.jk\@gmail\.com\>\\n\"/g' ./temp/windows.po
if [[ $? -gt 0 ]]; then
  echo "error: sed can not replace translator."
  exit 1
fi

# --------------------------------------------------------------------------------
# write the final localization file "de_DE.mo" ...
# --------------------------------------------------------------------------------
echo "[= create final utf8.mo =]"
msgfmt --check --output-file \
	./temp/windows.mo \
	./temp/windows.po
if [[ $? -gt 0 ]]; then
  echo "error: msgfmt could not create windows.mo file."
  cd ..
  exit 1
fi

# --------------------------------------------------------------------------------
# to hold locales database tiny as possible, we use gzip, to shrink the size of
# the final output file ...
# --------------------------------------------------------------------------------
echo "[= compress windows.mo file =]"
gzip -9 -c ./temp/windows.mo > ./locale/de_DE.utf8/LC_MESSAGES/windows.mo.gz

# --------------------------------------------------------------------------------
# create object file ...
# --------------------------------------------------------------------------------
echo "[= compile GetLastError.cc file =]"
g++ -O2 -std=c++20 -o ./temp/GetLastError.o -c GetLastError.cc
if [[ $? -gt 0 ]]; then
  echo "error: could not create ./temp/GetLastError.o"
  exit 1
fi

# --------------------------------------------------------------------------------
# we reach the end of this script task ...
# --------------------------------------------------------------------------------
echo "[= done =]"
exit 0
