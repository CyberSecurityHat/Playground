#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define DEFINED_LENGTH 200

typedef struct {
    char *question;
    char *answer;
    int (*check_answer)(char *user_answer, char *correct_answer);
} Question;

int check_answer(char *user_answer, char *correct_answer) {
    if (strcmp(user_answer, correct_answer) == 0) {
        printf("정답입니다!\n\n");
        return 1;
    } else {
        printf("오답입니다. 정답은 '%s'입니다.\n\n", correct_answer);
        return 0;
    }
}

Question questions[] = {
    {"파일 난독화 탐지 용도로 사용되며 패킹 여부와 언패킹 방식을 확인 가능한 윈도우용 프로그램은 무엇인가?", "EXEinfo PE\n", check_answer},
    {"PE 파일의 리소스를 확인하고 프로세스를 조사하는 윈도우용 프로그램은 무엇인가?", "Resource Hacker\n", check_answer},
    {"strings, 파일 의존성과 임포트 조사 등을 하는 윈도우용 프로그램은 무엇인가?", "PE Studio\n", check_answer},
    {"PE 파일에서 실행코드가 위치하는 영역은 어느 어디인가?", ".text\n", check_answer},
    {"PE 파일에서 저장 문자열 등(초기화된 전역변수, Static 변수)이 위치하는 영역은 어디인가?", ".data\n", check_answer},
    {"PE 파일에서 임포트가 위치하는 영역은 어디인가?", ".idata\n", check_answer},
    {"PE 파일에서 익스포트가 위치하는 영역은 어디인가?", ".edata\n", check_answer},
    {"PE Studio의 섹션에서 실행파일 크기를 나타내는 부분은 어디인가?", "raw-size\n", check_answer},
    {"PE Studio의 섹션에서 실제 실행 중에 차지하는 크기를 나타내는 부분은 어디인가?", "virtual-size\n", check_answer},
    {"아래 보기를 보고 ','를 구분자로 하여, 동적분석의 절차를 순서대로 적으시오.(기호를 적으시오.)\n\n<보기>\nA : 클린샷으로 복원\nB : 모니터링 동적분석 도구 준비하기\nC : 결과 분석하기\nD : 모니터링 도구 종료하기\nE : 악성코드 샘플 실행하기", "A,B,E,D,C\n", check_answer},
    {"시스템의 상호작용을 조사하는 윈도우용 악성코드 동적 분석 프로그램은 무엇인가?", "Process Monitor\n", check_answer},
    {"시스템 활동 로깅을 하며, Pcoress Monitor를 엑셀 형식으로 정리해주는 윈도우용 프로그램은 무엇인가?", "Noriben\n", check_answer},
    {"Process Hacker에서 remote address를 보려고 한다. 무엇을 확인해야 하는가?", "Network\n", check_answer},
    {"Process Hacker에서 dll 로드를 확인 하려고 한다. Properties에서 무엇을 확인해야 하는가?", "Modules\n", check_answer},
    {"Process Hacker에서 api를 확인하려고 한다. Properties에서 무엇을 확인해야 하는가?", "Threads\n", check_answer},
    {"Noriben에서 파일 쓰고 열기를 확인 하려고 한다. 무엇을 확인해야 하는가?", "File Activity\n", check_answer},
    {"Noriben에서 CTR, Black list IP 관련해서 확인 하려고 한다. 무엇을 확인해야 하는가?", "Unique Hosts\n", check_answer},
    {"Noriben이 위치한 폴더에서 cmd를 열었다. Noriben을 실행시키는 명령어를 적으시오.", "python Noriben.py\n", check_answer},
    {"통제된 상황에서 실행한 후 분석하는 것을 무엇이라고 하는지 적으시오.", "동적 분석\n", check_answer},
    {"사용자와 상호작용을 통해 전자(복제)되는, 자가 복제 및 전파 기능을 가진 악성코드의 이름을 적으시오.", "바이러스\n", check_answer},
    {"스스로 전파가 가능한, 자가 복제 및 전파 기능을 가진 악성코드의 이름을 적으시오.", "웜\n", check_answer},
    {"일반 프로그램으로 위장하여 시스템에 설치하도록 유도하는 악성코드의 이름을 적으시오.", "트로이 목마\n", check_answer},
    {"공격자가 침투한 시스템에 원격 접속하거나 명령을 실행할 수 있는 악성코드의 이름을 적으시오.", "백도어\n", check_answer},
    {"사용자에게 원치 않는 광고를 노출하는 악성코드의 이름을 적으시오.", "애드웨어\n", check_answer},
    {"동일한 악성코드에 감염된 시스템의 그룹으로, 공격자가 통제하는 C2 서버의 지시를 대기하는 것의 이름을 적으시오.", "봇넷\n", check_answer},
    {"사용자의 개인 정보를 수집하거나 유출하는 악성코드의 이름을 적으시오.", "정보 스틸러\n", check_answer},
    {"사용자를 시스템 밖으로 쫓아내거나 파일을 암호화한 후 대가를 요구하는 악성코드의 이름을 적으시오.", "랜섬웨어\n", check_answer},
    {"공격자에게 관리자 권한을 제공하거나 자신 또는 다른 SW의 존재를 숨기는 악성코드의 이름을 적으시오.", "루트킷\n", check_answer},
    {"추가 악성코드 컴포넌트를 다운로드 하거나 설치하도록 설계된 악성코드의 이름을 적으시오.", "다운로더\n", check_answer},
    {"악성코드의 행위를 연구하는 것을 무엇이라고 하는지 적으시오.", "악성코드 분석\n", check_answer},
    {"SQL 슬래머는 어떠한 악성코드 유형의 사례인지 적으시오.", "웜\n", check_answer},
    {"모든 공격 통로를 무엇이라고 하는지 적으시오.", "Attack Surface\n", check_answer},
    {"실제 공격자가 이용한 공격 통로를 무엇이라고 하는지 적으시오.", "Attack Vector\n", check_answer},
    {"다른 파일에 붙여넣기해서 기생하는 방식으로 감염이 이루어지고 실행해야지 감염되는 악성코드의 유형을 적으시오.", "바이러스\n", check_answer},
    {"각종 공격 기법이 결합된 악성코드 유형의 이름을 적으시오.", "멀티 스테이지\n", check_answer},
    {"악성코드를 분석하는 이유는 악성코드와 관련된 네트워크 식별자를 파악하기 위해서, 파일명과 레지스트리 키 등의 호스트 내부의 식별자를 추출하기 위해서이다. 이러한 식별자를 무엇이라고 하는지 적으시오.", "Indicator\n", check_answer},
    {"악성코드와 관련된 네트워크 식별자를 파악할 때 사용하는 지표를 적으시오.", "IOC\n", check_answer},
    {"악성코드 분석 방법 중 의심 바이너리의 모든 기능을 찾을 수는 없는 방법을 적으시오.", "동적 분석\n", check_answer},
    {"의심 바이너리 내부 동작을 이해하기 위하여 코드를 분석하는 방법의 이름을 적으시오.", "코드 분석\n", check_answer},
    {"의심 바이너리를 디스어셈블링하여 코드 분석하는 것을 무엇이라고 하는지 적으시오.", "정적 코드 분석\n", check_answer},
    {"의심 바이너리를 통제된 방법으로 디버깅하는 것을 무엇이라고 하는지 적으시오.", "동적 코드 분석\n", check_answer},
    {"포렌식 아티팩트(흔적)를 찾기 위해 메모리를 분석하는 기법의 이름을 적으시오.", "메모리 분석\n", check_answer},
    {"감염 후 악성코드 행위를 이해하며, 악성코드 은닉 또는 회피 능력을 파악하는데 유용한 의심 바이너리 분석 방법을 적으시오.", "동적 코드 분석\n", check_answer},
    {"의심 바이너리의 파일 유형 구분의 기준이 되는 것이 무엇인지 적으시오.", "파일 시그니처\n", check_answer},
    {"도구를 이용한 파일 유형 식별을 할 경우, 윈도우에서 사용하는 에디터를 적으시오.", "CFF Explorer\n", check_answer},
    {"의심 바이너리의 악성코드 식별 기준이 되는 것의 이름을 적으시오.", "파일 해시\n", check_answer},
    {"난독화된 문자열을 추출하는 툴의 이름을 적으시오.", "FLOSS\n", check_answer},
    {"악성코드의 탐지를 회피하고자 실행 파일의 내용을 압축하여 난독화하는 것의 이름을 적으시오.", "패커\n", check_answer},
    {"악성코드의 탐지를 회피하고자 실행 파일의 내용을 암호화하여 난독화하는 것의 이름을 적으시오.", "크립터\n", check_answer},
    {"윈도우에서 파일 난독화를 탐지하는 프로그램을 적으시오.", "Exeinfo PE\n", check_answer},
    {"윈도우에서 파일 난독화를 탐지하는 프로그램을 적으시오.", "PE/COFF\n", check_answer},
    {"PE 헤더가 생성 정보를 포함하는 것은 바이너리에서 어떠한 작업이 이루어질 때인지 적으시오.", "컴파일\n", check_answer},
    {"악성코드 생성 시기를 조사하는 것의 이름을 적으시오.", "컴파일 타임프탬프 조사\n", check_answer},
    {"퍼지 해싱을 위해서 사용하는 모듈의 이름을 적으시오.", "ssdeep\n", check_answer},
    {"다음 보기의 각 절차들을 ','를 구분자로 하여, 순서대로 적으시오.(기호를 적으시오.)\n\n<보기>\nA : 악성코드 식별\nB : 다중 백신 스캐닝\nC : 파일 유형 파악", "C,A,B\n", check_answer},
    {"sha256 파일 해시 확인 명령어를 적으시오.", "sha256sum\n", check_answer}
};

void print_result(int total_points, int* correct, int* incorrect, char **user_answers, Question* questions, int index_correct, int index_incorrect) {
    printf("\n\n------------------Quiz Result------------------\n\n");
    printf("점수: %d\n", total_points);

    for(int i = 0; i < index_correct; i++) {
        printf("맞은 문제 번호: %d\n", correct[i]);
    }
    printf("\n");

    
    for(int i = 0; i < index_incorrect; i++) {
        int question_index = incorrect[i] - 1;
        printf("틀린 문제 번호: %d\n", incorrect[i]);
        printf("문제: %s\n", questions[question_index].question);
        printf("사용자 답변: %s", user_answers[question_index]);
        printf("정답: %s\n", questions[question_index].answer);
    }
    printf("\n");
}

int main(void) {
    srand(time(NULL));
    int point = 0;
    int correct[DEFINED_LENGTH] = {0};
    int incorrect[DEFINED_LENGTH] = {0};
    int index_correct = 0;
    int index_incorrect = 0;

    int num_questions = sizeof(questions) / sizeof(questions[0]);
    char **user_answers = malloc(num_questions * sizeof(char*));

    if(user_answers == NULL) {
        fprintf(stderr, "Memory allocation failed!\n\n");
        return -1;
    }

    for(int i = 0; i < num_questions; i++) {
        user_answers[i] = (char*) malloc(DEFINED_LENGTH * sizeof(char));
        if (user_answers[i] == NULL) {
            fprintf(stderr, "Memory allocation failed!\n\n");
            return -1;
        }
    }

    printf("-----------------악성코드 기말고사 대비 퀴즈-----------------\n\n");

    printf("문제 설명 : 다수의 정답을 기대할 때는 ','을 구분자로 사용(순서가 있을 경우, 순서에 맞춰서 작성)\n");
    printf("명령어는 실제로 명령어를 작성하듯이 순서대로 작성\n\n");

    for(int i = 0; i < num_questions; i++) {
        printf("------------------------------------------------------------------------\n");
        printf("문제 %d\n\n", i+1);
        printf("%s\n\n", questions[i].question);

        fgets(user_answers[i], DEFINED_LENGTH, stdin);

        if(questions[i].check_answer(user_answers[i], questions[i].answer) == 1) {
            correct[index_correct++] = i + 1;
            point++;
        } else {
            incorrect[index_incorrect++] = i + 1;
        }
    }

    print_result(point, correct, incorrect, user_answers, questions, index_correct, index_incorrect);

    getchar();

    for(int i = 0; i < num_questions; i++) {
        free(user_answers[i]);
    }
    free(user_answers);

    return 0;
}
