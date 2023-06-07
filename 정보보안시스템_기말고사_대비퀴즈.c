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
int question10();
int question11();
int question12();
int question13();
int question14();
int question15();
int question16();
int question17();
int question18();
int question19();
void print_result(int total_points, int* correct, int* incorrect, int index_correct, int index_incorrect);

int (*questions[])() = {question1, question2, question3, question4, question5, question6, question7, question8, question9, question10, question11, question12, question13, question14, question15, question16, question17, question18, question19};

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

    printf("-----------------정보보안시스템 기말고사 대비 퀴즈-----------------\n\n");

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
    printf("모든 IP 주소로부터 들어오는 패킷들을 모두 DROP 하는 iptables 정책을 작성하시오.(명령어 확장형)\n\n");

    fgets(answer, DEFINED_LENGTH, stdin);

    if(strcmp(answer, "iptables --append INPUT --source 0/0 --jump DROP\n") == 0) {
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
    printf("localhost가 아닌 호스트에서 192.168.0.100 호스트로 가는 모든 패킷에 대해 허락하는 iptables 정책을 작성하시오.(명령어 확장형)\n\n");

    fgets(answer1, DEFINED_LENGTH, stdin);

    if((strcmp(answer1, "iptabels --append INPUT --source ! localhost --destination 192.168.0.100 --jump ACCEPT\n") == 0)) {
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
    printf("TCP 프로토콜에 대한 목적지 포트가 23번(TELNET)에 대해서 모드 패킷을 허락하는 iptables 정책을 작성하시오.(명령어 확장형)\n\n");


    fgets(answer1, DEFINED_LENGTH, stdin);

    if((strcmp(answer1, "iptables --append INPUT --protocol tcp --dport 23 --jump ACCEPT\n") == 0) ) {
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
    printf("INPUT 체인의 기본 정책을 DROP으로 설정하는 iptables 정책을 작성하시오.(명령어 확장형)\n\n");


    fgets(answer1, DEFINED_LENGTH, stdin);

    if((strcmp(answer1, "iptables --policy INPUT DROP\n") == 0) ) {
        return 1;
    }
    else {
        return 0;
    }
}



// 5번 문제

int question5() {
    char answer1[DEFINED_LENGTH];
    char answer2[DEFINED_LENGTH];
    printf("------------------------------------------------------------------------\n");
    printf("문제 5\n\n");
    printf("외부에서 들어오는 모든 ICMP 요청을 차단하는 iptables 정책을 작성하시오.(명령어 확장형)\n\n");


    fgets(answer1, DEFINED_LENGTH, stdin);
    fgets(answer2, DEFINED_LENGTH, stdin);

    if((strcmp(answer1, "iptables --append INPUT --protocol icmp --icmp-type echo-request --jump LOG\n") == 0) &&
    (strcmp(answer1, "iptables --append INPUT --protocol icmp --icmp-type echo-request --jump REJECT\n") == 0)) {
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
    printf("------------------------------------------------------------------------\n");
    printf("문제 6\n\n");
    printf("192.168.149.162에 들어오는 ICMP 요청을 차단하는 iptables 정책을 작성하시오.(명령어 확장형)\n\n");


    fgets(answer1, DEFINED_LENGTH, stdin);
    fgets(answer2, DEFINED_LENGTH, stdin);

    if((strcmp(answer1, "iptables --append INPUT --source 192.168.149.162 --protocol icmp --icmp-type echo-request --jump LOG\n") == 0) &&
    (strcmp(answer2, "iptables --append INPUT --source 192.168.149.162 --protocol icmp --icmp-type echo-request --jump REJECT\n") == 0)) {
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
    printf("------------------------------------------------------------------------\n");
    printf("문제 7\n\n");
    printf("ICMP 패킷 길이가 1024 바이트 이상이면 패킷을 거부하는 iptables 정책을 작성하시오.(명령어 확장형)\n\n");


    fgets(answer1, DEFINED_LENGTH, stdin);
    fgets(answer2, DEFINED_LENGTH, stdin);
    fgets(answer3, DEFINED_LENGTH, stdin);
    fgets(answer4, DEFINED_LENGTH, stdin);

    if((strcmp(answer1, "iptables --append INPUT --protocol icmp --icmp-type echo-request -m length --length 1024: --jump LOG\n") == 0) &&
    (strcmp(answer2, "iptables --append INPUT --protocol icmp --icmp-type echo-request --jump LOG\n") == 0) &&
    (strcmp(answer3, "iptables --append INPUT --protocol icmp --icmp-type echo-request -m length --length 1024: --jump DROP")== 0) &&
    (strcmp(answer4, "iptables --append INPUT --protocol icmp --icmp-type echo-request --jump ACCEPT")== 0)) {
        return 1;
    }
    else {
        return 0;
    }
}



// 8번 문제

int question8() {
    char answer1[DEFINED_LENGTH];
    char answer2[DEFINED_LENGTH];
    char answer3[DEFINED_LENGTH];
    printf("------------------------------------------------------------------------\n");
    printf("문제 8\n\n");
    printf("TCP 스캔을 플래그별 거부를 통해 차단하는 iptables 정책을 작성하시오.(명령어 확장형, 로그 부분 미작성)\n\n");


    fgets(answer1, DEFINED_LENGTH, stdin);
    fgets(answer2, DEFINED_LENGTH, stdin);
    fgets(answer3, DEFINED_LENGTH, stdin);

    if((strcmp(answer1, "iptables --append INPUT --protocol tcp --tcp-flag ALL FIN --jump REJECT\n") == 0) &&
    (strcmp(answer2, "iptables --append INPUT --protocol tcp --tcp-flag ALL URG,PSH,FIN --jump REJECT\n") == 0) &&
    (strcmp(answer3, "iptables --append INPUT --protocol tcp --tcp -flag ALL NONE --jump REJECT"))) {
        return 1;
    }
    else {
        return 0;
    }
}



// 9번 문제

int question9() {
    char answer1[DEFINED_LENGTH];
    char answer2[DEFINED_LENGTH];
    printf("------------------------------------------------------------------------\n");
    printf("문제 9\n\n");
    printf("192.168.149.162에서 보내는 SSH 요청의 무차별 대입 공격을 차단하기 위해서 1초에 2번 들어오면 거부하는 iptables 정책을 작성하시오.(명령어 확장형, 로그 부분 미작성)\n\n");


    fgets(answer1, DEFINED_LENGTH, stdin);
    fgets(answer2, DEFINED_LENGTH, stdin);

    if((strcmp(answer1, "iptables --append INPUT --source 192.168.149.162 --protocol tcp --destination-port 22 --match state --state NEW --match recent --set\n") == 0) &&
    (strcmp(answer2, "iptables --append INPUT --source 192.168.149.162 --protocol tcp --destination-port 22 --match state --state NEW --match recent --update --seconds 1 --hitseconds 2 --jump REJECT") == 0)) {
        return 1;
    }
    else {
        return 0;
    }
}



// 10번 문제

int question10() {
    char answer1[DEFINED_LENGTH];
    printf("------------------------------------------------------------------------\n");
    printf("문제 10\n\n");
    printf("iptables에서 외부에서 유입되는 패킷에 대한 Chain은 어떤 Chain인가?\n\n");


    fgets(answer1, DEFINED_LENGTH, stdin);

    if((strcmp(answer1, "INPUT\n") == 0)) {
        return 1;
    }
    else {
        return 0;
    }
}



// 11번 문제

int question11() {
    char answer1[DEFINED_LENGTH];
    printf("------------------------------------------------------------------------\n");
    printf("문제 11\n\n");
    printf("iptables에서 로컬에서 생성된 패킷이 외부 시스템으로 접근하는 패킷 Chain은 어떤 Chain인가?\n\n");


    fgets(answer1, DEFINED_LENGTH, stdin);

    if((strcmp(answer1, "OUTPUT\n") == 0)) {
        return 1;
    }
    else {
        return 0;
    }
}



// 12번 문제

int question12() {
    char answer1[DEFINED_LENGTH];
    printf("------------------------------------------------------------------------\n");
    printf("문제 12\n\n");
    printf("iptables에서 로컬시스템을 경유하는 패킷에 대한 Chain은 어떤 Chain인가?\n\n");


    fgets(answer1, DEFINED_LENGTH, stdin);

    if((strcmp(answer1, "FORWARD\n") == 0)) {
        return 1;
    }
    else {
        return 0;
    }
}



// 13번 문제

int question13() {
    char answer1[DEFINED_LENGTH];
    printf("------------------------------------------------------------------------\n");
    printf("문제 13\n\n");
    printf("아래에서 소개하는 내용은 iptables에서 어떤 테이블의 기능인가?\n\n");

    printf("1. 기본 체인과 사용자 체인을 만들어서 각종 명령 수행\n");
    printf("2. 규칙에 해당하는 패킷에 처분\n\n");

    fgets(answer1, DEFINED_LENGTH, stdin);

    if((strcmp(answer1, "Filter\n") == 0)) {
        return 1;
    }
    else {
        return 0;
    }
}



// 14번 문제

int question14() {
    char answer1[DEFINED_LENGTH];
    printf("------------------------------------------------------------------------\n");
    printf("문제 14\n\n");
    printf("아래에서 소개하는 내용은 iptables에서 어떤 테이블의 기능인가?\n\n");

    printf("1. 사설 IP만을 사용하는 네트워크에서 IP 주소만을 변환하는 NAT 수행\n");
    printf("2. 모든 사설 호스트가 하나의 공인 주소를 통해서 연결되도록 NAPT 수행\n\n");

    fgets(answer1, DEFINED_LENGTH, stdin);

    if((strcmp(answer1, "NAT\n") == 0)) {
        return 1;
    }
    else {
        return 0;
    }
}



// 15번 문제

int question15() {
    char answer1[DEFINED_LENGTH];
    printf("------------------------------------------------------------------------\n");
    printf("문제 15\n\n");
    printf("아래에서 소개하는 내용은 iptables에서 어떤 테이블의 기능인가?\n\n");

    printf("1. 넷필터에 관여하는 여러 부분들을 수정하거나 유지하는 역할\n");
    printf("2. Filter Table 등에서 match하는 부분과 연동되어 패킷 진로에 지속적인 영향\n\n");

    fgets(answer1, DEFINED_LENGTH, stdin);

    if((strcmp(answer1, "Mangle\n") == 0)) {
        return 1;
    }
    else {
        return 0;
    }
}



// 16번 문제

int question16() {
    char answer1[DEFINED_LENGTH];
    printf("------------------------------------------------------------------------\n");
    printf("문제 16\n\n");
    printf("iptables에서 NAT의 기본 체인 중에서 패킷이 들어오기 전에 목적지 주소 변환을 수행해서 부하분산 및 프록시 등의 여러 가지 일을 수행하는 기본 체인은 무엇인가?\n\n");

    fgets(answer1, DEFINED_LENGTH, stdin);

    if((strcmp(answer1, "PREROUTING\n") == 0)) {
        return 1;
    }
    else {
        return 0;
    }
}




// 17번 문제

int question17() {
    char answer1[DEFINED_LENGTH];
    printf("------------------------------------------------------------------------\n");
    printf("문제 17\n\n");
    printf("iptables에서 NAT의 기본 체인 중에서 라우팅 후, 패킷이 빠져나가기 전에 출발지 주소 변환을 수행하는 기본 체인은 무엇인가?\n\n");

    fgets(answer1, DEFINED_LENGTH, stdin);

    if((strcmp(answer1, "POSTROUTING\n") == 0)) {
        return 1;
    }
    else {
        return 0;
    }
}




// 18번 문제

int question18() {
    char answer1[DEFINED_LENGTH];
    printf("------------------------------------------------------------------------\n");
    printf("문제 18\n\n");
    printf("iptables에서 NAT의 기본 체인 중에서 로컬 프로세스/네트워크에서 생성되어 나가는 패킷이 라우팅 되기 전에 목적지 주소에 변환이나 방향 재설정, 포트 포워딩을 수행하는 기본 체인은 무엇인가?\n\n");

    fgets(answer1, DEFINED_LENGTH, stdin);

    if((strcmp(answer1, "OUTPUT\n") == 0)) {
        return 1;
    }
    else {
        return 0;
    }
}



// 19번 문제

int question19() {
    char answer1[DEFINED_LENGTH];
    printf("------------------------------------------------------------------------\n");
    printf("문제 19\n\n");
    printf("iptalbes에서 Filter 테이블의 기본 체인들의 이름은 무엇인가?\n\n");

    fgets(answer1, DEFINED_LENGTH, stdin);

    if((strcmp(answer1, "INPUT,FORWARD,OUTPUT\n") == 0)) {
        return 1;
    }
    else {
        return 0;
    }
}