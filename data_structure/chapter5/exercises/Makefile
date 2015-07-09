CC = gcc
CFLAGS = -g -lm
%.o: %.c
	${CC} ${CFLAGS} -c $<
all: two_three two_six
two_three: two_three.o types.o
	${CC} ${CFLAGS} $^ -o $@
two_six: two_six.o types.o
	${CC} ${CFLAGS} $^ -o $@
types.o: types.c types.h
	${CC} ${CFLAGS} -c $<
two_six.o: two_six.c
	${CC} ${CFLAGS} -c $<
two_three.o: two_three.c
	${CC} ${CFLAGS} -c $<

