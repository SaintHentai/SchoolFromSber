#/bin/bash

fails_count=0

if [[ $# -ne 2 ]]; then
      echo "Expecting 2 arg" >&2
      echo "NAME_DIR NAME_FILE"
      echo "------------------------------------------------"
      exit 1
fi

echo "------------------------------------------------"
ls -la $1/materials/linters
echo "------------------------------------------------\n"
echo "------------------------------------------------"
ls -l $1/src/
echo "------------------------------------------------\n"
echo "------------------------------------------------"
find -f $1/materials/linters/.clang-format
echo "------------------------------------------------\n"

find -f $1/src/*.out

if [[ $? -ne 0 ]]; then
        echo "------------------------------------------------"
        echo -e "\033[32mDONE!\033[0m"
        echo "------------------------------------------------\n"
else
        echo "------------------------------------------------"
        echo -e "\033[31mFAIL!\033[0m You have FILE .out"
        echo "------------------------------------------------\n"
        fails_count=$((fails_count+1))
fi

find -f $2

if [[ $? -eq 0 ]]; then
        echo "------------------------------------------------"
        echo -e "\033[32mDONE!\033[0m File found"
        echo "------------------------------------------------\n"
        fails_count=$((fails_count+1))
fi

find -f $1/src/.clang-format

if [[ $? -eq 0 ]]; then
        echo "------------------------------------------------"
        echo -e "\033[32mDONE!\033[0m Clang-format found"
        echo "------------------------------------------------\n"
else
        echo "------------------------------------------------"
        echo -e "\033[31mFAIL!\033[0m No such file or directory"
        echo "------------------------------------------------\n"
        fails_count=$((fails_count+1))
fi

if [[ ! -f $1/src/.clang-format ]]; then
    echo "I: generating .clang-file"
    cp  $1/materials/linters/.clang-format $1/src/.clang-format
fi

find -d $1/src >> /dev/null

if [[ $? -eq 0 ]]; then
        echo "------------------------------------------------"
        echo -e "\033[32mDONE!\033[0m Directory src is found"
        echo "------------------------------------------------\n"
else
        echo "------------------------------------------------"
        echo -e "\033[31mFAIL!\033[0m No such directory or file"
        echo "------------------------------------------------\n"
        fails_count=$((fails_count+1))
fi

echo "------------------------------------------------\n"
pwd
echo "------------------------------------------------\n"
ls .
echo "------------------------------------------------\n"

if [[ ! $2 == *.c ]]; then
    echo "E: not a .c file: $2"
    exit 2
fi

echo "I: checking and formating for clang format"
clang-format -n $2
echo -e "I:\033[32mdone\033[0m\n"
echo "------------------------------------------------\n"


echo "I: checking by cppcheck"
if ! cppcheck --enable=all --suppress=checkersReport --suppress=missingIncludeSystem $2; then
    fails_count=$((fails:_count+1))
    echo "E: cppcheck fails"
fi
echo -e "I:\033[32mdone\033[0m\n"

echo "I: checking with gcc"
if ! gcc $2 -fsanitize=leak -fsanitize=undefined -fsanitize=unreachable -fsanitize=address; then
    fails_count=$((fails_count+1))
    echo "E: gcc check fails"
fi
echo -e "I:\033[32mdone\033[0m\n"

rm a.out

echo "I: compiling"
if ! gcc -Wall -Wextra -Wall -std=c11 $2; then
    fails_count=$((fails_count+1))
    echo "E: can not compile"
fi
echo -e "I:\033[32mdone\033[0m\n"

echo "I: checking for memory leaks (program's running)"
if ! leaks -quiet -atExit -- ./a.out; then
    fails_count=$((fails_count+1))
    echo "E: leaks fails"
fi
echo -e "I: \033[32mdone\033[0m\n"

echo -e "I: fails count - \033[31m$fails_count/10\033[0m\n"

rm a.out
rm .clang-format

echo -e "\033[32mFinish script\033[0m\n"
