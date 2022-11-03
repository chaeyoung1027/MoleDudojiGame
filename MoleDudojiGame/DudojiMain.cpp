//(문제 맞추기) 두더지 게임
#include<SFML/Graphics.hpp>
#include<iostream>

#define WIDTH 544
#define HEIGHT 340

#define TOY_HAMMER   100.f

using namespace sf;
using namespace std;

int main(void) {
    int x = 0, y = 0;

    //마우스 이동시 따라 움직일 Circle 객체
    CircleShape circle_shape(TOY_HAMMER);
    circle_shape.setFillColor(Color::Green);

    circle_shape.setRadius(TOY_HAMMER);
    circle_shape.setOutlineColor(sf::Color::Red);
    //circle_shape.setOutlineThickness(0); 겉 테두리
    circle_shape.setPosition(x, y);


	RenderWindow app(VideoMode(WIDTH, HEIGHT), "Catch Dudoji");
    app.setFramerateLimit(60);
    
    Texture t1;
    t1.loadFromFile("images/background.jpg");

    Sprite s1;
    s1.setTexture(t1);

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

            //마우스 버튼 뗌(Released)
                switch (event.type)
                {
                case Event:: MouseMoved:
                {
                    Vector2i pos = Mouse::getPosition(app);
                    cout << "이동 : pos.x = " << pos.x << " pos.y = " << pos.y << endl;
                    x = pos.x;
                    y = pos.y;
                    break;
                }
            }
        }
        app.clear();
        app.draw(s1);
        
        //Circloe 위치 보정
        circle_shape.setPosition(Vector2f(x - 100.f, y - 100.f));
        app.draw(circle_shape);

        //프레임을 스크린에 출력
        app.display();
    }

    return 0;
}