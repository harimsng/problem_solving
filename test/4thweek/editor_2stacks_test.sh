#!/bin/bash

BIN=editor_2stacks

echo "test start"
for i in 1 2 3 4 5 6 7 8 9 a
do
	./$BIN < editor.in$i | diff - editor.ou$i
done
echo "test end"
