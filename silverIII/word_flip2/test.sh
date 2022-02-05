#!bin/bash
for i in 1 2 3 4 5 6 7
do
	echo ""
	echo "[$i]th testcase"
	./word_flip2 < input$i > comp$i
	cat out$i comp$i
	diff out$i comp$i
done
