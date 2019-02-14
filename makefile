LOPTS = -Wall -Wextra -std=c99
OBJS = lexer.o lexeme.o types.o scanner.o parser.o recognizer.o environment.o test-env.o pretty-printing.o

make : recognizer

run : test1

environment:
	gcc $(LOPTS) -c test-env.c lexeme.c types.c environment.c
	gcc $(LOPTS) test-env.c lexeme.o types.o environment.o -o environment

recognizer:
	gcc $(LOPTS) -c recognizer.c lexer.c lexeme.c types.c parser.c pretty-printing.c
	gcc $(LOPTS) recognizer.c lexer.o lexeme.o types.o parser.o pretty-printing.o -o recognizer

scanner :
	gcc $(LOPTS) -c scanner.c lexer.c lexeme.c types.c
	gcc $(LOPTS) scanner.c lexer.o lexeme.o types.o -o scanner

test1 :
	./recognizer test2.txt

clean :
	rm -f $(OBJS) scanner recognizer environment