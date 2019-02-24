#!/usr/bin/env bash

PROGRAM="./lw1"
OUT=$(mktemp)
INPUT_DATA_FOLDER="tests"
CORRECT_OUT_FOLDER="correctOutput"

function error() {
    rm ${OUT}
    echo -en \\nProgram test failed\\n

    exit 1
}

echo Без параметров
${PROGRAM} > ${OUT}
diff ${OUT} ${CORRECT_OUT_FOLDER}/output1.txt > /dev/null || error
echo -en Passed\\n\\n

echo Пустое искомое значение
${PROGRAM} ${INPUT_DATA_FOLDER}/input.txt ${OUT} "" "666"
diff ${OUT} ${CORRECT_OUT_FOLDER}/output2.txt > /dev/null || error
echo -en Passed\\n\\n

echo Замена нескольких значений в 1 строке
${PROGRAM} ${INPUT_DATA_FOLDER}/input.txt ${OUT} "Lorem" "666"
diff ${OUT} ${CORRECT_OUT_FOLDER}/output3.txt > /dev/null || error
echo -en Passed\\n\\n

echo Одиннаковые файлы
${PROGRAM} ${INPUT_DATA_FOLDER}/input.txt ${INPUT_DATA_FOLDER}/input.txt "Lorem" "666" > ${OUT}
diff ${OUT} ${CORRECT_OUT_FOLDER}/output4.txt > /dev/null || error
echo -en Passed\\n\\n

rm ${OUT}
echo All tests passed

exit 0