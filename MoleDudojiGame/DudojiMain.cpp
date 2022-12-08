#include<SFML/Graphics.hpp>
#include<iostream>
#include<SFML/Audio.hpp>
#include <stdlib.h> 
//두더지 애니메이션, 맞는효과, 시간,  효과음

#define WIDTH 1152
#define HEIGHT 942

using namespace sf;
using namespace std;

struct Position
{
    int x;
    int y;
};

void hit_sound_detail(const std::string& hitSound) {
    SoundBuffer buffer;
    //오디오 파일 읽기
    if (!buffer.loadFromFile(hitSound))
    {
        cout << "loadFromFile에러" << endl;
        return;
    }
}
//오디오 재생
//Sound sound(buffer);
//sound.play();

int main(void) {


	RenderWindow app(VideoMode(WIDTH, HEIGHT), "Catch Dudoji");
    app.setFramerateLimit(60);
    
    Texture b1;
    b1.loadFromFile("images/background.png");
    
    Texture h1, h2;
    h1.loadFromFile("images/hammer.png");
    h2.loadFromFile("images/hammer_pressed.png");

    //두더지 맞기 전
    Texture d1, d2, d3, d4, d5, d6;
    d1.loadFromFile("images/dudoji_img1.png");
    d2.loadFromFile("images/dudoji_img2.png");
    d3.loadFromFile("images/dudoji_img3.png");
    d4.loadFromFile("images/dudoji_img4.png");
    d5.loadFromFile("images/dudoji_img5.png");
    d6.loadFromFile("images/dudoji_img6.png");

    //두더지 맞은 후
    Texture dh1, dh2, dh3, dh4, dh5, dh6;
    dh1.loadFromFile("images/dudojihit_img1.png");
    dh2.loadFromFile("images/dudojihit_img2.png");
    dh3.loadFromFile("images/dudojihit_img3.png");
    dh4.loadFromFile("images/dudojihit_img4.png");
    dh5.loadFromFile("images/dudojihit_img5.png");
    dh6.loadFromFile("images/dudojihit_img6.png");

    //배경
    Sprite background(b1);      
    background.setScale(1.2f, 1.2f);

    Sprite hammer[2];
    hammer[0] = Sprite(h1);     //망치
    hammer[1] = Sprite(h2);     //때리는 망치

    //변하는 모습
    Sprite Dudoji[6];
    Dudoji[0] = Sprite(d1);
    Dudoji[1] = Sprite(d2);
    Dudoji[2] = Sprite(d3);
    Dudoji[3] = Sprite(d4);
    Dudoji[4] = Sprite(d5);
    Dudoji[4] = Sprite(d6);

    //두더지
    Sprite dudoji[9];
    dudoji[0] = Sprite(d1);
    dudoji[1] = Sprite(d1);
    dudoji[2] = Sprite(d1);
    dudoji[3] = Sprite(d1);
    dudoji[4] = Sprite(d1);
    dudoji[5] = Sprite(d1);
    dudoji[6] = Sprite(d1);
    dudoji[7] = Sprite(d1);
    dudoji[8] = Sprite(d1);

    //망치
    Sprite s(h1);

    //망치 위치
    Position hammerPos;
    hammerPos.x = 0;
    hammerPos.y = 0;

    srand(time(NULL));

    //두더지 유무 배열
    int dudoji_ox[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1};

    //두더지 위치 좌표
    float position[2][3] = { 240.0f, 490.0f, 740.0f, 210.0f, 440.0f, 640.0f };
    int a = 0;

    //두더지 위치 설정 for문
    for (int i = 0; i < 9; i++) {
        dudoji[i].setScale(0.3f, 0.3f);
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            dudoji[a].setPosition(position[0][i], position[1][j]);
            a++;
        }
    }

    /*//타이머
    clock_t start = clock();
    clock_t end = clock();
    int second = 1; //1초마다 반복하기 위한 변수
    int endsecond = 100;    //100초동안 게임
    while (double(end - start) / CLOCKS_PER_SEC == endsecond) {
        printf("%d", double(end - start) / CLOCKS_PER_SEC == endsecond);
        end = clock();

        if (double(end - start) / CLOCKS_PER_SEC == second) {
            //두더지 유무 랜덤
            for (int i = 0; i < 9; i++) {
                if (dudoji_ox[i] == 0) {
                    dudoji_ox[i] = rand() % 3;
                }
            }
            //만약 ox(유무)가 1이면 출력
            for (int i = 0; i < 9; i++) {
                if (dudoji_ox[i] == 1) {
                    app.draw(dudoji[i]);
                }
            }
        }
    }*/

    //x누르면 종료되는 코드
    //SFML 메인 루프 - 윈도우가 닫힐때 까지 반복
    while (app.isOpen())
    {
        
        // 루프가 반복되는 동안 트리거가 걸린 윈도우의 이벤트 체크
        Event event;
        while (app.pollEvent(event))
        {
            //"close 요청" 이벤트. 윈도우를 종료.
            if (event.type == Event::Closed) {
                app.close();
            }
            //마우스가 눌렸을 때
            switch (event.type) {
                case Event::MouseButtonPressed:
                case Mouse::Left:
                {
                    Vector2i pos = Mouse::getPosition(app);
                    s = hammer[1];
                    //눌렀을 때 두더지가 사라지는 영역 설정
                    if (pos.x > 240.0f && pos.x < 450.0f && pos.y>210.0f && pos.y < 420.0f) dudoji_ox[0] = 0;
                    if (pos.x > 470.0f && pos.x < 680.0f && pos.y>210.0f && pos.y < 420.0f) dudoji_ox[3] = 0;
                    if (pos.x > 700.0f && pos.x < 910.0f && pos.y>210.0f && pos.y < 420.0f) dudoji_ox[6] = 0;

                    if (pos.x > 240.0f && pos.x < 450.0f && pos.y>440.0f && pos.y < 630.0f) dudoji_ox[1] = 0;
                    if (pos.x > 470.0f && pos.x < 680.0f && pos.y>440.0f && pos.y < 630.0f) dudoji_ox[4] = 0;
                    if (pos.x > 700.0f && pos.x < 910.0f && pos.y>440.0f && pos.y < 630.0f) dudoji_ox[7] = 0;

                    if (pos.x > 260.0f && pos.x < 470.0f && pos.y>640.0f && pos.y < 850.0f) dudoji_ox[2] = 0;
                    if (pos.x > 490.0f && pos.x < 600.0f && pos.y>640.0f && pos.y < 850.0f) dudoji_ox[5] = 0;
                    if (pos.x > 740.0f && pos.x < 950.0f && pos.y>640.0f && pos.y < 850.0f) dudoji_ox[8] = 0;
                    break;
                }
            }
            //마우스가 떼졌을 때MouseButtonReleased
            switch (event.type) {
            case Event::MouseButtonReleased:
            case Mouse::Left:
            {
                s = hammer[0];
                break;
            }
            }

            //마우스가 움직일 때
            switch (event.type)
            {
            case Event:: MouseMoved:
            {
                Vector2i pos = Mouse::getPosition(app);
                hammerPos.x = pos.x;
                hammerPos.y = pos.y;
                break;
                }
            }
            s.setPosition(hammerPos.x-70.0, hammerPos.y-77.0);
        }

        app.clear();
        app.draw(background);
        app.draw(s);

        //프레임을 스크린에 출력
        app.display();
    }
    return 0;
}