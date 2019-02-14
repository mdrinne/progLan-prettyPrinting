/*
 * Matthew Rinne
 * test-env.c
 * cs403 Programming Languages
 */


#include "lexeme.h"
#include "types.h"
#include "environment.h"
#include <stdio.h>
#include <stdlib.h>


int
main()
{
    printf("Creating a new environment,env1\n");
    Lexeme *env1 = newEnv();
    printf("The environment is:\n");
    displayEnv(env1);
    printf("Adding variable x with value 3\n");
    Lexeme *x = newLexemeID("x",1);
    Lexeme *x3 = newLexemeInt(3,1);
    insertEnv(env1,x,x3);
    printf("The environment is:\n");
    displayEnv(env1);
    printf("Adding variable str with value 'hello, world!'\n");
    Lexeme *str = newLexemeID("str",2);
    Lexeme *strVal = newLexemeString("hello, world!",2);
    insertEnv(env1,str,strVal);
    printf("The environment is:\n");
    displayEnv(env1);
    printf("Adding variable str with value 'hello, world!'\n");
    Lexeme *str2 = newLexemeID("str2",2);
    Lexeme *strVal2 = newLexemeString("matthew rinne",2);
    insertEnv(env1,str2,strVal2);
    printf("The environment is:\n");
    displayEnv(env1);
    printf("Extending the environment\n");
    Lexeme *env1_2 = extend(env1,NULL,NULL);
    printf("The environment is:\n");
    displayEnv(env1_2);
    printf("Adding variable y with value 7.24583\n");
    Lexeme *y = newLexemeID("y",1);
    Lexeme *yVal = newLexemeReal(7.24583,1);
    insertEnv(env1_2,y,yVal);
    printf("The environment is:\n");
    displayEnv(env1_2);
    printf("Creating a new environment, env2\n");
    Lexeme *env2 = newEnv();
    printf("The environment is:\n");
    displayEnv(env2);
    printf("Adding variable z with value 52 to env2\n");
    Lexeme *z = newLexemeID("z",1);
    Lexeme *zVal = newLexemeInt(52,1);
    insertEnv(env2,z,zVal);
    printf("The environment is:\n");
    displayEnv(env2);
    printf("Extending env1 with env2\n");
    Lexeme *env1_3 = extend(env1_2,car(car(env2)),cdr(car(env2)));
    printf("The environment is:\n");
    displayEnv(env1_3);
    printf("Looking up value of str: %s\n", getLexemeSval(lookup(str,env1_3)));
    printf("Updating value of str to 'hello dr. Lusth'\n");
    Lexeme *newStrVal = newLexemeString("hello dr. Lusth",1);
    update(env1_3,str,newStrVal);
    printf("The environment is:\n");
    displayEnv(env1_3);
    return 0;
}
