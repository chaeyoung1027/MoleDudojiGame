//(문제 맞추기) 두더지 게임
#include<SFML/Graphics.hpp>
#include<iostream>

#define WIDTH 1100
#define HEIGHT 942

using namespace sf;
using namespace std;

struct Position
{
    int x;
    int y;
};

int main(void) {


	RenderWindow app(VideoMode(WIDTH, HEIGHT), "Catch Dudoji");
    app.setFramerateLimit(60);
    
    Texture t1, t2, t3, t4, t5, t6, t7, t8;
    t1.loadFromFile("images/background.png");
    t2.loadFromFile("images/hammer.png");
    t3.loadFromFile("images/hammer_pressed.png");
    /*t4.loadFromFile("images/두더지1.png");
    t5.loadFromFile("images/두더지2.png");
    t6.loadFromFile("images/두더지3.png");
    t7.loadFromFile("images/두더지4.png");
    t8.loadFromFile("images/두더지5.png");
    t9.loadFromFile("images/두더지6.png");*/

    Sprite background(t1);

    Sprite hammer[2];
    hammer[0] = Sprite(t2);
    hammer[1] = Sprite(t3);

    Sprite Dudoji[6];

    Sprite s(t2);

    Position hammerPos;
    hammerPos.x = 0;
    hammerPos.y = 0;

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
                cout << "프로그램이 종료되었습니다." << endl;
            }
            //마우스가 눌렸을 때
            switch (event.type) {
                case Event::MouseButtonPressed:
                case Mouse::Left:
                {
                    s = hammer[1];
                    printf("마우스");
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
                cout << "이동 : pos.x = " << pos.x << " pos.y = " << pos.y << endl;
                hammerPos.x = pos.x;
                hammerPos.y = pos.y;
                break;
                }
            }
            s.setPosition(hammerPos.x-70, hammerPos.y-77);
        }
        app.clear();
        app.draw(background);
        app.draw(s);

        //프레임을 스크린에 출력
        app.display();
    }

    return 0;
}