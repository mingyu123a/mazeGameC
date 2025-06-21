    #include <stdio.h>

    #define SIZE 11

    char map[SIZE][SIZE] = {
        {'#','#','#','#','#','#','#','#','#','#','#'},
        {'#','P',' ',' ','#',' ',' ',' ',' ',' ','#'},
        {'#',' ','#',' ','#',' ','#','#','#',' ','#'},
        {'#',' ','#',' ',' ',' ',' ',' ','#',' ','#'},
        {'#',' ','#','#','#','#','#',' ','#',' ','#'},
        {'#',' ',' ',' ',' ',' ','#',' ','#',' ','#'},
        {'#','#','#','#','#',' ','#',' ','#',' ','#'},
        {'#',' ',' ',' ','#',' ','#',' ','#',' ','#'},
        {'#',' ','#',' ','#',' ','#',' ','#',' ','#'},
        {'#',' ','#',' ',' ',' ',' ',' ',' ','E','#'},
        {'#','#','#','#','#','#','#','#','#','#','#'}
    }; //사이즈 11만큼의 배열생성

    int px = 1, py = 1; //사용자의 시작 위치 설정
    int moveCount = 0; //움직이는 횟수를 세는 변수 선언

    void printMap() {
        for (int y = 0; y < SIZE; y++) {
            for (int x = 0; x < SIZE; x++) {
                printf("%c ", map[y][x]);
            }//x,y가 SIZE를 넘어가지 않도록,각 위치의 문자 출력
            printf("\n");//한줄 끝나면 줄바꿈
        }
    } 

    //방향키 입력에 따라 플레이어를 이동시키는 함수
    int movePlayer(char dir) {
        int nx = px, ny = py;


        if (dir == 'w') ny--;
        else if (dir == 's') ny++;
        else if (dir == 'a') nx--;
        else if (dir == 'd') nx++;

        if (map[ny][nx] == ' ' || map[ny][nx] == 'E') {
            if (map[ny][nx] == 'E') {
                moveCount++;
                return 1; // 도착
            }

            map[py][px] = ' ';
            px = nx;
            py = ny;
            map[py][px] = 'P';
            moveCount++;
        } else {
            
            printf("장애물 때문에 %c로 이동할 수 없습니다\n", dir);
        }

        return 0; // 아직 도착 안함
    }

    int main() {
        char input; //사용자의 입력을 받을 변수

        while (1) {
            printMap();

            printf("이동 (WASD), 종료(q): ");
            scanf(" %c", &input);

            if (input == 'q') break;

            if (movePlayer(input)) {
                printMap(); // 도착했을 때 최종 상태 출력
                printf("클리어!\n");
                printf("총 이동 횟수: %d\n", moveCount);
                break;
            }
    }


        return 0;
    }
