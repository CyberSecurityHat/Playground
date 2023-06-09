#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define DEFINED_LENGTH 200



// 함수 프로토타입

int question1();
int question2();
int question3();
int question4();
int question5();
int question6();
int question7();
int question8();
int question9();
void print_result(int total_points, int* correct, int* incorrect, int index_correct, int index_incorrect);

int (*questions[])() = {question1, question2, question3, question4, question5, question6, question7, question8, question9};

void shuffle(int *array, int n) {
    if (n > 1) {
        int i;
        for (i = 0; i < n - 1; i++) {
            int j = i + rand() / (RAND_MAX / (n - i) + 1);
            int t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}



// 메인 함수

int main(void) {
    srand(time(NULL));
    int point = 0;
    int correct[DEFINED_LENGTH] = {0};
    int incorrect[DEFINED_LENGTH] = {0};
    int index_correct = 0;
    int index_incorrect = 0;

    int num_questions = sizeof(questions) / sizeof(questions[0]);
    int *questionOrder = (int*) malloc(num_questions * sizeof(int));

    if(questionOrder == NULL) {
        fprintf(stderr, "Memory allocation failed!");
        return -1;
    }

    for(int i = 0; i < num_questions; i++) {
        questionOrder[i] = i;
    }

    shuffle(questionOrder, num_questions);

    printf("-----------------모의해킹 기말고사 대비 퀴즈-----------------\n\n");

    printf("문제 설명 : 다수의 정답을 기대할 때는 ','을 구분자로 사용(순서가 있을 경우, 순서에 맞춰서 작성)\n");
    printf("명령어는 실제로 명령어를 작성하듯이 순서대로 작성\n\n");

    for(int i = 0; i < num_questions; i++) {
        if(questions[questionOrder[i]]() == 1) {
             correct[index_correct++] = questionOrder[i] + 1;
            point++;
        } else {
            incorrect[index_incorrect++] = questionOrder[i] + 1;
        }
    }

    print_result(point, correct, incorrect, index_correct, index_incorrect);

    getchar();

    free(questionOrder);

    return 0;
}



// 출력 함수

void print_result(int total_points, int* correct, int* incorrect, int index_correct, int index_incorrect) {
    printf("\n\n------------------Quiz Result------------------\n");
    printf("점수: %d\n", total_points);

    printf("맞은 문제 번호: ");
    for(int i = 0; i < index_correct; i++) {
        printf("%d ", correct[i]);
    }
    printf("\n");

    printf("틀린 문제 번호: ");
    for(int i = 0; i < index_incorrect; i++) {
        printf("%d ", incorrect[i]);
    }
    printf("\n");
}



// 1번 문제

int question1() {
    char answer[DEFINED_LENGTH];
    printf("------------------------------------------------------------------------\n");
    printf("문제 1\n\n");
    printf("SET은 (a) 공격 기법에 기반한 도구로, (b)언어로 작성 되었으면, (c)와 연동해서 사용할 수 있다.\n\n");

    fgets(answer, DEFINED_LENGTH, stdin);

    if(strcmp(answer, "사회공학,파이썬,MSF\n") == 0) {
        return 1;
    }
    else {
        return 0;
    }
}



// 2번 문제

int question2() {
    char answer1[DEFINED_LENGTH];
    char answer2[DEFINED_LENGTH];
    char answer3[DEFINED_LENGTH];
    printf("------------------------------------------------------------------------\n");
    printf("문제 2\n\n");
    printf("SET 구동을 위한 명령어를 순서대로 적으시오\n\n");

    fgets(answer1, DEFINED_LENGTH, stdin);
    fgets(answer2, DEFINED_LENGTH, stdin);
    fgets(answer3, DEFINED_LENGTH, stdin);

    if((strcmp(answer1, "service apache2 start\n") == 0) && (strcmp(answer2, "service apache2 status\n") == 0) && (strcmp(answer3, "setoolkit\n") == 0)) {
        return 1;
    }
    else {
        return 0;
    }
}



// 3번 문제

int question3() {
    char answer1[DEFINED_LENGTH];
    printf("------------------------------------------------------------------------\n");
    printf("문제 3\n\n");
    printf("악성 스크립트가 포함된 URL을 사용자가 요청하게 되어 브라우저를 해석하는 단계에서 발생하는 XSS공격 유형의 이름을 적으시오.\n\n");


    fgets(answer1, DEFINED_LENGTH, stdin);

    if((strcmp(answer1, "DOM Based XSS\n") == 0) ) {
        return 1;
    }
    else {
        return 0;
    }
}



// 4번 문제

int question4() {
    char answer1[DEFINED_LENGTH];
    printf("------------------------------------------------------------------------\n");
    printf("문제 4\n\n");
    printf("악성코드에 기반해 침투 작업을 수행할 때 사용하는 MSF 인터페이스 이름을 적으시오.\n\n");


    fgets(answer1, DEFINED_LENGTH, stdin);

    if((strcmp(answer1, "msfvenom\n") == 0) ) {
        return 1;
    }
    else {
        return 0;
    }
}



// 5번 문제

int question5() {
    char answer1[DEFINED_LENGTH];
    printf("------------------------------------------------------------------------\n");
    printf("문제 5\n\n");
    printf("존더리퍼 실행 명령어를 적으시오.\n\n");


    fgets(answer1, DEFINED_LENGTH, stdin);

    if((strcmp(answer1, "john\n") == 0) ) {
        return 1;
    }
    else {
        return 0;
    }
}



// 6번 문제

int question6() {
    char answer1[DEFINED_LENGTH];
    char answer2[DEFINED_LENGTH];
    char answer3[DEFINED_LENGTH];
    char answer4[DEFINED_LENGTH];
    printf("------------------------------------------------------------------------\n");
    printf("문제 6\n\n");
    printf("문제 추가 정보\n");
    printf("원격지 ip : 192.168.152.0/24\n");
    printf("스레드 : 256\n\n");
    printf("MySQL 서버 존재 여부를 검색하는 metasploit 명령어를 적으시오.\n\n");


    fgets(answer1, DEFINED_LENGTH, stdin);
    fgets(answer2, DEFINED_LENGTH, stdin);
    fgets(answer3, DEFINED_LENGTH, stdin);
    fgets(answer4, DEFINED_LENGTH, stdin);

    if((strcmp(answer1, "use auxiliary/scanner/mysql/mysql_version\n") == 0) &&
    (strcmp(answer2, "set rhosts 192.168.152.0/24\n") == 0) &&
    (strcmp(answer3, "set threads 256\n") == 0) &&
    (strcmp(answer4, "run\n") == 0)) {
        return 1;
    }
    else {
        return 0;
    }
}



// 7번 문제

int question7() {
    char answer1[DEFINED_LENGTH];
    char answer2[DEFINED_LENGTH];
    char answer3[DEFINED_LENGTH];
    char answer4[DEFINED_LENGTH];
    char answer5[DEFINED_LENGTH];
    char answer6[DEFINED_LENGTH];
    char answer7[DEFINED_LENGTH];
    printf("------------------------------------------------------------------------\n");
    printf("문제 7\n\n");
    printf("문제 추가 정보\n");
    printf("원격지 ip : 192.168.152.0/24\n");
    printf("아이디 : root\n");
    printf("패스워드 : 1234\n");
    printf("스레드 : 256\n\n");
    printf("mysql_schemadump.rb 모듈을 이용한 MySQL 데이터베이스 및 테이블 현황 확인 metasploit 명령어를 적으시오.\n\n");


    fgets(answer1, DEFINED_LENGTH, stdin);
    fgets(answer2, DEFINED_LENGTH, stdin);
    fgets(answer3, DEFINED_LENGTH, stdin);
    fgets(answer4, DEFINED_LENGTH, stdin);
    fgets(answer5, DEFINED_LENGTH, stdin);
    fgets(answer6, DEFINED_LENGTH, stdin);
    fgets(answer7, DEFINED_LENGTH, stdin);

    if((strcmp(answer1, "use auxiliary/scanner/mysql/mysql_schemadump\n") == 0) &&
    (strcmp(answer2, "set rhosts 192.168.152.0/24\n") == 0) &&
    (strcmp(answer3, "set rport 3306\n") == 0) &&
    (strcmp(answer4, "set username root\n") == 0) && 
    (strcmp(answer5, "set password 1234\n") == 0) && 
    (strcmp(answer6, "set threads 256\n") == 0) && 
    (strcmp(answer7, "run\n") == 0)) {
        return 1;
    }
    else {
        return 0;
    }
}

// 8번 문제

int question8() {
    char answer1[DEFINED_LENGTH];
    printf("------------------------------------------------------------------------\n");
    printf("문제 8\n\n");
    printf("다음 MySQL 쿼리문에서 SQL Injection 입력값을 작성하시오.\n\n");
    printf("select userId, password from user where userId = 'test'\n\n");


    fgets(answer1, DEFINED_LENGTH, stdin);

    if((strcmp(answer1, "' or true;#\n") == 0)) {
        return 1;
    }
    else {
        return 0;
    }
}

// 9번 문제

int question9() {
    char answer1[DEFINED_LENGTH];
    printf("------------------------------------------------------------------------\n");
    printf("문제 9\n\n");
    printf("다음 MySQL 쿼리문에서 Union SQL Injection 입력값을 작성해서 userId에 'user_id', password에 'password'를 출력하시오.\n\n");
    printf("select userId, password from user where userId = 'test'\n\n");


    fgets(answer1, DEFINED_LENGTH, stdin);

    if((strcmp(answer1, "' UNION SELECT 'user_id', 'password';#\n") == 0)) {
        return 1;
    }
    else {
        return 0;
    }
}