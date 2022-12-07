#include<SFML/Graphics.hpp>
#include<iostream>
#include<SFML/Audio.hpp>
//for������ �δ��� �̹��� ����
//ũ�� ������ ��� �ϴ��� ->setScaled
//��ġ�� ������ �̹����� ������ �ȴٰ� ���� -> ��ǥ �˾Ƴ��� �� �ȿ��� Ŭ���� �Ͼ�� 
//ȿ�� �ֱ� -> �Ҹ� �ֱ�, �ִϸ��̼� �ֱ�
//���� �ֱ�, Ÿ�̸� �ֱ�
//�δ����� �´� �׸� �ֱ�
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

void hit_sound_detail(const std::
    string& hitSound) {
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

    //두더지 각 위치
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
    /*
    Sprite dudoji(d1);
    dudoji.setPosition(305.0f, 240.0f);//두더지 위치 잡기
    dudoji.setScale(0.26f, 0.26f);        //두더지 크기*/

    Sprite s(h1);

    Position hammerPos;
    hammerPos.x = 0;
    hammerPos.y = 0;

    //두더지 위치 좌표
    int position[2][3] = { 240.0f, 490.0f, 740.0f, 210.0f, 440.0f, 640.0f };
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
                    s = hammer[1];
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

                printf("x좌표 : %d, y좌표 : %d\n", pos.x ,pos.y);
                break;
                }
            }
            s.setPosition(hammerPos.x-70.0, hammerPos.y-77.0);
        }
        app.clear();
        app.draw(background);
        for (int i = 0; i < 9; i++) {
            app.draw(dudoji[i]);
        }
        app.draw(dudoji[0]);
        app.draw(s);

        //프레임을 스크린에 출력
        app.display();
    }

    return 0;
}