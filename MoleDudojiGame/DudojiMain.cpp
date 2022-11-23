//(문제 맞추기) 두더지 게임
#include<SFML/Graphics.hpp>
#include<iostream>

#define WIDTH 1100
#define HEIGHT 942

using namespace sf;
using namespace std;

int main(void) {
    int x = 0, y = 0;

	RenderWindow app(VideoMode(WIDTH, HEIGHT), "Catch Dudoji");
    app.setFramerateLimit(60);
    
    Texture background, hammer;
    background.loadFromFile("images/background.png");
    hammer.loadFromFile("images/뿅망치.png");
    /*t1.loadFromFile("images/두더지1.png");
    t1.loadFromFile("images/두더지2.png");
    t1.loadFromFile("images/두더지3.png");
    t1.loadFromFile("images/두더지4.png");
    t1.loadFromFile("images/두더지5.png");
    t1.loadFromFile("images/두더지6.png");*/

    Sprite s1;
    s1.setTexture(background);

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
            switch (event.type) {
            case Event::MouseButtonPressed:
            case Mouse::Left:
            {

            }
            }

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

        //프레임을 스크린에 출력
        app.display();
    }

    return 0;
}