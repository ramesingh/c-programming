maxSeq: maxSeq.o test-subseq.o
	gcc -o maxSeq maxSeq.o test-subseq.o
maxSeq.o:
	gcc -pedantic -std=gnu99 -Wall -Werror -ggdb3 -c maxSeq.c
test-subseq.o:
	gcc -pedantic -std=gnu99 -Wall -Werror -c -ggdb3 ../15_tests_subseq/test-subseq.c
.PHONY: clean
clean:
	rm -f maxSeq *.o *~
